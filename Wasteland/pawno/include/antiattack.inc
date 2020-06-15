/*

			  Anti-Attack Module
			    BJIADOKC & Co.
	Remove this copyright, if you want to be a superman!
*/





#if !defined _samp_included
	#error Include 'antiattack.inc' after 'a_samp.inc' !
#endif

#if defined _aat_included
	#endinput
#endif

#define _aat_included

#define SAMP_CURRENT_VERSION 		"0.3x-R1-2"
#define MAX_PACKETS_PER_SECOND		50000.0
#define MAX_FUNCTION_CALL_MS		150
#define MAX_FUNCTION_CALL_WARNS		5
#define MAX_CONNECTS_FROM_IP		3
//#define aat_DEBUG





native aat_Init(maxplayers, bool:logging = true, bool:clear_log = false);
native Float:aat_NetStats(stats[]); // There was a bug with float returning as int, fixed in 1.2.2-R2






enum
{
	ATTACK_TYPE_BAD_RCON_ATTEMPT = 0,
	ATTACK_TYPE_INVALID_CLIENT,
	ATTACK_TYPE_SERVER_FULL,
	ATTACK_TYPE_INVALID_RCON
}



enum
{
	ATTACK_TYPE_DIALOG_RESPONSE = 0,
	ATTACK_TYPE_DIALOG_EXPLOIT,
	ATTACK_TYPE_RCON_EXPLOIT,
	ATTACK_TYPE_PACKET_MODIFIED,
	ATTACK_TYPE_REMOTE_PORT_REFUSED,
	ATTACK_TYPE_ONESLOT_FLOOD,
	ATTACK_TYPE_INVALID_VERSION,
	ATTACK_TYPE_PING_RESPONSE,
	ATTACK_TYPE_MAX_IP_LIMIT,
	ATTACK_TYPE_OPRC_FLOOD,
	ATTACK_TYPE_OPRS_FLOOD,
	ATTACK_TYPE_OPS_FLOOD,
	ATTACK_TYPE_OPD_FLOOD,
	ATTACK_TYPE_OPPUP_FLOOD,
	ATTACK_TYPE_OPSMR_FLOOD,
	ATTACK_TYPE_OPEM_FLOOD,
	ATTACK_TYPE_OPCP_FLOOD,
	ATTACK_TYPE_OPIC_FLOOD,
	ATTACK_TYPE_SELFKILL,
	ATTACK_TYPE_INVALID_KILLERID,
	ATTACK_TYPE_INVALID_PING,
	ATTACK_TYPE_NULL_COMMAND,
	ATTACK_TYPE_INVALID_CLICK_SRC
}



enum (<<= 1)
{
	CALLBACK_DATA_OPC = 1,
	CALLBACK_DATA_OPD,
	CALLBACK_DATA_OPCT,
	CALLBACK_DATA_OPRC,
	CALLBACK_DATA_OPRS,
	CALLBACK_DATA_OPS,
	CALLBACK_DATA_OPD_,
	CALLBACK_DATA_OPPUP,
	CALLBACK_DATA_OPSMR,
	CALLBACK_DATA_OPEM,
	CALLBACK_DATA_OPCP,
	CALLBACK_DATA_OPIC,
	CALLBACK_DATA_ORLA,
	CALLBACK_DATA_PNSC,
	CALLBACK_DATA_ORAA,
	CALLBACK_DATA_OIAA
}





#pragma tabsize 8





new aat_playerConnected[MAX_PLAYERS char];
new aat_netStatsTimer;
new aat_maxPlayers;
new aat_CALLBACK_DATA;





forward OnRemoteAttackAttempt(attackType, data[]);
forward OnIngameAttackAttempt(attackType, data);
forward PlayerNetStatsCheck();





#if defined FILTERSCRIPT

	public OnFilterScriptInit()
	{
		aat_netStatsTimer = SetTimer("PlayerNetStatsCheck", 1000, true);
		aat_maxPlayers = GetMaxPlayers();

		aat_Init(aat_maxPlayers, true);

		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerConnect") != -1) ? CALLBACK_DATA_OPC : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerDisconnect") != -1) ? CALLBACK_DATA_OPD : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerCommandText") != -1) ? CALLBACK_DATA_OPCT : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerRequestClass") != -1) ? CALLBACK_DATA_OPRC : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerRequestSpawn") != -1) ? CALLBACK_DATA_OPRS : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerSpawn") != -1) ? CALLBACK_DATA_OPS : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerDeath") != -1) ? CALLBACK_DATA_OPD_ : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerPickUpPickup") != -1) ? CALLBACK_DATA_OPPUP : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerSelectedMenuRow") != -1) ? CALLBACK_DATA_OPSMR : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerExitedMenu") != -1) ? CALLBACK_DATA_OPEM : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerClickPlayer") != -1) ? CALLBACK_DATA_OPCP : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerInteriorChange") != -1) ? CALLBACK_DATA_OPIC : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnRconLoginAttempt") != -1) ? CALLBACK_DATA_ORLA : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_PlayerNetStatsCheck") != -1) ? CALLBACK_DATA_PNSC : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnRemoteAttackAttempt") != -1) ? CALLBACK_DATA_ORAA : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnIngameAttackAttempt") != -1) ? CALLBACK_DATA_OIAA : 0;

		#if defined aat_DEBUG
			printf("Anti-Attack: Callback data: %b\n", aat_CALLBACK_DATA);
		#endif

		if(funcidx("aat_OnFilterScriptInit") != -1) return CallLocalFunction("aat_OnFilterScriptInit", "");

		return 1;
	}

	#if defined _ALS_OnFilterScriptInit
    		#undef OnFilterScriptInit
	#else
    		#define _ALS_OnFilterScriptInit
	#endif

	#define OnFilterScriptInit aat_OnFilterScriptInit

	forward aat_OnFilterScriptInit();




	public OnFilterScriptExit()
	{
		KillTimer(aat_netStatsTimer);

		if(funcidx("aat_OnFilterScriptExit") != -1) return CallLocalFunction("aat_OnFilterScriptExit", "");

		return 1;
	}

	#if defined _ALS_OnFilterScriptExit
    		#undef OnFilterScriptExit
	#else
    		#define _ALS_OnFilterScriptExit
	#endif

	#define OnFilterScriptExit aat_OnFilterScriptExit

	forward aat_OnFilterScriptExit();

#else

	public OnGameModeInit()
	{
		aat_netStatsTimer = SetTimer("PlayerNetStatsCheck", 1000, true);
		aat_maxPlayers = GetMaxPlayers();

		aat_Init(aat_maxPlayers, true);

		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerConnect") != -1) ? CALLBACK_DATA_OPC : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerDisconnect") != -1) ? CALLBACK_DATA_OPD : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerCommandText") != -1) ? CALLBACK_DATA_OPCT : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerRequestClass") != -1) ? CALLBACK_DATA_OPRC : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerRequestSpawn") != -1) ? CALLBACK_DATA_OPRS : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerSpawn") != -1) ? CALLBACK_DATA_OPS : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerDeath") != -1) ? CALLBACK_DATA_OPD_ : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerPickUpPickup") != -1) ? CALLBACK_DATA_OPPUP : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerSelectedMenuRow") != -1) ? CALLBACK_DATA_OPSMR : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerExitedMenu") != -1) ? CALLBACK_DATA_OPEM : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerClickPlayer") != -1) ? CALLBACK_DATA_OPCP : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnPlayerInteriorChange") != -1) ? CALLBACK_DATA_OPIC : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnRconLoginAttempt") != -1) ? CALLBACK_DATA_ORLA : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_PlayerNetStatsCheck") != -1) ? CALLBACK_DATA_PNSC : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnRemoteAttackAttempt") != -1) ? CALLBACK_DATA_ORAA : 0;
		aat_CALLBACK_DATA |= (funcidx("aat_OnIngameAttackAttempt") != -1) ? CALLBACK_DATA_OIAA : 0;

		#if defined aat_DEBUG
			printf("Anti-Attack: Callback data: %b\n", aat_CALLBACK_DATA);
		#endif

		if(funcidx("aat_OnGameModeInit") != -1) return CallLocalFunction("aat_OnGameModeInit", "");

		return 1;
	}

	#if defined _ALS_OnGameModeInit
    		#undef OnGameModeInit
	#else
    		#define _ALS_OnGameModeInit
	#endif

	#define OnGameModeInit aat_OnGameModeInit

	forward aat_OnGameModeInit();




	public OnGameModeExit()
	{
		KillTimer(aat_netStatsTimer);

		if(funcidx("aat_OnGameModeExit") != -1) return CallLocalFunction("aat_OnGameModeExit", "");

		return 1;
	}

	#if defined _ALS_OnGameModeExit
    		#undef OnGameModeExit
	#else
    		#define _ALS_OnGameModeExit
	#endif

	#define OnGameModeExit aat_OnGameModeExit

	forward aat_OnGameModeExit();

#endif





public OnRemoteAttackAttempt(attackType, data[])
{
	if(data[0] <= '\1')
	{
		printf("Anti-Attack Warning: NULL data passed to callback \"OnRemoteAttackAttempt\" %i|\"\"", attackType);

		return 1;
	}

	if(!(7 <= strlen(data) <= 15))
	{
		printf("Anti-Attack Warning: Invalid data LEN in callback \"OnRemoteAttackAttempt\" %i|\"%s\" (LEN: %i)", attackType, data, strlen(data));

		return 1;
	}

	new aat_dest[32];

	switch(attackType)
	{
		case ATTACK_TYPE_BAD_RCON_ATTEMPT: // BAD RCON ATTEMPT BY ...
		{
			format(aat_dest, sizeof aat_dest, "banip %s", data);
			SendRconCommand(aat_dest);

			printf("Anti-Attack Warning: IP %s was banned (Reason: Bad RCON attempt attack)", data);

			return 1;
		}

		case ATTACK_TYPE_INVALID_CLIENT: // Invalid client connecting from ...
		{
			format(aat_dest, sizeof aat_dest, "banip %s", data);
			SendRconCommand(aat_dest);

			printf("Anti-Attack Warning: IP %s was banned (Reason: Invalid client)", data);

			return 1;
		}

		case ATTACK_TYPE_SERVER_FULL: // Blocking ... due to a 'server full' attack
		{
			format(aat_dest, sizeof aat_dest, "banip %s", data);
			SendRconCommand(aat_dest);

			printf("Anti-Attack Warning: IP %s was banned (Reason: 'Server full' attack)", data);

			return 1;
		}

		case ATTACK_TYPE_INVALID_RCON: // RCON is invalid, ...
		{
			format(aat_dest, sizeof aat_dest, "banip %s", data);
			SendRconCommand(aat_dest);

			printf("Anti-Attack Warning: IP %s was banned (Reason: Invalid RCON)", data);

			return 1;
		}

		default:
		{
			printf("Anti-Attack Warning: Incorrect data passed to callback \"OnRemoteAttackAttempt\" %i|\"%s\"", attackType, data);

			return 1;
		}
	}

	if(aat_CALLBACK_DATA & CALLBACK_DATA_ORAA) return CallLocalFunction("aat_OnRemoteAttackAttempt", "is", attackType, data);

	return 1;
}

#if defined _ALS_OnRemoteAttackAttempt
    #undef OnRemoteAttackAttempt
#else
    #define _ALS_OnRemoteAttackAttempt
#endif

#define OnRemoteAttackAttempt aat_OnRemoteAttackAttempt

forward aat_OnRemoteAttackAttempt(attackType, data[]);





public OnIngameAttackAttempt(attackType, data)
{
	if(!IsPlayerConnected(data)) return 1;

	switch(attackType)
	{
		case ATTACK_TYPE_DIALOG_RESPONSE: // PlayerDialogResponse ... dialog ID doesn't match last sent dialog ID
		{
			BanEx(data, "PlayerDialogResponse attack (Dialog match)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: PlayerDialogResponse attack (Dialog match))", data);

			return 1;
		}

		case ATTACK_TYPE_DIALOG_EXPLOIT: // PlayerDialogResponse crash exploit from ...
		{
			BanEx(data, "PlayerDialogResponse attack (Crash exploit)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: PlayerDialogResponse attack (Crash exploit))", data);

			return 1;
		}

		case ATTACK_TYPE_RCON_EXPLOIT: // /rcon command exploit from ...
		{
			BanEx(data, "RCON attack (Crash exploit)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: RCON command attack (Crash exploit))", data);

			return 1;
		}

		case ATTACK_TYPE_PACKET_MODIFIED: // Packet was modified, sent by ...
		{
			BanEx(data, "Client attack (Packet was modified)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: Modified packet attack)", data);

			return 1;
		}

		case ATTACK_TYPE_REMOTE_PORT_REFUSED: // Remote Port Refused for ...
		{
			BanEx(data, "Client attack (Remote port refused)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: Refusing port attack)", data);

			return 1;
		}

		case ATTACK_TYPE_ONESLOT_FLOOD: // 100 Joins per sec
		{
			BanEx(data, "Client attack (One-slot flood)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: One-slot flood attack)", data);

			return 1;
		}

		case ATTACK_TYPE_INVALID_VERSION: // Version of client is not conform to valid
		{
			BanEx(data, "Client attack (Invalid client version)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: Invalid client version)", data);

			return 1;
		}

		case ATTACK_TYPE_PING_RESPONSE: // UpdateScoresPingsIPs flood
		{
			BanEx(data, "Client attack (Ping response flood)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: Ping response flood)", data);

			return 1;
		}

		case ATTACK_TYPE_MAX_IP_LIMIT: // Many connects from 1 IP
		{
			Kick(data);
			printf("Anti-Attack Warning: Player %i was kicked (Reason: %i connections from 1 IP)", data, MAX_CONNECTS_FROM_IP);

			return 1;
		}

		case ATTACK_TYPE_OPRC_FLOOD: // OnPlayerRequestClass flood
		{
		/*	BanEx(data, "Client attack (OnPlayerRequestClass flood)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: OnPlayerRequestClass flood)", data);*/

			return 1;
		}

		case ATTACK_TYPE_OPRS_FLOOD: // OnPlayerRequestSpawn flood
		{
		/*	BanEx(data, "Client attack (OnPlayerRequestSpawn flood)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: OnPlayerRequestSpawn flood)", data);*/

			return 1;
		}

		case ATTACK_TYPE_OPS_FLOOD: // OnPlayerSpawn flood
		{
	/*		BanEx(data, "Client attack (OnPlayerSpawn flood)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: OnPlayerSpawn flood)", data);*/

			return 1;
		}

		case ATTACK_TYPE_OPD_FLOOD: // OnPlayerDeath flood
		{
			/*BanEx(data, "Client attack (OnPlayerDeath flood)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: OnPlayerDeath flood)", data);*/

			return 1;
		}

		case ATTACK_TYPE_OPPUP_FLOOD: // OnPlayerPickUpPickup flood
		{
			/*BanEx(data, "Client attack (OnPlayerPickUpPickup flood)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: OnPlayerPickUpPickup flood)", data);*/

			return 1;
		}

		case ATTACK_TYPE_OPSMR_FLOOD: // OnPlayerSelectedMenuRow flood
		{
		/*	BanEx(data, "Client attack (OnPlayerSelectedMenuRow flood)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: OnPlayerSelectedMenuRow flood)", data);*/

			return 1;
		}

		case ATTACK_TYPE_OPEM_FLOOD: // OnPlayerExitedMenu flood
		{
		/*	BanEx(data, "Client attack (OnPlayerExitedMenu flood)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: OnPlayerExitedMenu flood)", data);*/

			return 1;
		}

		case ATTACK_TYPE_OPCP_FLOOD: // OnPlayerClickPlayer flood
		{
			/*BanEx(data, "Client attack (OnPlayerClickPlayer flood)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: OnPlayerClickPlayer flood)", data);*/

			return 1;
		}

		case ATTACK_TYPE_OPIC_FLOOD: // OnPlayerInteriorChange flood
		{
		/*	BanEx(data, "Client attack (OnPlayerInteriorChange flood)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: OnPlayerInteriorChange flood)", data);*/

			return 1;
		}

		case ATTACK_TYPE_SELFKILL: // player killed himself (unreal :O)
		{
			BanEx(data, "Client attack (SelfKill)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: SelfKill)", data);

			return 1;
		}

		case ATTACK_TYPE_INVALID_KILLERID: // killerid is not connected and not equal 65535
		{
			BanEx(data, "Client attack (Invalid killerid)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: Invalid killerid)", data);

			return 1;
		}

		case ATTACK_TYPE_INVALID_PING: // player's ping = -1, lol
		{
			Kick(data);
			printf("Anti-Attack Warning: Player %i was kicked (Reason: Invalid ping)", data);

			return 1;
		}

		case ATTACK_TYPE_NULL_COMMAND: // sended "" command, unreal :O
		{
			BanEx(data, "Client attack (NULL command)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: NULL command)", data);

			return 1;
		}

		case ATTACK_TYPE_INVALID_CLICK_SRC: // clicked on != 0 source, unreal :O
		{
			BanEx(data, "Client attack (Invalid clicked source)");
			printf("Anti-Attack Warning: Player %i was banned (Reason: Invalid clicked source)", data);

			return 1;
		}

		default:
		{
			printf("Anti-Attack Warning: Incorrect data passed to callback \"OnIngameAttackAttempt\" %i|%i", attackType, data);

			return 1;
		}
	}

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OIAA) return CallLocalFunction("aat_OnIngameAttackAttempt", "ii", attackType, data);

	return 1;
}

#if defined _ALS_OnIngameAttackAttempt
    #undef OnIngameAttackAttempt
#else
    #define _ALS_OnIngameAttackAttempt
#endif

#define OnIngameAttackAttempt aat_OnIngameAttackAttempt

forward aat_OnIngameAttackAttempt(attackType, data);





public PlayerNetStatsCheck()
{
	static sCounter;
	
	sCounter += (sCounter == 5) ? -5 : 1;

	for(new i, nsdest[512]; i != aat_maxPlayers; i++)
	{
		if(!IsPlayerConnected(i)) continue;

		GetPlayerNetworkStats(i, nsdest, sizeof nsdest);

		if(aat_NetStats(nsdest) >= MAX_PACKETS_PER_SECOND)
		{
			CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_PING_RESPONSE, i);

			continue;
		}

		if(GetPlayerPing(i) == -1)
		{
			if((GetPVarInt(i, "invalid_ping_w") + 1) >= 3)
			{
				CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_INVALID_PING, i);

				continue;
			}

			SetPVarInt(i, "invalid_ping_w", (GetPVarInt(i, "invalid_ping_w") + 1));
		}

		if(!sCounter)
		{
			DeletePVar(i, "OPRC_flood_w");
			DeletePVar(i, "OPRS_flood_w");
			DeletePVar(i, "OPS_flood_w");
			DeletePVar(i, "OPD_flood_w");
			DeletePVar(i, "OPPUP_flood_w");
			DeletePVar(i, "OPSMR_flood_w");
			DeletePVar(i, "OPEM_flood_w");
			DeletePVar(i, "OPCP_flood_w");
			DeletePVar(i, "OPIC_flood_w");
		}
	}

	if(aat_CALLBACK_DATA & CALLBACK_DATA_PNSC) return CallLocalFunction("aat_PlayerNetStatsCheck", "");

	return 1;
}

#if defined _ALS_PlayerNetStatsCheck
    #undef PlayerNetStatsCheck
#else
    #define _ALS_PlayerNetStatsCheck
#endif

#define PlayerNetStatsCheck aat_PlayerNetStatsCheck

forward aat_PlayerNetStatsCheck();





public OnPlayerConnect(playerid)
{
	playerid &= 65535;

	if(aat_playerConnected{playerid}) 
	{
		CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_ONESLOT_FLOOD, playerid);

		return 1;
	}

	aat_playerConnected{playerid} = 1;

	new aat_dest[32];

	GetPlayerVersion(playerid, aat_dest, sizeof aat_dest);

	if(strfind(aat_dest, SAMP_CURRENT_VERSION, false) == -1)
	{
		CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_INVALID_VERSION, playerid);

		return 1;
	}

	GetPlayerIp(playerid, aat_dest, sizeof aat_dest);
	
	for(new i, f, aat_sub[16]; i != aat_maxPlayers; i++)
	{
		if(!IsPlayerConnected(i) || IsPlayerNPC(i) || i == playerid) continue;

		GetPlayerIp(i, aat_sub, sizeof aat_sub);

		if(!strcmp(aat_dest, aat_sub, false))
		{
			if(++f >= MAX_CONNECTS_FROM_IP)
			{
				CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_MAX_IP_LIMIT, playerid);

				break;
			}
		}
	}

	//ShowPlayerDialog(playerid, -1, -1, "", "", "", "");

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPC) return CallLocalFunction("aat_OnPlayerConnect", "i", playerid);

	return 1;
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect aat_OnPlayerConnect

forward aat_OnPlayerConnect(playerid);





public OnPlayerDisconnect(playerid, reason)
{
	playerid &= 65535;
	aat_playerConnected{playerid} = 0;

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPD) return CallLocalFunction("aat_OnPlayerDisconnect", "ii", playerid, reason);

	return 1;
}

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect aat_OnPlayerDisconnect

forward aat_OnPlayerDisconnect(playerid, reason);





public OnPlayerCommandText(playerid, cmdtext[])
{
	playerid &= 65535;

	if(!cmdtext[0])
	{
		CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_NULL_COMMAND, playerid);

		return 0;
	}

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPCT) return CallLocalFunction("aat_OnPlayerCommandText", "is", playerid, cmdtext);

	return 0;
}

#if defined _ALS_OnPlayerCommandText
    #undef OnPlayerCommandText
#else
    #define _ALS_OnPlayerCommandText
#endif

#define OnPlayerCommandText aat_OnPlayerCommandText

forward aat_OnPlayerCommandText(playerid, cmdtext[]);





public OnPlayerRequestClass(playerid, classid)
{
	playerid &= 65535;

	if(GetTickCount() <= GetPVarInt(playerid, "OPRC_flood"))
	{
		if((GetPVarInt(playerid, "OPRC_flood_w") + 1) >= MAX_FUNCTION_CALL_WARNS)
		{
			CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_OPRC_FLOOD, playerid);

			return 0;
		}

		SetPVarInt(playerid, "OPRC_flood_w", (GetPVarInt(playerid, "OPRC_flood_w") + 1));
	}

	SetPVarInt(playerid, "OPRC_flood", (GetTickCount() + MAX_FUNCTION_CALL_MS));

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPRC) return CallLocalFunction("aat_OnPlayerRequestClass", "ii", playerid, classid);

	return 1;
}

#if defined _ALS_OnPlayerRequestClass
    #undef OnPlayerRequestClass
#else
    #define _ALS_OnPlayerRequestClass
#endif

#define OnPlayerRequestClass aat_OnPlayerRequestClass

forward aat_OnPlayerRequestClass(playerid, classid);





public OnPlayerRequestSpawn(playerid)
{
	playerid &= 65535;

	if(GetTickCount() <= GetPVarInt(playerid, "OPRS_flood"))
	{
		if((GetPVarInt(playerid, "OPRS_flood_w") + 1) >= MAX_FUNCTION_CALL_WARNS)
		{
			CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_OPRS_FLOOD, playerid);

			return 0;
		}

		SetPVarInt(playerid, "OPRS_flood_w", (GetPVarInt(playerid, "OPRS_flood_w") + 1));
	}

	SetPVarInt(playerid, "OPRS_flood", (GetTickCount() + MAX_FUNCTION_CALL_MS));

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPRS) return CallLocalFunction("aat_OnPlayerRequestSpawn", "i", playerid);

	return 1;
}

#if defined _ALS_OnPlayerRequestSpawn
    #undef OnPlayerRequestSpawn
#else
    #define _ALS_OnPlayerRequestSpawn
#endif

#define OnPlayerRequestSpawn aat_OnPlayerRequestSpawn

forward aat_OnPlayerRequestSpawn(playerid);





public OnPlayerSpawn(playerid)
{
	playerid &= 65535;

	if(GetTickCount() <= GetPVarInt(playerid, "OPS_flood"))
	{
		if((GetPVarInt(playerid, "OPS_flood_w") + 1) >= MAX_FUNCTION_CALL_WARNS)
		{
			CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_OPS_FLOOD, playerid);

			return 0;
		}

		SetPVarInt(playerid, "OPS_flood_w", (GetPVarInt(playerid, "OPS_flood_w") + 1));
	}

	SetPVarInt(playerid, "OPS_flood", (GetTickCount() + MAX_FUNCTION_CALL_MS));

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPS) return CallLocalFunction("aat_OnPlayerSpawn", "i", playerid);

	return 1;
}

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn aat_OnPlayerSpawn

forward aat_OnPlayerSpawn(playerid);





public OnPlayerDeath(playerid, killerid, reason)
{
	playerid &= 65535;
	killerid &= 65535;

	if(playerid == killerid)
	{
		CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_SELFKILL, playerid);

		return 0;
	}

	if(!IsPlayerConnected(killerid) && killerid != 65535)
	{
		CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_INVALID_KILLERID, playerid);

		return 0;
	}

	if(GetTickCount() <= GetPVarInt(playerid, "OPD_flood"))
	{
		if((GetPVarInt(playerid, "OPD_flood_w") + 1) >= MAX_FUNCTION_CALL_WARNS)
		{
			CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_OPD_FLOOD, playerid);

			return 0;
		}

		SetPVarInt(playerid, "OPD_flood_w", (GetPVarInt(playerid, "OPD_flood_w") + 1));
	}

	SetPVarInt(playerid, "OPD_flood", (GetTickCount() + MAX_FUNCTION_CALL_MS));

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPD_) return CallLocalFunction("aat_OnPlayerDeath", "iii", playerid, killerid, reason);

	return 1;
}

#if defined _ALS_OnPlayerDeath
    #undef OnPlayerDeath
#else
    #define _ALS_OnPlayerDeath
#endif

#define OnPlayerDeath aat_OnPlayerDeath

forward aat_OnPlayerDeath(playerid, killerid, reason);





public OnPlayerPickUpPickup(playerid, pickupid)
{
	playerid &= 65535;

	if(GetTickCount() <= GetPVarInt(playerid, "OPPUP_flood"))
	{
		if((GetPVarInt(playerid, "OPPUP_flood_w") + 1) >= MAX_FUNCTION_CALL_WARNS)
		{
			CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_OPPUP_FLOOD, playerid);

			return 0;
		}

		SetPVarInt(playerid, "OPPUP_flood_w", (GetPVarInt(playerid, "OPPUP_flood_w") + 1));
	}

	SetPVarInt(playerid, "OPPUP_flood", (GetTickCount() + MAX_FUNCTION_CALL_MS));

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPPUP) return CallLocalFunction("aat_OnPlayerPickUpPickup", "ii", playerid, pickupid);

	return 1;
}

#if defined _ALS_OnPlayerPickUpPickup
    #undef OnPlayerPickUpPickup
#else
    #define _ALS_OnPlayerPickUpPickup
#endif

#define OnPlayerPickUpPickup aat_OnPlayerPickUpPickup

forward aat_OnPlayerPickUpPickup(playerid, pickupid);





public OnPlayerSelectedMenuRow(playerid, row)
{
	playerid &= 65535;

	if(GetTickCount() <= GetPVarInt(playerid, "OPSMR_flood"))
	{
		if((GetPVarInt(playerid, "OPSMR_flood_w") + 1) >= MAX_FUNCTION_CALL_WARNS)
		{
			CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_OPSMR_FLOOD, playerid);

			return 0;
		}

		SetPVarInt(playerid, "OPSMR_flood_w", (GetPVarInt(playerid, "OPSMR_flood_w") + 1));
	}

	SetPVarInt(playerid, "OPSMR_flood", (GetTickCount() + MAX_FUNCTION_CALL_MS));

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPSMR) return CallLocalFunction("aat_OnPlayerSelectedMenuRow", "ii", playerid, row);

	return 1;
}

#if defined _ALS_OnPlayerSelectedMenuRow
    #undef OnPlayerSelectedMenuRow
#else
    #define _ALS_OnPlayerSelectedMenuRow
#endif

#define OnPlayerSelectedMenuRow aat_OnPlayerSelectedMenuRow

forward aat_OnPlayerSelectedMenuRow(playerid, row);





public OnPlayerExitedMenu(playerid)
{
	playerid &= 65535;

	if(GetTickCount() <= GetPVarInt(playerid, "OPEM_flood"))
	{
		if((GetPVarInt(playerid, "OPEM_flood_w") + 1) >= MAX_FUNCTION_CALL_WARNS)
		{
			CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_OPEM_FLOOD, playerid);

			return 0;
		}

		SetPVarInt(playerid, "OPEM_flood_w", (GetPVarInt(playerid, "OPEM_flood_w") + 1));
	}

	SetPVarInt(playerid, "OPEM_flood", (GetTickCount() + MAX_FUNCTION_CALL_MS));

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPEM) return CallLocalFunction("aat_OnPlayerExitedMenu", "i", playerid);

	return 1;
}

#if defined _ALS_OnPlayerExitedMenu
    #undef OnPlayerExitedMenu
#else
    #define _ALS_OnPlayerExitedMenu
#endif

#define OnPlayerExitedMenu aat_OnPlayerExitedMenu

forward aat_OnPlayerExitedMenu(playerid);





public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	playerid &= 65535;
	clickedplayerid &= 65535;

	//0.3a => ???
	if(source)
	{
		CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_INVALID_CLICK_SRC, playerid);

		return 0;
	}

	if(GetTickCount() <= GetPVarInt(playerid, "OPCP_flood"))
	{
		if((GetPVarInt(playerid, "OPCP_flood_w") + 1) >= MAX_FUNCTION_CALL_WARNS)
		{
			CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_OPCP_FLOOD, playerid);

			return 0;
		}

		SetPVarInt(playerid, "OPCP_flood_w", (GetPVarInt(playerid, "OPCP_flood_w") + 1));
	}

	SetPVarInt(playerid, "OPCP_flood", (GetTickCount() + MAX_FUNCTION_CALL_MS));

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPCP) return CallLocalFunction("aat_OnPlayerClickPlayer", "iii", playerid, clickedplayerid, source);

	return 1;
}

#if defined _ALS_OnPlayerClickPlayer
    #undef OnPlayerClickPlayer
#else
    #define _ALS_OnPlayerClickPlayer
#endif

#define OnPlayerClickPlayer aat_OnPlayerClickPlayer

forward aat_OnPlayerClickPlayer(playerid, clickedplayerid, source);





public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	playerid &= 65535;

	if(GetTickCount() <= GetPVarInt(playerid, "OPIC_flood"))
	{
		if((GetPVarInt(playerid, "OPIC_flood_w") + 1) >= MAX_FUNCTION_CALL_WARNS)
		{
			CallLocalFunction("OnIngameAttackAttempt", "ii", ATTACK_TYPE_OPIC_FLOOD, playerid);

			return 0;
		}

		SetPVarInt(playerid, "OPIC_flood_w", (GetPVarInt(playerid, "OPIC_flood_w") + 1));
	}

	SetPVarInt(playerid, "OPIC_flood", (GetTickCount() + MAX_FUNCTION_CALL_MS));

	if(aat_CALLBACK_DATA & CALLBACK_DATA_OPIC) return CallLocalFunction("aat_OnPlayerInteriorChange", "iii", playerid, newinteriorid, oldinteriorid);

	return 1;
}

#if defined _ALS_OnPlayerInteriorChange
    #undef OnPlayerInteriorChange
#else
    #define _ALS_OnPlayerInteriorChange
#endif

#define OnPlayerInteriorChange aat_OnPlayerInteriorChange

forward aat_OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);





public OnRconLoginAttempt(ip[], password[], success)
{
	if(!success)
	{
		CallLocalFunction("OnRemoteAttackAttempt", "is", ATTACK_TYPE_INVALID_RCON, ip);

		return 0;
	}

	if(aat_CALLBACK_DATA & CALLBACK_DATA_ORLA) return CallLocalFunction("aat_OnRconLoginAttempt", "ssi", ip, password, success);

	return 1;
}

#if defined _ALS_OnRconLoginAttempt
    #undef OnRconLoginAttempt
#else
    #define _ALS_OnRconLoginAttempt
#endif

#define OnRconLoginAttempt aat_OnRconLoginAttempt

forward aat_OnRconLoginAttempt(ip[], password[], success);





#pragma tabsize 4
