////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

#include "../source_development_kit/source_development_kit.hh"

c_silentgui* silentgui;

vec2_t window_position = vec2_t(800, 200);
std::vector<std::string> tabs = { "Aimbot", "Visuals", "Misc" };
int main_window_selected_tab;

bool test_bool;
bool test_bool2;
bool test_bool3;
bool test_bool4;

float test_float = 15;

void c_silentgui::run()
{
	menu_helpers::handle_input();

	if (GetAsyncKeyState(VK_INSERT) & 1)
	{
		menu_helpers::menu_open = !menu_helpers::menu_open;
		interfaces::input_system->enable_input(!menu_helpers::menu_open);
		interfaces::input_system->reset_input_state();
	}

	if (!menu_helpers::menu_open)
		return;

	menu_helpers::control_index = 0;

	auto window = new c_window("xyo (its pronounced 'ze-oh' not 'ex-why-oh' retards)", &window_position, vec2_t(500, 350), tabs, &main_window_selected_tab);
	{
		auto groupbox = new c_groupbox("Groupbox", vec2_t(30, 80), vec2_t(300, 150), 0);
		{
			window->add_groupbox(groupbox);
			groupbox->add_control(new c_checkbox("Checkbox", &test_bool));
			groupbox->add_control(new c_checkbox("Checkbox 2", &test_bool2));
			groupbox->add_control(new c_checkbox("Checkbox 3", &test_bool3));
			groupbox->add_control(new c_slider("Slider", &test_float));
			groupbox->add_control(new c_checkbox("Checkbox 4", &test_bool4));

		}
	}
}