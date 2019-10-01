////////////////////////////////////////////
//////////// Silent GUI v0.1   /////////////
/////////// Developed by pSilent ///////////
////////////////////////////////////////////

class c_checkbox : public c_groupbox
{
public:
	c_checkbox();
	c_checkbox(std::string name, bool* value);
private:
	std::string name;
	bool* value;
};