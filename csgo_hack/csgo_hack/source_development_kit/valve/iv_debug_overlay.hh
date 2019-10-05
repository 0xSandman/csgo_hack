namespace valve
{
	class iv_debug_overlay
	{
	public:
		int screen_position(const vec3_t& point, vec3_t& screen)
		{
			typedef int(__thiscall * vfunc)(void*, const vec3_t&, vec3_t&);
			return utilties::get_virtual_function<vfunc>(this, 13)(this, point, screen);
		}
	};
}