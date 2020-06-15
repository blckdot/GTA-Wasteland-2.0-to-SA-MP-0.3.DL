#define MAX_BUTTONS		100
#define MAX_DISTANCE		1.3
#define OBJECT			2922
#define SOUND           		1083

#define INVALID_BUTTON_ID   -1

new LAST_BUTTON_ID = 1;

enum BUTTON_INFOS
{
	bool:Created,
	bool:Moving,
	bool:Usable[MAX_PLAYERS],
	Float:butPos[4],
	ObjectID
}
new ButtonInfo[MAX_BUTTONS+1][BUTTON_INFOS];
forward OnPlayerPressButton(playerid,buttonid);
Float:Distance3D(Float:PointA[], Float:PointB[], bool:sqrt = true)
{
	new Float:Dist[4];

	for (new i = 0; i < 3; i++)
	{
		Dist[i] = PointA[i] - PointB[i];
		Dist[i] *= Dist[i];
	}

	Dist[3] = Dist[0] + Dist[1] + Dist[2];

	return sqrt ? floatsqroot(Dist[3]) : Dist[3];
}
Float:Angle2D(Float:PointA[], Float:PointB[])
{
	new bool:A_LS_B[2], Float:Dist[2], Float:Angle;

	for (new i = 0; i < 2; i++)
	{
		A_LS_B[i] = PointA[i] < PointB[i];
		Dist[i] = A_LS_B[i] ? PointB[i] - PointA[i] : PointA[i] - PointB[i];
	}

	Angle = atan2(Dist[1],Dist[0]);
	Angle = A_LS_B[0] ? 270.0 + Angle : 90.0 - Angle;
	Angle = A_LS_B[1] ? Angle : 180.0 - Angle;

	return Angle;
}
stock GetClosestButton(Float:Point[], &Float:Distance = 0.0)
{
	new Closest = INVALID_BUTTON_ID, Float:Distance2 = 100000.0;

	for (new buttonid = 1, highest = GetHighestButtonID(); buttonid <= highest; buttonid ++)
	{
		if (ButtonInfo[buttonid][Created])
		{
			Distance = Distance3D(Point, ButtonInfo[buttonid][butPos]);

			if (Distance < Distance2)
			{
				Distance2 = Distance;
				Closest = buttonid;
			}
		}
	}

	Distance = Distance2;

	return Closest;
}
stock CreateButton(Float:X, Float:Y, Float:Z, Float:Angle, bool:object = true)
{
	new buttonid = LAST_BUTTON_ID;

	LAST_BUTTON_ID++;

	if(object) ButtonInfo[buttonid][ObjectID]	= CreateDynamicObject(OBJECT,X,Y,Z,0.0,0.0,Angle);
	ButtonInfo[buttonid][butPos][0]	= X;
	ButtonInfo[buttonid][butPos][1]	= Y;
	ButtonInfo[buttonid][butPos][2]	= Z;
	ButtonInfo[buttonid][butPos][3]	= Angle;
	ButtonInfo[buttonid][Moving]	= false;
	ButtonInfo[buttonid][Created]	= true;

	for (new playerid = 0; playerid < MAX_PLAYERS; playerid ++)
		ButtonInfo[buttonid][Usable][playerid] = true;

	return buttonid;
}
stock DestroyButton(buttonid)
{
	if (IsValidButton(buttonid))
	{
		CallRemoteFunction("OnButtonDestroyed", "i", buttonid);
		ButtonInfo[buttonid][Created] = false;
		DestroyDynamicObject(ButtonInfo[buttonid][ObjectID]);
	}
}
stock SetButtonPos(buttonid, Float:X, Float:Y, Float:Z, Float:Angle)
{
	if (IsValidButton(buttonid))
	{
		new objectid = ButtonInfo[buttonid][ObjectID];
		SetObjectPos(objectid, X, Y, Z);
		SetObjectRot(objectid, 0.0, 0.0, Angle);
		ButtonInfo[buttonid][butPos][0] = X;
		ButtonInfo[buttonid][butPos][1] = Y;
		ButtonInfo[buttonid][butPos][2] = Z;
		ButtonInfo[buttonid][butPos][3] = Angle;
	}
}
stock MoveButton(buttonid, Float:X, Float:Y, Float:Z, Float:Speed)
{
	if (IsValidButton(buttonid))
	{
		MoveDynamicObject(ButtonInfo[buttonid][ObjectID], X, Y, Z, Speed);
		ButtonInfo[buttonid][Moving] = true;
		ButtonInfo[buttonid][butPos][0] = 99999.9;
		ButtonInfo[buttonid][butPos][1] = 99999.9;
		ButtonInfo[buttonid][butPos][2] = 99999.9;
	}
}
stock StopButton(buttonid)
{
	if (IsValidButton(buttonid))
		StopDynamicObject(ButtonInfo[buttonid][ObjectID]);
}
//forward bool:IsValidButton(buttonid);
stock /*bool:*/IsValidButton(buttonid)
{
	return (buttonid <= MAX_BUTTONS && ButtonInfo[buttonid][Created]);
}
forward GetHighestButtonID();
public GetHighestButtonID()
{
	return (LAST_BUTTON_ID-1);
}
forward GetButtonObjectID(buttonid);
public GetButtonObjectID(buttonid)
{
	return IsValidButton(buttonid) ? ButtonInfo[buttonid][ObjectID] : INVALID_OBJECT_ID;
}
forward GetObjectButtonID(objectid);
public GetObjectButtonID(objectid)
{
	for (new buttonid = 1, highest = GetHighestButtonID(); buttonid <= highest; buttonid ++)
		if (ButtonInfo[buttonid][Created] && ButtonInfo[buttonid][ObjectID] == objectid && ButtonInfo[buttonid][ObjectID] != 0)
			return buttonid;

	return INVALID_BUTTON_ID;
}
stock Float:GetDistanceToButton(buttonid, Float:X, Float:Y, Float:Z)
{
	if (IsValidButton(buttonid))
	{
		new Float:Point[3];

		Point[0] = X;
		Point[1] = Y;
		Point[2] = Z;

		return Distance3D(Point, ButtonInfo[buttonid][butPos]);
	}

	return -1.0;
}
stock TeleportPlayerToButton(playerid, buttonid)
{
	if (IsValidButton(buttonid) && !ButtonInfo[buttonid][Moving])
	{
		new Float:Angle = ButtonInfo[buttonid][butPos][3];

		SetPlayerPos
		(
			playerid,
			ButtonInfo[buttonid][butPos][0] - (0.65 * floatsin(-Angle,degrees)),
			ButtonInfo[buttonid][butPos][1] - (0.65 * floatcos(-Angle,degrees)),
			ButtonInfo[buttonid][butPos][2] - 0.63
		);

		SetPlayerFacingAngle(playerid, -Angle);
		SetCameraBehindPlayer(playerid);
	}
}
stock ToggleButtonEnabledForPlayer(playerid, buttonid, bool:enabled)
{
	if (IsValidButton(buttonid))
		ButtonInfo[buttonid][Usable][playerid] = enabled;
}
stock ToggleButtonEnabled(buttonid, bool:enabled)
{
	if (IsValidButton(buttonid))
		for (new playerid = 0; playerid < MAX_PLAYERS; playerid ++)
			ButtonInfo[buttonid][Usable][playerid] = enabled;
}
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if (newkeys & 16)
		{
			new Float:Distance, Float:Angle, Float:PlayerPos[3], buttonid;

			GetPlayerPos(playerid, PlayerPos[0], PlayerPos[1], PlayerPos[2]);

			buttonid = GetClosestButton(PlayerPos, Distance);

			if (buttonid != INVALID_BUTTON_ID && ButtonInfo[buttonid][Usable][playerid] && Distance <= MAX_DISTANCE)
			{
				Angle = Angle2D(PlayerPos, ButtonInfo[buttonid][butPos]);

				SetPlayerFacingAngle(playerid, Angle);

				SetPlayerPos
				(
					playerid,
					ButtonInfo[buttonid][butPos][0] - (0.65 * floatsin(-Angle,degrees)),
					ButtonInfo[buttonid][butPos][1] - (0.65 * floatcos(-Angle,degrees)),
					ButtonInfo[buttonid][butPos][2] - 0.63
				);

				ApplyAnimation(playerid, "HEIST9", "Use_SwipeCard", 10.0, 0, 0, 0, 0, 0);
				SetTimerEx("OnPlayerPressButton", 500, false, "ii", playerid, buttonid);
			}
		}
	}
	#if defined YUM_OnPlayerKeyStateChange
		return YUM_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange YUM_OnPlayerKeyStateChange
#if defined YUM_OnPlayerKeyStateChange
	forward YUM_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif
public OnObjectMoved(objectid)
{
	new buttonid = GetObjectButtonID(objectid);

	if (buttonid != INVALID_BUTTON_ID)
	{
		new Float:ObjectPos[3];
		GetObjectPos(objectid, ObjectPos[0], ObjectPos[1], ObjectPos[2]);
		ButtonInfo[buttonid][butPos][0] = ObjectPos[0];
		ButtonInfo[buttonid][butPos][1] = ObjectPos[1];
		ButtonInfo[buttonid][butPos][2] = ObjectPos[2];
		ButtonInfo[buttonid][Moving] = false;
		CallRemoteFunction("OnButtonMoved", "i", buttonid);
	}
	#if defined YUM_OnObjectMoved
		YUM_OnObjectMoved(objectid);
	#endif
}
#if defined _ALS_OnObjectMoved
	#undef OnObjectMoved
#else
	#define _ALS_OnObjectMoved
#endif
#define OnObjectMoved YUM_OnObjectMoved
#if defined YUM_OnObjectMoved
	forward YUM_OnObjectMoved(objectid);
#endif

public OnGameModeExit()
{
	for (new buttonid = 1; buttonid <= MAX_BUTTONS; buttonid ++)
		if (ButtonInfo[buttonid][Created])
			DestroyButton(buttonid);
	#if defined YUM_OnGameModeExit
		YUM_OnGameModeExit();
	#endif
	return 1;
}
#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
#define OnGameModeExit YUM_OnGameModeExit
#if defined YUM_OnGameModeExit
	forward YUM_OnGameModeExit();
#endif