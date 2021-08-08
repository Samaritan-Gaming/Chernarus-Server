#include "$CurrentDir:mpmissions\dayzOffline.chernarusplus\spawnobject.c"
#include "$CurrentDir:mpmissions\dayzOffline.chernarusplus\Locations\terminals.c"
void main()
{
	AddLocationsTeleport();
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();
	
//	EditorLoaderModule.ExportLootData = true;

//GetCEApi().ExportProxyData(Vector(7500, GetGame().SurfaceY(7500, 7500), 7500), 20000);

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
{
	player.RemoveAllItems();

	EntityAI itemEnt;
	ItemBase itemBs;

	switch (Math.RandomInt(0, 5)) { 
	case 0:
	// SGBeige
	player.GetInventory().CreateInInventory("LeatherPants_Black");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("SG_Beige_Tshirt");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("AthleticShoes_Black");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("BaseballCap_Blue");itemBs = ItemBase.Cast(itemEnt);	
    player.GetInventory().CreateInInventory("SardinesCan");    // added items
    player.GetInventory().CreateInInventory("FangeKnife");    // added items
	player.GetInventory().CreateInInventory("SodaCan_Cola");	// added items
	break; 
	case 1: 
	// SGBlack
	player.GetInventory().CreateInInventory("LeatherPants_Natural");itemBs = ItemBase.Cast(itemEnt); 
	player.GetInventory().CreateInInventory("SG_Black_Tshirt");itemBs = ItemBase.Cast(itemEnt); 
	player.GetInventory().CreateInInventory("BoonieHat_NavyBlue");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("AthleticShoes_Black");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("SardinesCan");    // added items
    player.GetInventory().CreateInInventory("HuntingKnife");    // added items
	player.GetInventory().CreateInInventory("SodaCan_Cola");	// added items
	break; 
	case 2: 
	// SGBlue
	player.GetInventory().CreateInInventory("LeatherPants_Brown");itemBs = ItemBase.Cast(itemEnt); 
	player.GetInventory().CreateInInventory("SG_Blue_Tshirt");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("AthleticShoes_Black");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("ThinFramesGlasses");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("SodaCan_Cola");	// added items
    player.GetInventory().CreateInInventory("SardinesCan");    // added items
    player.GetInventory().CreateInInventory("CombatKnife");    // added items
	break; 
			case 3: 
	// SGGreen
	player.GetInventory().CreateInInventory("LeatherPants_Black");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("SG_Green_Tshirt");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("PMK_5A_Gas_Mask");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("HikingBootsLow_Black");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("BeanieHat_Beige");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("SodaCan_Cola");	// added items
    player.GetInventory().CreateInInventory("SardinesCan");    // added items
    player.GetInventory().CreateInInventory("KukriKnife");    // added items
	break; 
			case 4: 
	// SGGrey
	player.GetInventory().CreateInInventory("SG_Grey_Tshirt");itemBs = ItemBase.Cast(itemEnt); 
	player.GetInventory().CreateInInventory("LeatherPants_Beige");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("AthleticShoes_Black");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("SkullMask");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("SodaCan_Cola");	// added items
    player.GetInventory().CreateInInventory("SardinesCan");    // added items
    player.GetInventory().CreateInInventory("CombatKnife");    // added items
	break; 								}
//   Give universal gear
	itemEnt = player.GetInventory().CreateInInventory("Rag");
	itemBs = ItemBase.Cast(itemEnt);
	itemBs.SetQuantity(4);
//		SetRandomHealth(itemEnt);
//		player.GetInventory().CreateInInventory("HuntingKnife");
}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}