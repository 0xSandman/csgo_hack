class c_console
{
public:
	void attach(std::string window_title = "");
	void detach();
	void log(std::string message);
}; extern c_console* console;