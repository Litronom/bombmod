#include <stdbool.h>
#include <stdio.h>

#include "GameVars/GameVars.h"
#include "GameVars/DefVars.h"
#include "GameVars/Struct.h"

bool isCustomVarsInitialized = false; // Flag to check if the code is initialized
float PlayerScale[4] ALIGN16 = {1.0f, 1.0f, 1.0f, 1.0f}; // Player scale for each player

void GlobalUpdate()
{
	Object *ply;

	for (int i = 0; i < 4; i++)
	{
		if (PlayerData[i].PlayerLevelClass == 0)
		{
			continue;
		}
		
		ply = PlayerData[i].PlayerLevelClass->ObjectPointer;

		if (ControllerData[i].Button & BTN_B)
		{
			ply->position[1] += 15.0f; // Move player up when B is pressed
		}

		for (int u = 0; u < 3; u++)
		{
			ply->scale[u] = PlayerScale[i]; // Apply scale to player object
		}
	}
}

void InitCustomVars()
{
	common_shadow_model_scale = 3.0f;
}

void UpdateRenderFrame_Hook()
{
	UpdateRenderFrame();

	if (!isCustomVarsInitialized)
	{
		InitCustomVars();
		isCustomVarsInitialized = true; // Set the flag to true after initialization
	}

	GlobalUpdate();
}

void PlayerMovement_Hook(int num)
{
	PlayerMovement(num);
	
	if (ControllerData[num].Button & BTN_R)
	{
		PlayerScale[num] += 0.05f; // scale player up when R is pressed
	
	}
	if (ControllerData[num].Button & BTN_Z)
	{
		PlayerScale[num] -= 0.05f; // scale player down when Z is pressed
	}

	// Test
	// PlayerData[num].bomb_type = enemies_defeated_count % 5;
	
}
