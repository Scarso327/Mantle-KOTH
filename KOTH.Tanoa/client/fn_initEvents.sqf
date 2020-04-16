/*
	@File: fn_initEvents.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Inits events etc... 
*/

player addEventHandler ["Killed", {_this call CLI_fnc_onKilled}];
player addEventHandler ["Respawn", {_this call CLI_fnc_onRespawn}];
player addEventHandler ["GetOutMan", {_this call CLI_fnc_onLeaveVehicle}];
player addEventHandler ["HandleRating", {0}];

player addMPEventHandler["MPKilled", {
	_this params [["_unit", objNull, [objNull]], ["_killer", objNull, [objNull]]];

	if (_killer isEqualTo player) then {
		if !((faction _unit) isEqualTo (faction _killer)) then {
			[100, 100, "Enemy Killed"] call CLI_fnc_addXP;
		} else {
			// Punishment System for TKing???
		};
	};
}];