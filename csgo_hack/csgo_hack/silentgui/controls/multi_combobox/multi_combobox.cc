////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

#include "../../../source_development_kit/source_development_kit.hh"

c_multicombobox::c_multicombobox()
{
}

c_multicombobox::c_multicombobox(std::string name)
{
	this->name = name;
	this->items = items;
}

void c_multicombobox::run()
{
	static auto stored_index = -1;
	static bool open = false;
	auto combobox_size = 70;

	if (menu_helpers::key_was_pressed(VK_LBUTTON) && menu_helpers::mouse_is_over_point(vec2_t(this->position.x, this->position.y), vec2_t(combobox_size, 14)))
	{
		open = !open;
		stored_index = menu_helpers::control_index;
	}

	if (stored_index == menu_helpers::control_index)
		this->focused = open;

	render->rectangle(this->position.x, this->position.y, combobox_size, 14, this->focused ? D3DCOLOR_RGBA(150, 24, 27, 255) : D3DCOLOR_RGBA(25, 25, 25, 255));
	render->outline(this->position.x, this->position.y, combobox_size, 14, D3DCOLOR_RGBA(25, 25, 25, 255));
	render->text(this->position.x + combobox_size + 4, this->position.y + 1, fonts::main_font, this->name, D3DCOLOR_RGBA(0, 0, 0, 255));

	if (this->focused)
	{
		rectangles_to_draw.insert(rectangles_to_draw.begin(), rectangle_draw_t(this->position.x, this->position.y + 14, combobox_size, this->items.size() * 14, D3DCOLOR_RGBA(24, 24, 24, 255)));
		outlines_to_draw.insert(outlines_to_draw.begin(), outline_draw_t(this->position.x, this->position.y + 14, combobox_size, this->items.size() * 14, D3DCOLOR_RGBA(24, 24, 24, 255)));

		for (int i = 0; i < this->items.size(); i++)
		{
			if (menu_helpers::key_was_pressed(VK_LBUTTON) && menu_helpers::mouse_is_over_point(vec2_t(this->position.x, this->position.y + 14 + (i * 14)), vec2_t(combobox_size, 14)))
				*this->items[i].value = !*this->items[i].value;

			text_to_draw.insert(text_to_draw.begin(), text_draw_t(this->position.x + 2, this->position.y + 15 + (i * 14), fonts::main_font, this->items[i].name , *this->items[i].value ? D3DCOLOR_RGBA(150, 24, 27, 255) : D3DCOLOR_RGBA(255, 255, 255, 255)));
		}
	}

	std::string display;

	for (int i = 0; i < this->items.size(); i++)
	{
		if (*this->items[i].value)
		{
			if (display != "")
				display.append(", ");

			display.append(this->items[i].name);
		}
	}

	if(display == "")
		display.append("None");

	auto text_size = render->get_text_width(display.c_str(), fonts::main_font);

	if (this->position.x + 2 + text_size > this->position.x + combobox_size)
		display.resize(11); // hardcode for now

	render->text(this->position.x + 2, this->position.y + 1, fonts::main_font, display, D3DCOLOR_RGBA(255, 255, 255, 255));
}

void c_multicombobox::add_item(std::string name, bool* value)
{
	this->items.push_back(multicombobox_t(name, value));
}
