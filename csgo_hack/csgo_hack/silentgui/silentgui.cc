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

enum tab_list_t
{
	aimbot_tab = 0,
	visuals_tab,
	misc_tab
};

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

	rectangles_to_draw.clear();
	text_to_draw.clear();
	outlines_to_draw.clear();
}

void c_silentgui::run()
{
	menu_helpers::handle_input();

	if (menu_helpers::key_was_pressed(VK_INSERT))
	{
		menu_helpers::menu_open = !menu_helpers::menu_open;
		interfaces::input_system->enable_input(!menu_helpers::menu_open);
		interfaces::input_system->reset_input_state();
	}

	if (!menu_helpers::menu_open)
		return;

	menu_helpers::control_index = 0;

	auto window = new c_window("xyo (hex editing this is a federal crime, punishable by firing squad)", &window_position, vec2_t(500, 350), tabs, &main_window_selected_tab);
	{
	}

	this->handle_vector_drawing();

}