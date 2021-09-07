class CfgPatches
{
	class LostCoastAutorun
	{
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
	};
};

class CfgMods
{
	class LostCoastAutorun
	{
		name = "LostCoastAutorun";
		action = "https://github.com/schana/dayz-mod-autorun";
		author = "schana";
		type = "mod";
		inputs = "LostCoastAutorun/Data/Inputs.xml";
		dependencies[] =
		{
			"World",
			"Mission"
		};
		class defs
		{
			class worldScriptModule
			{
				files[] =
				{
					"LostCoastAutorun/World"
				};
			};
			class missionScriptModule
			{
				files[] =
				{
					"LostCoastAutorun/Mission"
				};
			};
		};
	};
};
