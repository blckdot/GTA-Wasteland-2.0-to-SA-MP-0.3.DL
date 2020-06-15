public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    switch( dialogid ) {
        case DIALOGID_MAP_LOAD: {
            if( !response ) {
                return 1;
            }

            if( isempty(inputtext) ) {
                SendClientMessage(playerid, RGBA_RED, "ERROR: Пустое текстовое поле!");
                ShowMapLoadDialog(playerid, dialogid);
                return 1;
            }

            new
                objects_loaded,
                vehicles_loaded,
                pickups_loaded,
                actors_loaded,
                attachments_loaded,
                buildings_loaded,
                load_success
            ;

            load_success = MapLoad(
                .mapname = inputtext,
                .objects_loaded = objects_loaded,
                .vehicles_loaded = vehicles_loaded,
                .pickups_loaded = pickups_loaded,
                .actors_loaded = actors_loaded,
                .attachments_loaded = attachments_loaded,
                .buildings_loaded = buildings_loaded,
                .playerid = playerid
            );

            if( !load_success ) {
                SendClientMessage(playerid, RGBA_RED, "ERROR: Карта не может быть загружена!");
                ShowMapLoadDialog(playerid, dialogid);
                return 1;
            }

            if( GetMapID(inputtext) == INVALID_MAP_ID ) {
                CreateMapID(inputtext);
            }

            g_MapLoadedID = GetMapID(inputtext);
            RefreshMapLoadedTextdraw();

            format(g_ClientMessage, sizeof g_ClientMessage, "[%i] %s загрузил карту: %s", playerid, ret_GetPlayerName(playerid), inputtext);
            SendClientMessageToAll(RGBA_WHITE, g_ClientMessage);

            format(g_ClientMessage, sizeof g_ClientMessage, "Загружено: %i Объектов(s), %i Автомобилей(s), %i Пикапов(s), %i Актеров(s), %i Зданий удалено.", objects_loaded, vehicles_loaded, pickups_loaded, actors_loaded, buildings_loaded);
            SendClientMessageToAll(RGBA_WHITE, g_ClientMessage);

            if( attachments_loaded > 0 ) {
                format(g_ClientMessage, sizeof g_ClientMessage, "+ %i ваших аттачей.", attachments_loaded);
                SendClientMessage(playerid, RGBA_WHITE, g_ClientMessage);
            }

            return 1;
        }
    }

    #if defined mload_OnDialogResponse
        return mload_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
    #else
        return 0;
    #endif
}
#if defined _ALS_OnDialogResponse
    #undef OnDialogResponse
#else
    #define _ALS_OnDialogResponse
#endif
#define OnDialogResponse mload_OnDialogResponse
#if defined mload_OnDialogResponse
    forward mload_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif
