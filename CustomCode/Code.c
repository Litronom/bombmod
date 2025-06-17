#include <stdbool.h>
#include <stdio.h>

#include "MainInclude.h"

bool isCustomVarsInitialized = false; // Flag to check if custom variables are initialized
float PlayerScale[4] ALIGN16 = {1.0f, 1.0f, 1.0f, 1.0f}; // Player scale for each player
ControllerEX ControllerInputsEX[4] ALIGN16; // Extended Controller inputs for each player
int modelID = OBJ_MODEL_ENM_TOTEM;
int modelbehavior = 7;

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

	Object *ply;

	for (int i = 0; i < 4; i++)
	{
		if (g_Players[i].PlayerLevelClass == 0)
		{
			continue;
		}
		
		ply = g_Players[i].PlayerLevelClass->ObjectPointer;

		if (g_ControllerInputs[i].Button & BTN_B)
		{
			//g_Players[i].ComputationLevelClass->CollisionPointer->flag |= 0x0810; // Bomberman Bounces
			g_Players[i].ComputationLevelClass->CollisionPointer->flag |= 0x1010; // Bomberman Bounces
			ply->position[1] += 15.0f; // Move player up when B is pressed
		}

		for (int u = 0; u < 3; u++)
		{
			ply->scale[u] = PlayerScale[i]; // Apply scale to player object
			g_Players[i].ComputationLevelClass->CollisionPointer->radius = 30.0f * PlayerScale[i];
		}
	}

	if (ControllerInputsEX[0].ButtonPressed & BTN_DUP)
	{
		modelID++;
	}
	if (ControllerInputsEX[0].ButtonPressed & BTN_DRIGHT)
	{
		modelbehavior++;
	}

	if (ControllerInputsEX[0].ButtonPressed & BTN_DDOWN)
	{
		modelID--;
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

/*
void InitLevelData()
{

}
*/

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
	Object *ply = g_Players[num].PlayerLevelClass->ObjectPointer;

	if (g_Players[num].flag & CUTSCENE_MOVEMENT)
	{
		g_GlobalPlayerState.movement_speed = 1.5f;
	}

	if (ControllerInputsEX[num].ButtonHeld & BTN_R)
	{
		PlayerScale[num] += 0.05f; // scale player up when R is pressed
	
	}
	if (ControllerInputsEX[num].ButtonHeld & BTN_Z)
	{
		PlayerScale[num] -= 0.05f; // scale player down when Z is pressed
	}

	if (ControllerInputsEX[num].ButtonPressed & BTN_CUP)
	{
		float fLocX = ply->position[0] + 50.0f;
		float fLocY = ply->position[1] + 10.0f;
		float fLocZ = ply->position[2] + 100.0f;

		int locX = *(int*)&fLocX;
		int locY = *(int*)&fLocY;
		int locZ = *(int*)&fLocZ;

		SpawnPlayerBomb(g_Players[num].bomb_type, locX, locY, locZ, num);
	}

	// Test
	// g_Players[num].bomb_type = enemies_defeated_count % 5;
}


void EnemyAllocate(int ID, int Behaviour, int Model)
{
	g_EnemySlots[ID].behaviour = modelbehavior;
	g_EnemySlots[ID].modelID = modelID;
}