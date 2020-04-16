/*
	@File: fn_initServer.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Server side stuff... 
*/

SRV_Ready = false;
publicVariable "SRV_Ready";

["Initialize"] call BIS_fnc_dynamicGroups;

private _zone = selectRandom ("true" configClasses (missionConfigFile >> "CfgZones" >> worldName));

private _objPosition = (getArray (_zone >> "zoneLocation"));
private _objRotation = (_objPosition select 2);
private _objSize = (getArray (_zone >> "zoneSize"));

["obj_marker", "", "", "ELLIPSE", _objPosition, _objSize, "Solid", "ColorBlack", 0.5, _objRotation] call GLB_fnc_createMarker;
["obj_marker_outline", "", "", "ELLIPSE", _objPosition, _objSize, "Border", "ColorBlack", 1, _objRotation] call GLB_fnc_createMarker;

(configName _zone) call SRV_fnc_createBase;
[] spawn SRV_fnc_captureLoop;

SRV_Ready = true;
publicVariable "SRV_Ready";