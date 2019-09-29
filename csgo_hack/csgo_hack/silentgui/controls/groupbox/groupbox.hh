////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

class c_groupbox
{
public:
	c_groupbox();
	c_groupbox(std::string name, vec2_t position, vec2_t size);
	void draw();

	std::string name;
	vec2_t position;
	vec2_t size;
};