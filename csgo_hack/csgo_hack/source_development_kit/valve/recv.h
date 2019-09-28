namespace valve
{
	struct recv_prop;
	class recv_proxy_data;
	typedef void( *recv_var_proxy_fn )( const recv_proxy_data* pData, void* pStruct, void* pOut );

	enum class send_prop_type
	{
		dpt_int = 0,
		dpt_float,
		dpt_vector,
		dpt_vectorxy,
		dpt_string,
		dpt_array,
		dpt_datatable,
		dpt_int64,
		dpt_numsendproptypes
	};

	class d_variant
	{
	public:
		union
		{
			float	m_Float;
			long	m_Int;
			char* m_pString;
			void* m_pData;
			float	m_Vector[ 3 ];
		};
	};

	class recv_proxy_data
	{
	public:
		const recv_prop* recv_prop;
		char _pad[ 4 ];
		d_variant value;
		int	element;
		int	object_id;
	};

	struct recv_table
	{
		recv_prop* props;
		int	num_props;
		void* decoder;
		char* net_table_name;
		bool initialized;
		bool in_main_list;
	};

	struct recv_prop
	{
		char* var_name;
		int	recv_type;
		int	flags;
		int	string_buffer_size;
		bool inside_array;
		const void* extra_data;
		recv_prop* prop_array;
		void* array_length_proxy;
		void* proxy;
		void* data_table_proxy;
		recv_table* data_table;
		int	offset;
		int	element_stride;
		int	elements;
		const char* parent_array_prop_name;
	};

	class client_class
	{
	public:
		void* create;
		void* create_event;
		char* network_name;
		recv_table* recv_table;
		client_class* next;
		int	class_id;
	};
}