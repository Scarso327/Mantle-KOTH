/*
	@File: fn_initClient.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Client side stuff... 
*/

CLI_Feed = [];
CLI_Last_Save = time;

if !(call CLI_fnc_getData) then {
	CLI_XP = 0;
	CLI_Money = 5000;
	CLI_Bought_Weapons = [];
};

[] call CLI_fnc_initEvents;

waitUntil {!(isNull (findDisplay 46))}; // Wait for UI...

["InitializePlayer", [player, true]] call BIS_fnc_dynamicGroups;

// Wait for Server...
waitUntil { !(isNil "SRV_Ready") };
waitUntil { SRV_Ready };

[] call CLI_fnc_initStores;

player setPos (markerPos (format["respawn_point_%1", toLower(str playerSide)]));

[] spawn CLI_fnc_hudLoop;
[] spawn {

	private _nearbyDead = [];
	private _revOption = objNull;

	for "_i" from 0 to 1 step 0 do {

		_nearbyDead = ([] call CLI_fnc_getNearbyDead);
	
		if ((count _nearbyDead) > 0) then {
			if (isNil "rev_action_id") then {
				_revOption = [((_nearbyDead select 0) getVariable "rev"), (_nearbyDead select 0)];

				rev_action_id = (player addAction [format["Revive %1", name (_revOption select 0)], CLI_fnc_revivePlayer, [(_revOption select 0), (_revOption select 1)], 2]);
			};
		} else {
			if !(isNil "rev_action_id") then {
				player removeAction rev_action_id;
				rev_action_id = nil;
			};
		};

		sleep 0.2;
	};
};