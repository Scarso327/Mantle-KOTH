/*
	@File: initServer.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Calls all files related to the server session... 
*/

if !(isServer) exitWith {};

[] call SRV_fnc_initServer;