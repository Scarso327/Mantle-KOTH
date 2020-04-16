/*
	@File: fn_progressBar.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Title... 
*/

//TODO: Animation

_this params [
	["_endTime", (time + 60), [0]]
];

private _startTime = time;

private _result = [false, "unknown"];

for "_i" from 0 to 1 step 0 do {
	if !([false] call GLB_fnc_canDO) exitWith { _result = [false, ""] };
	if (time >= _endTime) exitWith { _result = [true, ""] };

	systemChat format["Progress: %1/100", (((time - _startTime) / (_endTime - _startTime)) * 100)];
};

_result