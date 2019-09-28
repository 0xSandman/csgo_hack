#include "../source_development_kit.hh"

vmt_hook::vmt_hook( )
{
}

vmt_hook::vmt_hook( void* p_interface )
{
	this->p_interface = reinterpret_cast< uintptr_t * * >( p_interface );

	size_t method_count = 0;

	while ( reinterpret_cast< uintptr_t* >( *this->p_interface )[ method_count ] )
		method_count++;

	original_vmt = *this->p_interface;

	vmt = new uintptr_t[ method_count + 1 ];

	memcpy( vmt, &original_vmt[ -1 ], ( sizeof( uintptr_t ) * method_count ) + sizeof( uintptr_t ) );
}

void vmt_hook::hook( void* method, size_t methodIndex )
{
	vmt[ methodIndex + 1 ] = reinterpret_cast< uintptr_t >( method );
}

void vmt_hook::apply( )
{
	*this->p_interface = &vmt[ 1 ];
}

void vmt_hook::release( )
{
	*this->p_interface = original_vmt;
	delete[ ] vmt;
}
