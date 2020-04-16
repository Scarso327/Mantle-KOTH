/*
	@File: initPlayerLocal.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Calls all files related to the client session... 
*/

if !(isMultiplayer) exitWith {}; // Can't play solo...

[] call CLI_fnc_initClient;