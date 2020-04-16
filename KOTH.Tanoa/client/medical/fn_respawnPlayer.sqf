/*
	@File: fn_respawnPlayer.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Respawns.. 
*/

_this params [["_changePos", false, [true]]];

// Remove UI...
"RscIncapacitated" cutText ["","PLAIN"];

// Remove Binding...
if !(isNil "ESC_EH_NUM") then {
	(findDisplay 46) displayRemoveEventHandler ["KeyDown", ESC_EH_NUM];
	ESC_EH_NUM = nil;
};

// Remove Effects...
{ ppEffectDestroy _x } forEach CLI_Effects;
CLI_Effects = [];

// Handle Corpse...
if !(isNil "CLI_Corpse") then {
	CLI_Corpse setVariable ["rev", nil, true];
	removeAllActions CLI_Corpse;
	CLI_Corpse = nil;
};

// Teleport to Base...
if (_changePos) then {
	player setPos (markerPos (format["respawn_point_%1", toLower(str playerSide)]));
};

// Remove Camera...
CLI_Death_Cam cameraEffect ["TERMINATE","BACK"];
camDestroy CLI_Death_Cam;