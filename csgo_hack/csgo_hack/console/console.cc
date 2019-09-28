#include "../source_development_kit/source_development_kit.hh"

c_console* console;

void c_console::attach( std::string window_title )
{
	AllocConsole( );
	freopen_s( ( FILE * * ) stdin, "CONIN$", "r", stdin );
	freopen_s( ( FILE * * ) stdout, "CONOUT$", "w", stdout );

	if ( window_title != "" )
		SetConsoleTitle( window_title.c_str( ) );
}

void c_console::detach( )
{
	fclose( ( FILE* ) stdin );
	fclose( ( FILE* ) stdout );
	FreeConsole( );
}

void c_console::log( std::string message )
{
	printf_s( "%s\n", message.c_str( ) );
}