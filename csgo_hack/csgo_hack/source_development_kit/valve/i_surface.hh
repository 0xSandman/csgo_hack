namespace valve
{
	class i_surface
	{
	public:
		void unlock_cursor()
		{
			typedef void(__thiscall * vfunc)(void*);
			return utilties::get_virtual_function<vfunc>(this, 66)(this);
		}
	};
}