#include "../../source_development_kit/source_development_kit.hh"

LRESULT __stdcall hooks::wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{

	if (msg == WM_MOUSEMOVE)
	{
		menu_helpers::mouse_position.x = GET_X_LPARAM(lparam);
		menu_helpers::mouse_position.y = GET_Y_LPARAM(lparam);
	}

	return CallWindowProcA(original_wndproc, hwnd, msg, wparam, lparam);
}
