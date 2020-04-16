class RscText {
    x = 0;
    y = 0;
    h = 0.037;
    w = 0.3;
    type = 0;
    style = 0;
    shadow = 1;
    colorShadow[] = {0, 0, 0, 0.5};
    font = "PuristaMedium";
    SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    text = "";
    colorText[] = {1, 1, 1, 1.0};
    colorBackground[] = {0, 0, 0, 0};
    linespacing = 1;
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    tooltipColorShade[] = {0,0,0,0.65};
};

class RscStructuredText {
    type = 13;
    style = 0;
    x = 0;
    y = 0;
    h = 0.035;
    w = 0.1;
    text = "";
    size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    colorText[] = {1, 1, 1, 1.0};
    shadow = 1;

    class Attributes {
        font = "PuristaMedium";
        color = "#ffffff";
        align = "left";
        shadow = 1;
    };
};

class RscBackground: RscText {
    type = 0;
    IDC = -1;
    style = 512;
    shadow = 0;
    x = 0.0;
    y = 0.0;
    w = 1.0;
    h = 1.0;
    text = "";
    ColorBackground[] = {0.48, 0.5, 0.35, 1};
    ColorText[] = {0.1, 0.1, 0.1, 1};
    font = "PuristaMedium";
    SizeEx = 1;
};

class RscProgress {
    type = 8;
    style = 0;
    x = 0.344;
    y = 0.619;
    w = 0.313726;
    h = 0.0261438;
    texture = "";
    shadow = 2;
    colorFrame[] = {0, 0, 0, 0};
    colorBackground[] = {0, 0, 0, 0.5};
    colorBar[] =  {0, 0, 0, 0.5};
};

class RscPicture {
    shadow = 0;
    type = 0;
    style = 48;
    sizeEx = 0.023;
    font = "PuristaMedium";
    colorBackground[] = {};
    colorText[] = {};
    x = 0;
    y = 0;
    w = 0.2;
    h = 0.15;
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    tooltipColorShade[] = {0,0,0,0.65};
    text = "";
};

class RscPictureKeepAspect : RscPicture
{
    style = 0x30 + 0x800;
};

class RscShortcutButton {
    idc = -1;
    style = 0;
    default = 0;
    shadow = 1;
    w = 0.183825;
    h = "((((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
    color[] = {1,1,1,1.0};
    colorFocused[] = {1,1,1,1.0};
    color2[] = {0.95,0.95,0.95,1};
    colorDisabled[] = {1,1,1,0.25};
    colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
    colorBackgroundFocused[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
    colorBackground2[] = {1,1,1,1};
    animTextureDefault = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
    animTextureNormal = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
    animTextureDisabled = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
    animTextureOver = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\over_ca.paa";
    animTextureFocused = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\focus_ca.paa";
    animTexturePressed = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\down_ca.paa";
    periodFocus = 1.2;
    periodOver = 0.8;
    class HitZone
    {
        left = 0.0;
        top = 0.0;
        right = 0.0;
        bottom = 0.0;
    };
    class ShortcutPos
    {
        left = 0;
        top = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
        w = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
        h = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    };
    class TextPos
    {
        left = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
        top = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
        right = 0.005;
        bottom = 0.0;
    };
    period = 0.4;
    font = "PuristaMedium";
    size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    text = "";
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
    action = "";
    class Attributes
    {
        font = "PuristaMedium";
        color = "#E5E5E5";
        align = "left";
        shadow = "true";
    };
    class AttributesImage
    {
        font = "PuristaMedium";
        color = "#E5E5E5";
        align = "left";
    };
};

class RscButtonMenu : RscShortcutButton {
    idc = -1;
    type = 16;
    style = "0x02 + 0xC0";
    default = 0;
    shadow = 0;
    x = 0;
    y = 0;
    w = 0.095589;
    h = 0.039216;
    animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
    animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
    colorBackground[] = {0,0,0,0.8};
    colorBackgroundFocused[] = {1,1,1,1};
    colorBackground2[] = {0.75,0.75,0.75,1};
    color[] = {1,1,1,1};
    colorFocused[] = {0,0,0,1};
    color2[] = {0,0,0,1};
    colorText[] = {1,1,1,1};
    colorDisabled[] = {1,1,1,0.25};
    period = 1.2;
    periodFocus = 1.2;
    periodOver = 1.2;
    size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    tooltipColorShade[] = {0,0,0,0.65};
    class TextPos
    {
        left = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
        top = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
        right = 0.005;
        bottom = 0.0;
    };
    class Attributes
    {
        font = "PuristaMedium";
        color = "#E5E5E5";
        align = "left";
        shadow = "false";
    };
    class ShortcutPos
    {
        left = "(6.25 * (((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005";
        top = 0.005;
        w = 0.0225;
        h = 0.03;
    };
    soundEnter[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",0.09,1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundPush",0.09,1};
    soundClick[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundClick",0.09,1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",0.09,1};
    textureNoShortcut = "";
};

class RscButtonIcon : RscButtonMenu {
    type = 1;
    style = "2096";

    animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
    animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";

    colorBackground[] = {0, 0, 0, 0.8};
    colorBackgroundFocused[] = {1, 1, 1, 1};
    colorBackground2[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])", 1};

    color[] = {1, 1, 1, 1};
    colorFocused[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])", 1};

    color2[] = {0, 0, 0, 1};
    colorText[] = {1, 1, 1, 1};
    colorDisabled[] = {1, 1, 1, 0.25};
    colorBackgroundActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])", 1};
    colorBackgroundDisabled[] = {0.1, 0.1, 0.1, 1};
    offsetX = 0;
    offsetY = 0;
    offsetPressedX = 0;
    offsetPressedY = 0;
    colorShadow[] = {0, 0, 0, 0};
    colorBorder[] = {0, 0, 0, 0};
    borderSize = 0;
};

class RscEdit {
    type = 2;
    style = 0x00 + 0x40;
    font = "PuristaMedium";
    shadow = 2;
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    colorBackground[] = {0, 0, 0, 1};
    soundSelect[] = {"",0.1,1};
    soundExpand[] = {"",0.1,1};
    colorText[] = {0.95, 0.95, 0.95, 1};
    colorDisabled[] = {1, 1, 1, 0.25};
    autocomplete = false;
    colorSelection[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 1};
    canModify = 1;
};

class RscScrollBar
{
    color[] = {1,1,1,0.6};
    colorActive[] = {1,1,1,1};
    colorDisabled[] = {1,1,1,0.3};
    thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
    arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
    arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
    border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
    shadow = 0;
    scrollSpeed = 0.06;
    width = 0;
    height = 0;
    autoScrollEnabled = 1;
    autoScrollSpeed = -1;
    autoScrollDelay = 5;
    autoScrollRewind = 0;
};

class RscControlsGroup {
    type = 15;
    idc = -1;
    x = 0;
    y = 0;
    w = 1;
    h = 1;
    shadow = 0;
    style = 16;

    class VScrollBar : RscScrollBar
    {
        width = 0.021;
        autoScrollEnabled = 1;
    };

    class HScrollBar : RscScrollBar
    {
        height = 0.028;
    };

    class Controls {};
};

class RscControlsGroupNoScrollbars : RscControlsGroup {
    class VScrollbar : VScrollbar {
        width = 0;
    };

    class HScrollbar : HScrollbar {
        height = 0;
    };
};