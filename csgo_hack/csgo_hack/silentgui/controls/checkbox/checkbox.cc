#include "../../../source_development_kit/source_development_kit.hh"

c_checkbox::c_checkbox()
{
}

c_checkbox::c_checkbox(std::string name, bool* value)
{
	this->name = name;
	this->value = value;
}
