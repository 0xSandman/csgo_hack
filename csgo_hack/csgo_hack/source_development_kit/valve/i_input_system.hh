namespace valve
{
	class i_input_system
	{
	public:
		void enable_input(bool enabled)
		{
			typedef void(__thiscall * vfunc)(void*, bool);
			return utilties::get_virtual_function<vfunc>(this, 11)(this, enabled);
		}

		void reset_input_state()
		{
			typedef void(__thiscall * vfunc)(void*);
			return utilties::get_virtual_function<vfunc>(this, 39)(this);
		}
	};
}