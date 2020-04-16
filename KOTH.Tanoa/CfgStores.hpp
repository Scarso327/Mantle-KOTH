#define true 1
#define false 0

class CfgStores {
	class Weapon {
		class Primary {
			class TRG21 {
				variants[] = { "arifle_TRG21_F" };
				scopes[] = {};
				levelRequired = 0;
				buyCost = 0;
				rentCost = 0;
				forceUnlocked = true;
			};

			class PDW {
				variants[] = { "hgun_PDW2000_F" };
				scopes[] = {};
				levelRequired = 0;
				buyCost = 10000;
				rentCost = 300;
				forceUnlocked = false;
			};
		};
		class Secondary {};
		class Handgun {};
	};
};