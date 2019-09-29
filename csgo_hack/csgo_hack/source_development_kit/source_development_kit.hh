#include <Windows.h>
#include <string>
#include <chrono>
#include <thread>
#include <Psapi.h>
#include <map>
#include <d3d9.h>
#include <d3dx9.h>


#include "../console/console.hh"
#include "../source_development_kit/math/vector/vector2d.hh"
#include "../render/fonts/fonts.hh"
#include "../render/render.hh"
#include "../source_development_kit/utilities/utilities.hh"
#include "../source_development_kit/valve/recv.hh"
#include "../netvar_manager/netvar_manager.hh"
#include "../source_development_kit/valve/c_client.hh"
#include "../source_development_kit/valve/iv_engine_client.h"
#include "../source_development_kit/interfaces/interfaces.hh"
#include "../source_development_kit/hooking/hooking.hh"
#include "../source_development_kit/memory/memory.hh"
#include "../hooks/hooks.hh"
#include "../silentgui/silentgui.hh"