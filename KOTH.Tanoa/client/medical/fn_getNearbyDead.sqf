/*
	@File: fn_getNearbyDead.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Returns array of nearby dead people... 
*/

allDeadMen select { !(isNil { _x getVariable "rev" }) && { (_x distance player) <= 2 } && { (faction player) isEqualTo (faction _x) }};