#include "../source_development_kit.hh"

void* interfaces::client = nullptr;

void interfaces::setup()
{
	interfaces::client = reinterpret_cast<void*>(utilties::get_interface("client_panorama.dll", "VClient018"));
}