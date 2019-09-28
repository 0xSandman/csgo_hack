#include "../source_development_kit/source_development_kit.hh"

void start_hack()
{
	MessageBox(NULL, "cum_daddy", "niggers_lynched.dll", MB_OK);
}

// copyright_microsoft_2019 (developer.microsoft.com/en-us/windows) (((not my code)))
BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH: start_hack(); break;
	}
}