#include "../source_development_kit/source_development_kit.hh"

unsigned long __stdcall start_hack(_In_ LPVOID reserved)
{
	console->attach("debug");

	console->log("hack loaded");

	while (!GetAsyncKeyState(VK_DELETE))
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

	console->detach();

	FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(reserved), 0);
}

BOOL WINAPI DllMain(_In_ HINSTANCE instance, _In_ DWORD reason, _In_ LPVOID reserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:  CreateThread(0, 0, start_hack, instance, 0, 0); break;
	}

	return TRUE;
}