/*
	@File: fn_createBase.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Creates base markers and location... 
*/
#define CFG missionConfigFile >> "CfgZones" >> worldName

if !(_this params [
	["_zone", "", [""]]
]) exitWith {};

private _base = objNull;
private _object = objNull;

private _name = "";
private _loc = [];
private _size = [];
private _rot = 0;

private _veh = objNull;
private _vehLoc = [];

{
	_base = (CFG >> _zone >> _x);

	{
		if (_x params [
			["_classname", "", [""]],
			["_cPos", [], [[]]],
			["_func", "", [""]]
		]) then {
			_object = _classname createVehicle [0, 0, 0];
			_object allowDamage false;
			_object enableSimulation false;

			_object call compile _func;

			_object setDir (_cPos select 3);
			_object setPosATL [_cPos select 0, _cPos select 1, _cPos select 2];
		};
	} forEach (getArray(_base >> "Buildings" >> "objects"));

	_vehLoc = (getArray (_base >> "vehicleSpawn"));

	if !(_vehLoc isEqualTo []) then {
		private _veh = (getText (_base >> "vehicleClass")) createVehicle [_vehLoc select 0, _vehLoc select 1, _vehLoc select 2];
		_veh setDir (_vehLoc select 3);
		_veh setVehiclePosition [[_vehLoc select 0, _vehLoc select 1, _vehLoc select 2], [], 0, "CAN_COLLIDE"];

		[_veh] call GLB_fnc_clearObject;

		[
			_veh, 180, 300, -1, { [(_this select 0)] call GLB_fnc_clearObject }, 0, 1, 2, false
		] call BIS_fnc_moduleRespawnVehicle;
	};

	_name = (getText (_base >> "name"));
	_loc = (getArray (_base >> "spawnLocation"));
	_rot = (_loc select 2);
	_size = (getArray (CFG >> _zone >> "safezoneSize"));

	// Safezone Marker...
	[format["%1_safezone", _x], "", "", "ELLIPSE", _loc, _size, "Solid", "ColorBlack", 0.5, _rot] call GLB_fnc_createMarker;
	[format["%1_safezone_outline", _x], "", "", "ELLIPSE", _loc, _size, "Border", "ColorBlack", 1, _rot] call GLB_fnc_createMarker;

	// Respawn Marker...
	[format["respawn_point_%1", _x], "", "Empty", "ICON", _loc, [1,1], "Solid", "ColorBlack", 1, 0] call GLB_fnc_createMarker;

} forEach (["west", "independent", "east"] select { 
	isClass(CFG >> _zone >> _x) 
});