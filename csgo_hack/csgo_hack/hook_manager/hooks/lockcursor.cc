#include "../../source_development_kit/source_development_kit.hh"

void __stdcall hooks::lockcursor()
{
	lock_cursor_fn original = i_surface_hook->original<lock_cursor_fn>(67);
	menu_helpers::menu_open ? interfaces::surface->unlock_cursor() : original();
}