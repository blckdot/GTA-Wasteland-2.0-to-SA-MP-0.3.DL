/*
* Foreach Include by Dimazzz based on lists.
*/
 
#include <memory>
#include <list>


#define foreach(new%0:%1) for(new ListIt:%0@_ = ListIt:%1[LIST_base_end], %0; _:%0@_ != 0; %0@_ = ListIt:MEM_EX::get_val(Pointer:(%0@_)->LIST_IT_data_previous)) if((%0 = MEM_EX::get_val(LIST_IT_data_ptr(%0@_)->0)) >= 0)

#define Iterator:%0<%1> LIST_init<%0> // преобразовываем старый вариант в новый
//#define Iterator:%0 LIST_init<%0>


#define Iter_Add Itter_Add
stock Itter_Add(List:list[], value)
{
	LIST_push_back(list, value);
	return 1;
}

#define Iter_Remove Itter_Remove
stock Itter_Remove(List:list[], value)
{
	new ListIt:idx = LIST_find(list, value);
	if(_:idx != 0)
	{ 
		LIST_erase(list, idx);
		return 1;
	}
	return 0;
}

#define Iter_Clear Itter_Clear
stock Itter_Clear(List:list[])
{
	LIST_clear(list);
	return 1;
}

#define Iter_Count Itter_Count
stock Itter_Count(List:list[]) 
{
	return LIST_count_nodes(list);
}

#define Iter_Free Itter_Free
stock Itter_Free(List:list[]) 
{
	return LIST_count_nodes(list);
}

#define Iter_Contains Itter_Contains
stock Itter_Contains(List:list[], value)
{
	new ListIt:idx = LIST_find(list, value);
	if(_:idx != 0)
	{
		return 1;
	}
	return 0;
}

// Player
/*
new Iterator:Player<MAX_PLAYERS>;
public OnPlayerConnect(playerid)
{
	if(!IsPlayerNPC(playerid))
	{
		Itter_Add(Player, playerid);
	}

	#if defined Itter_OnPlayerConnect
		return Itter_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Itter_OnPlayerConnect
#if defined Itter_OnPlayerConnect
	forward Itter_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	#if defined Itter_OnPlayerDisconnect
		Itter_OnPlayerDisconnect(playerid, reason);
	#endif

	Itter_Remove(Player, playerid);

	return 1;
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect Itter_OnPlayerDisconnect
#if defined Itter_OnPlayerDisconnect
	forward Itter_OnPlayerDisconnect(playerid, reason);
#endif
*/