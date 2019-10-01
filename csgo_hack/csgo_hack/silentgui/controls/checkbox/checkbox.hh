////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

class c_checkbox : public c_groupbox
{
public:
	c_checkbox();
	c_checkbox(std::string name, bool* value);
	void run();
	vec2_t position;
private:
	std::string name;
	bool* value;
};