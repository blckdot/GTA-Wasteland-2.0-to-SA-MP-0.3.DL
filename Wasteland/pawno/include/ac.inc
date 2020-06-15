/*
* Анти-чит
*/

forward OnPlayerHacking(playerid, hackid);

enum {
	// Anti DDos Bots
	PLAYER_BOT_LEVEL3, // 0
	PLAYER_BOT_LEVEL2, // 1
	PLAYER_BOT_LEVEL1, // 2

	// Anti Cleo4 Fake-kill
	PLAYER_DEATHFLOOD_LEVEL3,
	PLAYER_DEATHFLOOD_LEVEL2,
	PLAYER_DEATHFLOOD_LEVEL1,

	// Anti Bug Cars
	PLAYER_SURF_VEHICLE,
	PLAYER_CAR_TELEPORT,
	PLAYER_STATE_HACK,

	// Ammo Weapon
	PLAYER_NORELOAD_HACK,
	PLAYER_WEAPON_HACK,
	PLAYER_AMMO_HACK,


	// hackings
	PLAYER_FREEZE_HACK,
	PLAYER_SCORE_HACK,
	PLAYER_MONEY_HACK,
	PLAYER_HEALTH_HACK,
	PLAYER_ARMOUR_HACK,

	// Text Chat
	PLAYER_PUBLISH_TEXT,
	PLAYER_OFFEND_TEXT,
	PLAYER_FLOOD_TEXT,

	// pos cheat
	PLAYER_TELEPORT_HACK,
	PLAYER_AIRBREAK_HACK,
	PLAYER_BUGGER_HACK,

	// outros
	PLAYER_HIGH_PING,
	PLAYER_SPIDER_HACK,
	PLAYER_CPRACE_HACK,
	PLAYER_SPEED_HACK,
	PLAYER_PSPEED_HACK,
	PLAYER_FLY_HACK,
	PLAYER_FAKE_DAMAGE
}


stock SetPlayerScore_pB(playerid,score) return CallRemoteFunction("SetPlayerScore_pB", "ii", playerid,score);
stock PutPlayerInVehicle_pB(playerid, vehicleid, seatid) return CallRemoteFunction("PutPlayerInVehicle_pB", "iii", playerid, vehicleid, seatid);
stock SetPlayerPos_pB(playerid, Float:x, Float:y, Float:z) return CallRemoteFunction("SetPlayerPos_pB", "ifff", playerid, Float:x, Float:y, Float:z);
stock SetVehiclePos_pB(vehicleid, Float:x, Float:y, Float:z) return CallRemoteFunction("SetVehiclePos_pB", "ifff", vehicleid, Float:x, Float:y, Float:z);
stock SetVehicleVelocity_pB(vehicleid, Float:X, Float:Y, Float:Z) return CallRemoteFunction("SetVehicleVelocity_pB", "ifff", vehicleid, Float:X, Float:Y, Float:Z);
stock SetVehicleToRespawn_pB(vehicleid) return CallRemoteFunction("SetVehicleToRespawn_pB", "i", vehicleid);

public OnPlayerHacking(playerid, hackid)
{
	/*switch(hackid)
	{
		case PLAYER_SURF_VEHICLE:
		{
			SendClientMessage(playerid, 0x008080FF, "[Anti-cheat]: Вы были кикнуты за использование читов! [#0x%x]", hackid);
			Kick(playerid);
		}
	}*/
	new str[128];
	format(str, sizeof str, "[Anti-cheat]: Вы были кикнуты за использование читов! [#0x%x]", hackid);
	SendClientMessage(playerid, 0x008080FF, str);
	Kick(playerid);
	return 1;
}

#define SetPlayerScore			SetPlayerScore_pB
#define PutPlayerInVehicle			PutPlayerInVehicle_pB
#define SetPlayerPos  			SetPlayerPos_pB
#define SetVehiclePos  			SetVehiclePos_pB
#define SetVehicleVelocity			SetVehicleVelocity_pB
#define SetVehicleToRespawn		SetVehicleToRespawn_pB