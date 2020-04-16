/*
	@File: fn_addXP.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Add XP, cal levels etc... 
*/

_this params [
	["_xp", 1, [0]],
	["_money", -1, [0]],
	["_reason", "", [""]]
];

if (_xp < 1) exitWith {};
if (_reason isEqualTo "") then { _reason = "Something" };

_xp = round(_xp); // force round it...

private _levelInfo = (call CLI_fnc_getLevelInfo);

CLI_XP = CLI_XP + _xp;

private _maxLevel = getNumber(missionConfigFile >> "CfgLevels" >> "maxLevel");

if (CLI_XP >= (_levelInfo select 2)) then {
	_levelInfo = (call CLI_fnc_getLevelInfo);

	// failsafe...
	if ((_levelInfo select 0) > _maxLevel) then {
		CLI_XP = (getNumber(missionConfigFile >> "CfgLevels" >> "baseXP")) * (_maxLevel - 1);
		_levelInfo = (call CLI_fnc_getLevelInfo);
	};

	if ((_levelInfo select 0) isEqualTo _maxLevel) then {
		CLI_XP = (_levelInfo select 1);
	};
};

private _notification = format["%1 <t color='#38751d'>%2xp</t>", _reason, _xp];
if !(_money isEqualTo -1) then {
	_notification = format["%1 <t color='#6aa74f'>£%2</t>", _notification, _money];
	CLI_Money = CLI_Money + _money;
};

[_notification] call CLI_fnc_notify;
[] call CLI_fnc_saveData;