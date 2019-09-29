#include "../source_development_kit.hh"

void* utilties::get_interface( const char* module, const char* interface_name )
{
	create_interface_fn create_interface = ( create_interface_fn ) GetProcAddress( GetModuleHandleA( module ), "CreateInterface" );

	auto interface_to_return = create_interface( interface_name, 0 );

	char output[1024];

	/// using printf_s instead of console log so we can log extra info
	if (interface_to_return)
	{
		sprintf_s(output, "[ interface ] found %s in %s -> 0x%p", interface_name, module, interface_to_return);
		console->log(output, 2);
	}
	else
	{
		sprintf_s(output, "[ interface ] failed to find %s in %s", interface_name, module);
		console->log(output, 4);
	}
		

	return interface_to_return;
}
