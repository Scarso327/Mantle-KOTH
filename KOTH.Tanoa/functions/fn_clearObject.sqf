/*
	@File: fn_clearObject.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Clears inventory of object... 
*/

_this params [
	["_obj", objNull, [objNull]]
];

if (isNull _obj) exitWith {};

clearWeaponCargoGlobal _obj;
clearMagazineCargoGlobal _obj;
clearItemCargoGlobal _obj;
clearBackpackCargoGlobal _obj;