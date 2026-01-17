
extern Bomb* SpawnPlayerBomb_Hook(short bombType, int locX, int locY, int locZ, short playerID);
extern void SpawnPlayer_Hook(int playerID);
extern void* AllocateModel_Hook(int modelID);
extern void EquipCustomModel(int playerID, int partSlot, int customModelSubID);
extern void EquipCustomPart(int playerID, int partSlot, int modelID);
extern int InitPlayerAssetPointers(Object *playerObject, int count);