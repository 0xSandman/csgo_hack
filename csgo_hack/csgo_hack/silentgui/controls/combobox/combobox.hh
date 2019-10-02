////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

class c_combobox : public c_groupbox
{
public:
	c_combobox();
	c_combobox(std::string name, int* value, std::vector<std::string> items);
	void run();
	vec2_t position;
private:
	std::string name;
	int* value;
	std::vector<std::string> items;
	bool focused;
};