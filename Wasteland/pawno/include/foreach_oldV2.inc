new 
	num_players = -1,
	Pointer:player_mem
;
static 
	MaxPlayers = MAX_PLAYERS;

enum _:struct_mem_foreach
{
	Pointer:mem_pointer, last_slot, max_slot
}
#define Iterator:%0<%1> Iterator:%0[struct_mem_foreach] = {Pointer:0, -1, %1}
#define IteratorArray:%0<%1> Iterator:%0[struct_mem_foreach]
//static const player_array[MAX_PLAYERS] = {-1, ...};
#define pforeach(%0) for(new %0_it=0,%0=MEM_get_val(player_mem,%0_it);%0_it<=num_players;++%0_it,%0 = MEM_get_val(player_mem, %0_it))
#define foreach(%0:%1) for(new %0_it=0,%0=MEM_get_val(%1[mem_pointer],%0_it);%0_it<=%1[last_slot];++%0_it,%0 = MEM_get_val(%1[mem_pointer], %0_it))

#define Iter_Add Itter_Add
stock Itter_Add(Iterator:iter[], value)
{
	if(iter[mem_pointer] == Pointer:0) return 0;
	MEM::set_val(iter[mem_pointer], ++iter[last_slot], value);
	MEM::sort(iter[mem_pointer], _, iter[max_slot], MEM_E_sort_reverse);
	return 1;
}

#define Iter_Remove Itter_Remove
stock Itter_Remove(Iterator:iter[], value)
{
	if(iter[mem_pointer] == Pointer:0) return 0;
	foreach(i:iter)
	{
		if(i == value)
		{
			MEM_set_val(iter[mem_pointer], i_it, -1);
			MEM::sort(iter[mem_pointer], _, iter[max_slot], MEM_E_sort_reverse);
			break;
		}
	}
	--iter[last_slot];
	return 0;
}

#define Iter_Clear Itter_Clear
stock Itter_Clear(Iterator:iter[])
{
	if(iter[mem_pointer] == Pointer:0) return 0;
	MEM::free(iter[mem_pointer]);
	iter[mem_pointer] = Pointer:0;
	iter[last_slot] = -1;
	return 1;
}

#define Iter_Count Itter_Count
stock Itter_Count(Iterator:iter[]) 
{
	return iter[last_slot];
}

#define Iter_Free Itter_Free
stock Itter_Free(Iterator:iter[]) 
{
	return iter[last_slot];
}

#define Iter_Contains Itter_Contains
stock Itter_Contains(Iterator:iter[], value)
{
	if(iter[mem_pointer] == Pointer:0) return 0;
	foreach(i:iter)
	{
		if(i == value)
		{
			return 1;
		}
	}
	return 0;
}

#define Iter_Init Itter_Init
stock Itter_Init(Iterator:iter[], max)
{
	iter[max_slot] = max;
	iter[last_slot] = -1;
	iter[mem_pointer] = MEM::malloc(max);
	for(new i;i<max;++i) MEM::set_val(iter[mem_pointer], i, -1);
	return 0;
}

public OnGameModeInit()
{
	MaxPlayers = GetMaxPlayers();
	player_mem = MEM::malloc(MaxPlayers);
	for(new i;i<MaxPlayers;++i) MEM::set_val(player_mem, i, -1);

	#if defined pforeach_OnGameModeInit
		return pforeach_OnGameModeInit();
	#else
		return 1;
	#endif
}
public OnGameModeExit()
{
	MEM::free(player_mem);

	#if defined pforeach_OnGameModeExit
		return pforeach_OnGameModeExit();
	#else
		return 1;
	#endif
}
public OnPlayerConnect(playerid)
{
	MEM::set_val(player_mem, ++num_players, playerid);
	MEM::sort(player_mem, _, MaxPlayers, MEM_E_sort_reverse);

	#if defined pforeach_OnPlayerConnect
		return pforeach_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
public OnPlayerDisconnect(playerid, reason)
{
	SetTimerEx("foreachRemovePlayer", 10, false, "i", playerid);

	#if defined pforeach_OnPlayerDisconnect
		return pforeach_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}
forward foreachRemovePlayer(playerid);
public foreachRemovePlayer(playerid)
{
	pforeach(i)
	{
		if(i == playerid)
		{
			MEM_set_val(player_mem, i_it, -1);
			MEM::sort(player_mem, _, MaxPlayers, MEM_E_sort_reverse);
			break;
		}
	}
	--num_players;
}
// ALS HOOKS
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit pforeach_OnGameModeInit

#if defined pforeach_OnGameModeInit
	forward pforeach_OnGameModeInit();
#endif

#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif

#define OnGameModeExit pforeach_OnGameModeExit

#if defined pforeach_OnGameModeExit
	forward pforeach_OnGameModeExit();
#endif

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect pforeach_OnPlayerConnect

#if defined pforeach_OnPlayerConnect
	forward pforeach_OnPlayerConnect(playerid);
#endif

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect pforeach_OnPlayerDisconnect

#if defined pforeach_OnPlayerDisconnect
	forward pforeach_OnPlayerDisconnect(playerid, reason);
#endif
