#include <Windows.h>
#include <windowsx.h>
#include <string>
#include <chrono>
#include <thread>
#include <Psapi.h>
#include <map>
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>

#include "../console/console.hh"
#include "math/vector/vector2d.hh"
#include "math/vector/vector3d.hh"
#include "math/matrix/matrix3x4.hh"
#include "math/math.hh"
#include "../render/fonts/fonts.hh"
#include "../render/render.hh"
#include "utilities/utilities.hh"
#include "valve/recv.hh"
#include "../netvar_manager/netvar_manager.hh"
#include "valve/c_client.hh"
#include "valve/c_base_entity.hh"
#include "valve/i_client_entity_list.hh"
#include "valve/iv_engine_client.hh"
#include "valve/i_input_system.hh"
#include "valve/i_surface.hh"
#include "valve/iv_debug_overlay.hh"
#include "interfaces/interfaces.hh"
#include "hooker/hooker.hh"
#include "memory/memory.hh"
#include "../hook_manager/hook_manager.hh"
#include "../silentgui/menu_helpers/menu_helpers.hh"
#include "../silentgui/silentgui.hh"