#include <stdbool.h>
#include <stdio.h>

#include "MainInclude.h"

bool isCustomVarsInitialized = false; // Flag to check if custom variables are initialized
ControllerEX ControllerInputsEX[4] ALIGN16; // Extended Controller inputs for each player

int TestmodelID = OBJ_MODEL_BOMB_BIG; //Test
int modelbehavior = 7; //Test

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

void GlobalUpdate()
{
	ComputeControllerInputsEX(); // Update the extended controller inputs

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

void PlayerSpawning(int playerID)
{
	if (g_GameState.state == 0)
	{
		g_InitPlayerAssetPointers(g_Players[playerID].PlayerLevelClass->ObjectPointer,0xF);

		g_EquipCustomPart(playerID, CUSTOM_PART_FACE, OBJ_MODEL_CUSTOM_CAT_HOOD);
		g_EquipCustomPart(playerID, CUSTOM_PART_BELT, OBJ_MODEL_CUSTOM_CAT_TAIL);
		g_EquipCustomPart(playerID, CUSTOM_PART_HAND_L, OBJ_MODEL_CUSTOM_CAT_PAWS_ARMS_L);
		g_EquipCustomPart(playerID, CUSTOM_PART_HAND_R, OBJ_MODEL_CUSTOM_CAT_PAWS_ARMS_R);
		g_EquipCustomPart(playerID, CUSTOM_PART_FOOT_L, OBJ_MODEL_CUSTOM_CAT_PAWS_LEGS_L);
		g_EquipCustomPart(playerID, CUSTOM_PART_FOOT_R, OBJ_MODEL_CUSTOM_CAT_PAWS_LEGS_R);
		g_EquipCustomPart(playerID, CUSTOM_PART_HEAD_BALL, OBJ_MODEL_CUSTOM_CAT_PAWS_LEGS_R);
	}
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


void EnemyAllocate(int ID, int Behaviour, int Model)
{
	g_EnemySlots[ID].behaviour = Behaviour;
	g_EnemySlots[ID].modelID = ID;
	
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
		g_ContainerObjectSlots[i].u2 = obj->u2;
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