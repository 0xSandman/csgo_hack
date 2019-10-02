////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

#include "../../../source_development_kit/source_development_kit.hh"

c_slider::c_slider()
{
}

c_slider::c_slider(std::string name, float* value, int minimum_value, int maximum_value)
{
	this->name = name;
	this->value = value;
	this->minimum_value = minimum_value;
	this->maximum_value = maximum_value;
}

void c_slider::run()
{
	static auto stored_index = -1;
	auto slider_size = 70;
	auto value_min_delta = *this->value - this->minimum_value;
	auto max_min_delta = this->maximum_value - this->minimum_value;
	auto value_modifier = (value_min_delta / max_min_delta) * slider_size;
	auto value_text_size = render->get_text_width(std::to_string((int)* this->value).c_str(), fonts::main_font);

	if (GetAsyncKeyState(VK_LBUTTON) & 1 && menu_helpers::mouse_is_over_point(vec2_t(this->position.x, this->position.y + 2), vec2_t(slider_size, 8)))
		stored_index = menu_helpers::control_index;

	if (GetAsyncKeyState(VK_LBUTTON) && stored_index == menu_helpers::control_index)
	{
		*this->value = this->minimum_value + max_min_delta * (menu_helpers::mouse_position.x - this->position.x) / slider_size;

		if (*this->value < this->minimum_value)
			* this->value = this->minimum_value;

		if (*this->value > this->maximum_value)
			* this->value = this->maximum_value;
	}

	if (!GetAsyncKeyState(VK_LBUTTON))
		stored_index = -1;

	render->rectangle(this->position.x, this->position.y + 2, slider_size, 8, D3DCOLOR_RGBA(25, 25, 25, 255));
	render->rectangle(this->position.x, this->position.y + 2, value_modifier, 8, stored_index == menu_helpers::control_index ? D3DCOLOR_RGBA(150, 24, 27, 255) : D3DCOLOR_RGBA(200, 200, 200, 255));
	render->outline(this->position.x, this->position.y + 2, slider_size, 8, D3DCOLOR_RGBA(25, 25, 25, 255)); // (c1) fixes weird outline (also creates some sort of weird rounding effect, lol?)

	if (this->position.x + value_modifier + value_text_size + 1 > this->position.x + slider_size)
		render->text(this->position.x + slider_size - value_text_size - 1, this->position.y + 2, fonts::main_font, std::to_string((int)* this->value), D3DCOLOR_RGBA(255, 255, 255, 255), false, true, D3DCOLOR_RGBA(0, 0, 0, 255));
	else
		render->text(this->position.x + value_modifier, this->position.y + 2, fonts::main_font, std::to_string((int)* this->value), D3DCOLOR_RGBA(255, 255, 255, 255), false, true, D3DCOLOR_RGBA(0, 0, 0, 255));

	render->text(this->position.x + 74, this->position.y, fonts::main_font, this->name, D3DCOLOR_RGBA(0, 0, 0, 255));
}