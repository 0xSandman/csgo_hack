////////////////////////////////////////////
//////////// Silent GUI v0.1  /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

#include "controls/window/window.hh"
#include "controls/groupbox/groupbox.hh"
#include "controls/checkbox/checkbox.hh"
#include "controls/slider/slider.hh"

class c_silentgui
{
public:
	void run();
private:
	void handle_vector_drawing();
}; extern c_silentgui* silentgui;

// ghetto shit for now, we can do something more proper later (this is used for combobox drawing)

struct rectangle_draw_t
{
	rectangle_draw_t(float x, float y, float w, float h, D3DCOLOR color)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

	float x; 
	float y; 
	float w; 
	float h;
	D3DCOLOR color;
};

struct text_draw_t
{
	text_draw_t(float x, float y, LPD3DXFONT font, std::string text, D3DCOLOR color, bool centered = false, bool drop_shadow = false, D3DCOLOR shadow_color = D3DCOLOR())
	{
		this->x = x;
		this->y = y;
		this->font = font;
		this->text = text;
		this->color = color;
		this->centered = centered;
		this->drop_shadow = drop_shadow;
		this->shadow_color = shadow_color;
	}

	float x;
	float y;
	LPD3DXFONT font;
	std::string text;
	D3DCOLOR color;
	bool centered;
	bool drop_shadow; 
	D3DCOLOR shadow_color;
};

struct outline_draw_t
{
	outline_draw_t(float x, float y, float w, float h, D3DCOLOR color)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

	float x;
	float y;
	float w;
	float h;
	D3DCOLOR color;
};

extern std::vector<rectangle_draw_t> rectangles_to_draw;
extern std::vector<text_draw_t> text_to_draw;
extern std::vector<outline_draw_t> outlines_to_draw;