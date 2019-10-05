namespace valve
{
	typedef struct player_info_s
	{
		unsigned long __pad0[2];
		int xuid_low;
		int xuid_high;
		char name[128];
		int userid;
		char guid[33];
		unsigned int friends_id;
		char friends_name[128];
		bool fakeplayer;
		bool ishltv;
		unsigned long customfiles[4];
		unsigned char filesdownloaded;
		int __pad1;
	} player_info_t;

	class iv_engine_client
	{
	public:
		void get_screen_size(int& width, int& height)
		{
			typedef void(__thiscall * vfunc)(void*, int&, int&);
			utilties::get_virtual_function<vfunc>(this, 5)(this, width, height);
		}

		void get_player_info(int ent_num, player_info_t* info)
		{
			typedef void(__thiscall * vfunc)(void*, int, player_info_t*);
			utilties::get_virtual_function<vfunc>(this, 8)(this, ent_num, info);
		}

		int get_local_player()
		{
			typedef int(__thiscall * vfunc)(void*);
			return utilties::get_virtual_function<vfunc>(this, 12)(this);
		}

		void execute_client_cmd(const char* command)
		{
			typedef void(__thiscall * vfunc)(void*, const char*);
			utilties::get_virtual_function<vfunc>(this, 108)(this, command);
		}
	};
}