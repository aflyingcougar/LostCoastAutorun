// Found this block of code while searching through the DayZ  found at "\DayZ\dta\scripts\5_Mission\mission\missionGameplay.c"
// I created a small addon to simply reference the original missionGameplay file through my config.cpp using missionScriptModule

// and replicated it's folder path in my mod. The developers we're kind enough to comment exactly what the following code does!

// I have simply taken a single block of code and changed a single bool.

// The original line is "GetUApi().GetInputByName("UAWalkRunTemp").ForceEnable(true);"

// Here we can see they wish to force the player to walk as the most movement during the inventory being toggled open. We can change the

// ForceEnable bool to (false) to run + sprint while the inventory is open.

modded class MissionGameplay
{
	//!movement restrictions
	override void PlayerControlDisable(int mode)
	{
		super.PlayerControlDisable(mode);

		//Print("Disabling Controls");
		switch (mode)
		{
			case INPUT_EXCLUDE_ALL:
			{
				GetUApi().ActivateExclude("menu");
				break;
			}
			case INPUT_EXCLUDE_INVENTORY:
			{
				GetUApi().ActivateExclude("inventory");
				GetUApi().GetInputByName("UAWalkRunTemp").ForceEnable(false); // force walk off :)
				break;
			}
			case INPUT_EXCLUDE_MOUSE_ALL:
			{
				GetUApi().ActivateExclude("radialmenu");
				break;
			}
			case INPUT_EXCLUDE_MOUSE_RADIAL:
			{
				GetUApi().ActivateExclude("radialmenu");
				break;
			}
		}
		
		GetUApi().UpdateControls();
		m_ControlDisabled = true;
		
		PlayerBase playerSprint = PlayerBase.Cast( GetGame().GetPlayer() );
		if( playerSprint )
		{
			HumanInputController hic = playerSprint.GetInputController();
			//hic.ResetADS();
			playerSprint.RequestResetADSSync();
		}
	}
}