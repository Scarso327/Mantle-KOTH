/*
	@File: fn_initStores.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Finds and adds all actions to stores... 
*/

// Check for equipment box and add the actions...
if !(isNil (format["%1_equipment_box", toLower (str playerSide)])) then {
	(missionNamespace getVariable (format["%1_equipment_box", toLower (str playerSide)])) addAction ["Change Loadout", CLI_fnc_openStore, ["weapon"], 2.5, true, true, "", "", 5];
	(missionNamespace getVariable (format["%1_equipment_box", toLower (str playerSide)])) addAction ["Clothing Store", "", nil, 2, true, true, "", "", 5];
};