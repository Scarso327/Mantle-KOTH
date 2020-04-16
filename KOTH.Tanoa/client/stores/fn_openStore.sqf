/*
	@File: fn_openStore.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Creates Weapon Store UI etc... 
*/

(_this select 3) params [
	["_type", "weapon", [""]]
];

if !(createDialog "RscStore") exitWith { systemChat "Failed to Create Dialog" };

_fnc_createNavButtons = {
	private _display = (findDisplay 12000);
	if (isNull _display) exitWith { closeDialog 0; systemChat "Display couldn't be found" };

	private ["_button"];
	private _xValue = 0.314375;

	{
		_x params ["_picture", "_tooltip", "_fnc"];

		_button = _display ctrlCreate ["RscButtonIcon", -1];

		_button ctrlSetText _picture;
		_button ctrlSetTooltip _tooltip;
		_button ctrlSetEventHandler ["ButtonClick", _fnc];

		_button ctrlSetPosition [
			_xValue * safezoneW + safezoneX,
			0.269 * safezoneH + safezoneY,
			0.020625 * safeZoneW,
			0.033 * safeZoneH
		];

		_button ctrlCommit 0;

		_xValue = _xValue + 0.020625;
	} forEach _this;
};

switch (_type) do {
	case "weapon": {

		[
			[
				"\a3\ui_f\data\gui\Rsc\RscDisplayArsenal\primaryWeapon_ca.paa",
				"Rifles",
				"['Primary'] call CLI_fnc_populateWeaponList;"
			],
			[
				"\a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemOptic_ca.paa",
				"Scopes",
				""
			],
			[
				"\a3\ui_f\data\gui\Rsc\RscDisplayArsenal\secondaryWeapon_ca.paa",
				"Launchers",
				"['Secondary'] call CLI_fnc_populateWeaponList;"
			],
			[
				"\a3\ui_f\data\gui\Rsc\RscDisplayArsenal\handgun_ca.paa",
				"Handguns",
				"['Handgun'] call CLI_fnc_populateWeaponList;"
			]
		] call _fnc_createNavButtons;

		[] call CLI_fnc_populateWeaponList;
	};
};