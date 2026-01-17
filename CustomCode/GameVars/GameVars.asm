// ============================================================================
// OS
// ============================================================================

.definelabel osGetIntMask, 0x80010BC0
.definelabel osSetIntMask, 0x80010BE0
.definelabel gInterruptMask, 0x8001B1E4

// ============================================================================
// GLOBAL DATA
// ============================================================================

.definelabel g_GraphPtr, 0x80024748
.definelabel g_ControllerInputs, 0x80027060
.definelabel g_ExplosionComponents, 0x8008E658
.definelabel g_Bombs, 0x8008F4C0
.definelabel g_LevelClasses, 0x800A3F00
.definelabel g_HUDObject, 0x800A0DA0
.definelabel g_GameObjects, 0x800A0DF0
.definelabel g_Players, 0x800AEDF0
.definelabel g_getPlayerLevelClass, 0x802443F4
.definelabel g_EnemySlots, 0x800BA8E8
.definelabel g_EnemyData, 0x800BA900
.definelabel g_EnemyRuntimeData, 0x800BB340
.definelabel g_enemies_defeated_count, 0x800BC520
.definelabel g_itemPickupCounts, 0x800BA8A0
.definelabel g_4thGoldCardIDs, 0x802A1AF0
.definelabel g_ComputerPlayerController, 0x800BCFE8
.definelabel g_SoundChannels, 0x800BD778
.definelabel g_SoundFlags, 0x801C8B50
.definelabel g_RivalInitialValues, 0x802A1044
.definelabel g_HeldObjects, 0x802AFCE8
.definelabel g_ContainerData, 0x80090440

// Enemy Attack System - Unified Jump Table (33 entries at 0x802A1B74)
.definelabel g_EnemyAttackTable, 0x802A1B74

.definelabel g_ControllerInputsCopy, 0x802AC410
.definelabel g_ControllerInputsBuffer, 0x802AC428
.definelabel g_ControllerBufferIndex, 0x802AC5A8
.definelabel g_LevelLoader, 0x802AC5D0
.definelabel g_GameState, 0x802AC610
.definelabel g_VSGameState, 0x802AC660
.definelabel g_PlayerLoadedFlag, 0x802AC8A8
.definelabel g_GlobalPlayerState, 0x802AC9E0
.definelabel g_playerFlagBitField, 0x802AC9E8
.definelabel g_ComputerPlayerMovement, 0x802ACF08
.definelabel g_ContainerObjectSlots, 0x802B0190
.definelabel g_AllocateContainers, 0x8027EB5C

// ============================================================================
// PARTICLE EFFECTS SYSTEM
// ============================================================================

// Particle Effect Data
.definelabel g_ParticleEffects, 0x800BC528
.definelabel g_ParticleEffectAllocationIndex, 0x800BC768

// Particle Effect Functions
.definelabel func_80229E38, 0x80229E38
.definelabel func_8022FC90, 0x8022FC90
.definelabel g_CreateGameObjectEx, 0x80230CB4
.definelabel g_CreateGameObject, 0x80230E6C
.definelabel g_SpawnAndAttachRoundShadow, 0x802311E8
.definelabel g_SetObjectFlags, 0x80231408
.definelabel func_80238EA8, 0x80238EA8
.definelabel g_StopParticleEffect, 0x8028A4E0
.definelabel g_ClearAllParticleEffects, 0x8028A584
.definelabel g_ConfigureParticleEffect, 0x8028A5C4
.definelabel g_AllocateParticleEffectSlot, 0x8028A690
.definelabel g_AllocateAndConfigureEffect, 0x8028A7CC
.definelabel g_SpawnParticleEffect, 0x8028A81C
.definelabel func_8028A87C, 0x8028A87C
.definelabel g_InitParticleEffects, 0x8028A8A4
.definelabel func_8028A980, 0x8028A980
.definelabel func_8028A9CC, 0x8028A9CC
.definelabel func_8028A9D4, 0x8028A9D4
.definelabel func_80232DB4, 0x80232DB4
.definelabel func_8026C630, 0x8026C630
.definelabel func_8026E938, 0x8026E938
.definelabel func_8028E5E0, 0x8028E5E0
.definelabel func_8028E5EC, 0x8028E5EC
.definelabel func_8028EAD8, 0x8028EAD8
.definelabel func_8028EB28, 0x8028EB28
.definelabel g_EffectCollisionYMonitor, 0x8028EB70
.definelabel g_EffectNoOp, 0x8028EC00
.definelabel g_EffectIncrementNestedValue, 0x8028EC08
.definelabel g_EffectCleanup, 0x8028ECB0
.definelabel g_EffectProcess10, 0x8028ED18
.definelabel g_EffectProcess12_5, 0x8028ED9C
.definelabel g_EffectCopyPositionCleanup, 0x8028EE0C
.definelabel g_EffectStageProcessor, 0x8028EE78
.definelabel func_8028EE0C, 0x8028EE0C
.definelabel g_EffectSimpleSetup, 0x8028EF58
.definelabel g_EffectCollisionTimer, 0x8028EFE4
.definelabel g_EffectCollisionRotate, 0x8028F08C
.definelabel g_EffectGravityHandler, 0x8028F1F0
.definelabel g_EffectRotation4Stage, 0x8028F320
.definelabel g_EffectRotationStages, 0x8028F428
.definelabel g_EffectTimerCount30, 0x8028F55C
.definelabel g_EffectConditionalProcess, 0x8028F5E0
.definelabel g_EffectNullStub, 0x8028F664
.definelabel g_SavePositionToStack, 0x8028F66C
.definelabel g_EffectPreSpawnHelper, 0x8028F67C
.definelabel g_GetEffectAngle, 0x8028F710
.definelabel g_SpawnEffectTypeD, 0x8028F7CC
.definelabel g_SpawnEffectType0Alt, 0x8028F880
.definelabel g_SetupEffectType7, 0x8028F8F8
.definelabel g_SetupEffectTypeD, 0x8028F988
.definelabel g_SpawnEffectTypeE, 0x8028FA38
.definelabel g_SpawnEffectType0, 0x8028FB04
.definelabel g_EffectSetupAndSound, 0x8028FB98
.definelabel g_SpawnEffectType4, 0x8028FC2C
.definelabel g_SpawnEffectType0WithObject, 0x8028FCE4
.definelabel func_80297D30, 0x80297D30

// ============================================================================
// ENEMY SYSTEM
// ============================================================================

.definelabel g_spawnEnemyFromAllocation, 0x802867E4
.definelabel g_EnemyAllocate, 0x80287008
.definelabel func_80282430, 0x80282430
.definelabel func_8028304C, 0x8028304C
.definelabel func_802824B4, 0x802824B4
.definelabel g_FinalizeEnemySpawn, 0x802847E4
.definelabel EnemyDamagedCheck, 0x80284CAC
.definelabel func_8028805C, 0x8028805C
.definelabel func_802313DC, 0x802313DC

// ============================================================================
// GAME/LEVEL SYSTEM
// ============================================================================

.definelabel g_GetVSGameState, 0x8023A834
.definelabel g_GetGameState, 0x8023A840
.definelabel g_EndLevel, 0x8023E8AC
.definelabel g_InitLevelClass, 0x80231274
.definelabel g_SpawnPlayer, 0x802459BC
.definelabel g_InitPlayers, 0x80245CDC
.definelabel g_PlayerMovement, 0x8024E088
.definelabel g_SetupRivalBoss, 0x8025DC60
.definelabel g_RenderModel, 0x8022D58C
.definelabel g_spawnItem, 0x8027B7C4
.definelabel g_spawnItemType_Grid, 0x8027B828
.definelabel g_spawnItemByChance_Grid, 0x8027B8D4
.definelabel g_playerThrowHeldObject, 0x80270770
.definelabel g_containerItemDefinitionPtr, 0x802AFE80
.definelabel g_ItemSpawnProbabilityTable, 0x802AFE88
.definelabel g_LastItemIDCollected, 0x802AFECC
.definelabel g_spawnContainerObject, 0x8026F068
.definelabel g_destroyContainerObject, 0x8027D328
.definelabel g_handlePlayerKnockback, 0x80249648
.definelabel g_SubtractPlayerBombCount, 0x80277AA0
.definelabel g_AddPlayerBombCount, 0x80277AF8
.definelabel g_SubtractPlayerFirePower, 0x80278E28
.definelabel g_AddPlayerFirePower, 0x80278E84

// ============================================================================
// BOMB SYSTEM
// ============================================================================

.definelabel g_BombSpawnLocation, 0x802AFE60
.definelabel g_ExplosionCounter, 0x802AFE70

.definelabel g_SpawnPlayerBomb, 0x80273F30
.definelabel g_spawnBomb, 0x8027361C
.definelabel g_UpdateBomb, 0x8027655C

.definelabel g_ConvertBomb2ExplosionPosition, 0x80275120
.definelabel g_SpawnPumpedRedBombExplosion, 0x80275590
.definelabel g_SpawnPumpedBombExplosion, 0x802756DC
.definelabel g_SpawnBombExplosion, 0x802752BC
.definelabel g_SpawnRedBombExplosion, 0x802757E0
.definelabel g_BombExplosionRoutine, 0x80275948
.definelabel g_GetExplosionFlags, 0x80277F0C
.definelabel g_FindFreeExplosionSlot, 0x80277F74
.definelabel g_SpawnExplosion, 0x80277FC4
.definelabel g_CleanupExplosion, 0x80278740
.definelabel g_ExplosionAnimateDecay, 0x80278788
.definelabel g_ExplosionAnimateRotation, 0x802787E4
.definelabel g_UpdateExplosion, 0x80278D54
.definelabel g_ClearAllExplosions, 0x80278DBC

// ============================================================================
// MATH
// ============================================================================

.definelabel g_RandomIndex, 0x802ACFE0
.definelabel g_RandomTable, 0x802ACFE8
.definelabel g_RandomScale, 0x802A3A10

.definelabel g_initRandom, 0x8025E6A4
.definelabel g_shuffleRandomTable, 0x8025E4A0
.definelabel g_nextRandomRaw, 0x8025E5EC
.definelabel g_nextRandomDouble, 0x8025E63C
.definelabel g_getRandomNumber, 0x80234248

.definelabel g_FloatEpsilon, 0x8029FE30

.definelabel g_approxEqual, 0x80233650
.definelabel g_approxEqualEps, 0x8023369C
.definelabel g_approxZero, 0x802336E4
.definelabel g_inRange, 0x8023372C
.definelabel g_cmpWithEpsilon, 0x80233768
.definelabel g_floatCompare, 0x802337B0
.definelabel g_sign, 0x802337EC

.definelabel g_WorldToGridCoords, 0x8026DCAC
.definelabel g_GetObjectGridPosition, 0x80277A28

// ============================================================================
// CAMERA
// ============================================================================

.definelabel g_CameraValues, 0x80090000

.definelabel g_CameraMinX, 0x8009003C
.definelabel g_CameraMaxX, 0x80090044
.definelabel g_CameraMinZ, 0x80090040
.definelabel g_CameraMaxZ, 0x80090048

// ============================================================================

.definelabel g_LevelModelAllocations, 0x800A7F30
.definelabel g_ModelAllocCount, 0x802AFC30
.definelabel g_ObjectAllocCount, 0x802A5460

.definelabel g_PauseFlag, 0x802A0B80
.definelabel g_soundIndexCounter, 0x802A13C0
.definelabel g_gameFrameCounter, 0x802A13C4

.definelabel g_PlayerPointers, 0x80098C18

.definelabel g_ControllerCount, 0x800270A1
.definelabel g_common_shadow_model_scale, 0x802A2DE4

.definelabel g_CurrentScreenID, 0x802A5328
.definelabel g_PointerFor802268F4, 0x802A532C
.definelabel JumpToFunction, 0x802268F4

.definelabel LoadModelInRAM, 0x802310F4
.definelabel g_ModelPointerListROM, 0x802A5324

.definelabel UpdateRenderFrame, 0x8023A104

.definelabel AdditionalUpdate, 0x80247614
.definelabel FinalizeFrameUpdate, 0x80239094

.definelabel g_PickupGem, 0x8026C93C
.definelabel g_PlayGlobalSound, 0x8026C660
.definelabel g_PlayLocalSound, 0x8026C51C
.definelabel g_StopSound, 0x8026C0A8

.definelabel g_PlayMusic, 0x80046390
.definelabel g_PlayMusicValidator, 0x802A1330

.definelabel g_InitGameVS, 0x8023CA94

.definelabel g_VSPlayerSelectionID, 0x8004A328
.definelabel g_VSPlayerSubSelectionID, 0x8004A32C
.definelabel g_VSPlayerTeamSelectionID, 0x8004A330

.definelabel g_someBombVerification, 0x802AFC70

.definelabel SomeBoolStruct1, 0x802AC760
.definelabel SomeBoolStruct2, 0x802AC820

.definelabel func_80273E2C, 0x80273E2C
.definelabel func_80273AD4, 0x80273AD4

.definelabel func_80277E1C, 0x80277E1C
.definelabel func_80251804, 0x80251804
.definelabel LoadCustomParts, 0x8023A734
.definelabel g_EquipCustomPart, 0x80228008
.definelabel g_SetBodyPartToModelPart, 0x80227FE8
.definelabel g_FreePlayerModelPart, 0x8026CBD4
.definelabel g_FreePlayerAssets, 0x80227EE0
.definelabel func_8026CBD4, 0x8026CBD4
.definelabel g_InitPlayerAssetPointers, 0x802280F4

.definelabel g_SaveGameCustomParts, 0x8008E5A8

.definelabel g_CustomPartModelID_LUT, 0x802A0BA8
.definelabel g_CustomPartModelID_LUT_Head, 0x802A0BA8
.definelabel g_CustomPartModelID_LUT_Body, 0x802A0BD4
.definelabel g_CustomPartModelID_LUT_ArmsL, 0x802A0C00
.definelabel g_CustomPartModelID_LUT_LegsL, 0x802A0C2C
.definelabel g_CustomPartModelID_LUT_ArmsR, 0x802A0C58
.definelabel g_CustomPartModelID_LUT_LegsR, 0x802A0C84


.definelabel g_EngineCreateCommand, 0x80238A10

.definelabel D_802AC89C, 0x802AC89C
.definelabel D_802AC8A0, 0x802AC8A0

.definelabel D_802AC8E8, 0x802AC8E8
.definelabel D_802ACA78, 0x802ACA78

.definelabel g_XorLevelClassFlags, 0x802313B0
.definelabel g_SetLevelClassFlags, 0x80231408
.definelabel g_ClearLevelClassFlags, 0x802313DC
.definelabel g_UpdateLevelObjectFlags, 0x802312AC
.definelabel g_SetObjectDisplayMode, 0x8022946C

.definelabel func_80229F74, 0x80229F74
.definelabel func_8022984C, 0x8022984C

.definelabel func_8022979C, 0x8022979C
.definelabel func_80231408, 0x80231408
.definelabel g_AssignModelParts, 0x802297B8

.definelabel func_802444B8, 0x802444B8

.definelabel func_8027A640, 0x8027A640
.definelabel D_80024820, 0x80024820
.definelabel D_80019F90, 0x80019F90
.definelabel func_80000870, 0x80000870
.definelabel func_80001A30, 0x80001A30
.definelabel load_from_rom_to_addr, 0x80000698

.definelabel g_AllocateModelSize, 0x80225B00
.definelabel g_AllocateModel, 0x8026CE28
.definelabel g_GetAllocationIndex, 0x8026CD24
.definelabel g_InitModel, 0x802267E0
.definelabel g_LoadModel, 0x80226604
.definelabel g_PrepareModelBuffer, 0x8022616C
.definelabel g_ProcessModelBuffer, 0x802998EC
.definelabel g_RegisterModel, 0x80292BD0
.definelabel g_FinalizeModel, 0x80226368

.definelabel g_FrameBufferSnapshot, 0x8029F5E0