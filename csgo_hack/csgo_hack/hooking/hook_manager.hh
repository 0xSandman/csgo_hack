namespace hooks
{
	extern vmt_hook* d3d9_device_hook;

	using end_scene_fn = long(__stdcall*)(IDirect3DDevice9* device);
	extern WNDPROC original_wndproc;

	long __stdcall endscene(IDirect3DDevice9* device);
	LRESULT __stdcall wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	void setup();
	void free();
}