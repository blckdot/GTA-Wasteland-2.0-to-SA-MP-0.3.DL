/*  SA-MP Compatible Upgrades Function's
 *
 *		Version: 1.2
 *
 *  (c) Copyright 2011, AirKite
 */
 
#if defined _acuf_included
	#endinput
#endif
#define _acuf_included

static ModName[][64] = { // by BigETI
{"Pro Spoiler"},{"Win Spoiler"},{"Drag Spoiler"},{"Alpha Spoiler"},{"Champ Scoop Hood"},
{"Fury Scoop Hood"},{"Roof Scoop"},{"Right Sideskirt"},{"5x Nitro"},{"2x Nitro"},{"10x Nitro"},
{"Race Scoop Hood"},{"Worx Scoop Hood"},{"Round Fog Lamps"},{"Champ Spoiler"},{"Race Spoiler"},
{"Worx Spoiler"},{"Left Sideskirt"},{"Upswept Exhaust"},{"Twin Exhaust"},{"Large Exhaust"},
{"Medium Exhaust"},{"Small Exhaust"},{"Fury Spoiler"},{"Square Fog Lamps"},{"Offroad Wheels"},
{"Right Alien Sideskirt 'Sultan'"},{"Left Alien Sideskirt 'Sultan'"},{"Alien Exhaust 'Sultan'"},
{"X-Flow Exhaust 'Sultan'"},{"Left X-Flow Sideskirt 'Sultan'"},{"Right X-Flow Sideskirt 'Sultan'"},
{"Alien Roof Vent 'Sultan'"},{"X-Flow Roof Vent 'Sultan'"},{"Alien Exhaust 'Elegy'"},{"X-Flow Roof Vent 'Elegy'"},
{"Right Alien Sideskirt 'Elegy'"},{"X-Flow Exhaust 'Elegy'"},{"Alien Roof Vent 'Elegy'"},{"Right X-Flow Sideskirt 'Elegy'"},
{"Left Alien Sideskirt 'Elegy'"},{"Right X-Flow Sideskirt 'Elegy'"},{"Right Chrome Sideskirt 'Broadway'"},
{"Slamin Exhaust 'Broadway'"},{"Chrome Exhaust 'Broadway'"},{"X-Flow Exhaust 'Flash'"},{"Alien Exhaust 'Flash'"},
{"Right Alien Sideskirt 'Flash'"},{"Right X-Flow Sideskirt 'Flash'"},{"Alien Spoiler 'Flash'"},{"X-Flow Spoiler 'Flash'"},
{"Left Alien Sideskirt 'Flash'"},{"Left X-Flow Sideskirt 'Flash'"},{"X-Flow Roof 'Flash'"},{"Alien Roof 'Flash'"},
{"Alien Roof 'Stratum'"},{"Right Alien Sideskirt 'Stratum'"},{"Right X-Flow Sideskirt 'Stratum'"},{"Alien Spoiler 'Stratum'"},
{"X-Flow Exhaust 'Stratum'"},{"X-Flow Spoiler 'Stratum'"},{"X-Flow Roof 'Stratum'"},{"Left Alien Sideskirt 'Stratum'"},
{"Left X-Flow Sideskirt 'Stratum'"},{"Alien Exhaust 'Stratum'"},{"Alien Exhaust 'Jester'"},{"X-Flow Exhaust 'Jester'"},
{"Alien Roof 'Jester'"},{"X-Flow Roof 'Jester'"},{"Right Alien Sideskirt 'Jester'"},{"Right X-Flow Sideskirt 'Jester'"},
{"Left Alien Sideskirt 'Jester'"},{"Left X-Flow Sideskirt 'Jester'"},{"Shadow Wheels"},{"Mega Wheels"},{"Rimshine Wheels"},
{"Wires Wheels"},{"Classic Wheels"},{"Twist Wheels"},{"Cutter Wheels"},{"Switch Wheels"},{"Grove Wheels"},{"Import Wheels"},
{"Dollar Wheels"},{"Trance Wheels"},{"Atomic Wheels"},{"Stereo Sound"},{"Hydraulics"},{"Alien Roof 'Uranus'"},{"X-Flow Exhaust 'Uranus'"},
{"Right Alien Sideskirt 'Uranus'"},{"X-Flow Roof 'Uranus'"},{"Alien Exhaust 'Uranus'"},{"Right X-Flow Sideskirt 'Uranus'"},
{"Left Alien Sideskirt 'Uranus'"},{"Right X-Flow Sideskirt 'Uranus'"},{"Ahab Wheels"},{"Virtual Wheels"},{"Access Wheels"},
{"Left Chrome Sideskirt 'Broadway'"},{"Chrome Grill Bullbar 'Remington'"},{"Left 'Chrome Flames' Sideskirt 'Remington'"},
{"Left 'Chrome Strip' Sideskirt 'Savanna'"},{"Corvetible Roof 'Blade'"},{"Chrome Exhaust 'Blade'"},{"Slamin Exhaust 'Blade'"},
{"Right 'Chrome Arches' Sideskirt 'Remington'"},{"Left 'Chrome Strip' Sideskirt 'Blade'"},{"Right 'Chrome Strip' Sideskirt 'Blade'"},
{"Chrome Rear Bullbars 'Slamvan'"},{"Slamin Rear Bullbars 'Slamvan'"},{"Little Front Sign? 'Slamvan'"},{"Little Front Sign? 'Slamvan'"},
{"Chrome Exhaust 'Slamvan'"},{"Slamin Exhaust 'Slamvan'"},{"Chrome Front Bullbars 'Slamvan'"},{"Slamin Front Bullbars 'Slamvan'"},
{"Chrome Front Bumper 'Slamvan'"},{"Right 'Chrome Trim' Sideskirt 'Slamvan'"},{"Right 'Wheelcovers' Sideskirt 'Slamvan'"},
{"Left 'Chrome Trim' Sideskirt 'Slamvan'"},{"Left 'Wheelcovers' Sideskirt 'Slamvan'"},{"Right 'Chrome Flames' Sideskirt 'Remington'"},
{"Bullbar Chrome Bars 'Remington'"},{"Left 'Chrome Arches' Sideskirt 'Remington'"},{"Bullbar Chrome Lights 'Remongton'"},
{"Chrome Exhaust 'Remington'"},{"Slamin Exhaust 'Remington'"},{"Vinyl Hardtop 'Blade'"},{"Chrome Exhaust 'Savanna'"},
{"Hardtop Roof 'Savanna'"},{"Softtop Roof 'Savanna'"},{"Slamin Exhaust 'Savanna'"},{"Right 'Chrome Strip' Sideskirt 'Savanna'"},
{"Right 'Chrome Strip' Sideskirt 'Tornado'"},{"Slamin Exhaust 'Tornado'"},{"Chrome Exhaust 'Tornado'"},{"Left 'Chrome Strip' Sideskirt 'Tornado'"},
{"Alien Spoiler 'Sultan'"},{"X-Flow Spoiler 'Sultan'"},{"X-Flow Rear Bumper 'Sultan'"},{"Alien Rear Bumper 'Sultan'"},
{"Left Oval Vents"},{"Right Oval Vents"},{"Left Square Vents"},{"Right Square Vents"},{"X-Flow Spoiler 'Elegy'"},
{"Alien Spoiler 'Elegy'"},{"X-Flow Rear Bumper 'Elegy'"},{"Alien Rear Bumper 'Elegy'"},{"Alien Rear Bumper 'Flash'"},
{"X-Flow Rear Bumper 'Flash'"},{"X-Flow Front Bumper 'Flash'"},{"Alien Front Bumper 'Flash'"},{"Alien Rear Bumper 'Stratum'"},
{"Alien Front Bumper 'Stratum'"},{"X-Flow Rear Bumper 'Stratum'"},{"X-Flow Front Bumper 'Stratum'"},{"X-Flow Spoiler 'Jester'"},
{"Alien Rear Bumper 'Jester'"},{"Alien Front Bumper 'Jester'"},{"X-Flow Rear Bumper 'Jester'"},{"Alien Spoiler 'Jester'"},
{"X-Flow Spoiler 'Uranus'"},{"Alien Spoiler 'Uranus'"},{"X-Flow Front Bumper 'Uranus'"},{"Alien Front Bumper 'Uranus'"},
{"X-Flow Rear Bumper 'Uranus'"},{"Alien Rear Bumper 'Uranus'"},{"Alien Front Bumper 'Sultan'"},{"X-Flow Front Bumper 'Sultan'"},
{"Alien Front Bumper 'Elegy'"},{"X-Flow Front Bumper 'Elegy'"},{"X-Flow Front Bumper 'Jester'"},{"Chrome Front Bumper 'Broadway'"},
{"Slamin Front Bumper 'Broadway'"},{"Chrome Rear Bumper 'Broadway'"},{"Slamin Rear Bumper 'Broadway'"},{"Slamin Rear Bumper 'Remington'"},
{"Chrome Front Bumper 'Remington'"},{"Chrome Rear Bumper 'Remington'"},{"Slamin Front Bumper 'Blade'"},{"Chrome Front Bumper 'Blade'"},
{"Slamin Rear Bumper 'Blade'"},{"Chrome Rear Bumper 'Blade'"},{"Slamin Front Bumper 'Remington'"},{"Slamin Rear Bumper 'Savanna'"},
{"Chrome Rear Bumper 'Savanna'"},{"Slamin Front Bumper 'Savanna'"},{"Chrome Front Bumper 'Savanna'"},{"Slamin Front Bumper 'Tornado'"},
{"Chrome Front Bumper 'Tornado'"},{"Chrome Rear Bumper 'Tornado'"},{"Slamin Rear Bumper 'Tornado'"}};

stock GetComponentName(componentid) return ModName[componentid-1000]; // by BigETI

stock IsVehicleUpgradeCompatible(model,componentid) // by AirKite
{
	switch(model)
	{
		case 400:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1024: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 401:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1004: { return 1; }
				case 1005: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1017: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
				case 1144: { return 1; }
			}
		}
		case 404:
		{
			switch(componentid)
			{
				case 1000: { return 1; }
				case 1002: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1016: { return 1; }
				case 1017: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 405:
		{
			switch(componentid)
			{
				case 1000: { return 1; }
				case 1001: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1014: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 410:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1017: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1023: { return 1; }
				case 1024: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 415:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 418:
		{
			switch(componentid)
			{
				case 1002: { return 1; }
				case 1006: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1016: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 420:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1004: { return 1; }
				case 1005: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1019: { return 1; }
				case 1021: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 421:
		{
			switch(componentid)
			{
				case 1000: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1014: { return 1; }
				case 1016: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 422:
		{
			switch(componentid)
			{
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1017: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 426:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1004: { return 1; }
				case 1005: { return 1; }
				case 1006: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1019: { return 1; }
				case 1021: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 436:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1017: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1022: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 439:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1017: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 477:
		{
			switch(componentid)
			{
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 478:
		{
			switch(componentid)
			{
				case 1004: { return 1; }
				case 1005: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1012: { return 1; }
				case 1013: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1022: { return 1; }
				case 1024: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 489:
		{
			switch(componentid)
			{
				case 1000: { return 1; }
				case 1002: { return 1; }
				case 1004: { return 1; }
				case 1005: { return 1; }
				case 1006: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1016: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1024: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 491:
		{
			switch(componentid)
			{
				case 1003: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1014: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 492:
		{
			switch(componentid)
			{
				case 1000: { return 1; }
				case 1004: { return 1; }
				case 1005: { return 1; }
				case 1006: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1016: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 496:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1002: { return 1; }
				case 1003: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1011: { return 1; }
				case 1017: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
			}
		}
		case 500:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1024: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 516:
		{
			switch(componentid)
			{
				case 1000: { return 1; }
				case 1002: { return 1; }
				case 1004: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1015: { return 1; }
				case 1016: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 517:
		{
			switch(componentid)
			{
				case 1002: { return 1; }
				case 1003: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1016: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 518:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1005: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1020: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 527:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1014: { return 1; }
				case 1015: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 529:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1011: { return 1; }
				case 1012: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 534:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1100: { return 1; }
				case 1101: { return 1; }
				case 1106: { return 1; }
				case 1122: { return 1; }
				case 1123: { return 1; }
				case 1124: { return 1; }
				case 1125: { return 1; }
				case 1126: { return 1; }
				case 1127: { return 1; }
				case 1178: { return 1; }
				case 1179: { return 1; }
				case 1180: { return 1; }
				case 1185: { return 1; }
			}
		}
		case 535:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1109: { return 1; }
				case 1110: { return 1; }
				case 1113: { return 1; }
				case 1114: { return 1; }
				case 1115: { return 1; }
				case 1116: { return 1; }
				case 1117: { return 1; }
				case 1118: { return 1; }
				case 1119: { return 1; }
				case 1120: { return 1; }
				case 1121: { return 1; }
			}
		}
		case 536:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1103: { return 1; }
				case 1104: { return 1; }
				case 1105: { return 1; }
				case 1107: { return 1; }
				case 1108: { return 1; }
				case 1128: { return 1; }
				case 1181: { return 1; }
				case 1182: { return 1; }
				case 1183: { return 1; }
				case 1184: { return 1; }
			}
		}
		case 540:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1004: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1023: { return 1; }
				case 1024: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 542:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1014: { return 1; }
				case 1015: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 546:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1002: { return 1; }
				case 1004: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1023: { return 1; }
				case 1024: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 547:
		{
			switch(componentid)
			{
				case 1000: { return 1; }
				case 1003: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1016: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
			}
		}
		case 549:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1011: { return 1; }
				case 1012: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 550:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1004: { return 1; }
				case 1005: { return 1; }
				case 1006: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 551:
		{
			switch(componentid)
			{
				case 1002: { return 1; }
				case 1003: { return 1; }
				case 1005: { return 1; }
				case 1006: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1016: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1021: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 558:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1088: { return 1; }
				case 1089: { return 1; }
				case 1090: { return 1; }
				case 1091: { return 1; }
				case 1092: { return 1; }
				case 1093: { return 1; }
				case 1094: { return 1; }
				case 1095: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1163: { return 1; }
				case 1164: { return 1; }
				case 1165: { return 1; }
				case 1166: { return 1; }
				case 1167: { return 1; }
				case 1168: { return 1; }
			}
		}
		case 559:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1065: { return 1; }
				case 1066: { return 1; }
				case 1067: { return 1; }
				case 1068: { return 1; }
				case 1069: { return 1; }
				case 1070: { return 1; }
				case 1071: { return 1; }
				case 1072: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1158: { return 1; }
				case 1159: { return 1; }
				case 1160: { return 1; }
				case 1161: { return 1; }
				case 1162: { return 1; }
				case 1173: { return 1; }
			}
		}
		case 560:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1026: { return 1; }
				case 1027: { return 1; }
				case 1028: { return 1; }
				case 1029: { return 1; }
				case 1030: { return 1; }
				case 1031: { return 1; }
				case 1032: { return 1; }
				case 1033: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1138: { return 1; }
				case 1139: { return 1; }
				case 1140: { return 1; }
				case 1141: { return 1; }
				case 1169: { return 1; }
				case 1170: { return 1; }
			}
		}
		case 561:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1055: { return 1; }
				case 1056: { return 1; }
				case 1057: { return 1; }
				case 1058: { return 1; }
				case 1059: { return 1; }
				case 1060: { return 1; }
				case 1061: { return 1; }
				case 1062: { return 1; }
				case 1063: { return 1; }
				case 1064: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1154: { return 1; }
				case 1155: { return 1; }
				case 1156: { return 1; }
				case 1157: { return 1; }
			}
		}
		case 562:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1034: { return 1; }
				case 1035: { return 1; }
				case 1036: { return 1; }
				case 1037: { return 1; }
				case 1038: { return 1; }
				case 1039: { return 1; }
				case 1040: { return 1; }
				case 1041: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1146: { return 1; }
				case 1147: { return 1; }
				case 1148: { return 1; }
				case 1149: { return 1; }
				case 1171: { return 1; }
				case 1172: { return 1; }
			}
		}
		case 565:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1045: { return 1; }
				case 1046: { return 1; }
				case 1047: { return 1; }
				case 1048: { return 1; }
				case 1049: { return 1; }
				case 1050: { return 1; }
				case 1051: { return 1; }
				case 1052: { return 1; }
				case 1053: { return 1; }
				case 1054: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1150: { return 1; }
				case 1151: { return 1; }
				case 1152: { return 1; }
				case 1153: { return 1; }
			}
		}
		case 567:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1102: { return 1; }
				case 1129: { return 1; }
				case 1130: { return 1; }
				case 1131: { return 1; }
				case 1132: { return 1; }
				case 1133: { return 1; }
				case 1186: { return 1; }
				case 1187: { return 1; }
				case 1188: { return 1; }
				case 1189: { return 1; }
			}
		}
		case 575:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1042: { return 1; }
				case 1043: { return 1; }
				case 1044: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1099: { return 1; }
				case 1174: { return 1; }
				case 1175: { return 1; }
				case 1176: { return 1; }
				case 1177: { return 1; }
			}
		}
		case 576:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1134: { return 1; }
				case 1135: { return 1; }
				case 1136: { return 1; }
				case 1137: { return 1; }
				case 1190: { return 1; }
				case 1191: { return 1; }
				case 1192: { return 1; }
				case 1193: { return 1; }
			}
		}
		case 580:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1020: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 585:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1003: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1023: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 589:
		{
			switch(componentid)
			{
				case 1000: { return 1; }
				case 1004: { return 1; }
				case 1005: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1016: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1020: { return 1; }
				case 1024: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 600:
		{
			switch(componentid)
			{
				case 1004: { return 1; }
				case 1005: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1013: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1020: { return 1; }
				case 1022: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
		case 603:
		{
			switch(componentid)
			{
				case 1001: { return 1; }
				case 1006: { return 1; }
				case 1007: { return 1; }
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1017: { return 1; }
				case 1018: { return 1; }
				case 1019: { return 1; }
				case 1020: { return 1; }
				case 1023: { return 1; }
				case 1024: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
				case 1142: { return 1; }
				case 1143: { return 1; }
				case 1144: { return 1; }
				case 1145: { return 1; }
			}
		}
		case 402,403,406..409,411..414,416,419,423,424,427..429,431..435,437,438,440..445,448,450,451,455..459,461..463,466..468,470,471,474,475,479..486,490,494,495,498,499,502..510,514,515,521..526,528,530..533,541,552,543..545,554..557,566,568,578,571..574,579,581..584,586..588,591,594,596..599,601,602,604..611:
		{
			switch(componentid)
			{
				case 1008: { return 1; }
				case 1009: { return 1; }
				case 1010: { return 1; }
				case 1025: { return 1; }
				case 1073: { return 1; }
				case 1074: { return 1; }
				case 1075: { return 1; }
				case 1076: { return 1; }
				case 1077: { return 1; }
				case 1078: { return 1; }
				case 1079: { return 1; }
				case 1080: { return 1; }
				case 1081: { return 1; }
				case 1082: { return 1; }
				case 1083: { return 1; }
				case 1084: { return 1; }
				case 1085: { return 1; }
				case 1087: { return 1; }
				case 1096: { return 1; }
				case 1097: { return 1; }
				case 1098: { return 1; }
			}
		}
	}
	return 0;
}

stock GetVehicleCompatibleUpgrades(model, count, &componentid = 0) // by AirKite
{
	componentid = 0;
	switch(model)
	{
		case 400:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1013; }
				case 5: { componentid = 1018; }
				case 6: { componentid = 1019; }
				case 7: { componentid = 1020; }
				case 8: { componentid = 1021; }
				case 9: { componentid = 1024; }
				case 10: { componentid = 1025; }
				case 11: { componentid = 1073; }
				case 12: { componentid = 1074; }
				case 13: { componentid = 1075; }
				case 14: { componentid = 1076; }
				case 15: { componentid = 1077; }
				case 16: { componentid = 1078; }
				case 17: { componentid = 1079; }
				case 18: { componentid = 1080; }
				case 19: { componentid = 1081; }
				case 20: { componentid = 1082; }
				case 21: { componentid = 1083; }
				case 22: { componentid = 1084; }
				case 23: { componentid = 1085; }
				case 24: { componentid = 1087; }
				case 25: { componentid = 1096; }
				case 26: { componentid = 1097; }
				case 27: { componentid = 1098; }
			}
		}
		case 401:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1004; }
				case 4: { componentid = 1005; }
				case 5: { componentid = 1006; }
				case 6: { componentid = 1007; }
				case 7: { componentid = 1008; }
				case 8: { componentid = 1009; }
				case 9: { componentid = 1010; }
				case 10: { componentid = 1013; }
				case 11: { componentid = 1017; }
				case 12: { componentid = 1019; }
				case 13: { componentid = 1020; }
				case 14: { componentid = 1025; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
				case 32: { componentid = 1142; }
				case 33: { componentid = 1143; }
				case 34: { componentid = 1144; }
			}
		}
		case 404:
		{
			switch(count)
			{
				case 1: { componentid = 1000; }
				case 2: { componentid = 1002; }
				case 3: { componentid = 1007; }
				case 4: { componentid = 1008; }
				case 5: { componentid = 1009; }
				case 6: { componentid = 1010; }
				case 7: { componentid = 1013; }
				case 8: { componentid = 1016; }
				case 9: { componentid = 1017; }
				case 10: { componentid = 1019; }
				case 11: { componentid = 1020; }
				case 12: { componentid = 1021; }
				case 13: { componentid = 1025; }
				case 14: { componentid = 1073; }
				case 15: { componentid = 1074; }
				case 16: { componentid = 1075; }
				case 17: { componentid = 1076; }
				case 18: { componentid = 1077; }
				case 19: { componentid = 1078; }
				case 20: { componentid = 1079; }
				case 21: { componentid = 1080; }
				case 22: { componentid = 1081; }
				case 23: { componentid = 1082; }
				case 24: { componentid = 1083; }
				case 25: { componentid = 1084; }
				case 26: { componentid = 1085; }
				case 27: { componentid = 1087; }
				case 28: { componentid = 1096; }
				case 29: { componentid = 1097; }
				case 30: { componentid = 1098; }
			}
		}
		case 405:
		{
			switch(count)
			{
				case 1: { componentid = 1000; }
				case 2: { componentid = 1001; }
				case 3: { componentid = 1008; }
				case 4: { componentid = 1009; }
				case 5: { componentid = 1010; }
				case 6: { componentid = 1014; }
				case 7: { componentid = 1018; }
				case 8: { componentid = 1019; }
				case 9: { componentid = 1020; }
				case 10: { componentid = 1021; }
				case 11: { componentid = 1023; }
				case 12: { componentid = 1025; }
				case 13: { componentid = 1073; }
				case 14: { componentid = 1074; }
				case 15: { componentid = 1075; }
				case 16: { componentid = 1076; }
				case 17: { componentid = 1077; }
				case 18: { componentid = 1078; }
				case 19: { componentid = 1079; }
				case 20: { componentid = 1080; }
				case 21: { componentid = 1081; }
				case 22: { componentid = 1082; }
				case 23: { componentid = 1083; }
				case 24: { componentid = 1084; }
				case 25: { componentid = 1085; }
				case 26: { componentid = 1087; }
				case 27: { componentid = 1096; }
				case 28: { componentid = 1097; }
				case 29: { componentid = 1098; }
			}
		}
		case 410:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1007; }
				case 4: { componentid = 1008; }
				case 5: { componentid = 1009; }
				case 6: { componentid = 1010; }
				case 7: { componentid = 1013; }
				case 8: { componentid = 1017; }
				case 9: { componentid = 1019; }
				case 10: { componentid = 1020; }
				case 11: { componentid = 1021; }
				case 12: { componentid = 1023; }
				case 13: { componentid = 1024; }
				case 14: { componentid = 1025; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
			}
		}
		case 415:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1007; }
				case 4: { componentid = 1008; }
				case 5: { componentid = 1009; }
				case 6: { componentid = 1010; }
				case 7: { componentid = 1017; }
				case 8: { componentid = 1018; }
				case 9: { componentid = 1019; }
				case 10: { componentid = 1023; }
				case 11: { componentid = 1025; }
				case 12: { componentid = 1073; }
				case 13: { componentid = 1074; }
				case 14: { componentid = 1075; }
				case 15: { componentid = 1076; }
				case 16: { componentid = 1077; }
				case 17: { componentid = 1078; }
				case 18: { componentid = 1079; }
				case 19: { componentid = 1080; }
				case 20: { componentid = 1081; }
				case 21: { componentid = 1082; }
				case 22: { componentid = 1083; }
				case 23: { componentid = 1084; }
				case 24: { componentid = 1085; }
				case 25: { componentid = 1087; }
				case 26: { componentid = 1096; }
				case 27: { componentid = 1097; }
				case 28: { componentid = 1098; }
			}
		}
		case 418:
		{
			switch(count)
			{
				case 1: { componentid = 1002; }
				case 2: { componentid = 1006; }
				case 3: { componentid = 1008; }
				case 4: { componentid = 1009; }
				case 5: { componentid = 1010; }
				case 6: { componentid = 1016; }
				case 7: { componentid = 1020; }
				case 8: { componentid = 1021; }
				case 9: { componentid = 1025; }
				case 10: { componentid = 1073; }
				case 11: { componentid = 1074; }
				case 12: { componentid = 1075; }
				case 13: { componentid = 1076; }
				case 14: { componentid = 1077; }
				case 15: { componentid = 1078; }
				case 16: { componentid = 1079; }
				case 17: { componentid = 1080; }
				case 18: { componentid = 1081; }
				case 19: { componentid = 1082; }
				case 20: { componentid = 1083; }
				case 21: { componentid = 1084; }
				case 22: { componentid = 1085; }
				case 23: { componentid = 1087; }
				case 24: { componentid = 1096; }
				case 25: { componentid = 1097; }
				case 26: { componentid = 1098; }
			}
		}
		case 420:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1004; }
				case 4: { componentid = 1005; }
				case 5: { componentid = 1008; }
				case 6: { componentid = 1009; }
				case 7: { componentid = 1010; }
				case 8: { componentid = 1019; }
				case 9: { componentid = 1021; }
				case 10: { componentid = 1025; }
				case 11: { componentid = 1073; }
				case 12: { componentid = 1074; }
				case 13: { componentid = 1075; }
				case 14: { componentid = 1076; }
				case 15: { componentid = 1077; }
				case 16: { componentid = 1078; }
				case 17: { componentid = 1079; }
				case 18: { componentid = 1080; }
				case 19: { componentid = 1081; }
				case 20: { componentid = 1082; }
				case 21: { componentid = 1083; }
				case 22: { componentid = 1084; }
				case 23: { componentid = 1085; }
				case 24: { componentid = 1087; }
				case 25: { componentid = 1096; }
				case 26: { componentid = 1097; }
				case 27: { componentid = 1098; }
			}
		}
		case 421:
		{
			switch(count)
			{
				case 1: { componentid = 1000; }
				case 2: { componentid = 1008; }
				case 3: { componentid = 1009; }
				case 4: { componentid = 1010; }
				case 5: { componentid = 1014; }
				case 6: { componentid = 1016; }
				case 7: { componentid = 1018; }
				case 8: { componentid = 1019; }
				case 9: { componentid = 1020; }
				case 10: { componentid = 1021; }
				case 11: { componentid = 1023; }
				case 12: { componentid = 1025; }
				case 13: { componentid = 1073; }
				case 14: { componentid = 1074; }
				case 15: { componentid = 1075; }
				case 16: { componentid = 1076; }
				case 17: { componentid = 1077; }
				case 18: { componentid = 1078; }
				case 19: { componentid = 1079; }
				case 20: { componentid = 1080; }
				case 21: { componentid = 1081; }
				case 22: { componentid = 1082; }
				case 23: { componentid = 1083; }
				case 24: { componentid = 1084; }
				case 25: { componentid = 1085; }
				case 26: { componentid = 1087; }
				case 27: { componentid = 1096; }
				case 28: { componentid = 1097; }
				case 29: { componentid = 1098; }
			}
		}
		case 422:
		{
			switch(count)
			{
				case 1: { componentid = 1007; }
				case 2: { componentid = 1008; }
				case 3: { componentid = 1009; }
				case 4: { componentid = 1010; }
				case 5: { componentid = 1013; }
				case 6: { componentid = 1017; }
				case 7: { componentid = 1019; }
				case 8: { componentid = 1020; }
				case 9: { componentid = 1021; }
				case 10: { componentid = 1025; }
				case 11: { componentid = 1073; }
				case 12: { componentid = 1074; }
				case 13: { componentid = 1075; }
				case 14: { componentid = 1076; }
				case 15: { componentid = 1077; }
				case 16: { componentid = 1078; }
				case 17: { componentid = 1079; }
				case 18: { componentid = 1080; }
				case 19: { componentid = 1081; }
				case 20: { componentid = 1082; }
				case 21: { componentid = 1083; }
				case 22: { componentid = 1084; }
				case 23: { componentid = 1085; }
				case 24: { componentid = 1087; }
				case 25: { componentid = 1096; }
				case 26: { componentid = 1097; }
				case 27: { componentid = 1098; }
			}
		}
		case 426:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1004; }
				case 4: { componentid = 1005; }
				case 5: { componentid = 1006; }
				case 6: { componentid = 1008; }
				case 7: { componentid = 1009; }
				case 8: { componentid = 1010; }
				case 9: { componentid = 1019; }
				case 10: { componentid = 1021; }
				case 11: { componentid = 1025; }
				case 12: { componentid = 1073; }
				case 13: { componentid = 1074; }
				case 14: { componentid = 1075; }
				case 15: { componentid = 1076; }
				case 16: { componentid = 1077; }
				case 17: { componentid = 1078; }
				case 18: { componentid = 1079; }
				case 19: { componentid = 1080; }
				case 20: { componentid = 1081; }
				case 21: { componentid = 1082; }
				case 22: { componentid = 1083; }
				case 23: { componentid = 1084; }
				case 24: { componentid = 1085; }
				case 25: { componentid = 1087; }
				case 26: { componentid = 1096; }
				case 27: { componentid = 1097; }
				case 28: { componentid = 1098; }
			}
		}
		case 436:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1006; }
				case 4: { componentid = 1007; }
				case 5: { componentid = 1008; }
				case 6: { componentid = 1009; }
				case 7: { componentid = 1010; }
				case 8: { componentid = 1013; }
				case 9: { componentid = 1017; }
				case 10: { componentid = 1019; }
				case 11: { componentid = 1020; }
				case 12: { componentid = 1021; }
				case 13: { componentid = 1022; }
				case 14: { componentid = 1025; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
			}
		}
		case 439:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1007; }
				case 4: { componentid = 1008; }
				case 5: { componentid = 1009; }
				case 6: { componentid = 1010; }
				case 7: { componentid = 1013; }
				case 8: { componentid = 1017; }
				case 9: { componentid = 1023; }
				case 10: { componentid = 1025; }
				case 11: { componentid = 1073; }
				case 12: { componentid = 1074; }
				case 13: { componentid = 1075; }
				case 14: { componentid = 1076; }
				case 15: { componentid = 1077; }
				case 16: { componentid = 1078; }
				case 17: { componentid = 1079; }
				case 18: { componentid = 1080; }
				case 19: { componentid = 1081; }
				case 20: { componentid = 1082; }
				case 21: { componentid = 1083; }
				case 22: { componentid = 1084; }
				case 23: { componentid = 1085; }
				case 24: { componentid = 1087; }
				case 25: { componentid = 1096; }
				case 26: { componentid = 1097; }
				case 27: { componentid = 1098; }
				case 28: { componentid = 1142; }
				case 29: { componentid = 1143; }
				case 30: { componentid = 1144; }
				case 31: { componentid = 1145; }
			}
		}
		case 477:
		{
			switch(count)
			{
				case 1: { componentid = 1006; }
				case 2: { componentid = 1007; }
				case 3: { componentid = 1008; }
				case 4: { componentid = 1009; }
				case 5: { componentid = 1010; }
				case 6: { componentid = 1017; }
				case 7: { componentid = 1018; }
				case 8: { componentid = 1019; }
				case 9: { componentid = 1020; }
				case 10: { componentid = 1021; }
				case 11: { componentid = 1025; }
				case 12: { componentid = 1073; }
				case 13: { componentid = 1074; }
				case 14: { componentid = 1075; }
				case 15: { componentid = 1076; }
				case 16: { componentid = 1077; }
				case 17: { componentid = 1078; }
				case 18: { componentid = 1079; }
				case 19: { componentid = 1080; }
				case 20: { componentid = 1081; }
				case 21: { componentid = 1082; }
				case 22: { componentid = 1083; }
				case 23: { componentid = 1084; }
				case 24: { componentid = 1085; }
				case 25: { componentid = 1087; }
				case 26: { componentid = 1096; }
				case 27: { componentid = 1097; }
				case 28: { componentid = 1098; }
			}
		}
		case 478:
		{
			switch(count)
			{
				case 1: { componentid = 1004; }
				case 2: { componentid = 1005; }
				case 3: { componentid = 1008; }
				case 4: { componentid = 1009; }
				case 5: { componentid = 1010; }
				case 6: { componentid = 1012; }
				case 7: { componentid = 1013; }
				case 8: { componentid = 1020; }
				case 9: { componentid = 1021; }
				case 10: { componentid = 1022; }
				case 11: { componentid = 1024; }
				case 12: { componentid = 1025; }
				case 13: { componentid = 1073; }
				case 14: { componentid = 1074; }
				case 15: { componentid = 1075; }
				case 16: { componentid = 1076; }
				case 17: { componentid = 1077; }
				case 18: { componentid = 1078; }
				case 19: { componentid = 1079; }
				case 20: { componentid = 1080; }
				case 21: { componentid = 1081; }
				case 22: { componentid = 1082; }
				case 23: { componentid = 1083; }
				case 24: { componentid = 1084; }
				case 25: { componentid = 1085; }
				case 26: { componentid = 1087; }
				case 27: { componentid = 1096; }
				case 28: { componentid = 1097; }
				case 29: { componentid = 1098; }
			}
		}
		case 489:
		{
			switch(count)
			{
				case 1: { componentid = 1000; }
				case 2: { componentid = 1002; }
				case 3: { componentid = 1004; }
				case 4: { componentid = 1005; }
				case 5: { componentid = 1006; }
				case 6: { componentid = 1008; }
				case 7: { componentid = 1009; }
				case 8: { componentid = 1010; }
				case 9: { componentid = 1013; }
				case 10: { componentid = 1016; }
				case 11: { componentid = 1018; }
				case 12: { componentid = 1019; }
				case 13: { componentid = 1020; }
				case 14: { componentid = 1024; }
				case 15: { componentid = 1025; }
				case 16: { componentid = 1073; }
				case 17: { componentid = 1074; }
				case 18: { componentid = 1075; }
				case 19: { componentid = 1076; }
				case 20: { componentid = 1077; }
				case 21: { componentid = 1078; }
				case 22: { componentid = 1079; }
				case 23: { componentid = 1080; }
				case 24: { componentid = 1081; }
				case 25: { componentid = 1082; }
				case 26: { componentid = 1083; }
				case 27: { componentid = 1084; }
				case 28: { componentid = 1085; }
				case 29: { componentid = 1087; }
				case 30: { componentid = 1096; }
				case 31: { componentid = 1097; }
				case 32: { componentid = 1098; }
			}
		}
		case 491:
		{
			switch(count)
			{
				case 1: { componentid = 1003; }
				case 2: { componentid = 1007; }
				case 3: { componentid = 1008; }
				case 4: { componentid = 1009; }
				case 5: { componentid = 1010; }
				case 6: { componentid = 1014; }
				case 7: { componentid = 1017; }
				case 8: { componentid = 1018; }
				case 9: { componentid = 1019; }
				case 10: { componentid = 1020; }
				case 11: { componentid = 1021; }
				case 12: { componentid = 1023; }
				case 13: { componentid = 1025; }
				case 14: { componentid = 1073; }
				case 15: { componentid = 1074; }
				case 16: { componentid = 1075; }
				case 17: { componentid = 1076; }
				case 18: { componentid = 1077; }
				case 19: { componentid = 1078; }
				case 20: { componentid = 1079; }
				case 21: { componentid = 1080; }
				case 22: { componentid = 1081; }
				case 23: { componentid = 1082; }
				case 24: { componentid = 1083; }
				case 25: { componentid = 1084; }
				case 26: { componentid = 1085; }
				case 27: { componentid = 1087; }
				case 28: { componentid = 1096; }
				case 29: { componentid = 1097; }
				case 30: { componentid = 1098; }
				case 31: { componentid = 1142; }
				case 32: { componentid = 1143; }
				case 33: { componentid = 1144; }
				case 34: { componentid = 1145; }
			}
		}
		case 492:
		{
			switch(count)
			{
				case 1: { componentid = 1000; }
				case 2: { componentid = 1004; }
				case 3: { componentid = 1005; }
				case 4: { componentid = 1006; }
				case 5: { componentid = 1008; }
				case 6: { componentid = 1009; }
				case 7: { componentid = 1010; }
				case 8: { componentid = 1016; }
				case 9: { componentid = 1025; }
				case 10: { componentid = 1073; }
				case 11: { componentid = 1074; }
				case 12: { componentid = 1075; }
				case 13: { componentid = 1076; }
				case 14: { componentid = 1077; }
				case 15: { componentid = 1078; }
				case 16: { componentid = 1079; }
				case 17: { componentid = 1080; }
				case 18: { componentid = 1081; }
				case 19: { componentid = 1082; }
				case 20: { componentid = 1083; }
				case 21: { componentid = 1084; }
				case 22: { componentid = 1085; }
				case 23: { componentid = 1087; }
				case 24: { componentid = 1096; }
				case 25: { componentid = 1097; }
				case 26: { componentid = 1098; }
			}
		}
		case 496:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1002; }
				case 3: { componentid = 1003; }
				case 4: { componentid = 1006; }
				case 5: { componentid = 1007; }
				case 6: { componentid = 1008; }
				case 7: { componentid = 1009; }
				case 8: { componentid = 1010; }
				case 9: { componentid = 1011; }
				case 10: { componentid = 1017; }
				case 11: { componentid = 1019; }
				case 12: { componentid = 1020; }
				case 13: { componentid = 1023; }
				case 14: { componentid = 1025; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
				case 32: { componentid = 1142; }
				case 33: { componentid = 1143; }
			}
		}
		case 500:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1013; }
				case 5: { componentid = 1019; }
				case 6: { componentid = 1020; }
				case 7: { componentid = 1021; }
				case 8: { componentid = 1024; }
				case 9: { componentid = 1025; }
				case 10: { componentid = 1073; }
				case 11: { componentid = 1074; }
				case 12: { componentid = 1075; }
				case 13: { componentid = 1076; }
				case 14: { componentid = 1077; }
				case 15: { componentid = 1078; }
				case 16: { componentid = 1079; }
				case 17: { componentid = 1080; }
				case 18: { componentid = 1081; }
				case 19: { componentid = 1082; }
				case 20: { componentid = 1083; }
				case 21: { componentid = 1084; }
				case 22: { componentid = 1085; }
				case 23: { componentid = 1087; }
				case 24: { componentid = 1096; }
				case 25: { componentid = 1097; }
				case 26: { componentid = 1098; }
			}
		}
		case 516:
		{
			switch(count)
			{
				case 1: { componentid = 1000; }
				case 2: { componentid = 1002; }
				case 3: { componentid = 1004; }
				case 4: { componentid = 1007; }
				case 5: { componentid = 1008; }
				case 6: { componentid = 1009; }
				case 7: { componentid = 1010; }
				case 8: { componentid = 1015; }
				case 9: { componentid = 1016; }
				case 10: { componentid = 1017; }
				case 11: { componentid = 1018; }
				case 12: { componentid = 1019; }
				case 13: { componentid = 1020; }
				case 14: { componentid = 1021; }
				case 15: { componentid = 1025; }
				case 16: { componentid = 1073; }
				case 17: { componentid = 1074; }
				case 18: { componentid = 1075; }
				case 19: { componentid = 1076; }
				case 20: { componentid = 1077; }
				case 21: { componentid = 1078; }
				case 22: { componentid = 1079; }
				case 23: { componentid = 1080; }
				case 24: { componentid = 1081; }
				case 25: { componentid = 1082; }
				case 26: { componentid = 1083; }
				case 27: { componentid = 1084; }
				case 28: { componentid = 1085; }
				case 29: { componentid = 1087; }
				case 30: { componentid = 1096; }
				case 31: { componentid = 1097; }
				case 32: { componentid = 1098; }
			}
		}
		case 517:
		{
			switch(count)
			{
				case 1: { componentid = 1002; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1007; }
				case 4: { componentid = 1008; }
				case 5: { componentid = 1009; }
				case 6: { componentid = 1010; }
				case 7: { componentid = 1016; }
				case 8: { componentid = 1017; }
				case 9: { componentid = 1018; }
				case 10: { componentid = 1019; }
				case 11: { componentid = 1020; }
				case 12: { componentid = 1023; }
				case 13: { componentid = 1025; }
				case 14: { componentid = 1073; }
				case 15: { componentid = 1074; }
				case 16: { componentid = 1075; }
				case 17: { componentid = 1076; }
				case 18: { componentid = 1077; }
				case 19: { componentid = 1078; }
				case 20: { componentid = 1079; }
				case 21: { componentid = 1080; }
				case 22: { componentid = 1081; }
				case 23: { componentid = 1082; }
				case 24: { componentid = 1083; }
				case 25: { componentid = 1084; }
				case 26: { componentid = 1085; }
				case 27: { componentid = 1087; }
				case 28: { componentid = 1096; }
				case 29: { componentid = 1097; }
				case 30: { componentid = 1098; }
				case 31: { componentid = 1142; }
				case 32: { componentid = 1143; }
				case 33: { componentid = 1144; }
				case 34: { componentid = 1145; }
			}
		}
		case 518:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1005; }
				case 4: { componentid = 1006; }
				case 5: { componentid = 1007; }
				case 6: { componentid = 1008; }
				case 7: { componentid = 1009; }
				case 8: { componentid = 1010; }
				case 9: { componentid = 1013; }
				case 10: { componentid = 1017; }
				case 11: { componentid = 1018; }
				case 12: { componentid = 1020; }
				case 13: { componentid = 1023; }
				case 14: { componentid = 1025; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
				case 32: { componentid = 1142; }
				case 33: { componentid = 1143; }
				case 34: { componentid = 1144; }
				case 35: { componentid = 1145; }
			}
		}
		case 527:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1007; }
				case 3: { componentid = 1008; }
				case 4: { componentid = 1009; }
				case 5: { componentid = 1010; }
				case 6: { componentid = 1014; }
				case 7: { componentid = 1015; }
				case 8: { componentid = 1017; }
				case 9: { componentid = 1018; }
				case 10: { componentid = 1020; }
				case 11: { componentid = 1021; }
				case 12: { componentid = 1025; }
				case 13: { componentid = 1073; }
				case 14: { componentid = 1074; }
				case 15: { componentid = 1075; }
				case 16: { componentid = 1076; }
				case 17: { componentid = 1077; }
				case 18: { componentid = 1078; }
				case 19: { componentid = 1079; }
				case 20: { componentid = 1080; }
				case 21: { componentid = 1081; }
				case 22: { componentid = 1082; }
				case 23: { componentid = 1083; }
				case 24: { componentid = 1084; }
				case 25: { componentid = 1085; }
				case 26: { componentid = 1087; }
				case 27: { componentid = 1096; }
				case 28: { componentid = 1097; }
				case 29: { componentid = 1098; }
			}
		}
		case 529:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1006; }
				case 4: { componentid = 1007; }
				case 5: { componentid = 1008; }
				case 6: { componentid = 1009; }
				case 7: { componentid = 1010; }
				case 8: { componentid = 1011; }
				case 9: { componentid = 1012; }
				case 10: { componentid = 1017; }
				case 11: { componentid = 1018; }
				case 12: { componentid = 1019; }
				case 13: { componentid = 1020; }
				case 14: { componentid = 1023; }
				case 15: { componentid = 1025; }
				case 16: { componentid = 1073; }
				case 17: { componentid = 1074; }
				case 18: { componentid = 1075; }
				case 19: { componentid = 1076; }
				case 20: { componentid = 1077; }
				case 21: { componentid = 1078; }
				case 22: { componentid = 1079; }
				case 23: { componentid = 1080; }
				case 24: { componentid = 1081; }
				case 25: { componentid = 1082; }
				case 26: { componentid = 1083; }
				case 27: { componentid = 1084; }
				case 28: { componentid = 1085; }
				case 29: { componentid = 1087; }
				case 30: { componentid = 1096; }
				case 31: { componentid = 1097; }
				case 32: { componentid = 1098; }
			}
		}
		case 534:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1073; }
				case 6: { componentid = 1074; }
				case 7: { componentid = 1075; }
				case 8: { componentid = 1076; }
				case 9: { componentid = 1077; }
				case 10: { componentid = 1078; }
				case 11: { componentid = 1079; }
				case 12: { componentid = 1080; }
				case 13: { componentid = 1081; }
				case 14: { componentid = 1082; }
				case 15: { componentid = 1083; }
				case 16: { componentid = 1084; }
				case 17: { componentid = 1085; }
				case 18: { componentid = 1087; }
				case 19: { componentid = 1096; }
				case 20: { componentid = 1097; }
				case 21: { componentid = 1098; }
				case 22: { componentid = 1100; }
				case 23: { componentid = 1101; }
				case 24: { componentid = 1106; }
				case 25: { componentid = 1122; }
				case 26: { componentid = 1123; }
				case 27: { componentid = 1124; }
				case 28: { componentid = 1125; }
				case 29: { componentid = 1126; }
				case 30: { componentid = 1127; }
				case 31: { componentid = 1178; }
				case 32: { componentid = 1179; }
				case 33: { componentid = 1180; }
				case 34: { componentid = 1185; }
			}
		}
		case 535:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1073; }
				case 6: { componentid = 1074; }
				case 7: { componentid = 1075; }
				case 8: { componentid = 1076; }
				case 9: { componentid = 1077; }
				case 10: { componentid = 1078; }
				case 11: { componentid = 1079; }
				case 12: { componentid = 1080; }
				case 13: { componentid = 1081; }
				case 14: { componentid = 1082; }
				case 15: { componentid = 1083; }
				case 16: { componentid = 1084; }
				case 17: { componentid = 1085; }
				case 18: { componentid = 1087; }
				case 19: { componentid = 1096; }
				case 20: { componentid = 1097; }
				case 21: { componentid = 1098; }
				case 22: { componentid = 1109; }
				case 23: { componentid = 1110; }
				case 24: { componentid = 1113; }
				case 25: { componentid = 1114; }
				case 26: { componentid = 1115; }
				case 27: { componentid = 1116; }
				case 28: { componentid = 1117; }
				case 29: { componentid = 1118; }
				case 30: { componentid = 1119; }
				case 31: { componentid = 1120; }
				case 32: { componentid = 1121; }
			}
		}
		case 536:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1073; }
				case 6: { componentid = 1074; }
				case 7: { componentid = 1075; }
				case 8: { componentid = 1076; }
				case 9: { componentid = 1077; }
				case 10: { componentid = 1078; }
				case 11: { componentid = 1079; }
				case 12: { componentid = 1080; }
				case 13: { componentid = 1081; }
				case 14: { componentid = 1082; }
				case 15: { componentid = 1083; }
				case 16: { componentid = 1084; }
				case 17: { componentid = 1085; }
				case 18: { componentid = 1087; }
				case 19: { componentid = 1096; }
				case 20: { componentid = 1097; }
				case 21: { componentid = 1098; }
				case 22: { componentid = 1103; }
				case 23: { componentid = 1104; }
				case 24: { componentid = 1105; }
				case 25: { componentid = 1107; }
				case 26: { componentid = 1108; }
				case 27: { componentid = 1128; }
				case 28: { componentid = 1181; }
				case 29: { componentid = 1182; }
				case 30: { componentid = 1183; }
				case 31: { componentid = 1184; }
			}
		}
		case 540:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1004; }
				case 3: { componentid = 1006; }
				case 4: { componentid = 1007; }
				case 5: { componentid = 1008; }
				case 6: { componentid = 1009; }
				case 7: { componentid = 1010; }
				case 8: { componentid = 1017; }
				case 9: { componentid = 1018; }
				case 10: { componentid = 1019; }
				case 11: { componentid = 1020; }
				case 12: { componentid = 1023; }
				case 13: { componentid = 1024; }
				case 14: { componentid = 1025; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
				case 32: { componentid = 1142; }
				case 33: { componentid = 1143; }
				case 34: { componentid = 1144; }
				case 35: { componentid = 1145; }
			}
		}
		case 542:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1014; }
				case 5: { componentid = 1015; }
				case 6: { componentid = 1018; }
				case 7: { componentid = 1019; }
				case 8: { componentid = 1020; }
				case 9: { componentid = 1021; }
				case 10: { componentid = 1025; }
				case 11: { componentid = 1073; }
				case 12: { componentid = 1074; }
				case 13: { componentid = 1075; }
				case 14: { componentid = 1076; }
				case 15: { componentid = 1077; }
				case 16: { componentid = 1078; }
				case 17: { componentid = 1079; }
				case 18: { componentid = 1080; }
				case 19: { componentid = 1081; }
				case 20: { componentid = 1082; }
				case 21: { componentid = 1083; }
				case 22: { componentid = 1084; }
				case 23: { componentid = 1085; }
				case 24: { componentid = 1087; }
				case 25: { componentid = 1096; }
				case 26: { componentid = 1097; }
				case 27: { componentid = 1098; }
				case 28: { componentid = 1144; }
				case 29: { componentid = 1145; }
			}
		}
		case 546:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1002; }
				case 3: { componentid = 1004; }
				case 4: { componentid = 1006; }
				case 5: { componentid = 1007; }
				case 6: { componentid = 1008; }
				case 7: { componentid = 1009; }
				case 8: { componentid = 1010; }
				case 9: { componentid = 1017; }
				case 10: { componentid = 1018; }
				case 11: { componentid = 1019; }
				case 12: { componentid = 1023; }
				case 13: { componentid = 1024; }
				case 14: { componentid = 1025; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
				case 32: { componentid = 1142; }
				case 33: { componentid = 1143; }
				case 34: { componentid = 1144; }
				case 35: { componentid = 1145; }
			}
		}
		case 547:
		{
			switch(count)
			{
				case 1: { componentid = 1000; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1008; }
				case 4: { componentid = 1009; }
				case 5: { componentid = 1010; }
				case 6: { componentid = 1016; }
				case 7: { componentid = 1018; }
				case 8: { componentid = 1019; }
				case 9: { componentid = 1020; }
				case 10: { componentid = 1021; }
				case 11: { componentid = 1025; }
				case 12: { componentid = 1073; }
				case 13: { componentid = 1074; }
				case 14: { componentid = 1075; }
				case 15: { componentid = 1076; }
				case 16: { componentid = 1077; }
				case 17: { componentid = 1078; }
				case 18: { componentid = 1079; }
				case 19: { componentid = 1080; }
				case 20: { componentid = 1081; }
				case 21: { componentid = 1082; }
				case 22: { componentid = 1083; }
				case 23: { componentid = 1084; }
				case 24: { componentid = 1085; }
				case 25: { componentid = 1087; }
				case 26: { componentid = 1096; }
				case 27: { componentid = 1097; }
				case 28: { componentid = 1098; }
				case 29: { componentid = 1142; }
				case 30: { componentid = 1143; }
			}
		}
		case 549:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1007; }
				case 4: { componentid = 1008; }
				case 5: { componentid = 1009; }
				case 6: { componentid = 1010; }
				case 7: { componentid = 1011; }
				case 8: { componentid = 1012; }
				case 9: { componentid = 1017; }
				case 10: { componentid = 1018; }
				case 11: { componentid = 1019; }
				case 12: { componentid = 1020; }
				case 13: { componentid = 1023; }
				case 14: { componentid = 1025; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
				case 32: { componentid = 1142; }
				case 33: { componentid = 1143; }
				case 34: { componentid = 1144; }
				case 35: { componentid = 1145; }
			}
		}
		case 550:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1004; }
				case 4: { componentid = 1005; }
				case 5: { componentid = 1006; }
				case 6: { componentid = 1008; }
				case 7: { componentid = 1009; }
				case 8: { componentid = 1010; }
				case 9: { componentid = 1018; }
				case 10: { componentid = 1019; }
				case 11: { componentid = 1020; }
				case 12: { componentid = 1023; }
				case 13: { componentid = 1025; }
				case 14: { componentid = 1073; }
				case 15: { componentid = 1074; }
				case 16: { componentid = 1075; }
				case 17: { componentid = 1076; }
				case 18: { componentid = 1077; }
				case 19: { componentid = 1078; }
				case 20: { componentid = 1079; }
				case 21: { componentid = 1080; }
				case 22: { componentid = 1081; }
				case 23: { componentid = 1082; }
				case 24: { componentid = 1083; }
				case 25: { componentid = 1084; }
				case 26: { componentid = 1085; }
				case 27: { componentid = 1087; }
				case 28: { componentid = 1096; }
				case 29: { componentid = 1097; }
				case 30: { componentid = 1098; }
				case 31: { componentid = 1142; }
				case 32: { componentid = 1143; }
				case 33: { componentid = 1144; }
				case 34: { componentid = 1145; }
			}
		}
		case 551:
		{
			switch(count)
			{
				case 1: { componentid = 1002; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1005; }
				case 4: { componentid = 1006; }
				case 5: { componentid = 1008; }
				case 6: { componentid = 1009; }
				case 7: { componentid = 1010; }
				case 8: { componentid = 1016; }
				case 9: { componentid = 1018; }
				case 10: { componentid = 1019; }
				case 11: { componentid = 1020; }
				case 12: { componentid = 1021; }
				case 13: { componentid = 1023; }
				case 14: { componentid = 1025; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
			}
		}
		case 558:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1073; }
				case 6: { componentid = 1074; }
				case 7: { componentid = 1075; }
				case 8: { componentid = 1076; }
				case 9: { componentid = 1077; }
				case 10: { componentid = 1078; }
				case 11: { componentid = 1079; }
				case 12: { componentid = 1080; }
				case 13: { componentid = 1081; }
				case 14: { componentid = 1082; }
				case 15: { componentid = 1083; }
				case 16: { componentid = 1084; }
				case 17: { componentid = 1085; }
				case 18: { componentid = 1087; }
				case 19: { componentid = 1088; }
				case 20: { componentid = 1089; }
				case 21: { componentid = 1090; }
				case 22: { componentid = 1091; }
				case 23: { componentid = 1092; }
				case 24: { componentid = 1093; }
				case 25: { componentid = 1094; }
				case 26: { componentid = 1095; }
				case 27: { componentid = 1096; }
				case 28: { componentid = 1097; }
				case 29: { componentid = 1098; }
				case 30: { componentid = 1163; }
				case 31: { componentid = 1164; }
				case 32: { componentid = 1165; }
				case 33: { componentid = 1166; }
				case 34: { componentid = 1167; }
				case 35: { componentid = 1168; }
			}
		}
		case 559:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1065; }
				case 6: { componentid = 1066; }
				case 7: { componentid = 1067; }
				case 8: { componentid = 1068; }
				case 9: { componentid = 1069; }
				case 10: { componentid = 1070; }
				case 11: { componentid = 1071; }
				case 12: { componentid = 1072; }
				case 13: { componentid = 1073; }
				case 14: { componentid = 1074; }
				case 15: { componentid = 1075; }
				case 16: { componentid = 1076; }
				case 17: { componentid = 1077; }
				case 18: { componentid = 1078; }
				case 19: { componentid = 1079; }
				case 20: { componentid = 1080; }
				case 21: { componentid = 1081; }
				case 22: { componentid = 1082; }
				case 23: { componentid = 1083; }
				case 24: { componentid = 1084; }
				case 25: { componentid = 1085; }
				case 26: { componentid = 1087; }
				case 27: { componentid = 1096; }
				case 28: { componentid = 1097; }
				case 29: { componentid = 1098; }
				case 30: { componentid = 1158; }
				case 31: { componentid = 1159; }
				case 32: { componentid = 1160; }
				case 33: { componentid = 1161; }
				case 34: { componentid = 1162; }
				case 35: { componentid = 1173; }
			}
		}
		case 560:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1026; }
				case 6: { componentid = 1027; }
				case 7: { componentid = 1028; }
				case 8: { componentid = 1029; }
				case 9: { componentid = 1030; }
				case 10: { componentid = 1031; }
				case 11: { componentid = 1032; }
				case 12: { componentid = 1033; }
				case 13: { componentid = 1073; }
				case 14: { componentid = 1074; }
				case 15: { componentid = 1075; }
				case 16: { componentid = 1076; }
				case 17: { componentid = 1077; }
				case 18: { componentid = 1078; }
				case 19: { componentid = 1079; }
				case 20: { componentid = 1080; }
				case 21: { componentid = 1081; }
				case 22: { componentid = 1082; }
				case 23: { componentid = 1083; }
				case 24: { componentid = 1084; }
				case 25: { componentid = 1085; }
				case 26: { componentid = 1087; }
				case 27: { componentid = 1096; }
				case 28: { componentid = 1097; }
				case 29: { componentid = 1098; }
				case 30: { componentid = 1138; }
				case 31: { componentid = 1139; }
				case 32: { componentid = 1140; }
				case 33: { componentid = 1141; }
				case 34: { componentid = 1169; }
				case 35: { componentid = 1170; }
			}
		}
		case 561:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1055; }
				case 6: { componentid = 1056; }
				case 7: { componentid = 1057; }
				case 8: { componentid = 1058; }
				case 9: { componentid = 1059; }
				case 10: { componentid = 1060; }
				case 11: { componentid = 1061; }
				case 12: { componentid = 1062; }
				case 13: { componentid = 1063; }
				case 14: { componentid = 1064; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
				case 32: { componentid = 1154; }
				case 33: { componentid = 1155; }
				case 34: { componentid = 1156; }
				case 35: { componentid = 1157; }
			}
		}
		case 562:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1034; }
				case 6: { componentid = 1035; }
				case 7: { componentid = 1036; }
				case 8: { componentid = 1037; }
				case 9: { componentid = 1038; }
				case 10: { componentid = 1039; }
				case 11: { componentid = 1040; }
				case 12: { componentid = 1041; }
				case 13: { componentid = 1073; }
				case 14: { componentid = 1074; }
				case 15: { componentid = 1075; }
				case 16: { componentid = 1076; }
				case 17: { componentid = 1077; }
				case 18: { componentid = 1078; }
				case 19: { componentid = 1079; }
				case 20: { componentid = 1080; }
				case 21: { componentid = 1081; }
				case 22: { componentid = 1082; }
				case 23: { componentid = 1083; }
				case 24: { componentid = 1084; }
				case 25: { componentid = 1085; }
				case 26: { componentid = 1087; }
				case 27: { componentid = 1096; }
				case 28: { componentid = 1097; }
				case 29: { componentid = 1098; }
				case 30: { componentid = 1146; }
				case 31: { componentid = 1147; }
				case 32: { componentid = 1148; }
				case 33: { componentid = 1149; }
				case 34: { componentid = 1171; }
				case 35: { componentid = 1172; }
			}
		}
		case 565:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1045; }
				case 6: { componentid = 1046; }
				case 7: { componentid = 1047; }
				case 8: { componentid = 1048; }
				case 9: { componentid = 1049; }
				case 10: { componentid = 1050; }
				case 11: { componentid = 1051; }
				case 12: { componentid = 1052; }
				case 13: { componentid = 1053; }
				case 14: { componentid = 1054; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
				case 32: { componentid = 1150; }
				case 33: { componentid = 1151; }
				case 34: { componentid = 1152; }
				case 35: { componentid = 1153; }
			}
		}
		case 567:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1073; }
				case 6: { componentid = 1074; }
				case 7: { componentid = 1075; }
				case 8: { componentid = 1076; }
				case 9: { componentid = 1077; }
				case 10: { componentid = 1078; }
				case 11: { componentid = 1079; }
				case 12: { componentid = 1080; }
				case 13: { componentid = 1081; }
				case 14: { componentid = 1082; }
				case 15: { componentid = 1083; }
				case 16: { componentid = 1084; }
				case 17: { componentid = 1085; }
				case 18: { componentid = 1087; }
				case 19: { componentid = 1096; }
				case 20: { componentid = 1097; }
				case 21: { componentid = 1098; }
				case 22: { componentid = 1102; }
				case 23: { componentid = 1129; }
				case 24: { componentid = 1130; }
				case 25: { componentid = 1131; }
				case 26: { componentid = 1132; }
				case 27: { componentid = 1133; }
				case 28: { componentid = 1186; }
				case 29: { componentid = 1187; }
				case 30: { componentid = 1188; }
				case 31: { componentid = 1189; }
			}
		}
		case 575:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1042; }
				case 6: { componentid = 1043; }
				case 7: { componentid = 1044; }
				case 8: { componentid = 1073; }
				case 9: { componentid = 1074; }
				case 10: { componentid = 1075; }
				case 11: { componentid = 1076; }
				case 12: { componentid = 1077; }
				case 13: { componentid = 1078; }
				case 14: { componentid = 1079; }
				case 15: { componentid = 1080; }
				case 16: { componentid = 1081; }
				case 17: { componentid = 1082; }
				case 18: { componentid = 1083; }
				case 19: { componentid = 1084; }
				case 20: { componentid = 1085; }
				case 21: { componentid = 1087; }
				case 22: { componentid = 1096; }
				case 23: { componentid = 1097; }
				case 24: { componentid = 1098; }
				case 25: { componentid = 1099; }
				case 26: { componentid = 1174; }
				case 27: { componentid = 1175; }
				case 28: { componentid = 1176; }
				case 29: { componentid = 1177; }
			}
		}
		case 576:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1073; }
				case 6: { componentid = 1074; }
				case 7: { componentid = 1075; }
				case 8: { componentid = 1076; }
				case 9: { componentid = 1077; }
				case 10: { componentid = 1078; }
				case 11: { componentid = 1079; }
				case 12: { componentid = 1080; }
				case 13: { componentid = 1081; }
				case 14: { componentid = 1082; }
				case 15: { componentid = 1083; }
				case 16: { componentid = 1084; }
				case 17: { componentid = 1085; }
				case 18: { componentid = 1087; }
				case 19: { componentid = 1096; }
				case 20: { componentid = 1097; }
				case 21: { componentid = 1098; }
				case 22: { componentid = 1134; }
				case 23: { componentid = 1135; }
				case 24: { componentid = 1136; }
				case 25: { componentid = 1137; }
				case 26: { componentid = 1190; }
				case 27: { componentid = 1191; }
				case 28: { componentid = 1192; }
				case 29: { componentid = 1193; }
			}
		}
		case 580:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1006; }
				case 3: { componentid = 1007; }
				case 4: { componentid = 1008; }
				case 5: { componentid = 1009; }
				case 6: { componentid = 1010; }
				case 7: { componentid = 1017; }
				case 8: { componentid = 1018; }
				case 9: { componentid = 1020; }
				case 10: { componentid = 1023; }
				case 11: { componentid = 1025; }
				case 12: { componentid = 1073; }
				case 13: { componentid = 1074; }
				case 14: { componentid = 1075; }
				case 15: { componentid = 1076; }
				case 16: { componentid = 1077; }
				case 17: { componentid = 1078; }
				case 18: { componentid = 1079; }
				case 19: { componentid = 1080; }
				case 20: { componentid = 1081; }
				case 21: { componentid = 1082; }
				case 22: { componentid = 1083; }
				case 23: { componentid = 1084; }
				case 24: { componentid = 1085; }
				case 25: { componentid = 1087; }
				case 26: { componentid = 1096; }
				case 27: { componentid = 1097; }
				case 28: { componentid = 1098; }
			}
		}
		case 585:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1003; }
				case 3: { componentid = 1006; }
				case 4: { componentid = 1007; }
				case 5: { componentid = 1008; }
				case 6: { componentid = 1009; }
				case 7: { componentid = 1010; }
				case 8: { componentid = 1013; }
				case 9: { componentid = 1017; }
				case 10: { componentid = 1018; }
				case 11: { componentid = 1019; }
				case 12: { componentid = 1020; }
				case 13: { componentid = 1023; }
				case 14: { componentid = 1025; }
				case 15: { componentid = 1073; }
				case 16: { componentid = 1074; }
				case 17: { componentid = 1075; }
				case 18: { componentid = 1076; }
				case 19: { componentid = 1077; }
				case 20: { componentid = 1078; }
				case 21: { componentid = 1079; }
				case 22: { componentid = 1080; }
				case 23: { componentid = 1081; }
				case 24: { componentid = 1082; }
				case 25: { componentid = 1083; }
				case 26: { componentid = 1084; }
				case 27: { componentid = 1085; }
				case 28: { componentid = 1087; }
				case 29: { componentid = 1096; }
				case 30: { componentid = 1097; }
				case 31: { componentid = 1098; }
				case 32: { componentid = 1142; }
				case 33: { componentid = 1143; }
				case 34: { componentid = 1144; }
				case 35: { componentid = 1145; }
			}
		}
		case 589:
		{
			switch(count)
			{
				case 1: { componentid = 1000; }
				case 2: { componentid = 1004; }
				case 3: { componentid = 1005; }
				case 4: { componentid = 1006; }
				case 5: { componentid = 1007; }
				case 6: { componentid = 1008; }
				case 7: { componentid = 1009; }
				case 8: { componentid = 1010; }
				case 9: { componentid = 1013; }
				case 10: { componentid = 1016; }
				case 11: { componentid = 1017; }
				case 12: { componentid = 1018; }
				case 13: { componentid = 1020; }
				case 14: { componentid = 1024; }
				case 15: { componentid = 1025; }
				case 16: { componentid = 1073; }
				case 17: { componentid = 1074; }
				case 18: { componentid = 1075; }
				case 19: { componentid = 1076; }
				case 20: { componentid = 1077; }
				case 21: { componentid = 1078; }
				case 22: { componentid = 1079; }
				case 23: { componentid = 1080; }
				case 24: { componentid = 1081; }
				case 25: { componentid = 1082; }
				case 26: { componentid = 1083; }
				case 27: { componentid = 1084; }
				case 28: { componentid = 1085; }
				case 29: { componentid = 1087; }
				case 30: { componentid = 1096; }
				case 31: { componentid = 1097; }
				case 32: { componentid = 1098; }
				case 33: { componentid = 1144; }
				case 34: { componentid = 1145; }
			}
		}
		case 600:
		{
			switch(count)
			{
				case 1: { componentid = 1004; }
				case 2: { componentid = 1005; }
				case 3: { componentid = 1006; }
				case 4: { componentid = 1007; }
				case 5: { componentid = 1008; }
				case 6: { componentid = 1009; }
				case 7: { componentid = 1010; }
				case 8: { componentid = 1013; }
				case 9: { componentid = 1017; }
				case 10: { componentid = 1018; }
				case 11: { componentid = 1020; }
				case 12: { componentid = 1022; }
				case 13: { componentid = 1025; }
				case 14: { componentid = 1073; }
				case 15: { componentid = 1074; }
				case 16: { componentid = 1075; }
				case 17: { componentid = 1076; }
				case 18: { componentid = 1077; }
				case 19: { componentid = 1078; }
				case 20: { componentid = 1079; }
				case 21: { componentid = 1080; }
				case 22: { componentid = 1081; }
				case 23: { componentid = 1082; }
				case 24: { componentid = 1083; }
				case 25: { componentid = 1084; }
				case 26: { componentid = 1085; }
				case 27: { componentid = 1087; }
				case 28: { componentid = 1096; }
				case 29: { componentid = 1097; }
				case 30: { componentid = 1098; }
			}
		}
		case 603:
		{
			switch(count)
			{
				case 1: { componentid = 1001; }
				case 2: { componentid = 1006; }
				case 3: { componentid = 1007; }
				case 4: { componentid = 1008; }
				case 5: { componentid = 1009; }
				case 6: { componentid = 1010; }
				case 7: { componentid = 1017; }
				case 8: { componentid = 1018; }
				case 9: { componentid = 1019; }
				case 10: { componentid = 1020; }
				case 11: { componentid = 1023; }
				case 12: { componentid = 1024; }
				case 13: { componentid = 1025; }
				case 14: { componentid = 1073; }
				case 15: { componentid = 1074; }
				case 16: { componentid = 1075; }
				case 17: { componentid = 1076; }
				case 18: { componentid = 1077; }
				case 19: { componentid = 1078; }
				case 20: { componentid = 1079; }
				case 21: { componentid = 1080; }
				case 22: { componentid = 1081; }
				case 23: { componentid = 1082; }
				case 24: { componentid = 1083; }
				case 25: { componentid = 1084; }
				case 26: { componentid = 1085; }
				case 27: { componentid = 1087; }
				case 28: { componentid = 1096; }
				case 29: { componentid = 1097; }
				case 30: { componentid = 1098; }
				case 31: { componentid = 1142; }
				case 32: { componentid = 1143; }
				case 33: { componentid = 1144; }
				case 34: { componentid = 1145; }
			}
		}
		case 402,403,406..409,411..414,416,419,423,424,427..429,431..435,437,438,440..445,448,450,451,455..459,461..463,466..468,470,471,474,475,479..486,490,494,495,498,499,502..510,514,515,521..526,528,530..533,541,552,543..545,554..557,566,568,578,571..574,579,581..584,586..588,591,594,596..599,601,602,604..611:
		{
			switch(count)
			{
				case 1: { componentid = 1008; }
				case 2: { componentid = 1009; }
				case 3: { componentid = 1010; }
				case 4: { componentid = 1025; }
				case 5: { componentid = 1073; }
				case 6: { componentid = 1074; }
				case 7: { componentid = 1075; }
				case 8: { componentid = 1076; }
				case 9: { componentid = 1077; }
				case 10: { componentid = 1078; }
				case 11: { componentid = 1079; }
				case 12: { componentid = 1080; }
				case 13: { componentid = 1081; }
				case 14: { componentid = 1082; }
				case 15: { componentid = 1083; }
				case 16: { componentid = 1084; }
				case 17: { componentid = 1085; }
				case 18: { componentid = 1087; }
				case 19: { componentid = 1096; }
				case 20: { componentid = 1097; }
				case 21: { componentid = 1098; }
			}
		}
	}
	return componentid;
}

/*
native GetComponentName(componentid);
native IsVehicleUpgradeCompatible(model,componentid);
native GetVehicleCompatibleUpgrades(model, count, &componentid = 0);
*/