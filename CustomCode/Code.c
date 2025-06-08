#include <stdbool.h>
#include <stdio.h>

#include "GameVars/GameVars.h"
#include "GameVars/DefVars.h"
#include "GameVars/Struct.h"

float PlayerScale[4] ALIGN16 = {1.0f, 1.0f, 1.0f, 1.0f}; // Player scale for each player

void PlayerMovement_Hook(int num)
{
	PlayerMovement(num);

	Object *ply;
	ply = PlayerData[num].PlayerLevelClass->ObjectPointer;

	
	if (ControllerData[num].Button & BTN_B)
	{
		ply->position[1] += 15.0f; // Move player up when B is pressed
	}

	if (ControllerData[num].Button & BTN_R)
	{
		for (int i = 0; i < 3; i++)
		{
			ply->scale[i] += 0.05f; // scale player up when R is pressed
		}		
	}
	if (ControllerData[num].Button & BTN_Z)
	{
		for (int i = 0; i < 3; i++)
		{
			ply->scale[i] -= 0.05f; // scale player down when Z is pressed
		}		
	}

	// Test
	// PlayerData[num].bomb_type = enemies_defeated_count % 5;
	
}
