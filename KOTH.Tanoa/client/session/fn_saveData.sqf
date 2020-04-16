/*
	@File: fn_saveData.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Creates a local save... 
*/

private _saveName = format["koth_save_%1", getPlayerUID player];

profileNamespace setVariable [_saveName, [
	CLI_XP,
	CLI_Money,
	CLI_Bought_Weapons
]];

if (time < (CLI_Last_Save + 300)) exitWith {}; // Only do file operation if it's been 5 minutes since our last save...

saveProfileNamespace;
CLI_Last_Save = time;