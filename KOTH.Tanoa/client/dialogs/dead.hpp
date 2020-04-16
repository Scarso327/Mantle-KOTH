class RscIncapacitated {
	idd = 9000;
	name = "RscIncapacitated";
	duration = 10e10;
	movingEnable = 0;
	fadein = 0;
	fadeout = 0;
  	onLoad="uiNamespace setVariable ['RscIncapacitated', _this select 0]";
  	objects[]={};

    class Controls {
		 class Background : RscBackground {
            idc = -1;
            colorBackground[] = {0.16,0.16,0.16,0.8};
            x = 0 * safezoneW + safezoneX;
            y = 0.665 * safezoneH + safezoneY;
            w = 1 * safezoneW;
            h = 0.154 * safezoneH;
        };

        class TitleText : RscStructuredText {
            idc = 9001;
            text = "<t align='center' size='2'>#######</t>";
            x = 0.29375 * safezoneW + safezoneX;
            y = 0.676 * safezoneH + safezoneY;
            w = 0.4125 * safezoneW;
            h = 0.044 * safezoneH;
        };
    };
};