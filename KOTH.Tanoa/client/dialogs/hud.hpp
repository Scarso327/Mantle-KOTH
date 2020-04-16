#include "macros.hpp"

class RscPlayerHUD {
	idd = -1;
	duration = 10e10;
	movingEnable = 0;
	fadein = 0;
	fadeout = 0;
	name = "RscPlayerHUD";
	onLoad = "uiNamespace setVariable ['RscPlayerHUD',_this select 0]";
	objects[] = {};
	controls[] = {
		HEALTH_BACK,
		HEALTH_BAR,
		HEALTH_TEXT,
		TICK_BACK,
		TICK_BAR,
		WEST_SIDE_BACK,
		INDP_SIDE_BACK,
		EAST_SIDE_BACK,
		WEST_SCORE_TEXT,
		INDP_SCORE_TEXT,
		EAST_SCORE_TEXT,
		XP_BACK,
		XP_BAR,
		XP_TEXT,
		CASH_TEXT
	};

	/* Background */

	class HEALTH_BACK: RscBackground
	{
		idc = IDC_HEALTH_BACK;
		x = 0.876406 * safezoneW + safezoneX;
		y = 0.97 * safezoneH + safezoneY;
		w = 0.1184373 * safezoneW;
		h = 0.022 * safezoneH;
		colorBackground[] = {0.1,0.1,0.1,0.4};
	};

	class XP_BACK: RscBackground
	{
		idc = IDC_XP_BACK;
		x = 0.876406 * safezoneW + safezoneX;
		y = 0.944 * safezoneH + safezoneY;
		w = 0.1184373 * safezoneW;
		h = 0.022 * safezoneH;
		colorBackground[] = {0.1,0.1,0.1,0.4};
	};

	class TICK_BACK: RscBackground
	{
		idc = IDC_TICK_BACK;
		x = 0.876406 * safezoneW + safezoneX;
		y = 0.93 * safezoneH + safezoneY;
		w = 0.1184373 * safezoneW;
		h = 0.011 * safezoneH;
		colorBackground[] = {0.1,0.1,0.1,0.4};
	};

	// 0.885
	
	class WEST_SIDE_BACK: RscPicture
	{
		idc = IDC_WEST_SIDE_BACK;
		text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_west_ca.paa";
		x = 0.876406 * safezoneW + safezoneX;
		y = 0.8795 * safezoneH + safezoneY;
		w = 0.0360937 * safezoneW;
		h = 0.055 * safezoneH;
		colorText[] = {0.0,0.3,0.6,1};
	};

	class INDP_SIDE_BACK: RscPicture
	{
		idc = IDC_INDP_SIDE_BACK;
		text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_west_ca.paa";
		x = 0.917656 * safezoneW + safezoneX;
		y = 0.8795 * safezoneH + safezoneY;
		w = 0.0360937 * safezoneW;
		h = 0.055 * safezoneH;
		colorText[] = {0,0.5,0,1};
	};

	class EAST_SIDE_BACK: RscPicture
	{
		idc = IDC_EAST_SIDE_BACK;
		text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_west_ca.paa";
		x = 0.958906 * safezoneW + safezoneX;
		y = 0.8795 * safezoneH + safezoneY;
		w = 0.0360937 * safezoneW;
		h = 0.055 * safezoneH;
		colorText[] = {0.5,0,0,1};
	};

	/* Progress Bars */
	
	class HEALTH_BAR: RscProgress
	{
		idc = IDC_HEALTH_BAR;
		x = 0.876406 * safezoneW + safezoneX;
		y = 0.97 * safezoneH + safezoneY;
		w = 0.1184373 * safezoneW;
		h = 0.022 * safezoneH;
		colorText[] = {1, 1, 1, 1};
		colorBackground[] = {0, 0, 0, 0};
		colorBar[] = {0,0,0,0.4};
	};

	class XP_BAR: RscProgress
	{
		idc = IDC_XP_BAR;
		x = 0.876406 * safezoneW + safezoneX;
		y = 0.944 * safezoneH + safezoneY;
		w = 0.1184373 * safezoneW;
		h = 0.022 * safezoneH;
		colorText[] = {1, 1, 1, 1};
		colorBackground[] = {0, 0, 0, 0};
		colorBar[] = {0,0,0,0.4};
	};

	class TICK_BAR: RscProgress
	{
		idc = IDC_TICK_BAR;
		x = 0.876406 * safezoneW + safezoneX;
		y = 0.93 * safezoneH + safezoneY;
		w = 0.1184373 * safezoneW;
		h = 0.011 * safezoneH;
		colorText[] = {1, 1, 1, 1};
		colorBackground[] = {0, 0, 0, 0};
		colorBar[] = {0,0,0,0.4};
	};

	/* Text */

	class HEALTH_TEXT: RscStructuredText
	{
		idc = IDC_HEALTH_TEXT;
		text = "";
		x = 0.876406 * safezoneW + safezoneX;
		y = 0.97 * safezoneH + safezoneY;
		w = 0.1184373 * safezoneW;
		h = 0.022 * safezoneH;
		class Attributes {
			font = "RobotoCondensed";
		};
	};

	class XP_TEXT: RscStructuredText
	{
		idc = IDC_XP_TEXT;
		text = "";
		x = 0.876406 * safezoneW + safezoneX;
		y = 0.944 * safezoneH + safezoneY;
		w = 0.1184373 * safezoneW;
		h = 0.022 * safezoneH;
		class Attributes {
			font = "RobotoCondensed";
		};
	};

	class CASH_TEXT: RscStructuredText
	{
		idc = IDC_CASH_TEXT;
		text = "3000 £";
		x = 0.876406 * safezoneW + safezoneX;
		y = 0.852 * safezoneH + safezoneY;
		w = 0.1184373 * safezoneW;
		h = 0.033 * safezoneH;
		class Attributes {
			color = "#6aa74f";
			align = "right";
			valign = "middle";
			size = "1.5";
		};
	};

	class WEST_SCORE_TEXT: RscStructuredText
	{
		idc = IDC_WEST_SCORE_TEXT;
		text = "0";
		x = 0.876406 * safezoneW + safezoneX;
		y = 0.8927 * safezoneH + safezoneY;
		w = 0.0360937 * safezoneW;
		h = 0.022 * safezoneH;
		class Attributes {
			align = "center";
			shadow = true;
			shadowColor = "#000000";
			size = "1.25";
		};
	};

	class INDP_SCORE_TEXT: RscStructuredText
	{
		idc = IDC_INDP_SCORE_TEXT;
		text = "0";
		x = 0.917656 * safezoneW + safezoneX;
		y = 0.8927 * safezoneH + safezoneY;
		w = 0.0360937 * safezoneW;
		h = 0.022 * safezoneH;
		class Attributes {
			align = "center";
			shadow = true;
			shadowColor = "#000000";
			size = "1.25";
		};
	};

	class EAST_SCORE_TEXT: RscStructuredText
	{
		idc = IDC_EAST_SCORE_TEXT;
		text = "0";
		x = 0.958906 * safezoneW + safezoneX;
		y = 0.8927 * safezoneH + safezoneY;
		w = 0.0360937 * safezoneW;
		h = 0.022 * safezoneH;
		class Attributes {
			align = "center";
			shadow = true;
			shadowColor = "#000000";
			size = "1.25";
		};
	};
};