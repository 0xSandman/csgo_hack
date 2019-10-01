#include "../source_development_kit/source_development_kit.hh"

c_render* render = NULL;

vmt_hook* hooks::d3d9_device_hook = nullptr;
WNDPROC hooks::original_wndproc;

void hooks::setup()
{
	d3d9_device_hook = new vmt_hook(reinterpret_cast<IDirect3DDevice9*>(interfaces::d3d9_device));
	d3d9_device_hook->hook(reinterpret_cast<void*>(endscene), 42);
	d3d9_device_hook->apply();
	console->log("[ hook ] hooked endscene", 2);

	original_wndproc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(FindWindowA(nullptr, "Counter-Strike: Global Offensive"), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(wndproc)));
	console->log("[ hook ] hooked wndproc", 2);
}

void hooks::free()
{
	d3d9_device_hook->release();
	SetWindowLongPtr(FindWindowA(nullptr, "Counter-Strike: Global Offensive"), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(original_wndproc));
}