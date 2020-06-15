/*  Callback Dialogs
 *
 *  (c) Copyright 2014, Dimazzz
 *
 */

#if defined _cdialog_included
	#endinput
#endif
#define _cdialog_included
#pragma library cdialog

#include <memory>

#define CALLBACK_DIALOG_ID 	32767 	// ID диалога с которым будем работать.
#define MAX_CALLBACK_NAME 	32 	// Максимальная длина имена колбэка.

#define Dialog:%1(%2)          			\
			forward %1(%2); 		\
			public %1(%2)
#if !defined isnull
	#define isnull(%1)	((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

Dialog_ShowCallback(playerid, callback[], style, name[], text[], button1[], button2[]) 
{
	new 
		Pointer:mem = MEM::malloc(MAX_CALLBACK_NAME) // выделяем память
	; 
	if(_:mem != NULL) 
	{
		MEM::set_arr(mem, _, callback, MAX_CALLBACK_NAME); // заносим название колбэка в память
		SetPVarInt(playerid, "cdialogmem", _:mem); // заносим индекс памяти игроку в PVar
	}
	else
	{
		print("[ERROR]: Failed to allocate memory for \"c_Dialog\"!");
		return 0;
	}
	SetPVarString(playerid, "lastDialog", callback);
	ShowPlayerDialog(playerid, CALLBACK_DIALOG_ID, style, name, text, button1, button2); // показываем диалоговое окно
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == CALLBACK_DIALOG_ID && GetPVarType(playerid, "cdialogmem"))
	{
		new 
			Pointer:mem = Pointer:GetPVarInt(playerid, "cdialogmem"), // получаем индекс памяти
			callback[MAX_CALLBACK_NAME]
		;
		MEM::get_arr(mem, _, callback); // берем название колбэка из памяти
		MEM::free(mem); // очищаем память
		DeletePVar(playerid, "cdialogmem"); // удаляем PVar
		if(isnull(inputtext)) CallLocalFunction(callback,"iiiis", playerid, dialogid, response, listitem, "\1"); // вызываем колбэк
		else CallLocalFunction(callback,"iiiis", playerid, dialogid, response, listitem, inputtext); // вызываем колбэк
		return 1; 
	}
	else if(GetPVarType(playerid, "cdialogmem")) // если ид диалога другой, а в памяти есть колбэк удаляем его
	{
		#if defined SECURE_MEMORY_PLUGIN // если включен безопасный режим memory access plugin'a
			if(MEM::is(Pointer:GetPVarInt(playerid, "cdialogmem"))) 
			{
				MEM::free(Pointer:GetPVarInt(playerid, "cdialogmem")); // очищаем память
			}
		#else
			MEM::free(Pointer:GetPVarInt(playerid, "cdialogmem")); // очищаем память
		#endif
		DeletePVar(playerid, "cdialogmem"); // удаляем PVar
	}
	
	
	#if defined cDialog_OnDialogResponse
		return cDialog_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}

public OnPlayerDisconnect(playerid, reason)
{
	if(GetPVarType(playerid, "cdialogmem")) // если индекс остался в PVar.
	{
		#if defined SECURE_MEMORY_PLUGIN // если включен безопасный режим memory access plugin'a
			if(MEM::is(Pointer:GetPVarInt(playerid, "cdialogmem"))) 
			{
				MEM::free(Pointer:GetPVarInt(playerid, "cdialogmem")); // очищаем память
			}
		#else
			MEM::free(Pointer:GetPVarInt(playerid, "cdialogmem")); // очищаем память
		#endif
		DeletePVar(playerid, "cdialogmem"); // удаляем PVar
	}

	#if defined cDialog_OnPlayerDisconnect
		return cDialog_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}



// Hooks
#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif
#define OnDialogResponse cDialog_OnDialogResponse
#if defined cDialog_OnDialogResponse
	forward cDialog_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect cDialog_OnPlayerDisconnect
#if defined cDialog_OnPlayerDisconnect
	forward OnPlayerDisconnect(playerid, reason);
#endif