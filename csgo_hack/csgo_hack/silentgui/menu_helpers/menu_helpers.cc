#include "../../source_development_kit/source_development_kit.hh"

static bool key_state[256];
static bool previous_key_state[256];

vec2_t menu_helpers::mouse_position;
bool menu_helpers::menu_open = true;
int menu_helpers::control_index;

bool menu_helpers::mouse_is_over_point(vec2_t position, vec2_t size)
{
	return mouse_position.x > position.x  && mouse_position.y > position.y && mouse_position.x < position.x + size.x && mouse_position.y < position.y + size.y;
}

void menu_helpers::handle_input()
{
	for (int i = 0; i < 256; i++) {
		previous_key_state[i] = key_state[i];
		key_state[i] = GetAsyncKeyState(i);
	}
}

bool menu_helpers::key_was_pressed(const int key)
{
	return key_state[key] && !previous_key_state[key];
}