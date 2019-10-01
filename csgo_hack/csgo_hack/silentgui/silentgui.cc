////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

#include "../source_development_kit/source_development_kit.hh"

c_silentgui* silentgui;

std::vector<std::string> tabs = { "Aimbot", "Visuals", "Misc" };
int main_window_selected_tab;

void c_silentgui::run()
{
	static bool menu_opened = true;

	if (GetAsyncKeyState(VK_INSERT) & 1)
		menu_opened = !menu_opened;

	if (!menu_opened)
		return;

	auto window = new c_window("xyo (its pronounced 'ze-oh' not 'ex-why-oh' retards)", &vec2_t(800, 200), vec2_t(500, 350), tabs, &main_window_selected_tab);
	{
		auto groupbox = new c_groupbox("Groupbox", vec2_t(30, 80), vec2_t(100, 100), 0);
		{
			window->add_groupbox(groupbox);
		}
	}
}