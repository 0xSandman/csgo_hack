////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

#include "../../../source_development_kit/source_development_kit.hh"

c_groupbox::c_groupbox()
{
}

c_groupbox::c_groupbox(std::string name, vec2_t position, vec2_t size)
{
	this->name = name;
	this->position = position;
	this->size = size;
}

void c_groupbox::draw()
{
}