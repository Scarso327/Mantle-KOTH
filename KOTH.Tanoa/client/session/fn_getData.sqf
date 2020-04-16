/*
	@File: fn_getData.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Checks for a local save... 
*/

private _saveName = format["koth_save_%1", getPlayerUID player];

if (isNil { profileNamespace getVariable _saveName }) exitWith { false };

private _save = profileNamespace getVariable _saveName;

CLI_XP = _save select 0;
CLI_Money = _save select 1;
CLI_Bought_Weapons = _save select 2;

true