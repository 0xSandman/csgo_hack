////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

#include "../../../source_development_kit/source_development_kit.hh"

c_checkbox::c_checkbox()
{
}

c_checkbox::c_checkbox(std::string name, bool* value)
{
	this->name = name;
	this->value = value;
}

void c_checkbox::run()
{
	if (menu_helpers::mouse_is_over_point(vec2_t(this->position.x, this->position.y), vec2_t(14, 14)) && menu_helpers::key_was_pressed(VK_LBUTTON))
		* this->value = !*this->value;

	render->rectangle(this->position.x, this->position.y, 14, 14, D3DCOLOR_RGBA(25, 25, 25, 255));
	render->outline(this->position.x, this->position.y, 14, 14, D3DCOLOR_RGBA(25, 25, 25, 255)); // (c1) fixes weird outline (also creates some sort of weird rounding effect, lol?)
	render->text(this->position.x + 19, this->position.y, fonts::main_font, this->name, D3DCOLOR_RGBA(0, 0, 0, 255));

	if (*this->value)
	{
		render->rectangle(this->position.x + 2, this->position.y + 2, 10, 10, D3DCOLOR_RGBA(200, 200, 200, 255)); // too lazy to do a checkmark for now
		render->outline(this->position.x + 2, this->position.y + 2, 10, 10, D3DCOLOR_RGBA(200, 200, 200, 255)); // refer to c1
	}
}