/**********************************
 *                                *
 *   @Author:      ZeeX           *
 *   @Version:     0.3.1          *
 *   @Released:    31/10/2009     *
 *                                *
 **********************************/
 // Пофикшенная и ускоренная версия ZCMD от Dimazzz'a.

#if defined _zcmd_included
	#endinput
#endif
#define _zcmd_included

#define MAX_FUNC_NAME (32)

#define COMMAND:%1(%2)          		\
			forward cmd_%1(%2); 		\
			public cmd_%1(%2)

#define CMD:%1(%2) 						\
			COMMAND:%1(%2)

#define command(%1,%2,%3) 				\
			COMMAND:%1(%2, %3)

#define cmd(%1,%2,%3) 					\
			COMMAND:%1(%2, %3)
#define ALT:%1:%0; \
						forward cmd_%1(playerid, params[]); \
						public cmd_%1(playerid, params[]) \
								return cmd_%0(playerid, params);

#if !defined isnull
	#define isnull(%1) 					\
				((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#if defined OnPlayerCommandReceived
	forward OnPlayerCommandReceived(playerid, cmdtext[]);
#endif
#if defined OnPlayerCommandPerformed
	forward OnPlayerCommandPerformed(playerid, cmdtext[], success);
#endif
stock IsRussianChar(c)
{
	switch(c)
	{
		case 'А'..'Я', 'а'..'я', 'ё', 'Ё': return 1;
	}
	return 0;
}
stock RusToEngChar(c)
{
	new strRus[] = "йцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ.";
	new strEng[] = "qwertyuiop[]asdfghjkl;'zxcvbnm,./QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
	new pos_ = 0;
	while(pos_ < sizeof strRus)
	{
		if(strRus[pos_] == c) return strEng[pos_];
		++pos_;
	}
	return c;
}
public OnPlayerCommandText(playerid, cmdtext[])
{
	if (isnull(cmdtext)) return (!defined FILTERSCRIPT);
	#if defined OnPlayerCommandReceived
		if (!OnPlayerCommandReceived(playerid, cmdtext))
		{
			return (!defined FILTERSCRIPT);
		}
	#endif
	new
		pos,
		funcname[MAX_FUNC_NAME];
	// проверка на ошибочное написание команды на русском a.k.a /рудз /й 
	if(IsRussianChar(cmdtext[1]))
	{
		while(cmdtext[++pos] > ' ')
		{
			cmdtext[pos] = RusToEngChar(cmdtext[pos]);
		}
		pos = 0;
	}
	//	
	while (cmdtext[++pos] > ' ')
	{
		funcname[pos-1] = tolower(cmdtext[pos]);
	}
	format(funcname, sizeof(funcname), "cmd_%s", funcname);
	while (cmdtext[pos] == ' ') ++pos;
	if (!cmdtext[pos])
	{
		#if defined OnPlayerCommandPerformed
			OnPlayerCommandPerformed(playerid, cmdtext, CallLocalFunction(funcname, "is", playerid, "\1"));
			return (!defined FILTERSCRIPT);
		#else
			CallLocalFunction(funcname, "is", playerid, "\1");
			return (!defined FILTERSCRIPT);
		#endif
	}
	#if defined OnPlayerCommandPerformed
		OnPlayerCommandPerformed(playerid, cmdtext, CallLocalFunction(funcname, "is", playerid, cmdtext[pos]));
	#else
		CallLocalFunction(funcname, "is", playerid, cmdtext[pos]);
	#endif
	#if defined zcmd_OnPlayerCommandText
		zcmd_OnPlayerCommandText(playerid, cmdtext[pos]);
	#endif
	return (!defined FILTERSCRIPT);
}
#if defined _ALS_OnPlayerCommandText
	#undef OnPlayerCommandText
#else
	#define _ALS_OnPlayerCommandText
#endif
#define OnPlayerCommandText zcmd_OnPlayerCommandText
#if defined zcmd_OnPlayerCommandText
	forward zcmd_OnPlayerCommandText(playerid, cmdtext[]);
#endif
