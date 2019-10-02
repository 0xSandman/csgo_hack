////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

class c_slider : public c_groupbox
{
public:
	c_slider();
	c_slider(std::string name, float* value, int minimum_value = 0, int maximum_value = 100);
	void run();
	vec2_t position;
private:
	std::string name;
	float* value;
	int minimum_value;
	int maximum_value;
};