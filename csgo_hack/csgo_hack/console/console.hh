class c_console
{
public:
	void attach( std::string window_title = "" );
	void detach( );
	void log( std::string message, int color = 0 );
}; extern c_console* console;