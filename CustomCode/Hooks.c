#include "MainInclude.h"

Bomb* SpawnPlayerBomb_Hook(short bombType, int locX, int locY, int locZ, short playerID)
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
    if (g_HeldObjects[playerID].heldLvlClass != 0)
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
    return g_spawnBomb(bombType, spawnX.f, spawnY.f, spawnZ.f, playerID);
}


void SpawnPlayer(int playerID)
{
    int sp38 = 0;
    LevelClass *plyLvl = g_InitLevelClass(OBJ_MODEL_PLAYER_BOMBERMAN, 0x0D000011, 0x70, 0);
    Player *ply = &g_Players[playerID];
    ply->PlayerLevelClass = plyLvl;
    plyLvl->ObjectPointer->position[0] = ply->spawnLocation[0];
    ply->PlayerLevelClass->ObjectPointer->position[1] = ply->spawnLocation[1];
    ply->PlayerLevelClass->ObjectPointer->position[2] = ply->spawnLocation[2];
    ply->PlayerLevelClass->ObjectPointer->angle[1] = ply->directionAngle;
    ply->PlayerLevelClass->u11 = 1;
    ply->PlayerLevelClass->radius = 30.0f;
    ply->PlayerLevelClass->unk_float = 51.0f;
    ply->PlayerLevelClass->unk_float2 = 0.0f;
    ply->PlayerLevelClass->unk_float3 = 1.6333334f;
    ply->PlayerLevelClass->unk_float1 = 0.0f;
    ply->PlayerLevelClass->u2 = 0x1FF0;
    func_80229F74(ply->PlayerLevelClass->ObjectPointer, 2);
    func_8022984C(ply->PlayerLevelClass->ObjectPointer, 0xC);
    int var_v1 = 0;
    if ((ply->u12 & 0x200) == 0x200)
    {
        var_v1 = 1;
    }
    int var_s1 = sp38;
    if (var_v1 != 0)
    {
        LevelClass *plyLvl2 = ply->PlayerLevelClass;
        func_8022979C(plyLvl2->ObjectPointer, 4, 4);
        func_8022979C(plyLvl2->ObjectPointer, 5, 5);
        func_80231408(plyLvl2, 0x80000);
        plyLvl2->ObjectPointer->u7 = 0x80;
        Object *plyObj = plyLvl2->ObjectPointer;
        plyObj->param = plyObj->param | 0x1000;
        var_s1 = sp38;
    }
    int var_s0 = 0;
    
    do
    {
        switch (playerID)                               /* irregular */
        {
        case 0:
            var_s1 = 0x4A;
            break;
        case 1:
            var_s1 = 0x4B;
            break;
        case 2:
            var_s1 = 0x4C;
            break;
        case 3:
            var_s1 = 0x4D;
            break;
        }
        g_AssignModelParts(ply->PlayerLevelClass->ObjectPointer, var_s1, var_s0, var_s0);
        var_s0 += 1;
    } while (var_s0 != 0xC);

    sp38 = var_s1;
    int temp_s0_2 = playerID * 4;
    ply->ComputationLevelClass = g_SpawnAndAttachRoundShadow(ply->PlayerLevelClass);
    g_PlayerLoadedFlag[temp_s0_2] = 1;
    D_802AC89C = 0;
    D_802AC8A0 = 0;
    func_802444B8(playerID, 0);
    D_802AC8E8[temp_s0_2] = -1;
    D_802ACA78[temp_s0_2] = 0.0f;
    ply->flag = 0;
    ply->u12 = ply->u12 & 0x200;
    ply->HeldLevelClass = 0;
    ply->collisionEnabled = 1;
    ply->u13 = 0;
    ply->u14 = 0;
    ply->u15 = 0;
    ply->u16[1] = 3;
    ply->u17[0] = 0;
    ply->u17[2]= 0;
    ply->u17[3] = 0;
    ply->u20[0] = 0;
    ply->u9 = 0;
    ply->bombType = ply->bombType & ~0x404;
    ply->timer2 = 0;
    ply->u11 = 0;
    ComputerPlayerMovement *plyMov = &g_ComputerPlayerMovement[playerID];
    plyMov->u1 = 0;
    plyMov->u2 = 0;
    plyMov->moveSpeed = 0.0f;
    plyMov->f1 = 0.0f;
    plyMov->moveDirection = 0.0f;
}


void SpawnPlayer_Hook(int playerID)
{
	g_SpawnPlayer(playerID);
	
	PlayerSpawning(playerID);
}

void RenderDynamicObjects_Hook(Gfx **dlPtr, s32 baseAddress, s32 attachmentIndex)
{
    g_RenderModel(dlPtr, baseAddress, attachmentIndex);
}

void RenderMap_Hook(Gfx **dlPtr, s32 baseAddress, s32 attachmentIndex)
{
//    uintptr_t address = (uintptr_t)&jumperHeader;

    g_RenderModel(dlPtr, baseAddress, attachmentIndex);

//    g_RenderModel(dlPtr, address, 0);
}

void RenderMapObjects_Hook(Gfx **dlPtr, s32 baseAddress, s32 attachmentIndex)
{
    //if(attachmentIndex != 0)
    //{
    //    attachmentIndex = 1;
    //}
    g_RenderModel(dlPtr, baseAddress, attachmentIndex);
}

int GetAllocationIndex(int modelID)
{
    // First pass: find existing allocation
    for (int i = 0; i < 100; i++)
    {
        if (g_LevelModelAllocations[i].modelID == modelID)
        {
            return i;
        }
    }

    // Second pass: find free slot in groups of 4
    for (int base = 0; base < 100; base += 4)
    {
        if (g_LevelModelAllocations[base].modelID == -1 && g_LevelModelAllocations[base].modelData == INVALID_PTR)
        {
            return base;
        }
        if (g_LevelModelAllocations[base + 1].modelID == -1 && g_LevelModelAllocations[base + 1].modelData == INVALID_PTR)
        {
            return base + 1;
        }
        if (g_LevelModelAllocations[base + 2].modelID == -1 && g_LevelModelAllocations[base + 2].modelData == INVALID_PTR)
        {
            return base + 2;
        }
        if (g_LevelModelAllocations[base + 3].modelID == -1 && g_LevelModelAllocations[base + 3].modelData == INVALID_PTR)
        {
            return base + 3;
        }
    }

    // No available slot found
    return -1;
}


void* AllocateModel_Hook(int modelID)
{
    if (modelID == -1)
    {
        return INVALID_PTR;
    }

    if (modelID == OBJ_MODEL_PLAYER_BOMBERMAN)
    {
        //modelID = OBJ_MODEL_OVERWORLD_DRAGON;
    }


    int allocIndex = GetAllocationIndex(modelID);

    ModelAlloc* entry = &g_LevelModelAllocations[allocIndex];
    if (entry->modelID != modelID)
    {
        g_ModelAllocCount++;

        entry->modelID = modelID;

        g_InitModel(0x18);

        void* modelData = g_LoadModel(modelID, 1);
        
        void* bufferPtr;
        g_PrepareModelBuffer(&bufferPtr, 4, 1, modelData);

        void* modelHandle = g_ProcessModelBuffer(bufferPtr);
        entry->modelData = modelHandle;

        g_RegisterModel(modelData, modelHandle, bufferPtr);
        g_FinalizeModel(modelData);
    }

    entry->count++;
   
    return entry->modelData;
}

void EquipCustomPart(int playerID, int partSlot, int modelID)
{
    void** playerParts = (void**)g_PlayerPointers[playerID].attachmentModelPtr;
    int offset = partSlot * 4;
    void* currentModel = playerParts[partSlot];

    if (modelID == -1)
    {
        g_FreePlayerModelPart(currentModel, offset, playerID);
        playerParts[partSlot] = NULL;
        return;
    }

    if (currentModel != NULL)
    {
        g_FreePlayerModelPart(currentModel, offset, playerID);
    }

    playerParts[partSlot] = AllocateModel_Hook(modelID);
}

// Test to equip custom display list as model part - unfinished
void EquipCustomModel(int playerID, int partSlot, int customModelSubID)
{
/*
    int modelID = OBJ_MODEL_MAP_UP_AND_DOWN_UNUSED;
    void* modelAddress = &jumperHeader[0];
    void** playerParts = (void**)g_PlayerPointers[playerID].attachmentModelPtr;
    int offset = partSlot * 4;
    void* currentModel = playerParts[partSlot];

    if (modelID == -1)
    {
        g_FreePlayerModelPart(currentModel, offset, playerID);
        playerParts[partSlot] = NULL;
        return;
    }

    if (currentModel != NULL)
    {
    //    g_FreePlayerModelPart(currentModel, offset, playerID);
    }

    //Allocation
    int allocIndex = GetAllocationIndex(modelID);

    ModelAlloc* entry = &g_LevelModelAllocations[allocIndex];
    if (entry->modelID != modelID)
    {
        g_ModelAllocCount++;

        entry->modelID = modelID;

        g_InitModel(0x18);

        void* modelData = g_LoadModel(modelID, 1);
        
        void* bufferPtr;
        g_PrepareModelBuffer(&bufferPtr, 4, 1, modelData);

        void* modelHandle = g_ProcessModelBuffer(bufferPtr);
        entry->modelData = modelHandle;

        //g_RegisterModel(modelData, modelHandle, bufferPtr);
        //g_FinalizeModel(modelData);

        u8* dst = (u8*)modelHandle;
        u8* src = (u8*)modelAddress;
        size_t size = ModelJumperEnd - ModelJumperStart;
        for (int i = 0; i < size; i++)
            dst[i] = src[i];
    }

    entry->count++;
   
    //Euqip
    playerParts[partSlot] = entry->modelData;
    g_SetBodyPartToModelPart(playerID,partSlot,customModelSubID);
*/
}

void EquipCustomPart_Hook(int playerID, int partSlot, int modelID)
{
	if (g_CurrentScreenID == 0x23)
	{
        return;
    }
    
    EquipCustomPart(playerID, partSlot, modelID);
}

/*
void FreePlayerAssets(int playerID)
{
    PlayerPointer *player = &g_PlayerPointers[playerID];

    if (player->count > 0)
    {
        for (int i = 0; i < player->count; i++)
        {
            // Free each model part if it exists
            g_FreePlayerModelPart(player->modelPart[i]);
            player->modelPart[i] = 0;
        }
    }

    // Free the modelPart and attachmentModelPtr arrays themselves
    func_8029ADCC(player->modelPart);
    func_8029ADCC(player->attachmentModelPtr);

    // Reset the struct
    player->playerObject = NULL;
    player->count = 0;
}
*/
int InitPlayerAssetPointers(Object *playerObject, int count)
{
    int i;

    // Find an unused player pointer slot
    for (i = 0; i < 5; i++)
    {
        if (g_PlayerPointers[i].playerObject == NULL)
            break;
    }

    if (i == 5)
        return -1; // All slots full

    PlayerPointer *player = &g_PlayerPointers[i];
    player->count = count;
    player->playerObject = playerObject;

    // Allocate memory: count entries, each assumed 0x10 bytes
    size_t allocSize = count * 0x10;

    player->attachmentModelPtr = g_ProcessModelBuffer((void *)(uintptr_t)allocSize);
    player->modelPart = g_ProcessModelBuffer((void *)(uintptr_t)allocSize);

    // Make sure allocation succeeded
    if (!player->attachmentModelPtr || !player->modelPart)
        return -1;

    // Zero out each pointer in the arrays
    for (int j = 0; j < count; j++)
    {
        // Pointers to the element start
        uint8_t *elem1 = (uint8_t *)player->attachmentModelPtr + j * 0x10;
        uint8_t *elem2 = (uint8_t *)player->modelPart + j * 0x10;

        // Zero 16 bytes manually (avoid using memset if unavailable)
        for (int k = 0; k < 0x10; k++)
        {
            elem1[k] = 0;
            elem2[k] = 0;
        }
    }

    return i; // Return the index used
}

/*
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
*/


/*
void func_8023B8D0(void)
{
    ? sp30;
    s32 sp38;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f6;
    s32 temp_t8;
    s32 var_s1;
    s32 var_s2;
    s32 var_v0;
    void **var_s3;
    void *temp_v0;

    if (!(g_LevelLoader.flag & 4))
    {
        D_802A0B1C = *(&D_802A08F8 + ((D_802AC5E8 * 0x10) + (D_802AC5EC * 4)));
    }
    else
    {
        D_802A0B1C = &D_802A0448;
    }
    if (g_LevelLoader.flag & 0x2C)
    {
        func_8023B318(&D_802A0B1C);
        temp_t8 = g_LevelLoader.flag & 4;
        var_v0 = temp_t8;
        if (temp_t8 == 0)
        {
            func_8023B7C0();
            var_v0 = g_LevelLoader.flag & 4;
        }
    }
    else
    {
        func_80287680(&D_802A0B1C);
        func_8023B450(2);
        D_802AC814 = func_802811F0(&sp30, 0xDC, 0x50, D_802A2F0C, D_802A2F0C, 2);
        temp_f28 = D_802A2F10;
        temp_f26 = D_802A2F14;
        temp_f24 = D_802A2F18;
        temp_f22 = D_802A2F1C;
        temp_f20 = D_802A2F20;
        var_s3 = &D_802AC7F8;
        var_s1 = 0;
        var_s2 = 0;
        sp38 = g_AllocateModel(0x19);
        do
        {
            temp_v0 = func_8022A6C4(sp38, 0x40);
            *var_s3 = temp_v0;
            var_s3 += 4;
            if ((func_8028A36C((D_802AC5E8 * 0x14) + (D_802AC5EC * 5) + var_s1 + 0x2C) != 0) || ((var_s1 == 3) && (*(&D_800BE818 + var_s2) != 0)))
            {
                temp_v0->unkC = temp_v0->unkC | 0x100;
            }
            else
            {
                temp_v0->unkC = temp_v0->unkC | 0x1180;
                temp_v0->unk36 = 0x64;
            }
            temp_f6 = var_s1;
            var_s1 += 1;
            var_s2 += 4;
            temp_v0->unk14 = temp_f26;
            temp_v0->unk18 = temp_f28;
            temp_v0->unk28 = temp_f20;
            temp_v0->unk2C = temp_f20;
            temp_v0->unk10 = (temp_f6 * temp_f22) + temp_f24;
            temp_v0->unk30 = temp_f20;
            temp_v0->unk34 = D_802AC5CC;
        } while (var_s1 != 5);
        func_8023B7C0();
        if ((D_802AC75C == 0) || (func_8023AB90() == 0))
        {
            func_8023B318(&D_802A0B1C);
            func_802814D8(D_802A0B40, 0xFFE8, 0);
            var_v0 = g_LevelLoader.flag & 4;
        }
        else
        {
            func_8023B318(&D_802A0B1C);
            func_802814D8(D_802A0B40, 0xFFE8, 0);
            var_v0 = g_LevelLoader.flag & 4;
        }
    }
    if (var_v0 == 0)
    {
        func_8023AF5C();
    }
}
    */