////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

#include "../../../source_development_kit/source_development_kit.hh"

c_groupbox::c_groupbox()
{
}

c_groupbox::c_groupbox(std::string name, vec2_t position, vec2_t size, int tab)
{
	this->name = name;
	this->position = position;
	this->size = size;
	this->tab = tab;
}

void c_groupbox::draw()
{
	auto text_size = render->get_text_width(this->name.c_str(), fonts::main_font);

	render->line(this->position.x, this->position.y, this->position.x + 16, this->position.y, D3DCOLOR_RGBA(0, 0, 0, 255));
	render->line(this->position.x + text_size + 16 + 6, this->position.y, this->position.x + this->size.x, this->position.y, D3DCOLOR_RGBA(0, 0, 0, 255));
	render->line(this->position.x, this->position.y, this->position.x, this->position.y + this->size.y, D3DCOLOR_RGBA(0, 0, 0, 255));
	render->line(this->position.x + this->size.x, this->position.y, this->position.x + this->size.x, this->position.y + this->size.y, D3DCOLOR_RGBA(0, 0, 0, 255));
	render->line(this->position.x, this->position.y + this->size.y, this->position.x + this->size.x, this->position.y + this->size.y, D3DCOLOR_RGBA(0, 0, 0, 255));
	
	render->text(this->position.x + 20, this->position.y - 8, fonts::main_font, this->name, D3DCOLOR_RGBA(0, 0, 0, 255));
}