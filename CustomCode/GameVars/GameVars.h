#include "../MainInclude.h"

extern Gfx *GFXgraphPtr;

extern void g_InitPlayers(); //0x80245CDC
extern void g_SpawnPlayer(int playerID); //0x802459BC
extern void g_PlayerMovement(int num); //0x8024E088
extern void g_EndLevel(); //0x8023E8AC

extern VSGame *g_GetVSGameState(); //0x8023A834
extern Game *g_GetGameState(); //0x8023A840

extern LevelLoader g_LevelLoader; //0x802AC5D0
extern LevelClass g_LevelClasses[]; //0x800A3F00
extern Object g_HUD_Object; //0x800A0DA0
extern Object g_GameObjects[]; //0x800A0DF0
extern Player g_Players[8]; //0x800AEDF0
extern Controller g_ControllerInputs[4]; //0x80027060
extern ControllerCopy g_ControllerInputsCopy[4]; //0x802AC410
extern ControllerBuffer g_ControllerInputsBuffer[4][16]; //0x802AC428
extern uint g_ControllerBufferIndex[4]; //0x802AC5A8
extern Game g_GameState; //0x802AC610
extern VSGame g_VSGameState; //0x802AC660
extern Bomb g_Bombs[]; //0x8008F4C0
extern EnemyAlloc g_EnemySlots[6]; //0x800BA8E8
extern ContainerObjectAlloc g_ContainerObjectSlots[4]; //0x802B0190
extern ComputerPlayerController g_ComputerPlayerController[4]; //0x800BCFE8
extern ComputerPlayerMovement g_ComputerPlayerMovement[4]; //0x802ACF08

extern PickupState g_PickupState[]; //0x802AFCF0

extern GlobalPlayerState g_GlobalPlayerState; //0x802AC9E0
extern SFXChannel g_SoundChannels[8]; //0x800BD778
extern SFXStruct g_SoundFlags[8]; //0x801C8B50

extern int g_enemies_defeated_count; //0x800BC520
extern uint g_playerFlagBitField; //0x802AC9E8
extern int g_PauseFlag; //0x802A0B80
extern int g_soundIndexCounter; //0x802A13C0
extern int g_gameFrameCounter; //0x802A13C4

extern PlayerPointer g_PlayerPointers[4]; //0x80098C18


extern char g_ControllerCount; //0x800270A1
extern float g_common_shadow_model_scale; //0x802A2DE4

extern int g_CurrentScreenID; //0x802A5328
extern int g_PointerFor802268F4; //0x802A532C
extern void JumpToFunction(); //0x802268F4

extern ModelEntry LoadModelInRAM (int ModelID, int Unk, float X, float Y, float Z);

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

extern CameraValues g_CameraValues; //0x80090000

extern void g_InitGameVS(); //0x8023CA94

extern int g_VSPlayerSelectionID; //0x8004A328
extern int g_VSPlayerSubSelectionID; //0x8004A32C
extern int g_VSPlayerTeamSelectionID; //0x8004A330

extern int g_someBombVerification; //0x802AFC70

extern BoolStruct SomeBoolStruct1; //0x802AC760
extern BoolStruct SomeBoolStruct2; //0x802AC820

extern void func_80273E2C(short playerID); //0x80273E2C
extern int func_8027361C(short A16, float B32, float C32, float D32, int AB32); //0x8027361C
extern int func_80273AD4(short A16, int A32, int B32, int C32); //0x80273AD4

extern void func_80277E1C(); //0x80277E1C
extern void func_80251804(int ID); //0x80251804
extern void LoadCustomParts(int playerID, int partTypeID, int partSetID); //0x8023A734
extern void g_EquipCustomPart(int playerID, int partSlot, int modelID); //0x80228008

extern int g_InitPlayerAssetPointers(Object *playerObject, int flag); //0x802280F4

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

extern int g_AllocateModel(int modelID); //0x8026CE28
extern int g_GetModelIndex(int modelID1, int modelID2); //0x8026CD24
extern void g_InitModel(int param); //0x802267E0
extern int g_LoadModel(int modelID, int flag); //0x80226604
extern void g_PrepareModelBuffer(int* dst, int size, int flag, int modelHandle); //0x8022616C
extern int g_ProcessModelBuffer(int buffer); //0x802998EC
extern void g_RegisterModel(int modelHandle, int processed, int buffer); //0x80292BD0
extern void g_FinalizeModel(int modelHandle); //0x80226368