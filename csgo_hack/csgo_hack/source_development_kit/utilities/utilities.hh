typedef void* (*create_interface_fn)(const char* name, int* return_code); /// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/tier1/interface.h#L68
 
namespace utilties
{
	void* get_interface(const char* module, const char* interface_name);
}