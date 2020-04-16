class RscStore {
	idd = 12000;
	name = "RscStore";
	movingEnabled = 0;
	enableSimulation = 1;

	class ControlsBackground {
		class Background : RscBackground {
			idc = -1;
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.37125 * safezoneW;
			h = 0.506 * safezoneH;
			colorBackground[] = {0, 0, 0, 0.8};
		};

		class SectionBackground : RscBackground {
			idc = -1;
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			//w = 0.020625 * safezoneW;
			w = 0.37125 * safezoneW;
			//h = 0.396 * safezoneH;
			h = 0.033 * safezoneH;
			colorBackground[] = {0, 0, 0, 1};
		};

		class Header : RscStructuredText {
			idc = -1;
			text = "Loadout";
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.37125 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])", 1};
		};
	};

	class Controls {
		class CloseButton : RscButtonIcon {
			onButtonClick = "closeDialog 0;";
			idc = -1;
			x = 0.670156 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.0154688 * safeZoneW;
			h = 0.022 * safeZoneH;
			colorBackground[] = {0,0,0,1};
			colorFocused[] = {0.09,0.09,0.09,1};
			tooltip = "Close";
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
		};

		/*
		class PrimaryWeaponButton : RscButtonIcon {
			onButtonClick = "['Primary'] call CLI_fnc_populateWeaponList;";
			idc = -1;
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.020625 * safeZoneW;
			h = 0.033 * safeZoneH;
			colorBackground[] = {0,0,0,1};
			colorFocused[] = {0.09,0.09,0.09,1};
			tooltip = "Rifles";
			text = "\a3\ui_f\data\gui\Rsc\RscDisplayArsenal\primaryWeapon_ca.paa";
		};

		class ScopeButton : RscButtonIcon {
			onButtonClick = "";
			idc = -1;
			//x = 0.314375 * safezoneW + safezoneX;
			x = 0.335 * safezoneW + safezoneX;
			//y = 0.302 * safezoneH + safezoneY;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.020625 * safeZoneW;
			h = 0.033 * safeZoneH;
			colorBackground[] = {0,0,0,1};
			colorFocused[] = {0.09,0.09,0.09,1};
			tooltip = "Scopes";
			text = "\a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemOptic_ca.paa";
		};

		class SecondaryWeaponButton : RscButtonIcon {
			onButtonClick = "['Secondary'] call CLI_fnc_populateWeaponList;";
			idc = -1;
			//x = 0.314375 * safezoneW + safezoneX;
			x = 0.355625 * safezoneW + safezoneX;
			//y = 0.335 * safezoneH + safezoneY;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.020625 * safeZoneW;
			h = 0.033 * safeZoneH;
			colorBackground[] = {0,0,0,1};
			colorFocused[] = {0.09,0.09,0.09,1};
			tooltip = "Launchers";
			text = "\a3\ui_f\data\gui\Rsc\RscDisplayArsenal\secondaryWeapon_ca.paa";
		};

		class SideWeaponButton : RscButtonIcon {
			onButtonClick = "['Handgun'] call CLI_fnc_populateWeaponList;";
			idc = -1;
			//x = 0.314375 * safezoneW + safezoneX;
			x = 0.37625 * safezoneW + safezoneX;
			//y = 0.368 * safezoneH + safezoneY;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.020625 * safeZoneW;
			h = 0.033 * safeZoneH;
			colorBackground[] = {0,0,0,1};
			colorFocused[] = {0.09,0.09,0.09,1};
			tooltip = "Handguns";
			text = "\a3\ui_f\data\gui\Rsc\RscDisplayArsenal\handgun_ca.paa";
		};
		*/

		class ItemList : RscControlsGroup {
			idc = 12009;
			//x = 0.335 * safezoneW + safezoneX;
			x = 0.314375 * safezoneW + safezoneX;
			//y = 0.269 * safezoneH + safezoneY;
			y = 0.302 * safezoneH + safezoneY;
			//w = 0.350625 * safezoneW;
			w = 0.37125 * safezoneW;
			h = 0.341 * safezoneH;
			colorBackground[] = {0, 0, 0, 0};

			// Filled by script...
			class Controls {};
		};

		class Primary : RscStructuredText {
			idc = 12001;
			text = "Rifle";
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.643 * safezoneH + safezoneY;
			w = 0.12675 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0, 0, 0, 1};
		};

		class PrimaryPicture : RscPictureKeepAspect
		{
			idc = 12002;
			text = "\A3\weapons_F\Rifles\Trg20\Data\UI\gear_TRG21_X_CA.paa";
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.12675 * safezoneW;
			h = 0.088 * safezoneH;
			colorText[] = {1,1,1,1};
		};

		class Scope : RscStructuredText {
			idc = 12003;
			text = "Scope";
			x = 0.443281 * safezoneW + safezoneX;
			y = 0.643 * safezoneH + safezoneY;
			w = 0.0494063 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0, 0, 0, 1};
		};

		class ScopePicture : RscPictureKeepAspect
		{
			idc = 12004;
			text = "\a3\Weapons_F_Exp\Acc\Data\UI\icon_optic_ERCO_blk_F_ca.paa";
			x = 0.443281 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.0494063 * safezoneW;
			h = 0.088 * safezoneH;
			colorText[] = {1,1,1,1};
		};

		class Secondary : RscStructuredText {
			idc = 12005;
			text = "Launcher";
			x = 0.494844 * safezoneW + safezoneX;
			y = 0.643 * safezoneH + safezoneY;
			w = 0.137062 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0, 0, 0, 1};
		};

		class SecondaryPicture : RscPictureKeepAspect
		{
			idc = 12006;
			text = "\A3\Weapons_F\launchers\RPG32\data\UI\gear_RPG32_X_CA.paa";
			x = 0.494844 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.137062 * safezoneW;
			h = 0.088 * safezoneH;
			colorText[] = {1,1,1,1};
		};

		class Handgun : RscStructuredText {
			idc = 12007;
			text = "Handgun";
			x = 0.634062 * safezoneW + safezoneX;
			y = 0.643 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0, 0, 0, 1};
		};

		class HandgunPicture : RscPictureKeepAspect
		{
			idc = 12008;
			text = "\A3\weapons_F\Pistols\P07\data\UI\gear_p07_x_ca.paa";
			x = 0.634062 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.088 * safezoneH;
			colorText[] = {1,1,1,1};
		};
	};
};