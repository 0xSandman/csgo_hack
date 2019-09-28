#include "../source_development_kit.hh"

void* utilties::get_interface(const char* module, const char* interface_name)
{
	create_interface_fn create_interface = (create_interface_fn)GetProcAddress(GetModuleHandleA(module), "CreateInterface");

	auto interface_to_return = create_interface(interface_name, 0);

	if (!interface_to_return)
		printf_s("failed to find %s in %s\n", interface_name, module); /// using printf_s instead of console log so we can log extra info
		
	return interface_to_return;
}
