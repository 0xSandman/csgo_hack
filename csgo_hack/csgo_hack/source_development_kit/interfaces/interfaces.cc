#include "../source_development_kit.hh"

valve::c_client* interfaces::client = nullptr;
valve::iv_engine_client* interfaces::engine = nullptr;
valve::i_input_system* interfaces::input_system = nullptr;
valve::i_surface* interfaces::surface = nullptr;
valve::i_client_entity_list* interfaces::entity_list;
DWORD interfaces::d3d9_device;

void interfaces::setup()
{
	interfaces::client = reinterpret_cast<valve::c_client*>(utilties::get_interface("client_panorama.dll", "VClient018"));
	interfaces::engine = reinterpret_cast<valve::iv_engine_client*>(utilties::get_interface("engine.dll", "VEngineClient014"));
	interfaces::input_system = reinterpret_cast<valve::i_input_system*>(utilties::get_interface("inputsystem.dll", "InputSystemVersion001"));
	interfaces::surface = reinterpret_cast<valve::i_surface*>(utilties::get_interface("vguimatsurface.dll", "VGUI_Surface031"));
	interfaces::entity_list = reinterpret_cast<valve::i_client_entity_list*>(utilties::get_interface("client_panorama.dll", "VClientEntityList003"));
	interfaces::d3d9_device = **reinterpret_cast<DWORD * *>(memory::find_pattern_ida("shaderapidx9.dll", "A1 ?? ?? ?? ?? 50 8B 08 FF 51 0C") + 0x1);
	char d3d9_device_output[1024]; sprintf_s(d3d9_device_output, "[ interface ] d3d9_device -> 0x%p", interfaces::d3d9_device);
	console->log(d3d9_device_output, d3d9_device_output ? 2 : 4);
}