#include "MainInclude.h"

bool isCustomVarsInitialized = false; // Flag to check if custom variables are initialized
ControllerEX ControllerInputsEX[4] ALIGN16; // Extended Controller inputs for each player

int TestmodelID = OBJ_MODEL_BOMB_BIG; //Test
int modelbehavior = 7; //Test
int TestValue = 3; //Test

int rivalEquipID[4] = {0,1,2,3};
int rival[] = { OBJ_MODEL_PLAYER_ARTEMIS, OBJ_MODEL_PLAYER_ORION, OBJ_MODEL_PLAYER_REGULUS, OBJ_MODEL_PLAYER_ALTAIR, OBJ_MODEL_PLAYER_ALTAIR_ARMOR}; 
int BombCol = 0x4A;

// Function to compute extended controller inputs
void ComputeControllerInputsEX()
{
	for (int i = 0; i < 4; i++)
	{
		if (g_ControllerInputs[i].Flags & CONT_PLUGGED_OUT)
		{
			continue;
		}
		ushort current = g_ControllerInputs[i].Button;
		ushort previous = g_ControllerInputsCopy[i].Button;

		ControllerInputsEX[i].AnalogX = g_ControllerInputs[i].AnalogX;
		ControllerInputsEX[i].AnalogY = g_ControllerInputs[i].AnalogY;

		ControllerInputsEX[i].ButtonHeld = current & previous;
		ControllerInputsEX[i].ButtonPressed = current & ~previous;
		ControllerInputsEX[i].ButtonReleased = ~current & previous;
	}
}

void EquipRivalParts(int playerID, int rivalID)
{
	int count = 16;

//	Object *plyObj = g_PlayerPointers[playerID].playerObject;

//	g_FreePlayerAssets(playerID);
//	g_InitPlayerAssetPointers(plyObj,count);

	for (int i = 0; i < count; i++)
	{
		EquipCustomPart(playerID, i, rival[rivalID]);
		g_SetBodyPartToModelPart(playerID,i,i);
	}
}

void EquipArtemisParts(int playerID)
{
	for (int i = 0; i < 16; i++)
	{
		EquipCustomPart(playerID, i, OBJ_MODEL_PLAYER_ARTEMIS);
		g_SetBodyPartToModelPart(playerID,i,i);
	}
}

void EquipOrionParts(int playerID)
{
	for (int i = 0; i < 16; i++)
	{
		EquipCustomPart(playerID, i, OBJ_MODEL_PLAYER_ORION);
		g_SetBodyPartToModelPart(playerID,i,i);
	}
}

void EquipRegulusParts(int playerID)
{
	for (int i = 0; i < 16; i++)
	{
		EquipCustomPart(playerID, i, OBJ_MODEL_PLAYER_REGULUS);
		g_SetBodyPartToModelPart(playerID,i,i);
	}
}

void EquipAltairParts(int playerID)
{
	for (int i = 0; i < 16; i++)
	{
		EquipCustomPart(playerID, i, OBJ_MODEL_PLAYER_ALTAIR);
		g_SetBodyPartToModelPart(playerID,i,i);
	}
}

void ChangeBombermanColors(int playerID, int colorModelID)
{
	if (g_Players[playerID].PlayerLevelClass->ObjectPointer == NULL)
	{
		return;
	}
	
	for (int i = 0; i < 0xC; i++)
	{
		g_AssignModelParts(g_Players[playerID].PlayerLevelClass->ObjectPointer, colorModelID, i, i);
	}
}

void ItemRainAroundPlayer(int itemID, int radius, int chance)
{
	if (!g_PauseFlag && g_Players[0].controlType == 1 && g_Players[0].heartCount > 0 && g_GameState.delta_time != 0.0f)
	{
		if (g_getRandomNumber(chance) == 0)
		{
			Object* playerObj = g_Players[0].PlayerLevelClass->ObjectPointer;
			float PosX = playerObj->position[0] + (float)(g_getRandomNumber(radius * 2 + 1) - radius) * 100.0f;
			float PosY = playerObj->position[1] + 1000.0f;
			float PosZ = playerObj->position[2] + (float)(g_getRandomNumber(radius * 2 + 1) - radius) * 100.0f;
			g_spawnItem(itemID, PosX, PosY, PosZ);
		}
	}
}

void BombRainAroundPlayer(int bombType, int radius, int chance)
{
	if (!g_PauseFlag && g_Players[0].controlType == 1 && g_Players[0].heartCount > 0 && g_GameState.delta_time != 0.0f)
	{
		if (g_getRandomNumber(chance) == 0)
		{
			Object* playerObj = g_Players[0].PlayerLevelClass->ObjectPointer;
			float PosX = playerObj->position[0] + (float)(g_getRandomNumber(radius * 2 + 1) - radius) * 100.0f;
			float PosY = playerObj->position[1] + 1000.0f;
			float PosZ = playerObj->position[2] + (float)(g_getRandomNumber(radius * 2 + 1) - radius) * 100.0f;
			g_spawnBomb(bombType, PosX, PosY, PosZ, 4);
		}
	}
}

void GlobalUpdate()
{
	ComputeControllerInputsEX(); // Update the extended controller inputs


	//if (ControllerInputsEX[0].ButtonPressed&BTN_L)
	//{
	//	BombCol = (g_gameFrameCounter % 4) + 0x4A;
	//	ChangeBombermanColors(0, BombCol);	
	//}
	
	if (g_CurrentScreenID == 0x23)
	{
		//int player = g_VSPlayerSelectionID;

		if (g_GameObjects[0].angle[0] > 0)
		{
			//EquipRivalParts(player,rivalEquipID[player]);
		}	

		if ((g_GameObjects[0].angle[0] > 0 && g_GameObjects[0].angle[0] < 90.0f) || (g_GameObjects[0].angle[0] > 90.0f && g_GameObjects[0].angle[0] < 180.0f) || g_VSPlayerSubSelectionID == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				switch (i)
				{
				case 0:
					EquipArtemisParts(i);
					break;
				case 1:
					EquipOrionParts(i);
					break;
				case 2:
					EquipRegulusParts(i);
					break;
				case 3:
					EquipAltairParts(i);
					break;				
				default:
					break;
				}
			}	
		}
	}
	if (g_CurrentScreenID >= 0x28)
	{
//		BombRainAroundPlayer(BOMB_TYPE_NORMAL, 2, 50);
	}
	if (ControllerInputsEX[0].ButtonPressed & BTN_DLEFT)
	{
		TestValue--;
	}
	if (ControllerInputsEX[0].ButtonPressed & BTN_DRIGHT)
	{
		TestValue++;
	}
	if (ControllerInputsEX[0].ButtonPressed & BTN_DUP)
	{
		Object* playerObj = g_Players[0].PlayerLevelClass->ObjectPointer;
//		LevelClass* playerLvl = g_Players[0].PlayerLevelClass;
//		g_SpawnParticleEffect(effectID, playerObj->position[0], playerObj->position[1] + 160.0f, playerObj->position[2], playerLvl);
//		g_SpawnParticleEffect(TestValue, 0, 160.0f, 0, playerLvl);
		g_spawnItem(g_getRandomNumber(9), playerObj->position[0] + 150.0f, playerObj->position[1] + 160.0f, playerObj->position[2] + 150.0f);
	}
	if (ControllerInputsEX[0].ButtonPressed & BTN_DDOWN)
	{
		g_spawnContainerObject(0xB+TestValue, 1, 0xD, 0x60);
	}
	/*
	for (int i = 0; i < 4; i++)
	{
		if (g_Players[i].PlayerLevelClass != 0)
		{
			g_Players[i].bombType = BOMB_TYPE_REMOTE;
		}

		// Battle Custom Parts equip!
		if (g_CurrentScreenID == 0x23)
		{
			g_VSGameState.isCustomToggled[i] = 1;
			g_VSGameState.customParts[i].customHeadID = 2+i;
			g_VSGameState.customParts[i].customBodyID = 3+i;
			g_VSGameState.customParts[i].customArmsID = 5+i;
			g_VSGameState.customParts[i].customLegsID = 8+i;
		}
		
	}

	bool PlayerLoaded = 0;

	if (g_GameState.state == 0 && g_LevelLoader.flag == 0x91)
	{
		for (int i = 0; i < 100; i++)
		{
			if (g_LevelModelAllocations[i].modelID == OBJ_MODEL_PLAYER_BOMBERMAN)
			{
				PlayerLoaded = 1;
				break;
			}
			
		}
		if (PlayerLoaded)
		{
			LoadCustomParts(g_VSGameState.customPartSetID[0],0, g_VSGameState.customParts[0].customHeadID);
			LoadCustomParts(g_VSGameState.customPartSetID[0],0, g_VSGameState.customParts[0].customBodyID);
			LoadCustomParts(g_VSGameState.customPartSetID[0],0, g_VSGameState.customParts[0].customArmsID);
			LoadCustomParts(g_VSGameState.customPartSetID[0],0, g_VSGameState.customParts[0].customLegsID);
		}
	}


	g_PlayMusicValidator = 0;
	g_GameState.time_elapsed = TestmodelID;

	if (ControllerInputsEX[0].ButtonPressed & BTN_DUP)
	{
		TestmodelID++;
	}
	if (ControllerInputsEX[0].ButtonPressed & BTN_DRIGHT)
	{
		modelbehavior++;
		g_PlayGlobalSound(TestmodelID);
	}

	if (ControllerInputsEX[0].ButtonPressed & BTN_DDOWN)
	{
		TestmodelID--;
	}
	if (ControllerInputsEX[0].ButtonPressed & BTN_DLEFT)
	{
		for (int i = 0; i < 8; i++)
		{
			if (g_SoundFlags[i].playFlag != -1)
			{
				g_SoundFlags[i].controlFlag = 0x2000;
			}	
		}
		
	}
	
	for (int i = 1; i < 4; i++)
	{
		g_Players[i].bombType = g_Players[0].bombType;
	}
	*/	
}

void EquipInvisiblePart(int playerID, int partSlot)
{
	g_EquipCustomPart(playerID, partSlot, OBJ_MODEL_EMPTY);
}

void PlayerSpawning(int playerID)
{
	int count = 0x10;
//	if (!(g_LevelLoader.flag&0x4))
//	{
//		if (playerID != 0)
//		{
//			return;
//		}
		
		g_InitPlayerAssetPointers(g_Players[playerID].PlayerLevelClass->ObjectPointer,count);

		/*
		g_EquipCustomPart(playerID, CUSTOM_PART_BODY, OBJ_MODEL_SPELLMAKER_ITEM_BOMB_UP_EVIL);
		EquipInvisiblePart(playerID, CUSTOM_PART_FACE);
		EquipInvisiblePart(playerID, CUSTOM_PART_HEAD);
		EquipInvisiblePart(playerID, CUSTOM_PART_BELT);
		EquipInvisiblePart(playerID, CUSTOM_PART_HAND_L);
		EquipInvisiblePart(playerID, CUSTOM_PART_ARM_L);
		EquipInvisiblePart(playerID, CUSTOM_PART_HAND_R);
		EquipInvisiblePart(playerID, CUSTOM_PART_ARM_R);
		EquipInvisiblePart(playerID, CUSTOM_PART_FOOT_L);
		EquipInvisiblePart(playerID, CUSTOM_PART_LEG_L);
		EquipInvisiblePart(playerID, CUSTOM_PART_FOOT_R);
		EquipInvisiblePart(playerID, CUSTOM_PART_LEG_R);
		EquipInvisiblePart(playerID, CUSTOM_PART_HEAD_BALL);
		*/

		//LoadCustomParts(playerID,0,g_SaveGameCustomParts.customHeadID);
		//LoadCustomParts(playerID,1,g_SaveGameCustomParts.customBodyID);
		//LoadCustomParts(playerID,2,g_SaveGameCustomParts.customArmsID);
		//LoadCustomParts(playerID,3,g_SaveGameCustomParts.customLegsID);
		//EquipCustomPart(playerID, CUSTOM_PART_BODY, OBJ_MODEL_PLAYER_REGULUS);
		count = 0xF;
		//testModel[5] = (u32)((u8*)TestPlane_Kirby_Bush_001_mesh - (u8*)testModel);
		//testModel[8] = (u32)((u8*)values - (u8*)testModel);

		//EquipCustomModel(playerID, CUSTOM_PART_BODY, 0);
		//EquipCustomModel(playerID, CUSTOM_PART_FACE, 1);

		//EquipInvisiblePart(playerID, CUSTOM_PART_HEAD_BALL);
		//EquipInvisiblePart(playerID, CUSTOM_PART_BELT);

		//for (int i = 0; i < count; i++)
		//{
			//EquipCustomPart(playerID, i, OBJ_MODEL_PLAYER_ALTAIR_FINAL);
		//	g_SetBodyPartToModelPart(playerID,i,0);
		//}
		//g_SetBodyPartToModelPart(playerID,CUSTOM_PART_FACE,1);


		//EquipCustomModel(playerID, CUSTOM_PART_HEAD, OBJ_MODEL_OVERWORLD_DRAGON, &testModel[0]);

		//void** playerParts = (void**)g_PlayerPointers[playerID].attachmentModelPtr;
		//playerParts[CUSTOM_PART_HEAD] = &testModel[0];
/*	}
	else
	{
		if (playerID > 3)
		{
			return;
		}
		
		g_InitPlayerAssetPointers(g_Players[playerID].PlayerLevelClass->ObjectPointer,count);

		for (int i = 0; i < count; i++)
		{
			EquipCustomPart(playerID, i, rival[rivalEquipID[playerID]]);
			g_SetBodyPartToModelPart(playerID,i,i);
		}
	}
*/
}

void InitCustomVars()
{
	//g_common_shadow_model_scale = 3.0f;
}


void UpdateRenderFrame_Hook()
{
	GlobalUpdate();

	UpdateRenderFrame();

	if (!isCustomVarsInitialized)
	{
		InitCustomVars();
		isCustomVarsInitialized = true; // Set init flag to true after initialization
	}
}



void PlayerMovement_Hook(int num)
{
	g_PlayerMovement(num);
}


void EnemyAllocate(int ID, int behaviour, int modelID)
{
	g_EnemySlots[ID].behaviour = behaviour;
	g_EnemySlots[ID].modelID = modelID;

//	g_EnemySlots[ID].behaviour = BEHAVIOR_ENM_BAT;	
// 	g_EnemySlots[ID].modelID = OBJ_MODEL_ENM_BAT;

	//g_EnemySlots[ID].behaviour = modelbehavior;
	//g_EnemySlots[ID].modelID = TestmodelID;
}

void ContainerObjAllocate(ContainerObjectAlloc* LevelContainers)
{
	for (int i = 0; i < 3; i++)
	{
		ContainerObjectAlloc* obj = &LevelContainers[i];

		g_ContainerObjectSlots[i].modelID = obj->modelID;
		g_ContainerObjectSlots[i].collisionType = obj->collisionType;
		g_ContainerObjectSlots[i].u1 = obj->u1;
		g_ContainerObjectSlots[i].particleEffectID = obj->particleEffectID;
		g_ContainerObjectSlots[i].flag = obj->flag;
	}
/*
	for (int i = 0; i < 3; i++)
	{
		ContainerObjectAlloc* obj = &LevelContainers[i];

		g_ContainerObjectSlots[i].modelID = OBJ_MODEL_SPRITE_CERAMIC_POT;
		g_ContainerObjectSlots[i].collisionType = obj->collisionType;
		g_ContainerObjectSlots[i].u1 = obj->u1;
		g_ContainerObjectSlots[i].u2 = obj->u2;
		g_ContainerObjectSlots[i].flag = SET_FLAG(obj->flag, CONTAINER_BILLBOARD);
	}
*/
}