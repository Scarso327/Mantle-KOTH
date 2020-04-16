/*
	@File: fn_createMarker.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Creates marker using params... 
*/

if !(_this params [
	["_mName", "", [""]],
	["_mText", "", [""]],
	["_mType", "", [""]],
	["_mShape", "ELLIPSE", [""]],
	["_mPos", [], [[]]],
	["_mSize", [80, 80], [[]]],
	["_mBrush", "Border", [""]],
	["_mColour", "ColorBlack", [""]],
	["_mAlpha", 0, [0]],
	["_mRot", 0, [0]]
]) exitWith {};

createMarker [_mName, _mPos];
_mName setMarkerText _mText;
_mName setMarkerType _mType;
_mName setMarkerShape _mShape;
_mName setMarkerSize _mSize;
_mName setMarkerBrush _mBrush;
_mName setMarkerColor _mColour;
_mName setMarkerAlpha _mAlpha;
_mName setMarkerDir _mRot;