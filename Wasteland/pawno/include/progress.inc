/**
 *  Progress Bar 1.3.1.0
 *  Copyright 2007-2010 Infernus' Group, modified by RayJ 12.05.2012
 *  Flavio Toribio (flavio_toibio@hotmail.com)
 */

#if defined _progress_included
	#endinput
#endif

#if !defined _samp_included
	#tryinclude <a_samp>
	#if !defined _samp_included
		#error could not locate a_samp.inc file, please check your server includes
	#endif
#endif

//#tryinclude <foreach>

#define _progress_included
#define _progress_version	0x1310

#define MAX_BARS				(3)
#define INVALID_BAR_VALUE		(Float:0xFFFFFFFF)
#define INVALID_BAR_ID			(Bar:-1)
#define pb_percent(%1,%2,%3,%4)	((%1 - 6.0) + ((((%1 + 6.0 + %2 - 2.0) - %1) / %3) * %4))
//pb_percent(x, width, max, value)

/* Pawno/Infernus Pawn Editor function list
native Bar:CreateProgressBar(playerid,Float:x, Float:y, Float:width=55.5, Float:height=3.2, color, Float:max=100.0);
native DestroyProgressBar(playerid,Bar:barid);
native ShowProgressBarForPlayer(playerid, Bar:barid);
native HideProgressBarForPlayer(playerid, Bar:barid);
native SetProgressBarValue(playerid,Bar:barid, Float:value);
native Float:GetProgressBarValue(playerid,Bar:barid);
native SetProgressBarMaxValue(playerid,Bar:barid, Float:max);
native SetProgressBarColor(playerid,Bar:barid, color);
native UpdateProgressBar(playerid,Bar:barid);
*/

forward Bar:CreateProgressBar(playerid,Float:x, Float:y, Float:width=55.5, Float:height=3.2, color, Float:max=100.0);
forward Float:GetProgressBarValue(playerid,Bar:barid);

enum e_bar
{
	Float:pb_x,
	Float:pb_y,
	Float:pb_w,
	Float:pb_h,
	Float:pb_m,
	Float:pb_v,
	PlayerText:pb_t1,
	PlayerText:pb_t2,
	PlayerText:pb_t3,
	pb_color,
	bool:pb_created
}

static Bars[MAX_PLAYERS][MAX_BARS][e_bar];

stock Bar:CreateProgressBar(playerid,Float:x, Float:y, Float:width=55.5, Float:height=3.2, color, Float:max=100.0)
{
	new
		barid;

	for(barid = 0; barid < MAX_BARS; ++barid)
		if(!Bars[playerid][barid][pb_created]) break;

	if(Bars[playerid][barid][pb_created])
		return INVALID_BAR_ID;

	new PlayerText:in_t = Bars[playerid][barid][pb_t1] = CreatePlayerTextDraw(playerid,x, y, "_");
	PlayerTextDrawUseBox		(playerid,in_t, 1);
	PlayerTextDrawTextSize	(playerid,in_t, x + width, 0.0);
	PlayerTextDrawLetterSize	(playerid,in_t, 1.0, height / 10);
	PlayerTextDrawBoxColor	(playerid,in_t, 0x00000000 | (color & 0x000000FF));

	in_t = Bars[playerid][barid][pb_t2] = CreatePlayerTextDraw(playerid,x + 1.2, y + 2.15, "_");
	PlayerTextDrawUseBox		(playerid,in_t, 1);
	PlayerTextDrawTextSize	(playerid,in_t, x + width - 2.0, 0.0);
	PlayerTextDrawLetterSize	(playerid,in_t, 1.0, height / 10 - 0.35);
	PlayerTextDrawBoxColor	(playerid,in_t, (color & 0xFFFFFF00) | (0x66 & ((color & 0x000000FF) / 2)));

	in_t = Bars[playerid][barid][pb_t3] = CreatePlayerTextDraw(playerid,x + 1.2, y + 2.15, "_");
	PlayerTextDrawTextSize	(playerid,in_t, pb_percent(x, width, max, 1.0), 0.0);
	PlayerTextDrawLetterSize	(playerid,in_t, 1.0, height / 10 - 0.35);
	PlayerTextDrawBoxColor	(playerid,in_t, color);

	Bars[playerid][barid][pb_x] = x;
	Bars[playerid][barid][pb_y] = y;
	Bars[playerid][barid][pb_w] = width;
	Bars[playerid][barid][pb_h] = height;
	Bars[playerid][barid][pb_m] = max;
	Bars[playerid][barid][pb_color] = color;
	Bars[playerid][barid][pb_created] = true;
	return Bar:barid;
}

stock DestroyProgressBar(playerid,Bar:barid)
{
	if(barid != INVALID_BAR_ID && Bar:-1 < barid < Bar:MAX_BARS)
	{
		if(!Bars[playerid][_:barid][pb_created])
			return 0;

		PlayerTextDrawDestroy(playerid,Bars[playerid][_:barid][pb_t1]);
		PlayerTextDrawDestroy(playerid,Bars[playerid][_:barid][pb_t2]);
		PlayerTextDrawDestroy(playerid,Bars[playerid][_:barid][pb_t3]);

		Bars[playerid][_:barid][pb_t1] = PlayerText:0;
		Bars[playerid][_:barid][pb_t2] = PlayerText:0;
		Bars[playerid][_:barid][pb_t3] = PlayerText:0;
		Bars[playerid][_:barid][pb_x] = 0.0;
		Bars[playerid][_:barid][pb_y] = 0.0;
		Bars[playerid][_:barid][pb_w] = 0.0;
		Bars[playerid][_:barid][pb_h] = 0.0;
		Bars[playerid][_:barid][pb_m] = 0.0;
		Bars[playerid][_:barid][pb_v] = 0.0;
		Bars[playerid][_:barid][pb_color] = 0;
		Bars[playerid][_:barid][pb_created] = false;
		return 1;
	}
	return 0;
}

stock ShowProgressBarForPlayer(playerid, Bar:barid)
{
	if(IsPlayerConnected(playerid) && barid != INVALID_BAR_ID && Bar:-1 < barid < Bar:MAX_BARS)
	{
		if(!Bars[playerid][_:barid][pb_created])
			return 0;

		PlayerTextDrawShow(playerid, Bars[playerid][_:barid][pb_t1]);
		PlayerTextDrawShow(playerid, Bars[playerid][_:barid][pb_t2]);
		PlayerTextDrawShow(playerid, Bars[playerid][_:barid][pb_t3]);
		return 1;
	}
	return 0;
}

stock HideProgressBarForPlayer(playerid, Bar:barid)
{
	if(IsPlayerConnected(playerid) && barid != INVALID_BAR_ID && Bar:-1 < barid < Bar:MAX_BARS)
	{
		if(!Bars[playerid][_:barid][pb_created])
			return 0;

		PlayerTextDrawHide(playerid, Bars[playerid][_:barid][pb_t1]);
		PlayerTextDrawHide(playerid, Bars[playerid][_:barid][pb_t2]);
		PlayerTextDrawHide(playerid, Bars[playerid][_:barid][pb_t3]);
		return 1;
	}
	return 0;
}

stock SetProgressBarValue(playerid,Bar:barid, Float:value)
{
	if(barid == INVALID_BAR_ID || Bar:MAX_BARS < barid < Bar:-1)
		return 0;

	if(Bars[playerid][_:barid][pb_created])
	{
		value =
			(value < 0.0) ? (0.0) : (value > Bars[playerid][_:barid][pb_m]) ? (Bars[playerid][_:barid][pb_m]) : (value);

		PlayerTextDrawUseBox(playerid,Bars[playerid][_:barid][pb_t3], value > 0.0);

        Bars[playerid][_:barid][pb_v] = value;

		PlayerTextDrawTextSize(playerid,Bars[playerid][_:barid][pb_t3],
			pb_percent(Bars[playerid][_:barid][pb_x], Bars[playerid][_:barid][pb_w], Bars[playerid][_:barid][pb_m], value), 0.0);

		return 1;
	}
	return 0;
}

stock Float:GetProgressBarValue(playerid,Bar:barid)
{
	if(barid == INVALID_BAR_ID || Bar:MAX_BARS < barid < Bar:-1)
		return INVALID_BAR_VALUE;

	if(Bars[playerid][_:barid][pb_created])
		return Bars[playerid][_:barid][pb_v];

	return INVALID_BAR_VALUE;
}

stock SetProgressBarMaxValue(playerid,Bar:barid, Float:max)
{
	if(barid == INVALID_BAR_ID || Bar:MAX_BARS < barid < Bar:-1)
		return 0;

	if(Bars[playerid][_:barid][pb_created])
	{
		Bars[playerid][_:barid][pb_m] = max;
		SetProgressBarValue(playerid,barid, Bars[playerid][_:barid][pb_v]);
		return 1;
	}
	return 0;
}

stock SetProgressBarColor(playerid,Bar:barid, color)
{
	if(barid == INVALID_BAR_ID || Bar:MAX_BARS < barid < Bar:-1)
		return 0;

	if(Bars[playerid][_:barid][pb_created])
	{
		Bars[playerid][_:barid][pb_color] = color;
		PlayerTextDrawColor(playerid,Bars[playerid][_:barid][pb_t1], 0x00000000 | (color & 0x000000FF));

		PlayerTextDrawColor(playerid,Bars[playerid][_:barid][pb_t2],
			(color & 0xFFFFFF00) | (0x66 & ((color & 0x000000FF) / 2)));

		PlayerTextDrawColor(playerid,Bars[playerid][_:barid][pb_t3], color);
		return 1;
	}
	return 0;
}


stock UpdateProgressBar(playerid,Bar:barid)
{
	return ShowProgressBarForPlayer(playerid, barid);
}