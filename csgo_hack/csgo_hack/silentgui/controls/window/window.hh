////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

class c_groupbox;

class c_window
{
public:
	c_window();
	c_window(std::string name, vec2_t* position, vec2_t size, std::vector<std::string> window_tabs = {}, int* selected_tab = 0);
	void add_groupbox(c_groupbox* groupbox);
	vec2_t* window_position;
	std::vector<std::string> window_tabs;
	int* selected_tab;
private:
	void draw();
	void run();
	void handle_tabs();
	void handle_position();
	std::string name;
	vec2_t size;
};