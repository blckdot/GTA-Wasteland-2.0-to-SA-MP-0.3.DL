/*
*	Created:			26.02.11
*	Author:				Staff Coder
*	Description:			Функции
*/

#if defined _functions_included
	#endinput
#endif

#define _functions_included
#pragma library functions


native ShowVehicleBuyList(playerid,leaderplayer = 0);
native Float:PointToPoint2D(Float:x,Float:y,Float:x2,Float:y2);
native Float:PointToPoint3D(Float:x,Float:y,Float:z,Float:x2,Float:y2,Float:z2);
native IsVehicleOccupied(vehicleid);
native ChangeVehiclePrice(modelid,price);
native GetVehiclePrice(modelid);
native IsCanAddVehicleComponent(vehmodelid,componentid);
native IsNumeric(const string[]);
native F_Debug(debug = 0);
native AddPlayer(playerid);
native RemovePlayer(playerid);
native ChangePlayerState(playerid,stateid);
native Functions_SetTickRate(tick_rate = 500);
native GetTimeStamp();

//Callbacks
forward OnPlayerSpeedo(playerid);


//---------------------[PAWN Functions]--------------------------|
forward functions_PublicFunction();
public functions_PublicFunction()
{
	F_Debug(false);
	printf("");
	ShowPlayerDialog(0,0,0,"","","","");
	SendClientMessage(0,0xFFFFFFF,"");
	GetMaxPlayers();
	IsPlayerConnected(0);
	IsPlayerInVehicle(1,1);
}