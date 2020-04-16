/*
	@File: fn_onKilled.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Sets us up for revive, ui and corpse handling shit... 
*/

_this params [
	["_unit", objNull, [objNull]], 
	["_killer", objNull, [objNull]]
];

// Force us out any vehicles...
if  !((vehicle _unit) isEqualTo _unit) then {
    unassignVehicle _unit;
    _unit action ["getOut", vehicle _unit];
};

// Save Weapons...
private _y = [];

{
    _y = _x;

    {
        if ((_y select 0) isEqualTo (_x select 0)) exitWith {
            _unit setVariable [(_y select 1), _x];
        };
    } forEach (weaponsItems _unit);
} forEach [
	[(primaryWeapon _unit), "primary"],
	[(secondaryWeapon _unit), "secondary"]
];

// Camera...
CLI_Death_Cam = "CAMERA" camCreate (getPosATL _unit);
showCinemaBorder false;

// UI...
"RscIncapacitated" cutRsc ["RscIncapacitated", "PLAIN", 0];

CLI_Death_Cam cameraEffect ["Internal", "Back"];
CLI_Death_Cam camSetTarget _unit;
CLI_Death_Cam camSetRelPos [0,3.5,4.5];
CLI_Death_Cam camSetFOV .5;
CLI_Death_Cam camSetFocus [50,0];
CLI_Death_Cam camCommit 0;

// Block ESC, Rebind to Respawn
ESC_EH_NUM = ((findDisplay 46) displayAddEventHandler ["KeyDown","if ((_this select 1) isEqualTo 1) then {[true] call CLI_fnc_respawnPlayer; true}"]);

// Effects...
if (isNil "CLI_Effects") then { CLI_Effects = [] };

_effectBlur = ppEffectCreate ["DynamicBlur", 300];
_effectBlur ppEffectEnable true;
_effectBlur ppEffectAdjust [2.5];
_effectBlur ppEffectCommit 0;

_effectColour = ppEffectCreate ["colorCorrections", 301];
_effectColour ppEffectEnable true;
_effectColour ppEffectAdjust [1, 1, 0, [0, 0, 0, 0.7], [1, 0, 0, 0.5],[1, 1, 1, 0]]; 
_effectColour ppEffectCommit 0;

CLI_Effects pushBack _effectColour;
CLI_Effects pushBack _effectBlur;

_unit spawn {
    waitUntil {
        CLI_Death_Cam camSetTarget _this;
        CLI_Death_Cam camSetRelPos [0,3.5,4.5];
        CLI_Death_Cam camCommit 0;
        speed _this isEqualTo 0
    };
};