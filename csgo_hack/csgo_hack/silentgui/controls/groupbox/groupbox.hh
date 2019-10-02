////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

class c_checkbox;
class c_slider;
class c_combobox;

class c_groupbox : public c_window
{
public:
	c_groupbox();
	c_groupbox(std::string name, vec2_t position, vec2_t size, int tab = 0);
	void run();

	void add_control(c_checkbox* checkbox);
	void add_control(c_slider* slider);
	void add_control(c_combobox* combobox);

	std::string name;
	vec2_t position;
	vec2_t size;
	int tab;
	int control_offset_x, control_offset_y;
	bool visible;
};