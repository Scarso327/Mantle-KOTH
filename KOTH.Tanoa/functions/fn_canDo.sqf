/*
	@File: fn_canDo.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Returns if we're able to do this action or not... 
*/

_this params [
	["_inVehicle", false, [false]]
];

(_inVehicle && (isNull (objectParent player))) ||
{ alive player && (isNil "CLI_Corpse") }