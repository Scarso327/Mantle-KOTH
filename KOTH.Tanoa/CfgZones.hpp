class CfgZones {
	class Tanoa {
		class GeorgeTown {
			zoneLocation[] = {5776.64, 10278.7, 108.469};
			zoneSize[] = {500, 400};
			safezoneSize[] = {250, 300};

			class West {
				name = "NATO";
				spawnLocation[] = {5629.08, 12111.3, 0};
				vehicleClass = "I_Heli_Transport_02_F";
				vehicleSpawn[] = {5618.65, 12130.1, 0, 241.335};
				class Buildings {
					objects[] = {
						{"CargoPlaftorm_01_jungle_F", {5632.21, 12112.1, -6.966, 0}, "_this animate [""panel_2_hide"", 1];"},
						{"CargoPlaftorm_01_jungle_F", {5626.19, 12112.1, -6.9, 0}, "_this animate [""panel_4_hide"", 1]; _this animate [""panel_1_rotate"", 2]; _this animate [""panel_3_rotate"", 2];"},
						{"CamoNet_BLUFOR_open_F", {5629.48, 12112.4, 0.702, 0}, ""},
						{"MapBoard_Tanoa_F", {5634.41, 12114.4, 0.135726, 44.352}, ""},
						{"Land_CampingTable_F", {5630.64, 12109.704, 0.228, 0}, ""},
						{"Land_IPPhone_01_olive_F", {5631.27, 12109.7, 1.02339, 162.097}, ""},
						{"Land_Money_F", {5630.81, 12109.7, 1.03835, 1.038}, ""},
						{"Land_Laptop_unfolded_F", {5630.1, 12109.8, 1.06102, 12.973}, ""},
						{"Land_Camping_Light_F", {5629.85, 12109.5, 1.068, 0}, ""},
						{"B_CargoNet_01_ammo_F", {5633.94, 12110.4, 0.123422, 117.389}, "[_this] call GLB_fnc_clearObject; missionNamespace setVariable [""west_equipment_box"", _this, true];"}
					};
				};
			};

			class Independent {
				name = "AAF";
				spawnLocation[] = {7575.6, 10519.9, 90};
				vehicleClass = "I_Heli_Transport_02_F";
				vehicleSpawn[] = {7590.04, 10540.4, 0, 262.968};
				class Buildings {
					objects[] = {
						{"CargoPlaftorm_01_jungle_F", {7576.78, 10517, -6.56973, 70.242}, "_this animate [""panel_2_hide"", 1];"},
						{"CargoPlaftorm_01_jungle_F", {7574.75, 10522.7, -6.72846, 70.242}, "_this animate [""panel_4_hide"", 1]; _this animate [""panel_1_rotate"", 2]; _this animate [""panel_3_rotate"", 2];"},
						{"CamoNet_BLUFOR_open_F", {7575.48,10520,0.496918, 68.800}, ""},
						{"MapBoard_Tanoa_F", {7579.65,10515.7,0.942963, 114.594}, ""},
						{"Land_CampingTable_F", {7574.05,10517.8,0.273514, 248.388}, ""},
						{"Land_IPPhone_01_olive_F", {7574.32,10517.2,1.10236, 232.339}, ""},
						{"Land_Money_F", {7574.11,10517.6,1.08936, 1.038}, ""},
						{"Land_Laptop_unfolded_F", {7573.86,10518.2,1.07919, 83.214}, ""},
						{"Land_Rampart_F", {7579.03,10524.3,-1.75446, 339.950}, ""}
					};
				};
			};

			class East {
				name = "CSAT";
				spawnLocation[] = {4374.496, 8700.865, 27};
				vehicleClass = "I_Heli_Transport_02_F";
				vehicleSpawn[] = {4364.079, 8718.693, 0, 38.849};
				class Buildings {
					objects[] = {
						{"CargoPlaftorm_01_jungle_F", {4377.44, 8700.63, -6.966, 0}, "_this animate [""panel_2_hide"", 1];"},
						{"CargoPlaftorm_01_jungle_F", {4371.42, 8700.63, -6.9, 0}, "_this animate [""panel_4_hide"", 1]; _this animate [""panel_1_rotate"", 2]; _this animate [""panel_3_rotate"", 2];"},
						{"CamoNet_BLUFOR_open_F", {4374.71, 8700.88, 0.703116, 0}, ""},
						{"MapBoard_Tanoa_F", {4379.643, 8702.88, 0.428, 44.352}, ""},
						{"Land_CampingTable_F", {4375.870, 8698.222, 0.137, 0}, ""},
						{"Land_IPPhone_01_olive_F", {4376.499, 8698.220, 0.943, 162.097}, ""},
						{"Land_Money_F", {4376.036, 8698.247, 0.953, 1.038}, ""},
						{"Land_Laptop_unfolded_F", {4375.333, 8698.28, 0.959, 12.973}, ""},
						{"Land_Camping_Light_F", {4375.080, 8698, 0.944, 0}, ""}
					};
				};
			};
		};
	};
};