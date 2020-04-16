/*
	@File: fn_getLevelInfo.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Calculates and returns our current level and required xp for next and current level... 
*/

private _xp = getNumber(missionConfigFile >> "CfgLevels" >> "baseXP");
private _level = floor (CLI_XP / _xp);

if !(_level isEqualTo (getNumber(missionConfigFile >> "CfgLevels" >> "maxLevel"))) then { _level = _level + 1 };

private _nextXP = _xp * _level;
private _thisXP = _nextXP - _xp;

[_level, _thisXP, _nextXP]