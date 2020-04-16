/*
	@File: fn_inControl.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Returns faction in control... 
*/

private _playersInZone = allPlayers inAreaArray "obj_marker";

private	_westInZone = count (_playersInZone select { (side _x) isEqualTo west });
private	_eastInZone = count (_playersInZone select { (side _x) isEqualTo east });
private	_indpInZone = count (_playersInZone select { (side _x) isEqualTo independent });

switch (true) do {
	case (_westInZone > _eastInZone && { _westInZone > _indpInZone }): { west };
	case (_eastInZone > _westInZone && { _eastInZone > _indpInZone }): { east };
	case (_indpInZone > _eastInZone && { _indpInZone > _westInZone }): { independent };
	case (_westInZone > 0 || { _eastInZone > 0 } || { _indpInZone > 0 }): { sideUnknown };
	default { civilian };
};