////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

#include "../source_development_kit/source_development_kit.hh"

c_silentgui* silentgui;

std::vector<rectangle_draw_t> rectangles_to_draw;
std::vector<text_draw_t> text_to_draw;
std::vector<outline_draw_t> outlines_to_draw;

vec2_t window_position = vec2_t(800, 200);
std::vector<std::string> tabs = { "Aimbot", "Visuals", "Misc" };
int main_window_selected_tab;

bool test_bool;
bool test_bool2;
bool test_bool3;
bool test_bool4;

float test_float = 15;

void c_silentgui::handle_vector_drawing()
{
	for (int i = 0; i < rectangles_to_draw.size(); i++)
	{
		render->rectangle(rectangles_to_draw[i].x, rectangles_to_draw[i].y, rectangles_to_draw[i].w, rectangles_to_draw[i].h, rectangles_to_draw[i].color);
	}

	for (int i = 0; i < text_to_draw.size(); i++)
	{
		render->text(text_to_draw[i].x, text_to_draw[i].y, text_to_draw[i].font, text_to_draw[i].text, text_to_draw[i].color, text_to_draw[i].centered, text_to_draw[i].drop_shadow, text_to_draw[i].shadow_color);;
	}

	for (int i = 0; i < outlines_to_draw.size(); i++)
	{
		render->outline(outlines_to_draw[i].x, outlines_to_draw[i].y, outlines_to_draw[i].w, outlines_to_draw[i].h, outlines_to_draw[i].color);
	}
}

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

	this->handle_vector_drawing();
}