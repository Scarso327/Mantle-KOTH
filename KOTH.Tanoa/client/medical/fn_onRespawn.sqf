/*
	@File: fn_onRespawn.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Gives us a variable for our corpse... 
*/

if !(canSuspend) exitWith { _this spawn CLI_fnc_onRespawn };

_this params [
	["_unit", objNull, [objNull]], 
	["_corpse", objNull, [objNull]]
];

player playMoveNow "AmovPpneMstpSrasWrflDnon";

CLI_Corpse = _corpse;

waitUntil { (primaryWeapon CLI_Corpse) isEqualTo "" }; // Ensure we've dropped our weapons...

// Get the weaponn holders for anything we dropped...
private _primary = (CLI_Corpse getVariable ["primary", [""]]) select 0;
private _secondary = (CLI_Corpse getVariable ["secondary", [""]]) select 0;

private _nObjects = nearestObjects [CLI_Corpse, ["WeaponHolderSimulated"], 5] select { local _x };

private _y = [];

{
	_y = _x;

	{
		if (!((_y select 0) isEqualTo "") && { (_y select 0) isEqualTo ((weaponCargo _x) select 0) }) exitWith {
			CLI_Corpse setVariable [format["%1_holder", (_y select 1)], _x];
		};
	} forEach _nObjects;
} forEach [
	[_primary, "primary"],
	[_secondary, "secondary"]
];

// Tells everyone we can be revived...
CLI_Corpse setVariable ["rev", _unit, true];