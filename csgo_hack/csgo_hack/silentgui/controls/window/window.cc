////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

#include "../../../source_development_kit/source_development_kit.hh"

c_window::c_window()
{
	this->name = "invalid window";
	*this->position = vec2_t();
	this->size = vec2_t();
}

c_window::c_window(std::string name, vec2_t* position, vec2_t size)
{
	this->name = name;
	this->position = position;
	this->size = size;
}

void c_window::add_groupbox(c_groupbox* groupbox)
{
	//
}

void c_window::draw()
{
	render->rectangle(this->position->x, this->position->y, this->size.x, this->size.y, D3DCOLOR_RGBA(30, 32, 38, 255));
	render->outline(this->position->x, this->position->y, this->size.x, this->size.y, D3DCOLOR_RGBA(10, 12, 18, 255));
}
