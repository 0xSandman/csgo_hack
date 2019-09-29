#include "../source_development_kit/source_development_kit.hh"

c_console* console;

void c_console::attach( std::string window_title )
{
	AllocConsole( );
	freopen_s( ( FILE * * ) stdin, "CONIN$", "r", stdin );
	freopen_s( ( FILE * * ) stdout, "CONOUT$", "w", stdout );

	if ( window_title != "" )
		SetConsoleTitle( window_title.c_str( ) );

	/// set default color
	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_handle, 7);
}

void c_console::detach( )
{
	fclose( ( FILE* ) stdin );
	fclose( ( FILE* ) stdout );
	FreeConsole( );
}

void c_console::log( std::string message, int color )
{
	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	bool change_color = color != 0;

	if(change_color) SetConsoleTextAttribute(console_handle, color);
	printf_s( "%s\n", message.c_str( ) );
	if (change_color) SetConsoleTextAttribute(console_handle, 7);
}