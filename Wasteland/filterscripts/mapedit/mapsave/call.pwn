public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    switch( dialogid ) {
        case DIALOGID_MAP_SAVE_AS: {
            if( !response ) {
                return 1;
            }

            new
                objects_saved,
                vehicles_saved,
                pickups_saved,
                actors_saved,
                attachments_saved,
                buildings_saved,
                save_success
            ;

            save_success = SaveMap(
                .mapname = inputtext,
                .objects_saved = objects_saved,
                .vehicles_saved = vehicles_saved,
                .pickups_saved = pickups_saved,
                .actors_saved = actors_saved,
                .attachments_saved = attachments_saved,
                .buildings_saved = buildings_saved,
                .playerid = playerid
            );

            if( !save_success ) {
                SendClientMessage(playerid, RGBA_RED, "ERROR: Карта не может быть сохранена!");
                ShowMapSaveDialog(playerid, dialogid);
                return 1;
            }

            if( GetMapID(inputtext) == INVALID_MAP_ID ) {
                CreateMapID(.mapname = inputtext);
            }

            format(g_ClientMessage, sizeof g_ClientMessage, "[%i] %s сохранил карту под названием: %s", playerid, ret_GetPlayerName(playerid), inputtext);
            SendClientMessageToAll(RGBA_WHITE, g_ClientMessage);
                
            format(g_ClientMessage, sizeof g_ClientMessage, "Сохранено: %i Объектов(s), %i Автомобилей(s), %i Пикапов(s), %i Актеров(s), %i Зданий.", objects_saved, vehicles_saved, pickups_saved, buildings_saved);
            SendClientMessageToAll(RGBA_WHITE, g_ClientMessage);
                
            if( attachments_saved > 0 ) {
                format(g_ClientMessage, sizeof g_ClientMessage, "+ %i ваших аттачей.", attachments_saved);
                SendClientMessage(playerid, RGBA_WHITE, g_ClientMessage);
            }
            return 1;
        }
        case DIALOGID_MAP_SAVE_CONFIRM: {
            if( !response ) {
                return 1;
            }
            
            if( g_MapLoadedID == INVALID_MAP_ID ) {
                SendClientMessage(playerid, RGBA_RED, "ERROR: Карта не была загружена!");
                ShowMapSaveDialog(playerid, dialogid);
                return 1;
            }

            if( isempty(inputtext) || strcmp(inputtext, SAVEMAP_COMMAND, true) != 0 ) {
                SendClientMessage(playerid, RGBA_RED, "ERROR: Вы ввели неверную комманду к текстовом поле!");
                ShowMapSaveDialog(playerid, dialogid);
                return 1;
            }

            GetMapName(g_MapLoadedID, g_MapString, sizeof g_MapString);

            new
                objects_saved,
                vehicles_saved,
                pickups_saved,
                actors_saved,
                attachments_saved,
                buildings_saved,
                save_success
            ;

            save_success = SaveMap(
                .mapname = g_MapString,
                .objects_saved = objects_saved,
                .vehicles_saved = vehicles_saved,
                .pickups_saved = pickups_saved,
                .actors_saved = actors_saved,
                .attachments_saved = attachments_saved,
                .buildings_saved = buildings_saved,
                .playerid = playerid
            );

            if( !save_success ) {
                SendClientMessage(playerid, RGBA_RED, "ERROR: Карта не может быть сохранена!");
                ShowMapSaveDialog(playerid, dialogid);
                return 1;
            }

            format(g_ClientMessage, sizeof g_ClientMessage, "[%i] %s сохранил карту.", playerid, ret_GetPlayerName(playerid));
            SendClientMessageToAll(RGBA_WHITE, g_ClientMessage);

            format(g_ClientMessage, sizeof g_ClientMessage, "Сохранено: %i Объектов, %i Автомобилей, %i Пикапов, %i Актеров, %i Зданий.", objects_saved, vehicles_saved, pickups_saved, actors_saved, buildings_saved);
            SendClientMessageToAll(RGBA_WHITE, g_ClientMessage);

            if( attachments_saved > 0 ) {
                format(g_ClientMessage, sizeof g_ClientMessage, "+ %i ваших аттачей", attachments_saved);
                SendClientMessage(playerid, RGBA_WHITE, g_ClientMessage);
            }
            return 1;
        }
    }

    #if defined msave_OnDialogResponse
        return msave_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
    #else
        return 0;
    #endif
}
#if defined _ALS_OnDialogResponse
    #undef OnDialogResponse
#else
    #define _ALS_OnDialogResponse
#endif
#define OnDialogResponse msave_OnDialogResponse
#if defined msave_OnDialogResponse
    forward msave_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif
