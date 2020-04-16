/*
	@File: fn_revivePlayer.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Revives Corpse... 
*/

if !(canSuspend) exitWith { _this spawn CLI_fnc_revivePlayer };

(_this select 3) params [
	["_player", objNull, [objNull]],
	["_corpse", objNull, [objNull]]
];

private _result = [(time + 10)] call CLI_fnc_progressBar;
if !((_result select 0)) exitWith {};

[100, 50, "Reviving Friendly"] call CLI_fnc_addXP;
[_corpse] remoteExecCall ["CLI_fnc_onRevived", _player];