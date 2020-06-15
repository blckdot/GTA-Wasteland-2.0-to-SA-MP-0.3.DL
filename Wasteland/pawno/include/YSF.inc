/* YSF - kurta999's version */
#if defined _YSF_included
	#endinput
#endif
#define _YSF_included

// File functions
native ffind(const pattern[], filename[], len, &idx);
native frename(const oldname[], const newname[]);

// Directory functions
native dfind(const pattern[], filename[], len, &idx);
native dcreate(const name[]);
native drename(const oldname[], const newname[]);

// Server rule and other functions
native SetModeRestartTime(Float:time);
native Float:GetModeRestartTime();

native SetPlayerAdmin(playerid, bool:admin); // Set player as RCON admin
native LoadFilterScript(scriptname[]); // difference between "rcon loadfs": Return -> True if success, false if not
native UnLoadFilterScript(scriptname[]); // ^
native GetFilterScriptCount();
native GetFilterScriptName(id, name[], len = sizeof(name));

#define CON_VARFLAG_DEBUG       1
#define CON_VARFLAG_READONLY    2
#define CON_VARFLAG_RULE        4
#define CON_VARFLAG_UNREMOVABLE 8

native AddServerRule(name[], value[], flags = CON_VARFLAG_RULE);
native SetServerRule(name[], value[]);
native ModifyFlag(name[], flags);

// Per player things
native SetPlayerGravity(playerid, Float:gravity);
native Float:GetPlayerGravity(playerid);
native SetPlayerTeamForPlayer(forplayerid, playerid, teamid);
native GetPlayerTeamForPlayer(forplayerid, playerid);
native GetPlayerWeather(playerid);
native TogglePlayerWidescreen(playerid, bool:set);
native IsPlayerWidescreenToggled(playerid);
native GetPlayerSpawnPos(playerid, &Float:fX, &Float:fY, &Float:fZ);
native GetPlayerSkillLevel(playerid, skill);
native GetPlayerCheckpoint(playerid, &Float:fX, &Float:fY, &Float:fZ, &Float:fSize);
native GetPlayerRaceCheckpoint(playerid, &Float:fX, &Float:fY, &Float:fZ, &Float:fNextX, &Float:fNextY, &fNextZ, &Float:fSize);
native GetPlayerWorldBounds(playerid, &Float:x_max, &Float:x_min, &Float:y_max, &Float:y_min);
native IsPlayerInModShop(playerid);
native GetPlayerSirenState(playerid);
native GetPlayerGearState(playerid);
native GetPlayerHydraReactorAngle(playerid);
native Float:GetPlayerTrainSpeed(playerid);
native Float:GetPlayerZAim(playerid);
native GetPlayerSurfingOffsets(playerid, &Float:fOffsetX, &Float:fOffsetY, &Float:fOffsetZ);
native GetPlayerRotationQuat(playerid, &Float:w, &Float:x, &Float:y, &Float:z);

// Objects get - global
native GetObjectModel(objectid);
native Float:GetObjectDrawDistance(objectid);
native GetObjectAttachedData(objectid, &attached_vehicleid, &attached_objectid);
native GetObjectAttachedOffset(objectid, &Float:fX, &Float:fY, &Float:fZ, &Float:fRotX, &Float:fRotY, &Float:fRotZ);

// Objects get - player
native GetPlayerObjectModel(playerid, objectid);
native Float:GetPlayerObjectDrawDistance(playerid, objectid);
native GetPlayerObjectAttachedData(playerid, objectid, &attached_vehicleid, &attached_objectid);
native GetPlayerObjectAttachedOffset(playerid, objectid, &Float:fX, &Float:fY, &Float:fZ, &Float:fRotX, &Float:fRotY, &Float:fRotZ);

// special - for attached objects
native GetPlayerAttachedObject(playerid, index, &modelid, &bone, &Float:fX, &Float:fY, &Float:fZ, &Float:fRotX, &Float:fRotY, &Float:fRotZ, &Float:fSacleX, &Float:fScaleY, &Float:fScaleZ, &materialcolor1, &materialcolor2);

//n_ative AttachPlayerObjectToPlayer(objectplayer, objectid, attachplayer, Float:OffsetX, Float:OffsetY, Float:OffsetZ, Float:rX, Float:rY, Float:rZ);
native AttachPlayerObjectToObject(playerid, objectid, attachtoid, Float:OffsetX, Float:OffsetY, Float:OffsetZ, Float:RotX, Float:RotY, Float:RotZ, SyncRotation = 1);

// RakNet ban functions
native ClearBanList();
native IsBanned(ipaddress[]);

// Raknet
native SetTimeoutTime(playerid, time_ms);
native GetMTUSize();
native GetLocalIP(index, localip[], len = sizeof(localip));

// vehicle functions
native GetVehicleSpawnPos(vehicleid, &Float:fX, &Float:fY, &Float:fZ);
native GetVehicleColor(vehicleid, &color1, &color2);
native GetVehiclePaintjob(vehicleid);
native GetVehicleInterior(vehicleid);
native GetVehicleNumberPlate(vehicleid, plate[], len = sizeof(plate));
native SetVehicleRespawnDelay(vehicleid, delay);
native GetVehicleRespawnDelay(vehicleid);
native GetVehicleOccupiedTick(vehicleid); // GetTickCount() - GetVehicleOccupiedTick(vehicleid) = time passed since vehicle is occupied, in ms
native SetVehicleRespawnTick(vehicleid);
native GetVehicleRespawnTick(vehicleid); // GetTickCount() - GetVehicleRespawnTick(vehicleid) = time passed since vehicle spawned, in ms
native GetVehicleLastDriver(vehicleid);

// Gangzones - Global
native IsValidGangZone(zoneid);
native IsPlayerInGangZone(playerid, zoneid);
native IsGangZoneVisibleForPlayer(playerid, zoneid);
native GangZoneGetColorForPlayer(playerid, zoneid);
native GangZoneGetFlashColorForPlayer(playerid, zoneid);
native GangZoneGetPos(zoneid, &Float:fMinX, &Float:fMinY, &Float:fMaxX, &Float:fMaxY);

// Gangzones - Player
native CreatePlayerGangZone(playerid, Float:minx, Float:miny, Float:maxx, Float:maxy);
native PlayerGangZoneDestroy(playerid, zoneid);
native PlayerGangZoneShow(playerid, zoneid, color);
native PlayerGangZoneHide(playerid, zoneid);
native PlayerGangZoneFlash(playerid, zoneid, color);
native PlayerGangZoneStopFlash(playerid, zoneid);
native IsValidPlayerGangZone(playerid, zoneid);
native IsPlayerInPlayerGangZone(playerid, zoneid);
native IsPlayerGangZoneVisible(playerid, zoneid);
native PlayerGangZoneGetColor(playerid, zoneid);
native PlayerGangZoneGetFlashColor(playerid, zoneid);
native PlayerGangZoneGetPos(playerid, zoneid);

// Textdraw - Global
native IsValidTextDraw(Text:textdrawid);
native IsTextDrawVisibleForPlayer(playerid, Text:textdrawid);
native TextDrawGetString(Text:textdrawid, text[], len = sizeof(text));
native TextDrawSetPos(Text:textdrawid, Float:fX, Float:fY); // You can change textdraw pos with it, but you need to use TextDrawShowForPlayer() after that
native TextDrawGetLetterSize(Text:textdrawid, &Float:fX, &Float:fY);
native TextDrawGetFontSize(Text:textdrawid, &Float:fX, &Float:fY);
native TextDrawGetPos(Text:textdrawid, &Float:fX, &Float:fY);
native TextDrawGetColor(Text:textdrawid);
native TextDrawGetBoxColor(Text:textdrawid);
native TextDrawGetBackgroundColor(Text:textdrawid);
native TextDrawGetShadow(Text:textdrawid);
native TextDrawGetOutline(Text:textdrawid);
native TextDrawGetFont(Text:textdrawid);
native TextDrawIsBox(Text:textdrawid);
native TextDrawIsProportional(Text:textdrawid);
native TextDrawGetAlignment(Text:textdrawid);
native TextDrawGetPreviewModel(Text:textdrawid);
native TextDrawGetPreviewRot(Text:textdrawid, &Float:fRotX, &Float:fRotY, &Float:fRotZ, &Float:fZoom);
native TextDrawGetPreviewVehCol(Text:textdrawid, &color1, &color2);

// Textdraw - Player
native IsValidPlayerTextDraw(playerid, PlayerText:textdrawid);
native IsPlayerTextDrawVisible(playerid, PlayerText:textdrawid);
native PlayerTextDrawGetString(playerid, PlayerText:textdrawid, text[], len = sizeof(text));
native PlayerTextDrawSetPos(playerid, PlayerText:textdrawid, Float:fX, Float:fY);
native PlayerTextDrawGetLetterSize(playerid, PlayerText:textdrawid, &Float:fX, &Float:fY);
native PlayerTextDrawGetFontSize(playerid, PlayerText:textdrawid, &Float:fX, &Float:fY);
native PlayerTextDrawGetPos(playerid, PlayerText:textdrawid, &Float:fX, &Float:fY);
native PlayerTextDrawGetColor(playerid, PlayerText:textdrawid);
native PlayerTextDrawGetBoxColor(playerid, PlayerText:textdrawid);
native PlayerTextDrawGetBackgroundCol(playerid, PlayerText:textdrawid);
native PlayerTextDrawGetShadow(playerid, PlayerText:textdrawid);
native PlayerTextDrawGetOutline(playerid, PlayerText:textdrawid);
native PlayerTextDrawGetFont(playerid, PlayerText:textdrawid);
native PlayerTextDrawIsBox(playerid, PlayerText:textdrawid);
native PlayerTextDrawIsProportional(playerid, PlayerText:textdrawid);
native PlayerTextDrawGetAlignment(playerid, PlayerText:textdrawid);
native PlayerTextDrawGetPreviewModel(playerid, PlayerText:textdrawid);
native PlayerTextDrawGetPreviewRot(playerid, PlayerText:textdrawid, &Float:fRotX, &Float:fRotY, &Float:fRotZ, &Float:fZoom);
native PlayerTextDrawGetPreviewVehCol(playerid, PlayerText:textdrawid, &color1, &color2);

// 3D Text - Global
native IsValid3DTextLabel(Text3D:id);
native Get3DTextLabelText(Text3D:id, text[], len = sizeof(text));
native Get3DTextLabelColor(Text3D:id);
native Get3DTextLabelPos(Text3D:id, &Float:fX, &Float:fY, &Float:fZ);
native Float:Get3DTextLabelDrawDistance(Text3D:id);
native Get3DTextLabelLOS(Text3D:id);
native Get3DTextLabelVirtualWorld(Text3D:id);
native Get3DTextLabelAttachedData(Text3D:id, &attached_playerid, &attached_vehicleid);

// 3D Text - Player
native IsValidPlayer3DTextLabel(playerid, PlayerText3D:id);
native GetPlayer3DTextLabelText(playerid, PlayerText3D:id, text[], len = sizeof(text));
native GetPlayer3DTextLabelColor(playerid, PlayerText3D:id);
native GetPlayer3DTextLabelPos(playerid, PlayerText3D:id, &Float:fX, &Float:fY, &Float:fZ);
native Float:GetPlayer3DTextLabelDrawDist(playerid, PlayerText3D:id);
native GetPlayer3DTextLabelLOS(playerid, PlayerText3D:id);
native GetPlayer3DTextLabelVirtualW(playerid, PlayerText3D:id);

// Menu
native IsMenuDisabled(Menu:menuid);
native IsMenuRowDisabled(Menu:menuid, row);
native GetMenuColumns(Menu:menuid);
native GetMenuItems(Menu:menuid, column);
native GetMenuPos(Menu:menuid, &Float:fX, &Float:fY);
native GetMenuColumnWidth(Menu:menuid, column, &Float:fColumn1, &Float:fColumn2);
native GetMenuColumnHeader(Menu:menuid, column, header[], len = sizeof(header));
native GetMenuItem(Menu:menuid, column, itemid, item[], len = sizeof(item));

// Pickups
native IsValidPickup(pickupid);
native GetPickupPos(pickupid, &Float:fX, &Float:fY, &Float:fZ);
native GetPickupModel(pickupid);
native GetPickupType(pickupid);
native GetPickupVirtualWorld(pickupid);

// Y_Less's model sizes inc
native GetColCount();
native Float:GetColSphereRadius(modelid);
native GetColSphereOffset(modelid, &Float:fX, &Float:fY, &Float:fZ);

// Callbacks
forward OnPlayerEnterGangZone(playerid, zoneid);
forward OnPlayerLeaveGangZone(playerid, zoneid);
forward OnPlayerEnterPlayerGangZone(playerid, zoneid);
forward OnPlayerLeavePlayerGangZone(playerid, zoneid);

//////////////////////////////////////////////////////////////
// Fixes
//////////////////////////////////////////////////////////////

// No comment..
#if !defined IsValidVehicle
	native IsValidVehicle(vehicleid);
#endif

//native Float:GetGravity();
native GetWeather();
//native GetWeaponSlot(weaponid);

enum
{
	BS_BOOL,
	BS_CHAR,
	BS_UNSIGNEDCHAR,
	BS_SHORT,
	BS_UNSIGNEDSHORT,
	BS_INT,
	BS_UNSIGNEDINT,
	BS_FLOAT,
	BS_STRING
};

// FOR DEVELOPERS ONLY!!!!!!!!!!!!!!!!!!!!
native SendRPC(playerid, RPC, {Float,_}:...); // playerid == -1 -> broadcast
native SendData(playerid, {Float,_}:...); // playerid == -1 -> broadcast

/* EXAMPLE
CMD:pickup(playerid, params[])
{
	new
	    Float:X, Float:Y, Float:Z;
	GetPlayerPos(playerid, X, Y, Z);

    SendRPC(playerid, 95, // rpcid
		BS_INT, strval(params), // int - pickupid
		BS_INT, 1222,    // int - modelid
		BS_INT, 19,     // int   - type
		BS_FLOAT, X + 2.0,   // float
		BS_FLOAT, Y,     // float
		BS_FLOAT, Z);    // float
	return 1;
}

CMD:destroypickup(playerid, params[])
{
	SendRPC(playerid, 63, // rpcid
		BS_INT, strval(params));    // int - pickupid
	return 1;
}
*/

// Initialize plugin functions
native YSF_AddPlayer(playerid);
native YSF_RemovePlayer(playerid);
native YSF_StreamIn(playerid, forplayerid);
native YSF_StreamOut(playerid, forplayerid);

public OnPlayerConnect(playerid)
{
    YSF_AddPlayer(playerid);
    #if defined YSF_OnPlayerConnect
        return YSF_OnPlayerConnect(playerid);
    #else
    	return 1;
	#endif
}

#if defined YSF_OnPlayerConnect
	forward YSF_OnPlayerConnect(playerid);
#endif
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect YSF_OnPlayerConnect


public OnPlayerDisconnect(playerid, reason)
{
    YSF_RemovePlayer(playerid);
    #if defined YSF_OnPlayerDisconnect
        return YSF_OnPlayerDisconnect(playerid, reason);
    #else
    	return 1;
	#endif
}

#if defined YSF_OnPlayerDisconnect
	forward YSF_OnPlayerDisconnect(playerid, reason);
#endif
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect YSF_OnPlayerDisconnect

/*
//////////////////////////////////////////////
public OnPlayerStreamIn(playerid, forplayerid)
{
	YSF_StreamIn(playerid, forplayerid);
	#if defined YSF_OnPlayerStreamIn
		return YSF_OnPlayerStreamIn(playerid, forplayerid);
	#else
		return 1;
	#endif
}

#if defined YSF_OnPlayerStreamIn
	forward YSF_OnPlayerStreamIn(playerid, forplayerid);
#endif
#if defined _ALS_OnPlayerStreamIn
	#undef OnPlayerStreamIn
#else
	#define _ALS_OnPlayerStreamIn
#endif
#define OnPlayerStreamIn YSF_OnPlayerStreamIn

//////////////////////////////////////////////
public OnPlayerStreamOut(playerid, forplayerid)
{
    YSF_StreamOut(playerid, forplayerid);
    #if defined YSF_OnPlayerStreamOut
        return YSF_OnPlayerStreamOut(playerid, forplayerid);
    #else
        return 1;
    #endif
}

#if defined YSF_OnPlayerStreamOut
	forward YSF_OnPlayerStreamOut(playerid, forplayerid);
#endif
#if defined _ALS_OnPlayerStreamOut
	#undef OnPlayerStreamOut
#else
	#define _ALS_OnPlayerStreamOut
#endif
#define OnPlayerStreamOut YSF_OnPlayerStreamOut
*/
stock YSF_AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2)
{
    return AddStaticVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, (color1 == -1) ? (random(255)) : (color1), (color2 == -1) ? (random(255)) : (color2));
}
#if defined _ALS_AddStaticVehicle
	#undef AddStaticVehicle 
#else
	#define _ALS_AddStaticVehicle
#endif
#define AddStaticVehicle YSF_AddStaticVehicle

stock YSF_AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay)
{
	return AddStaticVehicleEx(modelid, spawn_x, spawn_y, spawn_z, z_angle, (color1 == -1) ? (random(255)) : (color1), (color2 == -1) ? (random(255)) : (color2), respawn_delay);
}
#if defined _ALS_AddStaticVehicleEx
	#undef AddStaticVehicleEx 
#else
	#define _ALS_AddStaticVehicleEx
#endif
#define AddStaticVehicleEx YSF_AddStaticVehicleEx

stock YSF_CreateVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay)
{
	return CreateVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, (color1 == -1) ? (random(255)) : (color1), (color2 == -1) ? (random(255)) : (color2), respawn_delay);
}
#if defined _ALS_CreateVehicle 
	#undef CreateVehicle 
#else
	#define _ALS_CreateVehicle 
#endif
#define CreateVehicle YSF_CreateVehicle

