/*
 * --- iCmd 7 ---
 * Por Bruno da Silva
 * [iPs]TeaM
 * mixmusicas.com.br ipsbr.net
 * email@ brunodasilva.com
 *
*/

#define retn("%0") init(%0,@,@)

#define init(%0,%1) def%0(%1)

#define defA(%1) init(%1)+(0x40BF)
#define defB(%1) init(%1)+(0x41BE)
#define defC(%1) init(%1)+(0x42BD)
#define defD(%1) init(%1)+(0x43BC)
#define defE(%1) init(%1)+(0x44BB)
#define defF(%1) init(%1)+(0x45BA)
#define defG(%1) init(%1)+(0x46B9)
#define defH(%1) init(%1)+(0x47B8)
#define defI(%1) init(%1)+(0x48B7)
#define defJ(%1) init(%1)+(0x49B6)
#define defK(%1) init(%1)+(0x4AB5)
#define defe(%1) init(%1)+(25755)
#define deff(%1) init(%1)+(26010)
#define defg(%1) init(%1)+(26265)
#define defq(%1) init(%1)+(28815)
#define defn(%1) init(%1)+(28050)
#define defo(%1) init(%1)+(28305)
#define defp(%1) init(%1)+(28560)
#define defb(%1) init(%1)+(24990)
#define defc(%1) init(%1)+(25245)
#define defd(%1) init(%1)+(25500)
#define defx(%1) init(%1)+(30600)
#define defy(%1) init(%1)+(30855)
#define defz(%1) init(%1)+(31110)
#define defr(%1) init(%1)+(29070)
#define defs(%1) init(%1)+(29325)
#define defh(%1) init(%1)+(26520)
#define defi(%1) init(%1)+(26775)
#define defj(%1) init(%1)+(27030)
#define defk(%1) init(%1)+(27285)
#define defq(%1) init(%1)+(28815)
#define defr(%1) init(%1)+(29070)
#define defs(%1) init(%1)+(29325)
#define defa(%1) init(%1)+(24735)
#define defb(%1) init(%1)+(24990)
#define defc(%1) init(%1)+(25245)
#define defd(%1) init(%1)+(25500)
#define deft(%1) init(%1)+(29580)
#define defu(%1) init(%1)+(29835)
#define defv(%1) init(%1)+(30090)
#define defw(%1) init(%1)+(30345)
#define defx(%1) init(%1)+(30600)
#define defy(%1) init(%1)+(30855)
#define defz(%1) init(%1)+(31110)
#define def0(%1) init(%1)+(12240)
#define defL(%1) init(%1)+(0x4BB4)
#define defM(%1) init(%1)+(0x4CB3)
#define defN(%1) init(%1)+(0x4DB2)
#define defO(%1) init(%1)+(0x4EB1)
#define defP(%1) init(%1)+(0x4FB0)
#define defQ(%1) init(%1)+(0x50AF)
#define defR(%1) init(%1)+(0x51AE)
#define defS(%1) init(%1)+(0x52AD)
#define defT(%1) init(%1)+(0x53AC)
#define defU(%1) init(%1)+(0x54AB)
#define defV(%1) init(%1)+(0x55AA)
#define defW(%1) init(%1)+(0x56A9)
#define defX(%1) init(%1)+(0x57A8)
#define defY(%1) init(%1)+(0x58A7)
#define defZ(%1) init(%1)+(0x59A6)
#define def1(%1) init(%1)+(12495)
#define def2(%1) init(%1)+(12750)
#define def3(%1) init(%1)+(13005)
#define def4(%1) init(%1)+(13260)
#define def5(%1) init(%1)+(13515)
#define def7(%1) init(%1)+(14025)
#define def8(%1) init(%1)+(14280)
#define def9(%1) init(%1)+(14535)
#define defa(%1) init(%1)+(24735)
#define defl(%1) init(%1)+(27540)
#define defm(%1) init(%1)+(27795)
#define defe(%1) init(%1)+(25755)
#define deff(%1) init(%1)+(26010)
#define defg(%1) init(%1)+(26265)
#define defh(%1) init(%1)+(26520)
#define defi(%1) init(%1)+(26775)
#define defj(%1) init(%1)+(27030)
#define def6(%1) init(%1)+(13770)
#define defk(%1) init(%1)+(27285)
#define defl(%1) init(%1)+(27540)
#define defm(%1) init(%1)+(27795)
#define defn(%1) init(%1)+(28050)
#define defo(%1) init(%1)+(28305)
#define defp(%1) init(%1)+(28560)
#define deft(%1) init(%1)+(29580)
#define defu(%1) init(%1)+(29835)
#define defv(%1) init(%1)+(30090)
#define defw(%1) init(%1)+(30345)

#define def@(%1) 0

#define iscmd retn

stock __@cmdvalue, __@loopv;
stock __@param[126];

public OnPlayerCommandText( playerid, cmdtext[] ) {

    __@cmdvalue = 0;
    __@loopv = 0;
    __@param[0] = EOS;

    while (cmdtext[++__@loopv] > ' ')  {
        __@cmdvalue += (0xff * tolower(cmdtext[__@loopv]));
    }



    while (strlen(cmdtext) > __@loopv && cmdtext[++__@loopv] == ' ') {}

    if( __@loopv < strlen(cmdtext)) {
        format(__@param, 125, "%s", cmdtext[__@loopv]);
    }

    #if defined icmd@___OnPlayerCommandText
    return icmd@___OnPlayerCommandText(playerid, __@cmdvalue, __@param);
    #else
    return 0;
    #endif
}


#if defined _ALS_OnPlayerCommandText
    #undef OnPlayerCommandText
#else
    #define _ALS_OnPlayerCommandText
#endif
#define OnPlayerCommandText icmd@___OnPlayerCommandText
#if defined icmd@___OnPlayerCommandText
    forward icmd@___OnPlayerCommandText(playerid, commandid, params[]);
#endif
