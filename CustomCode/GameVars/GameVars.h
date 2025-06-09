#include <stdbool.h>
#include <stdio.h>
#include "Struct.h"
#include "DefVars.h"

extern void PlayerMovement(int num); //0x8024E088
extern void EndLevel(); //0x8023E8AC
extern LevelLoader LevelLoaderData; //0x802AC5D0
extern LevelClass LevelClassData[]; //0x800A3F00
extern Object ObjectData[]; //0x800A0DF0
extern Player PlayerData[4]; //0x800AEDF0
extern Controller ControllerData[4]; //0x80027060
extern Game GameState; //0x802AC620
extern Bomb BombData[]; //0x8008F4C0

extern int enemies_defeated_count; //0x800BC520

extern float common_shadow_model_scale; //0x802A2DE4

extern ModelEntry LoadModelInRAM (int ModelID, int Unk, float X, float Y, float Z);

extern void UpdateRenderFrame(); //0x802259F4

extern int D_80019F90; //0x80019F90
extern void D_80024820(); //0x80024820
extern void PAYLOAD_RAM(); //0x80024820
extern void func_80000870(); //0x80000870
extern void func_80001A30(unsigned int *table, unsigned int* func); //0x80001A30
extern void load_from_rom_to_addr(void* arg0, signed int arg1, unsigned int arg2); //0x80000698