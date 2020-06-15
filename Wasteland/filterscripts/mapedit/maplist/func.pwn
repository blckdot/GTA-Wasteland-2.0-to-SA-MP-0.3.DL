DefaultMapListData(playerid) {
    g_MapListData[playerid][MAPLIST_DATA_PAGE] = MIN_MAPLIST_PAGE;

    g_MapListData[playerid][MAPLIST_DATA_MAXPAGE] = MIN_MAPLIST_PAGE;

    strpack(g_MapListData[playerid][MAPLIST_DATA_SEARCH], "", MAX_SEARCH_LEN+1);

    for(new row; row < MAX_MAPLIST_ROWS; row ++) {
        g_MapListData[playerid][MAPLIST_DATA_ROW_ID][row] = INVALID_MAP_ID;
    }
}

LoadMapListData(playerid) {
    new rows_added, max_offset;

    strunpack(g_SearchString, g_MapListData[playerid][MAPLIST_DATA_SEARCH]);

    rows_added = FindMaps(
        .result = g_MapListData[playerid][MAPLIST_DATA_ROW_ID],
        .result_size = MAX_MAPLIST_ROWS,
        .search = g_SearchString,
        .offset = g_MapListData[playerid][MAPLIST_DATA_PAGE] * MAX_MAPLIST_ROWS,
        .max_offset = max_offset
    );

    for(new row = rows_added; row < MAX_MAPLIST_ROWS; row ++) {
        g_MapListData[playerid][MAPLIST_DATA_ROW_ID][row] = INVALID_MAP_ID;
    }

    g_MapListData[playerid][MAPLIST_DATA_MAXPAGE] = max_offset / MAX_MAPLIST_ROWS;
}

ShowMapListDialog(playerid, dialogid) {
    switch( dialogid ) {
        case DIALOGID_MAPLIST: {
            g_DialogCaption = "Map List";
            g_DialogInfo = "";

            for(new listitem; listitem < MAX_MAPLIST_LISTITEMS; listitem ++) {
                switch( listitem ) {
                    case MAPLIST_LISTITEM_ROW_F..MAPLIST_LISTITEM_ROW_L: {
                        new
                            row = listitem - MAPLIST_LISTITEM_ROW_F,
                            mapid = g_MapListData[playerid][MAPLIST_DATA_ROW_ID][row]
                        ;

                        if( mapid == INVALID_MAP_ID ) {
                            strcat(g_DialogInfo, "-\t-\n");
                        } else {
                            GetMapName(mapid, g_MapString, sizeof g_MapString);
                            format(g_DialogInfoRow, sizeof g_DialogInfoRow, "%i\t%s\n", mapid, g_MapString);
                            strcat(g_DialogInfo, g_DialogInfoRow);
                        }
                    }
                    case MAPLIST_LISTITEM_SEARCH: {
                        strunpack(g_SearchString, g_MapListData[playerid][MAPLIST_DATA_SEARCH]);
                        if( isempty(g_SearchString) ) {
                            strcat(g_DialogInfo, "Поиск\t \n");
                        } else {
                            format(g_DialogInfoRow, sizeof g_DialogInfoRow, "Поиск: %s\t \n", g_SearchString);
                            strcat(g_DialogInfo, g_DialogInfoRow);
                        }

                    }
                    case MAPLIST_LISTITEM_PAGE: {
                        format(g_DialogInfoRow, sizeof g_DialogInfoRow, "Страница: %i / %i\t \n", g_MapListData[playerid][MAPLIST_DATA_PAGE] + 1, g_MapListData[playerid][MAPLIST_DATA_MAXPAGE] + 1);
                        strcat(g_DialogInfo, g_DialogInfoRow);
                    }
                    case MAPLIST_LISTITEM_PAGE_F: {
                        strcat(g_DialogInfo, "<< Первая страница <<\t \n");
                    }
                    case MAPLIST_LISTITEM_PAGE_P: {
                        strcat(g_DialogInfo, "< Предыдущая страница <\t \n");
                    }
                    case MAPLIST_LISTITEM_PAGE_N: {
                        strcat(g_DialogInfo, "> Следующая страница >\t \n");
                    }
                    case MAPLIST_LISTITEM_PAGE_L: {
                        strcat(g_DialogInfo, ">> Последняя страница >>\t \n");
                    }
                    default: {
                        strcat(g_DialogInfo, " \t \n");
                    }
                }
            }
            ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_TABLIST, g_DialogCaption, g_DialogInfo, "Загрузить", "Отмена");
        }
        case DIALOGID_MAPLIST_PAGE: {
            g_DialogCaption = "Список карт: страница";
            format(g_DialogInfo, sizeof g_DialogInfo, "Текущая страница: %i", g_MapListData[playerid][MAPLIST_DATA_PAGE] + 1);
            ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_INPUT, g_DialogCaption, g_DialogInfo, "Выбор", "Отмена");
        }
        case DIALOGID_MAPLIST_SEARCH: {
            g_DialogCaption = "Список карт: поиск";
            strunpack(g_SearchString, g_MapListData[playerid][MAPLIST_DATA_SEARCH]);
            if( isempty(g_SearchString) ) {
                g_DialogInfo = "Вы ничего не искали.";
            } else {
                format(g_DialogInfo, sizeof g_DialogInfo, "Поиск: %s", g_SearchString);
            }
            ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_INPUT, g_DialogCaption, g_DialogInfo, "Выбор", "Отмена");
        }
        default: {
            return 0;
        }
    }
    return 1;
}
