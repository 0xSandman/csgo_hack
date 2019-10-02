////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

struct multicombobox_t
{
	multicombobox_t(std::string name, bool* value)
	{
		this->name = name;
		this->value = value;
	}

	std::string name;
	bool* value;
};

class c_multicombobox : public c_groupbox
{
public:
	c_multicombobox();
	c_multicombobox(std::string name);
	void run();
	void add_item(std::string name, bool* value);
	vec2_t position;
private:
	std::string name;
	std::vector<multicombobox_t> items;
	bool focused;
};