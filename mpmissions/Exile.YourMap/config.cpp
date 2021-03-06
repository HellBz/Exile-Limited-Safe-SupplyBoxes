class CfgInteractionMenus
{
    class SupplyBox
	{
        targetType = 2;
		target = "Exile_Container_SupplyBox";

		class Actions
		{
          // Delete the SupplyBox.
			class Delete: ExileAbstractAction
			{
				title = "Delete SupplyBox";
				condition = "call ExileClient_util_world_isInOwnTerritory";
				action = "_this spawn ExileClient_object_container_pack";
			};
		};
	};
};

class CfgExileCustomCode 
{
	/*
		You can overwrite every single file of our code without touching it.
		To do that, add the function name you want to overwrite plus the 
		path to your custom file here. If you wonder how this works, have a
		look at our bootstrap/fn_preInit.sqf function.

		Simply add the following scheme here:

		<Function Name of Exile> = "<New File Name>";

		Example:

		ExileClient_util_fusRoDah = "myaddon\myfunction.sqf";
	*/
	
	ExileClient_util_world_canBuildHere                            	= "overrides\ExileClient_util_world_canBuildHere.sqf";
	ExileServer_object_supplyBox_network_installSupplyBoxRequest   	= "overrides\ExileServer_object_supplyBox_network_installSupplyBoxRequest.sqf";
	ExileServer_object_construction_network_buildConstructionRequest= "overrides\ExileServer_object_construction_network_buildConstructionRequest.sqf";
};

class CfgTerritories
{
	// Base Cost / Radius
	// Level 1 is allways for Pop Tabs, >= 2 for Respect
	prices[] = 
	{
		// Purchase Price       Radius      Number of Objects   Number of Safes     Number of Boxes     Number of Crates    Number of Tents
		{5000,                  15,         30,                 5,                  1,                   5,                   5                   }, // Level 1
		{10000,                 30,         60,                 7,                  2,                   5,                   5                   }, // Level 2 
		{15000,                 45,         90,                 9,                  3,                   5,                   5                   }, // Level 3
		{20000,                 60,         120,                11,                 4,                   5,                   5                   }, // Level 4
		{25000,                 75,         150,                14,                 5,                   10,                  10                  }, // Level 5
		{30000,                 90,         180,                16,                 6,                   10,                  10                  }, // Level 6
		{35000,                 105,        210,                18,                 7,                   10,                  10                  }, // Level 7
		{40000,                 120,        240,                20,                 8,                   15,                  15                  }, // Level 8
		{45000,                 135,        270,                22,                 9,                   15,                  15                  }, // Level 9
		{50000,                 150,        300,                25,                 10,                  15,                  15                  }  // Level 10
	};

	// A shortcut of the above maximum radius
	maximumRadius = 150;

	// The above * 2 plus coverving the 20m you can move while placing things
	minimumDistanceToOtherTerritories = 325; 

	// Maximum number of territories a player can own
	maximumNumberOfTerritoriesPerPlayer = 2;

	/**
	 * Defines the minimum distance to safe zones / trader cities where players
	 * cannot build territories
	 */
	minimumDistanceToTraderZones = 1000;

	/**
	 * Defines the minimum distance to spawn zones where players
	 * cannot build territories
	 */
	minimumDistanceToSpawnZones = 1000;

	// Amount of pop tabs per object to pay
	popTabAmountPerObject = 10;
};