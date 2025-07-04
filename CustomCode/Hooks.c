#include <stdbool.h>
#include <stdio.h>

#include "MainInclude.h"


int SpawnPlayerBomb_Hook(short bombType, int locX, int locY, int locZ, short playerID)
{
    // Early out if the player ID is invalid
    if (playerID < 0 || playerID >= 5)
	{
        return 0;
    }

    // Ensure verification flag is set
    if (g_someBombVerification != 1)
	{
        g_someBombVerification = 1;
    }

    // Check if the player is already using a pickup
    if (g_PickupState[playerID].PickupLevelClass != 0)
	{
        func_80273E2C(playerID);
        return 0;
    }

    // Attempt to validate bomb spawn
    int result = func_80273AD4(playerID, locX, locY, locZ);
    if (result == 0)
	{
        return 0;
    }

    // Determine spawn coordinates
    hex2float spawnX;
	spawnX.i = (uint)locX;
    hex2float spawnY;
	spawnY.i = (uint)locY;
    hex2float spawnZ;
	spawnZ.i = (uint)locZ;

    if (result == 2)
	{
        spawnX.f = g_BombSpawnLocation[0];
        spawnY.f = g_BombSpawnLocation[1];
        spawnZ.f = g_BombSpawnLocation[2];
    }

	
    // Spawn the bomb
    return func_8027361C(bombType, spawnX.f, spawnY.f, spawnZ.f, playerID);
}

void SpawnPlayer_Hook(int playerID)
{
	g_SpawnPlayer(playerID);
	
	PlayerSpawning(playerID);
}

int AllocateModel_Hook(int modelID)
{
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