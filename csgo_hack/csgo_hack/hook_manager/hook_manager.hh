namespace hooks
{
	extern vmt_hook* d3d9_device_hook;
	extern vmt_hook* i_surface_hook;

	using end_scene_fn = long(__stdcall*)(IDirect3DDevice9* device);
	extern WNDPROC original_wndproc;
	using lock_cursor_fn = void(__stdcall*)();

	long __stdcall endscene(IDirect3DDevice9* device);
	LRESULT _stdcall wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	void __stdcall lockcursor();

	void setup();
	void free();
}