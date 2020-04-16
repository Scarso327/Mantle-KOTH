/*
	@File: fn_captureLoop.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Loops and increases side tickets, etc... 
*/

private _inControl = (call GLB_fnc_inControl);
private _exit = false;

LAST_TICK = serverTime;
publicVariable "LAST_TICK";

SIDE_SCORES = [0, 0, 0];
publicVariable "SIDE_SCORES";

for "_i" from 0 to 1 step 0 do {
	if (_exit) exitWith {};

	_inControl = (call GLB_fnc_inControl);
	
	switch (true) do {
		case (_inControl isEqualTo west): { SIDE_SCORES set [0, (SIDE_SCORES select 0) + 1]; };
		case (_inControl isEqualTo east): { SIDE_SCORES set [1, (SIDE_SCORES select 1) + 1]; };
		case (_inControl isEqualTo independent): { SIDE_SCORES set [2, (SIDE_SCORES select 2) + 1]; };
		default {  };
	};

	LAST_TICK = serverTime;

	publicVariable "LAST_TICK";
	publicVariable "SIDE_SCORES";

	{
		if (_x >= 100) exitWith {
			_exit = true;
			(format["END%1", _forEachIndex]) call BIS_fnc_endMissionServer;
		};
	} forEach SIDE_SCORES;
	 
	sleep 30;
};