/*
 * SA-MP Spike Strips
 *
 * Copyright (c) 2013, Stylock
 * This file is provided as is with no warranties of any kind.
 */

#define MAX_SPIKE_STRIPS	(128)
#define SS_TIME_INTERVAL	(250)
#define SS_LINE_SEGMENTS	(2) // 1, 2 or 4

// Spike strip models
#define SPIKE_STRIP_LONG	(2892)
#define SPIKE_STRIP_SHORT	(2899)

// Forwards
forward OnSpikeStripPopTire(spikeid, vehicleid, playerid, tire);

/*
native SpikeStrip_Create(mid, Float:x, Float:y, Float:z, Float:a);
*/

stock SpikeStrip_Create(mid, Float:x, Float:y, Float:z, Float:a)
{
	return CallRemoteFunction("SpikeStrip_Create_MA", "iffff", mid, x, y, z, a);
}

/*
native SpikeStrip_Delete(sid);
*/

stock SpikeStrip_Delete(sid)
{
	return CallRemoteFunction("SpikeStrip_Delete_MA", "i", sid);
}

/*
native SpikeStrip_DeleteAll();
*/

stock SpikeStrip_DeleteAll()
{
	return CallRemoteFunction("SpikeStrip_DeleteAll_MA", "");
}

/*
native SpikeStrip_IsValid(sid);
*/

stock SpikeStrip_IsValid(sid)
{
	return CallRemoteFunction("SpikeStrip_IsValid_MA", "i", sid);
}

/*
native SpikeStrip_GetObjectID(sid);
*/

stock SpikeStrip_GetObjectID(sid)
{
	return CallRemoteFunction("SpikeStrip_GetObjectID_MA", "i", sid);
}


/*
native SpikeStrip_SetGhost(pid, bool:toggle);
*/

stock SpikeStrip_SetGhost(pid, bool:toggle)
{
	return CallRemoteFunction("SpikeStrip_SetGhost_MA", "ii", pid, toggle);
}

/*
native SpikeStrip_IsGhost(pid);
*/

stock SpikeStrip_IsGhost(pid)
{
	return CallRemoteFunction("SpikeStrip_IsGhost_MA", "i", pid);
}