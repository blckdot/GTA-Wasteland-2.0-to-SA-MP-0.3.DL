/*
anti-cheat
*/
native _GiveMoney(playerid,ammount);
native _GetMoney(playerid);
native _ResetMoney(playerid);
native _SetPlayerHealth(playerid,Float:ammount);
native BAD_GetPlayerHealth(playerid, &Float:health) = GetPlayerHealth;
native _GetPlayerHealth(playerid, &Float:health);
native _SetPlayerArmour(playerid,Float:ammount);
native _GetPlayerArmour(playerid, &Float:armour);
native _GivePlayerWeapon(playerid,weaponid,ammo);
native _ResetPlayerWeapons(playerid);
native _SetPlayerPos(playerid,Float:x,Float:y,Float:z);
native _SetPlayerPosFindZ(playerid,Float:x,Float:y,Float:z);
native _PutPlayerInVehicle(playerid,vehicleid,seatid);
native _RemovePlayerFromVehicle(playerid);
native _SetVehiclePos(vehicleid, Float:x, Float:y, Float:z);
native ac_Kick(playerid,reason[]);
//native _ChangeVehicleColor(vehicleid,color1,color2);
//native _ChangeVehiclePaintjob(vehicleid,paint_job);
 

forward OnPlayerKicked(playerid, reason[]);
forward OnPlayerBanned(playerid, reason[]);
/*
forward GetVehicleColor_1(vehicleid);
public GetVehicleColor_1(vehicleid)
{
	new color1, color2;
	GetVehicleColor(vehicleid, color1, color2);
	return color1;
}
forward GetVehicleColor_2(vehicleid);
public GetVehicleColor_2(vehicleid)
{
	new color1, color2;
	GetVehicleColor(vehicleid, color1, color2);
	return color2;
}
forward ACGetVehiclePaintJob(vehicleid);
public ACGetVehiclePaintJob(vehicleid) return GetVehiclePaintjob(vehicleid);
*/
native Invoke_GetAddresses();


new gPlayerEnterVehicleTick[MAX_PLAYERS];

static 
	playerDialogUse[MAX_PLAYERS] = {-1, ...}
; 
/**
 * Запоминаем id последнего открытого диалога.
 */
stock aC_ShowPlayerDialog(playerid, dialogid, style, caption[], info[], button1[], button2[])
{
	playerDialogUse[playerid] = dialogid;
	ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);
	return 1;
}
#if defined _ALS_ShowPlayerDialog
	#undef ShowPlayerDialog
#else
	#define _ALS_ShowPlayerDialog
#endif
#define ShowPlayerDialog aC_ShowPlayerDialog

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(playerDialogUse[playerid] != dialogid) return 1;
	playerDialogUse[playerid] = -1;

	#if defined aC_OnDialogResponse
		return aC_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif
#define OnDialogResponse aC_OnDialogResponse
#if defined aC_OnDialogResponse
	forward aC_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif
 
public OnGameModeInit() {
 
	Invoke_GetAddresses();
	#if defined aC_OnGameModeInit
		aC_OnGameModeInit();
	#endif
	return 1;
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit aC_OnGameModeInit
#if defined aC_OnGameModeInit
	forward aC_OnGameModeInit();
#endif
 
forward public InvokeFunction();
public InvokeFunction()
{
	new Float:fVar;
	new Var[ 256 ];
	new iVar;
 
	// a_samp.inc
	SendClientMessage(0, 0, "");
	SendClientMessageToAll(0, "");
	SendDeathMessage(0, 0, 0);
	GameTextForAll("", 0, 0);
	GameTextForPlayer(0, "", 0, 0);
	GetTickCount();
	GetMaxPlayers();
	SetGameModeText("");
	SetTeamCount(0);
	AddPlayerClass(0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
	AddPlayerClassEx(0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
	AddStaticVehicle(0, 0.0, 0.0, 0.0, 0.0, 0, 0);
	AddStaticVehicleEx(0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0);
	AddStaticPickup(0, 0, 0.0, 0.0, 0.0);
	ShowNameTags(0);
	ShowPlayerMarkers(0);
	GameModeExit();
	SetWorldTime(0);
	GetWeaponName(0, Var, sizeof( Var ) );
	EnableTirePopping(0);
	AllowInteriorWeapons(0);
	SetWeather(0);
	SetGravity(0.0);
	AllowAdminTeleport(0);
	SetDeathDropAmount(0);
	CreateExplosion(0.0, 0.0, 0.0, 0, 0.0);
	//SetDisabledWeapons();
	EnableZoneNames(0);
	IsPlayerAdmin(0);
	Kick(0);
	Ban(0);
	SendRconCommand("");
	ShowPlayerDialog(0,0,0,"lol","lol","lol","lol");
 
	// a_players.inc
	SetSpawnInfo(0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0,0);
	SpawnPlayer(0);
	SetPlayerPos(0, 0.0, 0.0, 0.0);
	SetPlayerPosFindZ(0, 0.0, 0.0, 0.0);
	GetPlayerPos(0, fVar, fVar, fVar);
	SetPlayerFacingAngle(0,0.0);
	GetPlayerFacingAngle(0,fVar);
	SetPlayerInterior(0,0);
	GetPlayerInterior(0);
	SetPlayerHealth(0, 0.0);
	GetPlayerHealth(0, fVar);
	SetPlayerArmour(0, 0.0);
	GetPlayerArmour(0, fVar);
	SetPlayerAmmo(0, 0,0);
	GetPlayerAmmo(0);
	SetPlayerTeam(0,0);
	GetPlayerTeam(0);
	SetPlayerScore(0,0);
	GetPlayerScore(0);
	SetPlayerColor(0,0);
	GetPlayerColor(0);
	SetPlayerSkin(0,0);
	GivePlayerWeapon(0, 0,0);
	ResetPlayerWeapons(0);
	GetPlayerWeaponData(0, 0, iVar, iVar );
	GivePlayerMoney(0,0);
	ResetPlayerMoney(0);
	SetPlayerName(0, "");
	GetPlayerMoney(0);
	GetPlayerState(0);
	GetPlayerIp(0, Var, sizeof( Var ));
	GetPlayerPing(0);
	GetPlayerWeapon(0);
	GetPlayerKeys(0,iVar,iVar,iVar);
	GetPlayerName(0, Var, sizeof( Var ));
	PutPlayerInVehicle(0, 0,0);
	GetPlayerVehicleID(0);
	RemovePlayerFromVehicle(0);
	TogglePlayerControllable(0,0);
	PlayerPlaySound(0, 0, 0.0, 0.0,0.0);
	SetPlayerCheckpoint(0, 0.0, 0.0, 0.0,0.0);
	DisablePlayerCheckpoint(0);
	SetPlayerRaceCheckpoint(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,0.0);
	DisablePlayerRaceCheckpoint(0);
	SetPlayerWorldBounds(0,0.0,0.0,0.0,0.0);
	SetPlayerMarkerForPlayer(0, 0,0);
	ShowPlayerNameTagForPlayer(0, 0,0);
	SetPlayerMapIcon(0, 0, 0.0, 0.0, 0.0, 0,0);
	RemovePlayerMapIcon(0,0);
	SetPlayerCameraPos(0,0.0, 0.0, 0.0);
	SetPlayerCameraLookAt(0, 0.0, 0.0, 0.0);
	SetCameraBehindPlayer(0);
	AllowPlayerTeleport(0,0);
	IsPlayerConnected(0);
	IsPlayerInVehicle(0,0);
	IsPlayerInAnyVehicle(0);
	IsPlayerInCheckpoint(0);
	IsPlayerInRaceCheckpoint(0);
	SetPlayerTime(0, 0,0);
	TogglePlayerClock(0,0);
	SetPlayerWeather(0,0);
	GetPlayerTime(0,iVar,iVar);
	SetPlayerVirtualWorld(0,0);
	GetPlayerVirtualWorld(0);
 
	GetPlayerVelocity(0,fVar,fVar,fVar);
	GetPlayerAnimationIndex(0);
	GetAnimationName(0,Var, sizeof Var,Var, sizeof Var);
	GetVehicleVelocity(0,fVar,fVar,fVar);
	GetPlayerSpecialAction(0);
	GetPlayerSurfingVehicleID(0);
	   
 
	// a_vehicle.inc
	CreateVehicle(0,0.0,0.0,0.0,0.0,0,0,0);
	DestroyVehicle(0);
	GetVehiclePos(0,fVar,fVar,fVar);
	SetVehiclePos(0,0.0,0.0,0.0);
	GetVehicleZAngle(0,fVar);
	SetVehicleZAngle(0,0.0);
	SetVehicleParamsForPlayer(0,0,0,0);
	SetVehicleToRespawn(0);
	LinkVehicleToInterior(0,0);
	AddVehicleComponent(0,0);
	ChangeVehicleColor(0,0,0);
	ChangeVehiclePaintjob(0,0);
	SetVehicleHealth(0,0.0);
	GetVehicleHealth(0,fVar);
	AttachTrailerToVehicle(0, 0);
	DetachTrailerFromVehicle(0);
	IsTrailerAttachedToVehicle(0);
	GetVehicleModel(0);
	SetVehicleNumberPlate(0,"");
	SetVehicleVirtualWorld(0,0);
	GetVehicleVirtualWorld(0);
 
	ApplyAnimation(0,"","",1.0,0,0,0,0,0);
 
	// a_objects.inc
	CreateObject(0,0.0,0.0,0.0,0.0,0.0,0.0);
	SetObjectPos(0,0.0,0.0,0.0);
	GetObjectPos(0,fVar,fVar,fVar);
	SetObjectRot(0,0.0,0.0,0.0);
	GetObjectRot(0,fVar,fVar,fVar);
	IsValidObject(0);
	DestroyObject(0);
	MoveObject(0,0.0,0.0,0.0,0.0);
	StopObject(0);
	CreatePlayerObject(0,0,0.0,0.0,0.0,0.0,0.0,0.0);
	SetPlayerObjectPos(0,0,0.0,0.0,0.0);
	GetPlayerObjectPos(0,0,fVar,fVar,fVar);
	GetPlayerObjectRot(0,0,fVar,fVar,fVar);
	SetPlayerObjectRot(0,0,0.0,0.0,0.0);
	IsValidPlayerObject(0,0);
	DestroyPlayerObject(0,0);
	MovePlayerObject(0,0,0.0,0.0,0.0,0.0);
	StopPlayerObject(0,0);
 
	// Menu's
	CreateMenu("", 0, 0.0, 0.0, 0.0, 0.0);
	DestroyMenu(Menu:0);
	AddMenuItem(Menu:0, 0, "");
	SetMenuColumnHeader(Menu:0, 0, "");
	ShowMenuForPlayer(Menu:0, 0);
	HideMenuForPlayer(Menu:0, 0);
	IsValidMenu(Menu:0);
	DisableMenu(Menu:0);
	DisableMenuRow(Menu:0,0);
 
	// Textdraw
	TextDrawCreate(0.0,0.0,"");
	TextDrawDestroy(Text:0);
	TextDrawLetterSize(Text:0, 0.0,0.0);
	TextDrawTextSize(Text:0, 0.0,0.0);
	TextDrawAlignment(Text:0, 0);
	TextDrawColor(Text:0,0);
	TextDrawUseBox(Text:0, 0);
	TextDrawBoxColor(Text:0, 0);
	TextDrawSetShadow(Text:0, 0);
	TextDrawSetOutline(Text:0, 0);
	TextDrawBackgroundColor(Text:0,0);
	TextDrawFont(Text:0, 0);
	TextDrawSetProportional(Text:0, 0);
	TextDrawShowForPlayer(0, Text:0);
	TextDrawHideForPlayer(0, Text:0);
	TextDrawShowForAll(Text:0);
	TextDrawHideForAll(Text:0);
 
	// Others
	funcidx("");
	gettime(iVar,iVar,iVar);
	getdate(iVar,iVar,iVar);
	tickcount(iVar);

	return 1;
}

/*stock ac_GetPlayerHealth(playerid, &Float:health) 
{
	return (health = _GetPlayerHealth(playerid)), 1;
}
stock ac_GetPlayerArmour(playerid, &Float:armour)
{ 
	return (armour = _GetPlayerArmour(playerid)), 1;
}*/



#if defined _ALS_GivePlayerMoney
	#undef GivePlayerMoney
#else
	#define _ALS_GivePlayerMoney
#endif
#define GivePlayerMoney _GiveMoney
#if defined _ALS_GetPlayerMoney
	#undef GetPlayerMoney
#else
	#define _ALS_GetPlayerMoney
#endif
#define GetPlayerMoney _GetMoney
#if defined _ALS_ResetPlayerMoney
	#undef ResetPlayerMoney
#else
	#define _ALS_ResetPlayerMoney
#endif
#define ResetPlayerMoney _ResetMoney
#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif
#define SetPlayerHealth _SetPlayerHealth
#if defined _ALS_GetPlayerHealth
	#undef GetPlayerHealth
#else
	#define _ALS_GetPlayerHealth
#endif
#define GetPlayerHealth _GetPlayerHealth
#if defined _ALS_SetPlayerArmour
	#undef SetPlayerArmour
#else
	#define _ALS_SetPlayerArmour
#endif
#define SetPlayerArmour _SetPlayerArmour
#if defined _ALS_GetPlayerArmour
	#undef GetPlayerArmour
#else
	#define _ALS_GetPlayerArmour
#endif
#define GetPlayerArmour _GetPlayerArmour
#if defined _ALS_GivePlayerWeapon
	#undef GivePlayerWeapon
#else
	#define _ALS_GivePlayerWeapon
#endif
#define GivePlayerWeapon _GivePlayerWeapon
#if defined _ALS_ResetPlayerWeapons
	#undef ResetPlayerWeapons
#else
	#define _ALS_ResetPlayerWeapons
#endif
#define ResetPlayerWeapons _ResetPlayerWeapons
#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif
#define SetPlayerPos _SetPlayerPos
#if defined _ALS_PutPlayerInVehicle
	#undef PutPlayerInVehicle
#else
	#define _ALS_PutPlayerInVehicle
#endif
#define PutPlayerInVehicle _PutPlayerInVehicle
#if defined _ALS_RemovePlayerFromVehicle
	#undef RemovePlayerFromVehicle
#else
	#define _ALS_RemovePlayerFromVehicle
#endif
#define RemovePlayerFromVehicle _RemovePlayerFromVehicle
#if defined _ALS_SetPlayerPosFindZ
	#undef SetPlayerPosFindZ
#else
	#define _ALS_SetPlayerPosFindZ
#endif
#define SetPlayerPosFindZ _SetPlayerPosFindZ
/*#if defined _ALS_CreateVehicle 
	#undef CreateVehicle 
#else
	#define _ALS_CreateVehicle 
#endif
#define CreateVehicle  _CreateVehicle
#if defined _ALS_AddStaticVehicleEx
	#undef AddStaticVehicleEx
#else
	#define _ALS_AddStaticVehicleEx
#endif
#define AddStaticVehicleEx _AddStaticVehicleEx
#if defined _ALS_AddStaticVehicle
	#undef AddStaticVehicle
#else
	#define _ALS_AddStaticVehicle
#endif
#define AddStaticVehicle _AddStaticVehicle
#if defined _ALS_SetVehiclePos 
	#undef SetVehiclePos 
#else
	#define _ALS_SetVehiclePos 
#endif
#define SetVehiclePos  _SetVehiclePos
#if defined _ALS_DestroyVehicle
	#undef DestroyVehicle
#else
	#define _ALS_DestroyVehicle
#endif
#define DestroyVehicle _DestroyVehicle
#if defined _ALS_SetVehicleToRespawn
	#undef SetVehicleToRespawn
#else
	#define _ALS_SetVehicleToRespawn
#endif
#define SetVehicleToRespawn _SetVehicleToRespawn*/
/*#if defined _ALS_ChangeVehicleColor
	#undef ChangeVehicleColor
#else
	#define _ALS_ChangeVehicleColor
#endif
#define ChangeVehicleColor _ChangeVehicleColor
#if defined _ALS_ChangeVehiclePaintjob
	#undef ChangeVehiclePaintjob
#else
	#define _ALS_ChangeVehiclePaintjob
#endif
#define ChangeVehiclePaintjob _ChangeVehiclePaintjob*/