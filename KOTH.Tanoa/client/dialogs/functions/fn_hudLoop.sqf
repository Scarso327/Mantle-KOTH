/*
	@File: fn_hudLoop.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Updates HUD as well as objective colouring... 
*/
#define HUD (uiNamespace getVariable ["RscPlayerHUD", displayNull])
#define HUDCtrl(ctrl) (HUD displayCtrl ctrl)

#define WEST_COLOUR [0, 0.3, 0.6, 0.5]
#define INDP_COLOUR [0.0, 0.5, 0, 0.5]
#define EAST_COLOUR [0.5, 0, 0, 0.5]
#define CONTESTED_COLOUR [0.7, 0.6, 0, 0.4]
#define NEUTRAL_COLOUR [0, 0, 0, 0.4]

disableSerialization;

#include "..\macros.hpp"

private _inControl = (call GLB_fnc_inControl);
private _barColour = NEUTRAL_COLOUR;

private _requiredXP = 0;
private _lastTick = 0;

for "_i" from 0 to 1 step 0 do {

	if (isNull HUD) then { cutRsc ["RscPlayerHUD", "PLAIN", 2, true] };

	_inControl = (call GLB_fnc_inControl);

	// Map Markers...

	switch (true) do {
		case (_inControl isEqualTo west): { "obj_marker" setMarkerColorLocal "colorBLUFOR"; _barColour = WEST_COLOUR };
		case (_inControl isEqualTo east): { "obj_marker" setMarkerColorLocal "colorOPFOR"; _barColour = EAST_COLOUR };
		case (_inControl isEqualTo independent): { "obj_marker" setMarkerColorLocal "colorIndependent"; _barColour = INDP_COLOUR };
		case (_inControl isEqualTo sideUnknown): { "obj_marker" setMarkerColorLocal "ColorUNKNOWN"; _barColour = CONTESTED_COLOUR };
		default { "obj_marker" setMarkerColorLocal "ColorBlack"; _barColour = NEUTRAL_COLOUR };
	};

	// Hud...

	HUDCtrl(IDC_HEALTH_BAR) progressSetPosition (1 - (damage player));
	HUDCtrl(IDC_HEALTH_TEXT) ctrlSetStructuredText parseText format["Health<t align='right'>%1</t>", [round((1 - (damage player)) * 100), "%"] joinString ""];

	_requiredXP = (call CLI_fnc_getLevelInfo);

	HUDCtrl(IDC_XP_BAR) progressSetPosition ((CLI_XP - (_requiredXP select 1)) / ((_requiredXP select 2) - (_requiredXP select 1)));
	HUDCtrl(IDC_XP_TEXT) ctrlSetStructuredText parseText format["XP<t align='right'>%1/%2</t>", CLI_XP, (_requiredXP select 2)];

	if (!(LAST_TICK isEqualTo _lastTick) && { player inArea "obj_marker" }) then {
		if (playerSide isEqualTo _inControl) then {
			[100, 50, "Holding Main Objective"] call CLI_fnc_addXP;
		} else {
			[100, 50, "Attacking Main Objective"] call CLI_fnc_addXP;
		};
	};

	_lastTick = LAST_TICK;

	HUDCtrl(IDC_TICK_BAR) progressSetPosition ((serverTime - LAST_TICK) / 30);
	HUDCtrl(IDC_TICK_BAR) ctrlSetTextColor _barColour;

	HUDCtrl(IDC_WEST_SCORE_TEXT) ctrlSetStructuredText parseText format["%1", SIDE_SCORES select 0];
	HUDCtrl(IDC_INDP_SCORE_TEXT) ctrlSetStructuredText parseText format["%1", SIDE_SCORES select 2];
	HUDCtrl(IDC_EAST_SCORE_TEXT) ctrlSetStructuredText parseText format["%1", SIDE_SCORES select 1];

	HUDCtrl(IDC_CASH_TEXT) ctrlSetStructuredText parseText format["%1 £", CLI_Money];
	
	sleep 0.1;
};