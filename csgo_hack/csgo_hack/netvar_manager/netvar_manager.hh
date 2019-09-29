// (c) namazso (https://www.unknowncheats.me/forum/counterstrike-global-offensive/209624-fast-easy-netvar-manager.html)

class fnv_hash
{
	static const unsigned int fnv_prime = 16777619u;
	static const unsigned int offset_basis = 2166136261u;

	template <unsigned int N>
	static constexpr unsigned int fnvHashConst(const char(&str)[N], unsigned int I = N)
	{
		return I == 1 ? (offset_basis ^ str[0]) * fnv_prime : (fnvHashConst(str, I - 1) ^ str[I - 1]) * fnv_prime;
	}

	static unsigned int fnvHash(const char* str)
	{
		const size_t length = strlen(str) + 1;
		unsigned int hash = offset_basis;
		for (size_t i = 0; i < length; ++i)
		{
			hash ^= *str++;
			hash *= fnv_prime;
		}
		return hash;
	}

	struct Wrapper
	{
		Wrapper(const char* str) : str(str) { }
		const char* str;
	};

	unsigned int hash_value;
public:
	fnv_hash(Wrapper wrapper) : hash_value(fnvHash(wrapper.str)) { }

	template <unsigned int N>
	constexpr fnv_hash(const char(&str)[N]) : hash_value(fnvHashConst(str)) { }

	constexpr operator unsigned int() const { return this->hash_value; }
};

class netvar_manager
{
public:
	static netvar_manager& get()
	{
		static netvar_manager Instance;

		return Instance;
	}

	unsigned short get_offset(unsigned int wHash)
	{
		return map_offsets[wHash]->offset;
	}

	valve::recv_prop* get_prop_pointer(unsigned int wHash)
	{
		return map_offsets[wHash];
	}

private:
	netvar_manager();
	void dump_recursive(valve::recv_table* table);

private:
	std::map<unsigned int, valve::recv_prop*> map_offsets;
};

#define pointer_netvar(funcname, type, netvarname) type* funcname() \
{ \
	constexpr auto hash = fnv_hash(netvarname); \
	static uintptr_t offset = netvar_manager::get().get_offset(hash); \
	return reinterpret_cast<type*>(uintptr_t(this) + offset); \
}

#define netvar(funcname, type, netvarname) type& funcname() \
{ \
	constexpr auto hash = fnv_hash(netvarname); \
	static uintptr_t offset = netvar_manager::get().get_offset(hash); \
	return *reinterpret_cast<type*>(uintptr_t(this) + offset); \
}