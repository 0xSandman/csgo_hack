#include "../source_development_kit.hh"

// (c) learn_more

uint64_t memory::find_pattern_ida(const char* module, const char* pattern)
{
	MODULEINFO module_info;

	GetModuleInformation(GetCurrentProcess(), GetModuleHandleA(module), &module_info, sizeof(MODULEINFO));

	DWORD start_address = (DWORD)module_info.lpBaseOfDll;

	DWORD end_address = start_address + module_info.SizeOfImage;

	const char* pat = pattern;

	DWORD first_match = 0;

	for (DWORD cur = start_address; cur < end_address; cur++) 
	{
		if (!*pat)
			return first_match;

		if (*(PBYTE)pat == '\?' || *(BYTE*)cur == get_byte(pat)) 
		{
			if (!first_match) 
				first_match = cur;

			if (!pat[2]) return 
				first_match;

			if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?') 
				pat += 3;
			else 
				pat += 2;
		}
		else 
		{
			pat = pattern;
			first_match = 0;
		}

	}
	return NULL;
}