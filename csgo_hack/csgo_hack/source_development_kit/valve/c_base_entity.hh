namespace valve
{
	class c_base_entity
	{
	public:
		netvar(health, int, "DT_BasePlayer->m_iHealth");
		netvar(armor, int, "DT_CSPlayer->m_ArmorValue");
		netvar(team, int, "DT_BaseEntity->m_iTeamNum");
		netvar(flags, int, "DT_BasePlayer->m_fFlags");
		netvar(tickbase, int, "DT_BasePlayer->m_nTickBase");
		netvar(scoped, bool, "DT_CSPlayer->m_bIsScoped");
		netvar(immune, bool, "DT_CSPlayer->m_bGunGameImmunity");
		netvar(flash_duration, float, "DT_CSPlayer->m_flFlashDuration");
		netvar(eye_angles, vec3_t, "DT_CSPlayer->m_angEyeAngles[0]");
		netvar(velocity, vec3_t, "DT_BasePlayer->m_vecVelocity[0]");
		netvar(myweapons, HANDLE, "DT_BaseCombatCharacter->m_hMyWeapons");
		netvar(active_weapon, HANDLE, "DT_BaseCombatCharacter->m_hActiveWeapon");
	};
}