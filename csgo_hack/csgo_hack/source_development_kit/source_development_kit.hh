#include <Windows.h>
#include <string>
#include <chrono>
#include <thread>
#include <Psapi.h>

#include "../console/console.hh"
#include "../source_development_kit/utilities/utilities.hh"
#include "../source_development_kit/valve/recv.hh"
#include "../source_development_kit/valve/c_client.hh"
#include "../source_development_kit/interfaces/interfaces.hh"
#include "../source_development_kit/hooking/hooking.hh"
#include "../source_development_kit/memory/memory.hh"