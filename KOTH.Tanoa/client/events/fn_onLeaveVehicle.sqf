/*
	@File: fn_onLeaveVehicle.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Attached to "GetOutMan" event handler, does parachute stuff... 
*/

_this params [
	["_unit", objNull, [objNull]], 
	["_role", "", [""]], 
	["_vehicle", objNull, [objNull]],
	["_turret", [], [[]]]
];

if (_vehicle isKindOf "Air") then {
	if (((getPosATL _unit) select 2) >= 100 && { alive _unit }) then {
		_unit spawn {
			waitUntil { ((getPosATL _this) select 2) <= 100 };

			private _chute = createVehicle ['Steerable_Parachute_F', position _this, [], 0, 'FLY'];
			_chute allowDamage false;
			_chute setPos (position _this);
			_this moveInDriver _chute;
		};
	};
};