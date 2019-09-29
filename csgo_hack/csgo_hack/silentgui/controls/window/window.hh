////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

class c_groupbox;

class c_window
{
public:
	c_window();
	c_window(std::string name, vec2_t* position, vec2_t size);
	void add_groupbox(c_groupbox* groupbox);
private:
	void draw();
	std::string name;
	vec2_t* position;
	vec2_t size;
};