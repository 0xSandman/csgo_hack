////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

#include "../../../source_development_kit/source_development_kit.hh"

c_window::c_window()
{

}

c_window::c_window(std::string name, vec2_t* position, vec2_t size, std::vector<std::string> window_tabs, int* selected_tab)
{
	this->name = name;
	this->window_position = position;
	this->size = size;
	this->window_tabs = window_tabs;
	this->selected_tab = selected_tab; // later to be used for tab dependent stuff outside of the menu

	this->run();
}

void c_window::add_groupbox(c_groupbox* groupbox)
{
	groupbox->visible = groupbox->tab == *this->selected_tab;

	if (groupbox->visible)
	{
		groupbox->position += *this->window_position;
		groupbox->run();
	}
}

void c_window::draw()
{
	render->rectangle(this->window_position->x, this->window_position->y, this->size.x, this->size.y, D3DCOLOR_RGBA(46, 46, 46, 255));
	render->rectangle(this->window_position->x + 7, this->window_position->y + 46, this->size.x - 14, this->size.y - 53, D3DCOLOR_RGBA(208, 208, 208, 255));

	render->outline(this->window_position->x, this->window_position->y, this->size.x, this->size.y, D3DCOLOR_RGBA(0, 0, 0, 255));
	render->outline(this->window_position->x + 7, this->window_position->y + 21, this->size.x - 14, this->size.y - 28, D3DCOLOR_RGBA(0, 0, 0, 255));
	render->outline(this->window_position->x + 7, this->window_position->y + 46, this->size.x - 14, this->size.y - 53, D3DCOLOR_RGBA(0, 0, 0, 255));
	render->text(this->window_position->x + (this->size.x / 2), this->window_position->y + 3, fonts::main_font, this->name, D3DCOLOR_RGBA(255, 255, 255, 255), true);
}

void c_window::run()
{
	this->handle_position();
	this->draw();
	this->handle_tabs();
}

void c_window::handle_tabs()
{
	if (this->window_tabs.size() > 0)
	{
		auto tab_size = (this->size.x - 14) / this->window_tabs.size();

		for (int i = 0; i < this->window_tabs.size(); i++)
		{
			RECT tab_position = { this->window_position->x + 7 + (i * tab_size), this->window_position->y + 21, tab_size,  26 };

			if (menu_helpers::mouse_is_over_point(vec2_t(tab_position.left, tab_position.top), vec2_t(tab_position.right, tab_position.bottom)) && menu_helpers::key_was_pressed(VK_LBUTTON))
				*this->selected_tab = i;
				

			D3DCOLOR color = i == *selected_tab ? D3DCOLOR_RGBA(31, 31, 31, 255) : D3DCOLOR_RGBA(46, 46, 46, 255);

			render->rectangle(tab_position.left, tab_position.top, tab_position.right, tab_position.bottom, color);
			render->outline(tab_position.left, tab_position.top, tab_position.right, tab_position.bottom, D3DCOLOR_RGBA(0, 0, 0, 255));
			render->text(tab_position.left + (tab_position.right / 2), tab_position.top + 7, fonts::main_font, this->window_tabs[i], D3DCOLOR_RGBA(255, 255, 255, 255), true);
		}
	}
}

void c_window::handle_position()
{
	static bool drag = false;
	static vec2_t drag_offset;
	auto delta = menu_helpers::mouse_position - drag_offset;

	if (drag && !GetAsyncKeyState(VK_LBUTTON))
		drag = false;

	if (drag && GetAsyncKeyState(VK_LBUTTON))
		* this->window_position = delta;

	if (menu_helpers::mouse_is_over_point(vec2_t(this->window_position->x, this->window_position->y), vec2_t(this->size.x, 20)))
	{
		drag = true;
		drag_offset = menu_helpers::mouse_position - *this->window_position;
	}
}