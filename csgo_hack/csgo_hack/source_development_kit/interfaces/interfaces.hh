namespace interfaces
{
	void setup();
	extern valve::c_client* client;
	extern valve::iv_engine_client* engine;
	extern valve::i_input_system* input_system;
	extern valve::i_surface* surface;
	extern DWORD d3d9_device;
}