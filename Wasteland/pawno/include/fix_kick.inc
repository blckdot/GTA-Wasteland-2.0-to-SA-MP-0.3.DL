/*
* kick fix
*/
#if !defined BAD_Kick
	native BAD_Kick(playerid) = Kick;
#endif
	
#define IsKicked(%0) GetPVarInt(%0,"playerKicked")
#define GuardedNick	"0xPUBLI_c"

stock PFUNC_Kick(playerid)
{
	if(playerid >= 0 && playerid < MAX_PLAYERS)
	{
		if(!IsKicked(playerid))
		{
			SetPVarInt(playerid, "playerKicked", 1);
			SetPlayerName(playerid, GuardedNick);
			SetTimerEx("onKicked", 100, false, "i", playerid);
			#if defined checkSpectatorsPlayer
				checkSpectatorsPlayer(playerid);
			#endif
		}
		return 1;
	}
	return 0;
}

forward onKicked(playerid);
public onKicked(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		Kick(playerid);
	}
}
#if defined _ALS_Kick
	#undef Kick
#else
	#define _ALS_Kick
#endif
#define Kick PFUNC_Kick


public OnPlayerConnect(playerid) {
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, MAX_PLAYER_NAME);

	if(!strcmp(GuardedNick, name, true))
	{
		Kick(playerid);
		return true;
	}
	#if defined fKick_OnPlayerConnect
		fKick_OnPlayerConnect(playerid);
	#endif
	return 1;
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect fKick_OnPlayerConnect
#if defined fKick_OnPlayerConnect
	forward fKick_OnPlayerConnect(playerid);
#endif 

public OnPlayerDisconnect(playerid,reason) {
	SetPlayerName(playerid, GuardedNick);

	#if defined fKick_OnPlayerDisconnect
		fKick_OnPlayerDisconnect(playerid,reason);
	#endif
	return 1;
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect fKick_OnPlayerDisconnect
#if defined fKick_OnPlayerDisconnect
	forward fKick_OnPlayerDisconnect(playerid,reason);
#endif