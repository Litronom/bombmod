#include <stdbool.h>
#include <stdio.h>

#include "MainInclude.h"

bool isCustomVarsInitialized = false; // Flag to check if custom variables are initialized
ControllerEX ControllerInputsEX[4] ALIGN16; // Extended Controller inputs for each player

int TestmodelID = OBJ_MODEL_ENM_TOTEM; //Test
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


	for (int i = 0; i < 4; i++)
	{
		if (g_Players[i].PlayerLevelClass != 0)
		{
			g_Players[i].bomb_type = BOMB_TYPE_REMOTE;
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




	if (ControllerInputsEX[0].ButtonPressed & BTN_DUP)
	{
		TestmodelID++;
	}
	if (ControllerInputsEX[0].ButtonPressed & BTN_DRIGHT)
	{
		modelbehavior++;
	}

	if (ControllerInputsEX[0].ButtonPressed & BTN_DDOWN)
	{
		TestmodelID--;
	}
	if (ControllerInputsEX[0].ButtonPressed & BTN_DLEFT)
	{
		modelbehavior--;
	}

	if (ControllerInputsEX[0].ButtonPressed & BTN_L)
	{
		g_LevelLoader.flag = 1;
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
	PlayerMovement(num);
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

int AllocateModel_Hook(int modelID)
{
	/*
	//Just some model swap tests
	if (ModelID == (OBJ_MODEL_PLAYER_BOMBERMAN))
	{
		ModelID = OBJ_MODEL_PLAYER_BOMBERMAN; // Change player model to Bomberman
	}

	if (ModelID == (OBJ_MODEL_MAP_UP_AND_DOWN1))
	{
		ModelID = OBJ_MODEL_MAP_UP_AND_DOWN_UNUSED;
	}
	if (ModelID == (OBJ_MODEL_MAP_UP_AND_DOWN2))
	{
		ModelID = OBJ_MODEL_MAP_UP_AND_DOWN_UNUSED;
	}
	if (ModelID == (OBJ_MODEL_MAP_UP_AND_DOWN_WATER_PLANE))
	{
		ModelID = 1;
	}
	if (ModelID == (OBJ_MODEL_BATTLE_FRAMED_STONE_BLOCK))
	{
		ModelID = OBJ_MODEL_BATTLE_BRICK_STONE_BLOCK;
	}
	if (ModelID == (OBJ_MODEL_BOMB_REMOTE))
	{
		ModelID = OBJ_MODEL_DRAGON_JET;
	}
	*/

    if (modelID == -1)
	{
        return -1;
    }

    int index = g_GetModelIndex(modelID,modelID);

	ModelAlloc* entry = &g_LevelModelAllocations[index];

    if (entry->modelID != modelID)
	{
        // Model hasn't been allocated yet
        g_ModelAllocCount++;
        entry->modelID = modelID;

        g_InitModel(0x18);

        int modelHandle = g_LoadModel(modelID, 1);

		int modelHandle2 = modelHandle;
        int buffer;
        g_PrepareModelBuffer(&buffer, 4, 1, modelHandle);

        int processedModel = g_ProcessModelBuffer(buffer);
        entry->modelData = processedModel;

        g_RegisterModel(modelHandle2, processedModel, buffer);
        g_FinalizeModel(modelHandle2);
    }

    entry->count += 1;
	return entry->modelData;
}