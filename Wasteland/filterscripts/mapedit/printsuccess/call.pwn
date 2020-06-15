public OnFilterScriptInit() {

    #if defined ps_OnFilterScriptInit
        ps_OnFilterScriptInit();
    #endif
}
#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit ps_OnFilterScriptInit
#if defined ps_OnFilterScriptInit
    forward ps_OnFilterScriptInit();
#endif


public OnFilterScriptExit() {

    #if defined ps_OnFilterScriptExit
        ps_OnFilterScriptExit();
    #endif
}
#if defined _ALS_OnFilterScriptExit
    #undef OnFilterScriptExit
#else
    #define _ALS_OnFilterScriptExit
#endif
#define OnFilterScriptExit ps_OnFilterScriptExit
#if defined ps_OnFilterScriptExit
    forward ps_OnFilterScriptExit();
#endif
