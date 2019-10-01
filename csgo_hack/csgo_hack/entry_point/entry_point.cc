#include "../source_development_kit/source_development_kit.hh"

unsigned long __stdcall start_hack( _In_ LPVOID reserved )
{
	console->attach( "debug" );
	console->log("[ hack ] init", 5);
	interfaces::setup( );
	hooks::setup();
	console->log("[ hack ] loaded", 5);

	while ( !GetAsyncKeyState( VK_DELETE ) )
		std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );

	interfaces::input_system->enable_input(true);
	console->log("[ unload ] enabled input", 5);
	hooks::free();
	console->log("[ unload ] freed hooks", 5);
	fonts::release();
	console->log("[ unload ] released fonts", 5);
	console->detach( );

	FreeLibraryAndExitThread( reinterpret_cast< HMODULE >( reserved ), 0 );
}

BOOL WINAPI DllMain( _In_ HINSTANCE instance, _In_ DWORD reason, _In_ LPVOID reserved )
{
	switch ( reason )
	{
	case DLL_PROCESS_ATTACH:  CreateThread( 0, 0, start_hack, instance, 0, 0 ); break;
	}

	return TRUE;
}