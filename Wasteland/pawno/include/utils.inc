ReturnUser(text[], playerid = INVALID_PLAYER_ID)
{
	new pos = 0;
	while (text[pos] < 0x21) // Strip out leading spaces
	{
		if (text[pos] == 0) return INVALID_PLAYER_ID; // No passed text
		pos++;
	}
	new userid = INVALID_PLAYER_ID;
	if (IsNumeric(text[pos])) // Check whole passed string
	{
		userid = strval(text[pos]);
		if (userid >=0 && userid < MAX_PLAYERS)
		{
			if(!IsPlayerConnected(userid)) userid = INVALID_PLAYER_ID; 
			else return userid; // A player was found
			
		}
	}
	new len = strlen(text[pos]);
	new count = 0;
	new name[MAX_PLAYER_NAME];
	for (new i = 0; i < MAX_PLAYERS; i++)
	{
		if (IsPlayerConnected(i))
		{
			GetPlayerName(i, name, sizeof (name));
			if (strcmp(name, text[pos], true, len) == 0) // Check segment of name
			{
				if (len == strlen(name)) return i;
				else // Partial match
				{
					count++;
					userid = i;
				}
			}
		}
	}
	if (count != 1)
	{
		if (playerid != INVALID_PLAYER_ID)
		{
			if (count) SendClientMessage(playerid, 0xFF0000AA, "Multiple users found, please narrow earch"); 
			else SendClientMessage(playerid, 0xFF0000AA, "No matching user found");
			
		}
		userid = INVALID_PLAYER_ID;
	}
	return userid; // INVALID_USER_ID for bad return
}