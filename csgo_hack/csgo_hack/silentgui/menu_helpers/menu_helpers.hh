namespace menu_helpers
{
	extern vec2_t mouse_position;
	extern bool menu_open;
	extern int control_index;
	bool mouse_is_over_point(vec2_t position, vec2_t size);
	void handle_input();
	bool key_was_pressed(const int key);
}