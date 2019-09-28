namespace valve
{
	class c_client
	{
	public:
		client_class* get_classes( )
		{
			typedef client_class* ( __thiscall * vfunc )( void* );
			return utilties::get_virtual_function<vfunc>( this, 9 )( this );
		}
	};
}