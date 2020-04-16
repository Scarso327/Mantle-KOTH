/*
	@File: fn_notify.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Used for notifiying of XP, Money increases... 
*/
#define BASE_IDC 22000
#define X(float) float * safezoneW + safezoneX
#define Y(float) float * safezoneH + safezoneY
#define Y_VAL 0.97
#define Y_INCREASE 0.02

_this params [
	["_message", "", [""]]
];

private _y = Y_VAL;

if (count(CLI_Feed) > 0) then {
	_y = _y - (Y_INCREASE * (count(CLI_Feed)));
};

private _notification = (uiNamespace getVariable ["RscPlayerHUD", displayNull]) ctrlCreate ["RscStructuredText", (BASE_IDC + count(CLI_Feed))];
_notification ctrlSetPosition [X(0.732031), Y(_y), 0.139219 * safezoneW, 0.022 * safezoneH];
_notification ctrlSetStructuredText parseText format["<t align='right' shadow='2'>%1</t>", _message];
_notification ctrlCommit 0;

playSound "FD_Timer_F";

CLI_Feed pushBack _notification;

_notification spawn {

	private _y = Y_VAL;

	waitUntil { ((ctrlPosition _this) select 1) isEqualTo (Y(Y_VAL)) };

	uiSleep 5;

	_this ctrlSetFade 1;
	_this ctrlCommit 0.25;

	uiSleep 0.25;

	CLI_Feed deleteAt (CLI_Feed find _this);
	ctrlDelete _this;

	{
		(ctrlPosition _x) params ["_xV"];

		_y = Y_VAL;

		if !(_forEachIndex isEqualTo 0) then {
			_y = _y - (Y_INCREASE * _forEachIndex);
		};

		_x ctrlSetPosition [_xV, Y(_y)];
		_x ctrlCommit 0.5;
	} forEach CLI_Feed;
};