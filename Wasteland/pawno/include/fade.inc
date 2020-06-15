#define _UPDATERATE 100 //milliseconds
forward _UpdateFadeTimer(playerid);
forward OnFadeComplete(playerid,beforehold);
new _pEndColor[MAX_PLAYERS][4];
new _pCurrentColor[MAX_PLAYERS][4];
new _pRateColor[MAX_PLAYERS][4];
new _pStep[MAX_PLAYERS];
new _pHold[MAX_PLAYERS];
new Text:_text; //Look, only one!

/*
native ConvertToColor(RR,GG,BB,AA);
native StopPlayerFade(playerid);
native FadeColorForPlayer(playerid,RR1,GG1,BB1,AA1,RR2,GG2,BB2,AA2,steps,hold);
native FadePlayerConnect(playerid);
*/
stock ConvertToColor(RR,GG,BB,AA)return (RR*16777216)+(GG*65536)+(BB*256)+AA;
stock FadeColorForPlayer(playerid,RR1,GG1,BB1,AA1,RR2,GG2,BB2,AA2,steps,hold)
{
	_pStep[playerid]=steps;
	new tmpsteps;
	_pHold[playerid]=hold;
	_pEndColor[playerid][0]=RR2;
	_pEndColor[playerid][1]=GG2;
	_pEndColor[playerid][2]=BB2;
	_pEndColor[playerid][3]=AA2;
	_pCurrentColor[playerid][0]=RR1;
	_pCurrentColor[playerid][1]=GG1;
	_pCurrentColor[playerid][2]=BB1;
	_pCurrentColor[playerid][3]=AA1;
	_pRateColor[playerid][0]=(RR1-RR2)/steps;
	_pRateColor[playerid][1]=(GG1-GG2)/steps;
	_pRateColor[playerid][2]=(BB1-BB2)/steps;
	_pRateColor[playerid][3]=(AA1-AA2)/steps;
	//No dividing by 0!
	if(_pRateColor[playerid][0]!=0)if(((RR1-RR2)/_pRateColor[playerid][0])>steps)tmpsteps=((RR1-RR2)/_pRateColor[playerid][0])-steps;
	if(_pRateColor[playerid][1]!=0)if(((GG1-GG2)/_pRateColor[playerid][1])>steps+tmpsteps)tmpsteps=((GG1-GG2)/_pRateColor[playerid][1])-steps;
	if(_pRateColor[playerid][2]!=0)if(((BB1-BB2)/_pRateColor[playerid][2])>steps+tmpsteps)tmpsteps=((BB1-BB2)/_pRateColor[playerid][2])-steps;
	if(_pRateColor[playerid][3]!=0)if(((AA1-AA2)/_pRateColor[playerid][3])>steps+tmpsteps)tmpsteps=((AA1-AA2)/_pRateColor[playerid][3])-steps;
	if(tmpsteps)_pStep[playerid]+=tmpsteps+1;
	TextDrawShowForPlayer(playerid,_text);
	SetPVarInt(playerid,"TimerFade",SetTimerEx("_UpdateFadeTimer",_UPDATERATE,1,"d",playerid));
}
FadePlayerConnect(playerid)
{
	_pHold[playerid]=-1;
	_pStep[playerid]=-1;
	return 1;
}
stock StopPlayerFade(playerid)
{
	_pStep[playerid]=0;
	_pHold[playerid]=0;
}
public _UpdateFadeTimer(playerid)
{
		if(_pStep[playerid])
		{
			_pStep[playerid]--;
			for(new color;color<4;color++)
			{
				_pCurrentColor[playerid][color]-=_pRateColor[playerid][color];
				if(_pRateColor[playerid][color]>0)
				{
					if(_pCurrentColor[playerid][color]<_pEndColor[playerid][color])_pCurrentColor[playerid][color]=_pEndColor[playerid][color];
				}
				if(_pRateColor[playerid][color]<0)
				{
					if(_pCurrentColor[playerid][color]>_pEndColor[playerid][color])_pCurrentColor[playerid][color]=_pEndColor[playerid][color];
				}
				if(_pCurrentColor[playerid][color]<0)_pCurrentColor[playerid][color]=0;
				if(_pCurrentColor[playerid][color]>255)_pCurrentColor[playerid][color]=255;
			}
			TextDrawBoxColor(_text,ConvertToColor(_pCurrentColor[playerid][0],_pCurrentColor[playerid][1],_pCurrentColor[playerid][2],_pCurrentColor[playerid][3]));
			TextDrawShowForPlayer(playerid,_text);
		}
		else if(_pStep[playerid]==0)
		{
			if(_pHold[playerid]==1)TextDrawHideForPlayer(playerid,_text);
			_pHold[playerid]=-1;
			KillTimer(GetPVarInt(playerid,"TimerFade"));
		}
}