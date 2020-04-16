/*
	@File: fn_populateWeaponList.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Creates Weapon Store UI etc... 
*/

_this params [
	["_section", (uiNamespace getVariable ["wep_sec", "Primary"]), [""]]
];

if !(isClass(missionConfigFile >> "CfgStores" >> "Weapon" >> _section)) exitWith { closeDialog 0; systemChat "Failed to create list as section doesn't exist" };

private _display = (findDisplay 12000);
private _scrollView = (_display displayCtrl 12009);
if (isNull _scrollView) exitWith { closeDialog 0; systemChat "Scroll view couldn't be found" };

// Wipe anything already present...
if !(isNil { uiNamespace getVariable "elements" }) then {
	{
		{
			ctrlDelete _x;
		} forEach _x;
	} forEach (uiNamespace getVariable "elements");

	uiNamespace setVariable ["elements", nil];
};

private _allObjects = [];
private _idc = 100000;
private _y = 0;

private ["_picture", "_mag", "_title", "_buyPrice", "_rentPrice", "_buyButton", "_rentButton","_elements", "_variant"];

{
	_variant = (getArray(_x >> "variants")) select 0;
	_elements = [];

	_picture = _display ctrlCreate ["RscPictureKeepAspect", _idc, _scrollView];
	_picture ctrlSetTooltip (getText(configFile >> "CfgWeapons" >> _variant >> "displayName"));
	_picture ctrlSetText (getText(configFile >> "CfgWeapons" >> _variant >> "picture"));
	_picture ctrlSetPosition [0, _y, 0.35, 0.23];
	_elements pushBack _picture;

	_mag = _display ctrlCreate ["RscPictureKeepAspect", _idc + 1, _scrollView];
	_mag ctrlSetText "\a3\Weapons_F\MagazineProxies\data\UI\icon_30Rnd_556x45_Stanag_CA.paa";
	_mag ctrlSetPosition [0.35, _y, 0.12, 0.23];
	_elements pushBack _mag;

	_title = _display ctrlCreate ["RscStructuredText", _idc + 2, _scrollView];
	_title ctrlSetStructuredText parseText format["<t size='1.5'>%1", (getText(configFile >> "CfgWeapons" >> _variant >> "displayName"))];
	_title ctrlSetPosition [0.47, (0.02 + _y), 0.175313 * safezoneW, 0.033 * safezoneH];
	_elements pushBack _title;

	_rentButton = _display ctrlCreate ["RscButtonMenu", _idc + 5, _scrollView];
	_rentButton ctrlSetPosition [0.47, (0.115 + _y),0.0670312 * safezoneW,0.022 * safezoneH];
	_rentButton ctrlSetBackgroundColor [0, 0, 0, 1];

	if (!((configName _x) in CLI_Bought_Weapons) && { (getNumber(_x >> "forceUnlocked")) isEqualTo 0 }) then {
			_rentPrice = _display ctrlCreate ["RscStructuredText", _idc + 3, _scrollView];
			_rentPrice ctrlSetStructuredText parseText format["<t color='#6aa74f'>£ %1</t>", (getNumber(_x >> "rentCost"))];
			_rentPrice ctrlSetPosition [0.530937 * safezoneW + safezoneX,0.115,0.1082818 * safezoneW,0.022 * safezoneH];
			_elements pushBack _rentPrice;

			_buyPrice = _display ctrlCreate ["RscStructuredText", _idc + 4, _scrollView];
			_buyPrice ctrlSetStructuredText parseText format["<t color='#6aa74f'>£ %1</t>", (getNumber(_x >> "buyCost"))];
			_buyPrice ctrlSetPosition [0.530937 * safezoneW + safezoneX,0.157 ,0.1082818 * safezoneW,0.022 * safezoneH];
			_elements pushBack _buyPrice;

		_rentButton ctrlSetText "RENT";
		_buyButton = _display ctrlCreate ["RscButtonMenu", _idc + 6, _scrollView];
		_buyButton ctrlSetText "BUY";
	} else {
		_rentButton ctrlSetText "EQUIP";
		_buyButton = _display ctrlCreate ["RscStructuredText", _idc + 6, _scrollView];
		_buyButton ctrlSetText "OWNED";
	};

	_buyButton ctrlSetPosition [0.47,(0.157 + _y), 0.0670312 * safezoneW,0.022 * safezoneH];
	_buyButton ctrlSetBackgroundColor [0, 0, 0, 1];

	_elements pushBack _rentButton;
	_elements pushBack _buyButton;

	_idc = (_idc + (count _elements)) + 1;
	_y = _y + 0.23;
	_allObjects pushBack _elements;
} forEach ("true" configClasses (missionConfigFile >> "CfgStores" >> "Weapon" >> _section));

{
	{
		_x ctrlCommit 0;
	} forEach _x;
} forEach _allObjects;

uiNamespace setVariable ["elements", _allObjects];
uiNamespace setVariable ["wep_sec", _section];