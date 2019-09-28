// (c) mcswaggens

class vmt_hook
{
private:
	uintptr_t* vmt;
public:
	uintptr_t** p_interface = nullptr;
	uintptr_t* original_vmt = nullptr;
	uint32_t method_count = 0;
	vmt_hook( );
	vmt_hook( void* p_interface );
	void hook( void* method, size_t method_index );
	void apply( );
	void release( );
	template<typename Fn>
	Fn original( size_t method_index ) { return reinterpret_cast< Fn >( original_vmt[ method_index ] ); }
};