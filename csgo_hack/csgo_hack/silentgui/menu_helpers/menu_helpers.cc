#include "../../source_development_kit/source_development_kit.hh"

vec2_t menu_helpers::mouse_position;
bool menu_helpers::menu_open = true;
int menu_helpers::control_index;

bool menu_helpers::mouse_is_over_point(vec2_t position, vec2_t size)
{
	return mouse_position.x > position.x  && mouse_position.y > position.y && mouse_position.x < position.x + size.x && mouse_position.y < position.y + size.y;
}
