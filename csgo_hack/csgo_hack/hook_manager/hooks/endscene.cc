#include "../../source_development_kit/source_development_kit.hh"

long __stdcall hooks::endscene(IDirect3DDevice9* device)
{
	static end_scene_fn original = d3d9_device_hook->original<end_scene_fn>(42);

	if (render == NULL)
	{
		render = new c_render(device);
		fonts::setup(device);
		return original(device);
	}

	render->save_state();
	render->setup_render_states();
	render->text(300, 15, fonts::main_font, "counter-strike: global offensive", D3DCOLOR_RGBA(255, 255, 255, 255), true, true, D3DCOLOR_RGBA(0, 0, 0, 255));
	silentgui->run();
	render->restore_state();

	return original(device);
}