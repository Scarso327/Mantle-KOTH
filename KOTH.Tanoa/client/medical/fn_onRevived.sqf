/*
	@File: fn_onRevived.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Teleports us back and gives us our gear... 
*/

_this params [
	["_corpse", objNull, [objNull]]
];

private _loadout = getUnitLoadout _corpse;

// Gives us back any weapons we dropped if they're still there.
{
	_x params ["_weapon","_holder"];

	if !(isNull _holder) then {
		if ((_weapon select 0) isEqualTo ((weaponCargo _holder) select 0)) then {
			_loadout set[_forEachIndex, _weapon];
			deleteVehicle _holder;
		};
	};
} forEach [
	[_corpse getVariable["primary",[]], _corpse getVariable["primary_holder",objNull]],
	[_corpse getVariable["secondary",[]], _corpse getVariable["secondary_holder",objNull]]
];

player setUnitLoadout _loadout;

[] call CLI_fnc_respawnPlayer;

player setPosATL (getPosATL _corpse);
player setDir (getDir _corpse);

player setDamage 0.4;

deleteVehicle _corpse;
CLI_Corpse = nil;

if (player inArea "obj_marker") then {
	[100, 50, "Revived on Objective"] call CLI_fnc_addXP;
};