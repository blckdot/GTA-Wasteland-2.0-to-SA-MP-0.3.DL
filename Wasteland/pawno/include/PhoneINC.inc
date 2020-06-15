#define PHONE_DIALOG_ID 6000
#define MAX_PHONES 20
#define MAX_PHONE_NAME 24
new pPhoneNames[MAX_PLAYERS][MAX_PHONES][MAX_PHONE_NAME];
new pPhoneAmounts[MAX_PLAYERS][MAX_PHONES];
new gPhoneList[(MAX_PHONES+1)*(MAX_PHONE_NAME+3)];
stock AddPhone(playerid,ItemName[],Amount)
{
	new slot=-1;
	for(new item;item<MAX_PHONES;item++)
	{
		if(!strlen(pPhoneNames[playerid][item])&&(slot==-1))slot=item;
		if(!strlen(pPhoneNames[playerid][item]))continue;
		if(!strcmp(pPhoneNames[playerid][item],ItemName,true))
		{
			pPhoneAmounts[playerid][item]+=Amount;
			if(pPhoneAmounts[playerid][item]<=0)
			{
				pPhoneAmounts[playerid][item]=0;
				format(pPhoneNames[playerid][item],MAX_PHONE_NAME,"");
			}
			return 1;
		}
	}
	if(slot>-1)
	{
		format(pPhoneNames[playerid][slot],MAX_PHONE_NAME,ItemName);
		pPhoneAmounts[playerid][slot]=Amount;
		return 1;
	}
	return 0;
}
stock RemovePhone(playerid,Amount)
{
	for(new item;item<MAX_PHONES;item++)
	{
		if(!PlayerHaveNumber(playerid,item,Amount))continue;
		else
		{
			pPhoneAmounts[playerid][item]=0;
			format(pPhoneNames[playerid][item],MAX_PHONE_NAME,"");
			return 1;
		}
	}
	return 0;
}
stock GetPhoneName(playerid,Amount) 
{
new tyc;
for(new item;item<MAX_PHONES;item++) if(PlayerHaveNumber(playerid,item,Amount)){tyc=item;break;}
return pPhoneNames[playerid][tyc];
}
stock CheckPhone(playerid,Amount)
{
	for(new item;item<MAX_PHONES;item++)
	{
		if(!PlayerHaveNumber(playerid,item,Amount))continue;
		else return 1;
	}
	return 0;
}
stock PlayerHaveNumber(playerid,numb,numberphone)
{
		if(pPhoneAmounts[playerid][numb]==numberphone)return 1;
		else return 0;
}
stock PlayerHasNumber(playerid,items)
{
		//printf("%d",pPhoneAmounts[playerid][items]);
		if(pPhoneAmounts[playerid][items]==0)return 0;
		return pPhoneAmounts[playerid][items];
}
stock ResetPlayerPhone(playerid)
{
	for(new item;item<MAX_PHONES;item++)
	{
		format(pPhoneNames[playerid][item],MAX_PHONE_NAME,"");
		pPhoneAmounts[playerid][item]=0;
	}
}
stock ShowPhone(playerid)
{
	gPhoneList="";
	for(new item;item<MAX_PHONES;item++)
	{
		if(pPhoneAmounts[playerid][item]<=0)
		{
			pPhoneAmounts[playerid][item]=0;
			format(pPhoneNames[playerid][item],MAX_PHONE_NAME,"");
		}
		if(!strlen(pPhoneNames[playerid][item]))continue;
		format(gPhoneList,sizeof(gPhoneList),"%s\n%d\t\t%s",gPhoneList,pPhoneAmounts[playerid][item],pPhoneNames[playerid][item]);
	}
	if(strlen(gPhoneList))ShowPlayerDialog(playerid,PHONE_DIALOG_ID,DIALOG_STYLE_LIST,"Телефонная книга",gPhoneList,"Выбрать","Закрыть");
	else SendClientMessage(playerid,0xAFAFAFAA,"(( Телефонная книга пуста! ))");
	return 1;
}