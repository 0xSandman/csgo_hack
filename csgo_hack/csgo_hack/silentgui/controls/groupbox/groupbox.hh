////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

class c_groupbox : public c_window
{
public:
	c_groupbox();
	c_groupbox(std::string name, vec2_t position, vec2_t size, int tab = 0);
	void draw();

	std::string name;
	vec2_t position;
	vec2_t size;
	int tab;
};