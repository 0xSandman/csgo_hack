#include "../source_development_kit.hh"

valve::client_class* interfaces::client = nullptr;
valve::iv_engine_client* interfaces::engine = nullptr;
DWORD interfaces::d3d9_device;

void interfaces::setup()
{
	interfaces::client = reinterpret_cast<valve::client_class*>(utilties::get_interface("client_panorama.dll", "VClient018"));
	interfaces::engine = reinterpret_cast<valve::iv_engine_client*>(utilties::get_interface("engine.dll", "VEngineClient014"));
	interfaces::d3d9_device = **reinterpret_cast<DWORD * *>(memory::find_pattern_ida("shaderapidx9.dll", "A1 ?? ?? ?? ?? 50 8B 08 FF 51 0C") + 0x1);
	char d3d9_device_output[1024]; sprintf_s(d3d9_device_output, "[ interface ] d3d9_device -> 0x%p", interfaces::d3d9_device);
	console->log(d3d9_device_output, d3d9_device_output ? 2 : 4);
}