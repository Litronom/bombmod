#include "../MainInclude.h"

// ============================================================================
// GLOBAL DATA
// ============================================================================

extern Gfx *GFXgraphPtr; //0x80024748
extern Controller g_ControllerInputs[4]; //0x80027060
extern Bomb g_Bombs[]; //0x8008F4C0
extern LevelClass g_LevelClasses[]; //0x800A3F00
extern Object g_HUDObject; //0x800A0DA0
extern Object g_GameObjects[]; //0x800A0DF0
extern Player g_Players[8]; //0x800AEDF0
extern LevelClass* g_getPlayerLevelClass(int playerID); //802443F4
extern EnemyAlloc g_EnemySlots[6]; //0x800BA8E8
extern EnemyHeader g_EnemyData[16]; //0x800BA900
extern EnemyRuntimeData g_EnemyRuntimeData[16]; //0x800BB340
extern int g_enemies_defeated_count; //0x800BC520
extern short g_itemPickupCounts[4][8]; //0x800BA8A0
extern int g_4thGoldCardIDs[6][4]; //0x802A1AF0
extern ComputerPlayerController g_ComputerPlayerController[4]; //0x800BCFE8
extern SFXChannel g_SoundChannels[8]; //0x800BD778
extern SFXStruct g_SoundFlags[8]; //0x801C8B50
extern RivalValues g_RivalInitialValues[10]; //0x802A1044
extern HeldObject g_HeldObjects[5]; //0x802AFCE8
extern ContainerObject g_ContainerData[32]; //0x80090440

// Enemy Attack System - Unified Jump Table
// Note: This is ONE table indexed at different offsets by the state machine
extern void* g_EnemyAttackTable[33]; //0x802A1B74 - Unified attack function table

extern ControllerCopy g_ControllerInputsCopy[4]; //0x802AC410
extern ControllerBuffer g_ControllerInputsBuffer[4][16]; //0x802AC428
extern uint g_ControllerBufferIndex[4]; //0x802AC5A8
extern LevelLoader g_LevelLoader; //0x802AC5D0
extern Game g_GameState; //0x802AC610
extern VSGame g_VSGameState; //0x802AC660
extern int g_PlayerLoadedFlag[16]; //0x802AC8A8
extern GlobalPlayerState g_GlobalPlayerState; //0x802AC9E0
extern int g_playerFlagBitField; //0x802AC9E8
extern ComputerPlayerMovement g_ComputerPlayerMovement[4]; //0x802ACF08
extern ContainerObjectAlloc g_ContainerObjectSlots[4]; //0x802B0190
extern void g_AllocateContainers(ContainerObjectAlloc* LevelContainers); //0x8027EB5C

// ============================================================================
// PARTICLE EFFECTS SYSTEM
// ============================================================================

// Particle Effect Data
extern ParticleEffect g_ParticleEffects[16]; //0x800BC528 - Particle effect slots (16 slots, 36 bytes each)
extern int g_ParticleEffectAllocationIndex; //0x800BC768 - Index for reclaiming effect slots with activeFlag==2

// Main Particle Effect Functions
extern int g_SpawnParticleEffect(int effectID, float locX, float locY, float locZ, LevelClass* parent); //0x8028A81C - Spawn Particle effect with offset to parent or global (returns: effect slot index 0-15 on success, -1 on failure)
extern int g_StopParticleEffect(int effectID); //0x8028A4E0 - Stop/free Particle effect by ID (returns: 1 on success, 0 if invalid ID)
extern void g_ClearAllParticleEffects(); //0x8028A584 - Stop/free all 16 Particle effect slots

// Other Particle Effect Helper Functions
extern void func_80229E38(void* objectPointer, int param1, int param2); //0x80229E38 - Set object animation
extern void func_8022FC90(void* object); //0x8022FC90 - Cleanup/free object (called by g_StopParticleEffect for offset 0x20)
extern void* g_CreateGameObjectEx(void* param1, int param2, int param3, int param4, LevelClass* parent); //0x80230CB4 - Create game object with extended parameters
extern void* g_CreateGameObject(void* param1, void* param2); //0x80230E6C - Create simple game object
extern void g_SetObjectFlags(void* object, int flags); //0x80231408 - Configure game object flags
extern void func_80238EA8(int effectID); //0x80238EA8 - Cleanup/free effect ID (called by g_StopParticleEffect for offset 0x4)
extern void* g_SpawnAndAttachRoundShadow(LevelClass* parent); //0x802311E8 - Spawn and attach round shadow to LevelClass object
extern int g_ConfigureParticleEffect(); //0x8028A5C4 - Configure Particle effect slot (non-standard calling: $s1=ID, $t0=pos, $t1=param, $t2=effectType, $t3=parentObj; returns: slot index or -1)
extern int g_AllocateParticleEffectSlot(); //0x8028A690 - Non-standard: $s1=effectType. Smart allocator: searches free slots, for types 0x13/0x14/0xD/0xE/0xC returns index+100, uses round-robin reclaim for activeFlag==2
extern int g_AllocateAndConfigureEffect(); //0x8028A7CC - Non-standard: $a0=effectType, stack params. Calls g_AllocateParticleEffectSlot then g_ConfigureParticleEffect (returns: slot index or -1)
extern void func_8028A87C(); //0x8028A87C - Wrapper: calls func_80297D30(0x26, D_802A1CE4)
extern void g_InitParticleEffects(); //0x8028A8A4 - Initialize Particle effects system (clears all 16 slots, resets allocation index, calls func_8028A87C)
extern void func_8028A980(void* obj, float delta); //0x8028A980 - Adds delta to 3 consecutive floats at obj->ptr[0x40]->floats[0x28,0x2C,0x30]
extern void func_8028A9CC(); //0x8028A9CC - Empty stub function (does nothing)
extern void func_8028A9D4(); //0x8028A9D4 - Spawn game object for effect (non-standard: $a0=type, $s0=outPtr, $s1=effectPtr, $t0=param)
extern void func_80232DB4(void* object); //0x80232DB4 - Update object state/position
extern float func_8026E938(void* object); //0x8026E938 - Get object height/position value (returns float)
extern int func_8028E5E0(); //0x8028E5E0 - Effect callback function
extern int func_8028E5EC(); //0x8028E5EC - Effect callback function (alternate)
extern int func_8028EAD8(float angle, int offset, void* callback); //0x8028EAD8 - Process effect with angle and callback (returns int)
extern int func_8028EB28(float value); //0x8028EB28 - Collision/boundary check (returns int)
extern int g_EffectCollisionYMonitor(); //0x8028EB70 - Non-standard: $s2=effectPtr, $s3=maxCount. Monitors collision and Y position changes, returns 1 when collision/Y-drop detected or counter >= maxCount
extern void g_EffectNoOp(void* param); //0x8028EC00 - Empty function (no operation)
extern void g_EffectIncrementNestedValue(); //0x8028EC08 - Non-standard: $s1=effectPtr, $f12=delta. Increments value at effect->0x4->0x40->0x48->0x4 by delta, clamps to minimum 0.0
extern void g_EffectCleanup(void* effectPtr); //0x8028ECB0 - Deactivates effect (sets activeFlag=-1), optionally spawns sound at Y+100 if effect->0x18 != -1, calls cleanup
extern void g_EffectProcess10(void* effectPtr); //0x8028ED18 - Processes effect with value 10.0: collision check with maxCount=100, cleanup on collision, otherwise increment nested value
extern void g_EffectProcess12_5(void* effectPtr); //0x8028ED9C - Processes effect with value 12.5: collision check with maxCount=100, cleanup on collision (simplified version)
extern void g_EffectCopyPositionCleanup(void* effectPtr); //0x8028EE0C - Copies XYZ position from effect->0x8->0x40 to effect->0x4->0x40, then calls cleanup
extern void g_EffectStageProcessor(); //0x8028EE78 - Non-standard: $s2=effectPtr, $f12=value, $s3=cleanupFlag, $s4=maxCount, $f22=multiplier. Modifies rotZ, manages Y position, calls callbacks
extern void g_EffectSimpleSetup(void* param); //0x8028EF58 - Simple effect setup: calls g_EffectProcessValue(5.0f) and g_EffectStageProcessor(0.5f)
extern void g_EffectCollisionTimer(void* param); //0x8028EFE4 - Collision/velocity monitor: checks collision and velocity (0x68/0x6C), timer to 101 frames
extern void g_EffectCollisionRotate(void* param); //0x8028F08C - Collision check with rotation animation: rotX -50→80°, timer to 101 frames
extern void g_EffectGravityIDr(); //0x8028F1F0 - Non-standard: $s0=effectPtr, $s1=maxCount, $f22=delta. Applies gravity/falling physics, updates Y position, checks ground collision
extern void g_EffectRotation4Stage(void* param); //0x8028float0 - 4-stage rotation: <5 adds, 5-9 subtracts, 10-19 idle, >=20 subtracts more
extern void g_EffectRotationStages(void* param); //0x8028F428 - Multi-stage rotation: stage 1(<10), stage 2(10-19 adds rotation), stage 3(>=20 subtracts rotation)
extern void g_EffectTimerCount30(void* param); //0x8028F55C - Increments param->0xC until 30, then triggers effect processing
extern void g_EffectConditionalProcess(void* param); //0x8028F5E0 - Checks condition with 10.0f, branches to param or value processing
extern void g_EffectNullStub(); //0x8028F664 - Empty stub function (does nothing)
extern void g_SavePositionToStack(float x, float y, float z); //0x8028F66C - Stores 3 float position parameters to stack
extern void g_EffectPreSpawnHelper(); //0x8028F67C - Non-standard: $s0=effectPtr, $s1=posPtr, $s2=type, $s3/$s4=params. Creates objects at effectPtr->0x4/0x8, copies position
extern float g_GetEffectAngle(void* param); //0x8028F710 - Returns angle in degrees based on param->0x14 (1→180°, 2→135°, 3→90°, 4→45°, 5→0°, 7→270°, 8→225°)
extern void g_SpawnEffectTypeD(void* param1, void* param2, void* position); //0x8028F7CC - Spawn Particle effect type 0xD with LevelClass 0x102, plays sound 0x16C
extern void g_SpawnEffectType0Alt(void* param1, void* param2, void* position); //0x8028F880 - Spawn effect 0 with LevelClass 0x103, plays sound 0x16C
extern void g_SetupEffectType7(void* param1, void* param2, void* position); //0x8028F8F8 - Setup effect values and sound 0x171 (no spawn/LevelClass)
extern void g_SetupEffectTypeD(void* param1, void* param2, void* position); //0x8028F988 - Setup LevelClass 0x105 with sound 0x16E (no effect spawn)
extern void g_SpawnEffectTypeE(void* param1, void* param2, void* position); //0x8028FA38 - Spawn Particle effect type 0xE, plays sound 0x16F
extern void g_SpawnEffectType0(void* param1, void* param2, void* position); //0x8028FB04 - Spawn Particle effect type 0 at position, plays sound 0x16D
extern void g_EffectSetupAndSound(void* param1, void* param2, void* position); //0x8028FB98 - Setup effect values and play sound 0x16D (no effect spawn)
extern void g_SpawnEffectType4(void* param1, void* param2, void* position); //0x8028FC2C - Spawn Particle effect type 0x4 with Y+50 offset, plays sound 0x172
extern void g_SpawnEffectType0WithObject(void* param1, void* param2, void* position); //0x8028FCE4 - Spawn effect 0 with LevelClass object 0x10A
extern void func_8026C630(int soundID, void* position); //0x8026C630 - Play positional sound
extern void func_80297D30(int param1, void* param2); //0x80297D30 - Unknown function

// ============================================================================
// ENEMY SYSTEM
// ============================================================================

extern Enemy *g_spawnEnemyFromAllocation(int enemyAllocID, float locX, float locY, float locZ); //0x802867E4 - Spawns enemy from EnemyAlloc at specified location
extern void g_EnemyAllocate(int enemySlotID, int behavior, int modelID); //0x80287008 - Puts entry in g_EnemySlots
extern void func_80282430(void* enemyObj, int animID, int param); //0x80282430 - Set enemy animation
extern void func_8028304C(); //0x8028304C - ID enemy stun (non-standard: uses s0/s1 registers directly)
extern int func_802824B4(void* enemyObj); //0x802824B4 - Update enemy state
extern void g_FinalizeEnemySpawn(Enemy *enemy, short arg1, short arg2); //0x802847E4 - Finalize enemy spawn initialization
extern int EnemyDamagedCheck(EnemyObject* enemyObject); //0x80284CAC - Enemy damage IDr (returns: 1=damaged, 2=killed, 4=no_damage_invuln)
extern void func_8028805C(void* enemyObj); //0x8028805C - Clear enemy attachment
extern void func_802313DC(void* enemyObject, int state); //0x802313DC - Set enemy object state

// ============================================================================
// GAME/LEVEL SYSTEM
// ============================================================================

extern VSGame *g_GetVSGameState(); //0x8023A834
extern Game *g_GetGameState(); //0x8023A840
extern void g_EndLevel(); //0x8023E8AC
extern LevelClass* g_InitLevelClass(int modelID, int flag, int num2, int num3); //0x80231274
extern void g_SpawnPlayer(int playerID); //0x802459BC
extern void g_InitPlayers(); //0x80245CDC
extern void g_PlayerMovement(int num); //0x8024E088
extern void g_SetupRivalBoss(int playerID, int rivalID, int x, int y, int z); //0x8025DC60
extern void g_RenderModel(Gfx **dlPtr, s32 baseAddress, s32 attachmentIndex); //0x8022D58C
extern void g_spawnItem(int itemID, float locX, float locY, float locZ); //0x8027B7C4
extern bool g_spawnItemType_Grid(short itemID, short posX, short posY, short posZ); //0x8027B828
extern bool g_spawnItemByChance_Grid(short posX, short posY, short posZ, int patternIndex); //0x8027B8D4
extern void g_playerThrowHeldObject(short playerID, short throwSpeedID); //0x80270770 - Triggers when player should release/throw their held object through any means
extern ContainerItemDefinition *g_containerItemDefinitionPtr; //0x802AFE80 - Dynamic pointer to container item definitions
extern short g_ItemSpawnProbabilityTable[10][3]; // 0x802AFE88
extern int g_LastItemIDCollected; // 0x802AFECC - Last item ID collected by player, index based on 1
extern int g_PauseFlag; //0x802A0B80
extern int g_soundIndexCounter; //0x802A13C0
extern int g_gameFrameCounter; //0x802A13C4
extern bool g_spawnContainerObject(short posX, short posY, short posZ, short renderFlag); //0x8026F068 - Spawns a container object based on renderFlag at specified position
extern void g_destroyContainerObject(ContainerObject *cntObj); //0x8027D328
extern void g_handlePlayerKnockback(int playerID, LevelClass *collidedLevelclass, int collisionFlags); //0x80249648

// ============================================================================
// MATH
// ============================================================================

extern int g_RandomIndex; // 0x802ACFE0 - RNG table index
extern int g_RandomTable[56]; // 0x802ACFE8 - RNG lookup table
extern double g_RandomScale; // 0x802A3A10 = 1.0 / 1,000,000,000

extern void g_shuffleRandomTable(int *index); // 0x8025E4A0 - Resets / reshuffles RNG table
extern void g_initRandom(int seed); // 0x8025E6A4 - Initializes RNG with seed
extern int g_nextRandomRaw(); // 0x8025E5EC - Advances RNG and returns next value
extern double g_nextRandomDouble(); // 0x8025E63C - Advances RNG and returns next value as double in [0.0, 1.0)
extern int g_getRandomNumber(int max); //0x80234248 - Returns pseudo-random number in range [0, max]

extern float g_FloatEpsilon; // 0x8029FE30 - Small tolerance for float comparisons (0.0001f)

extern int g_approxEqual(float a, float b); // 0x80233650 - Returns 1 if |a - b| <= g_FloatEpsilon, else 0
extern int g_approxEqualEps(float a, float b, float eps); // 0x8023369C - Returns 1 if |a - b| <= eps, else 0
extern int g_approxZero(float a); // 0x802336E4 - Returns 1 if |a| <= g_FloatEpsilon, else 0
extern int g_inRange(float x, float r); // 0x8023372C - Returns 1 if -r <= x <= r, else 0
extern int g_cmpWithEpsilon(float a); // 0x80233768 - Returns 1 if a > g_FloatEpsilon, -1 if a < g_FloatEpsilon, else 0
extern int g_floatCompare(float a, float b); // 0x802337B0 - Returns 1 if a > b, -1 if a < b, else 0
extern int g_sign(float a); // 0x802337EC - Returns 1 if a > 0, -1 if a < 0, else 0

// ============================================================================
// CAMERA
// ============================================================================

extern CameraValues g_CameraValues; //0x80090000

extern float g_CameraMinX; // 0x8009003C - Minimum X coordinate the camera can move to
extern float g_CameraMaxX; // 0x80090044 - Maximum X coordinate the camera can move to
extern float g_CameraMinZ; // 0x80090040 - Minimum Z coordinate the camera can move to
extern float g_CameraMaxZ; // 0x80090048 - Maximum Z coordinate the camera can move to


// ============================================================================

extern PlayerPointer g_PlayerPointers[4]; //0x80098C18

extern char g_ControllerCount; //0x800270A1
extern float g_common_shadow_model_scale; //0x802A2DE4

extern int g_CurrentScreenID; //0x802A5328
extern int g_PointerFor802268F4; //0x802A532C
extern void JumpToFunction(); //0x802268F4

extern ModelEntry LoadModelInRAM (int ModelID, int Unk, float X, float Y, float Z);
extern int g_ModelPointerListROM; //0x802A5324

extern void UpdateRenderFrame(); //0x802259F4

extern void AdditionalUpdate(); //0x80247614
extern void FinalizeFrameUpdate(); //0x80239094

extern float g_BombSpawnLocation[3]; //0x802AFE60
extern int g_SpawnPlayerBomb(short bombType, int float_locX, int float_locY, int float_locZ, short playerID); //0x80273F30
extern void g_PickupGem(); //0x802794FC
//extern void PlayGlobalSound(int soundID, LevelClass *class); //0x8026C660
extern void g_PlayGlobalSound(int soundID); //0x8026C660
extern void g_PlayLocalSound(int soundID, float locX, float locY, float locZ); //0x8026C51C
extern void g_StopSound(int index, int stop); //0x8026C0A8


//crashes
extern int g_PlayMusic(short songID); //0x8026C93C

extern int g_PlayMusicValidator; //0x802A1330

extern void g_InitGameVS(); //0x8023CA94

extern int g_VSPlayerSelectionID; //0x8004A328
extern int g_VSPlayerSubSelectionID; //0x8004A32C
extern int g_VSPlayerTeamSelectionID; //0x8004A330

extern int g_someBombVerification; //0x802AFC70

extern BoolStruct SomeBoolStruct1; //0x802AC760
extern BoolStruct SomeBoolStruct2; //0x802AC820

extern void func_80273E2C(short playerID); //0x80273E2C
extern int g_spawnBomb(short bombType, float posX, float posY, float posZ, short playerID); //0x8027361C
extern int func_80273AD4(short A16, int A32, int B32, int C32); //0x80273AD4

extern void func_80277E1C(); //0x80277E1C
extern void func_80251804(int ID); //0x80251804
extern void LoadCustomParts(int playerID, int partTypeID, int partSetID); //0x8023A734
extern void g_EquipCustomPart(int playerID, int partSlot, int modelID); //0x80228008
extern void g_SetBodyPartToModelPart(int playerIndex, int partIndex, int value); //0x80227FE8
extern void g_FreePlayerModelPart(void* modelID, int partOffset, int playerID); //0x8026CBD4
extern void g_FreePlayerAssets(int playerID); //0x80227EE0
extern void func_8026CBD4(int num); //0x8026CBD4
extern int g_InitPlayerAssetPointers(Object *playerObject, int count); //0x802280F4

extern CustomParts g_SaveGameCustomParts; //8008E5A8

extern int g_CustomPartModelID_LUT[6][11]; //0x802A0BA8
extern int g_CustomPartModelID_LUT_Head[11]; //0x802A0BA8
extern int g_CustomPartModelID_LUT_Body[11]; //0x802A0BD4
extern int g_CustomPartModelID_LUT_ArmsL[11]; //0x802A0C00
extern int g_CustomPartModelID_LUT_LegsL[11]; //0x802A0C2C
extern int g_CustomPartModelID_LUT_ArmsR[11]; //0x802A0C58
extern int g_CustomPartModelID_LUT_LegsR[11]; //0x802A0C84

extern ushort g_EngineCreateCommand(void *callback, int userParam, void *data, int dataSize, ushort commandType); //0x80238A10

extern void func_8027A640(); //0x8027A640
extern int D_80019F90; //0x80019F90
extern void D_80024820(); //0x80024820
extern void PAYLOAD_RAM(); //0x80024820
extern void func_80000870(); //0x80000870
extern void func_80001A30(unsigned int *table, unsigned int* func); //0x80001A30
extern void load_from_rom_to_addr(void* arg0, signed int arg1, unsigned int arg2); //0x80000698

extern void g_AllocateLevel(); //0x80243BA8
extern void g_AllocateLevelCollision(); //0x8026FF64

extern ModelAlloc g_LevelModelAllocations[100]; //0x800A7F30
extern int g_ModelAllocCount; //0x802AFC30
extern int g_ObjectAllocCount; //0x802A5460

extern int D_802AC89C; //0x802AC89C
extern int D_802AC8A0; //0x802AC8A0

extern int D_802AC8E8[16]; //0x802AC8E8
extern float D_802ACA78[16]; //0x802ACA78

// LevelClass / Object flag helpers (descriptive aliases kept alongside original symbols)
extern void g_XorLevelClassFlags(LevelClass *levelPtr, int flags); // 0x802313B0 - XOR flags on LevelClass (original)
extern void g_SetLevelClassFlags(LevelClass *levelPtr, int flags); // 0x80231408 - OR flags on LevelClass (existing)
extern void g_ClearLevelClassFlags(LevelClass *levelPtr, int flags); // 0x802313DC - AND~ flags on LevelClass (existing)
extern void g_UpdateLevelObjectFlags(LevelClass *levelPtr); // 0x802312AC - Apply LevelClass flags to attached object
extern void g_SetObjectDisplayMode(void *obj, int mode); // 0x8022946C - Set object display/mode byte

extern void func_80229F74(Object* obj, int num); //0x80229F74
extern void func_8022984C(Object* obj, int flag); //0x8022984C

extern void func_8022979C(Object* obj, int num1, int num2); //0x8022979C
extern void func_80231408(void* obj, int flag); //0x80231408
extern void g_AssignModelParts(Object* obj, int modelID, int num1, int num2); //0x802297B8

extern void func_802444B8(int playerID, int num); //0x802444B8

extern int g_AllocateModelSize(int size); //0x80225B00
extern void* g_AllocateModel(int modelID); //0x8026CE28
extern int g_GetAllocationIndex(int modelID1, int modelID2); //0x8026CD24
extern void g_InitModel(int param); //0x802267E0
extern void* g_LoadModel(int modelID, int flag); //0x80226604
extern void g_PrepareModelBuffer(void* dst, int size, int flag, void* modelID); //0x8022616C
extern void* g_ProcessModelBuffer(void* buffer); //0x802998EC
extern void g_RegisterModel(void* modelID, void* processed, void* buffer); //0x80292BD0
extern void g_FinalizeModel(void* modelID); //0x80226368