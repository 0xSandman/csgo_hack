#include "../source_development_kit.hh"

valve::client_class* interfaces::client = nullptr;

void interfaces::setup( )
{
	interfaces::client = reinterpret_cast< valve::client_class* >( utilties::get_interface( "client_panorama.dll", "VClient018" ) );
}