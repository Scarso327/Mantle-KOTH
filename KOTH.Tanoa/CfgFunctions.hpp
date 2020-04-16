class Client_Funcs {
	tag = "CLI";

	class Core {
		file = "client";
		class initClient {};
		class initStores {};
		class initEvents {};
		class notify {};
	};
	
	class Stores {
		file = "client\stores";
		class openStore {};
		class populateWeaponList {};
	};

	class Events {
		file = "client\events";
		class onLeaveVehicle {};
	};

	class Leveling {
		file = "client\leveling";
		class getLevelInfo {};
		class addXP {};
	};

	class Medical {
		file = "client\medical";
		class revivePlayer {};
		class onKilled {};
		class onRespawn {};
		class onRevived {};
		class respawnPlayer {};
		class getNearbyDead {};
	};

	class Session {
		file = "client\session";
		class getData {};
		class saveData {};
	};

	class UI {
		file = "client\dialogs\functions";
		class hudLoop {};
		class progressBar {};
	};
};

class Global_Funcs {
	tag = "GLB";

	class Functions {
		file = "functions";
		class createMarker {};
		class inControl {};
		class canDo {};
		class clearObject {};
	};
};

class Server_Funcs {
	tag = "SRV";

	class Core {
		file = "server";
		class initServer {};
		class captureLoop {};
		class createBase {};
	};
};