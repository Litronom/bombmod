#include "../MainInclude.h"

extern void PlayerMovement(int num); //0x8024E088
extern void EndLevel(); //0x8023E8AC

extern LevelLoader g_LevelLoader; //0x802AC5D0
extern LevelClass g_LevelClasses[]; //0x800A3F00
extern Object g_GameObjects[]; //0x800A0DF0
extern Player g_Players[8]; //0x800AEDF0
extern Controller g_ControllerInputs[4]; //0x80027060
extern ControllerCopy g_ControllerInputsCopy[4]; //0x802AC410
extern ControllerBuffer g_ControllerInputsBuffer[4][16]; //0x802AC428
extern uint g_ControllerBufferIndex[4]; //0x802AC5A8
extern Game g_GameState; //0x802AC610
extern Bomb g_Bombs[]; //0x8008F4C0
extern EnemyAlloc g_EnemySlots[6]; //0x800BA8E8
extern ContainerObjectAlloc g_ContainerObjectSlots[4]; //0x802B0190

extern GlobalPlayerState g_GlobalPlayerState; //0x802AC9E0
extern SFXChannel g_SoundChannels[8]; //0x800BD778

extern int g_enemies_defeated_count; //0x800BC520
extern uint g_playerFlagBitField; //0x802AC9E8
extern int g_PauseFlag; //0x802A0B80

extern char g_ControllerCount; //0x800270A1
extern float g_common_shadow_model_scale; //0x802A2DE4

extern int g_CurrentScreenID; //0x802A5328
extern int g_PointerFor802268F4; //0x802A532C
extern void JumpToFunction(); //0x802268F4

extern ModelEntry LoadModelInRAM (int ModelID, int Unk, float X, float Y, float Z);

extern void UpdateRenderFrame(); //0x802259F4

extern void AdditionalUpdate(); //0x80247614
extern void FinalizeFrameUpdate(); //0x80239094

extern void SpawnPlayerBomb(int bombType, int float_locX, int float_locY, int float_locZ, int playerID); //0x80273F30
extern void PickupGem(); //0x802794FC
//extern void PlayGlobalSound(int soundID, LevelClass *class); //0x8026C660
extern void PlayGlobalSound(int soundID); //0x8026C660
extern void PlayLocalSound(int soundID, float locX, float locY, float locZ); //0x8026C51C


extern int D_80019F90; //0x80019F90
extern void D_80024820(); //0x80024820
extern void PAYLOAD_RAM(); //0x80024820
extern void func_80000870(); //0x80000870
extern void func_80001A30(unsigned int *table, unsigned int* func); //0x80001A30
extern void load_from_rom_to_addr(void* arg0, signed int arg1, unsigned int arg2); //0x80000698