.n64
.open "Rom\baserom.z64", "Rom\BM64_MOD.z64", 0

.org 0x0
.word 0x80371240

.definelabel ROM_RAM_OFFSET,    0xC00

.definelabel PAYLOAD_ROM,       0x007B75B0
.definelabel PAYLOAD_RAM,       0x802D0000
.definelabel PRE_PAYLOAD_RAM,   0x803E0000
.definelabel DMA_FUNC,          0x80000698
.definelabel RAM_END,           org(EndRAMData)
.definelabel DMA_MAX_LENGTH,    org(EndRAMData) - org(StartRAMData)
.definelabel CUSTOM_DMA,        0x4150
.definelabel CUSTOM_DMA_BRANCH, CUSTOM_DMA+0x1C


.include "CustomCode/GameVars/GameVars.asm"



.org 0x8EF30
JAL SpawnPlayerBomb_Hook

.org 0x8F7BC
JAL SpawnPlayerBomb_Hook

.org 0x60554
JAL SpawnPlayer_Hook

.org 0x78500
JAL SpawnPlayer_Hook

.org 0x593A0
JAL SpawnPlayer_Hook

.org 0x4B4E8
JAL AllocateModel_Hook

.org 0x87D24
JAL AllocateModel_Hook

.org 0x4400C
JAL AllocateModel_Hook

.org 0x42808
J EquipCustomPart_Hook
NOP

.org 0x436B8
JAL RenderMapObjects_Hook

.org 0x481E0
JAL RenderDynamicObjects_Hook

.org 0x47CAC
JAL RenderMap_Hook




.org 0xA1808
J EnemyAllocate
NOP
NOP
NOP
NOP

.org 0x9F818
JAL EnemyDamagedCheck_Hook
or $s2, $s7, $zero

//.org 0x9F510
//JAL OnEnemyHealthChanged_Hook
//or $a0, $s2, $zero   ; Pass enemyObject pointer (delay slot)

//.org 0xA0248
//JAL OnEnemySpawned_Hook

.org 0x99368
JAL ContainerObjAllocate
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP


.org 0x401F4
JAL UpdateRenderFrame_Hook

.org 0x6A858
JAL PlayerMovement_Hook

.org 0x2374
JAL CUSTOM_DMA-ROM_RAM_OFFSET

.org CUSTOM_DMA


ADDIU SP, SP, -0x18 //allocate stack space
SW RA, 0x0014 (SP) //push ra to the stack
JAL	0x80000450
NOP
LUI A2, 0x007B //A2 = PAYLOAD_ROM (source)
ADDIU A2, A2, 0x75B0 //A2 = PAYLOAD_ROM (source) + offset
LUI A1, hi(DMA_MAX_LENGTH)  //A1 = DMA_MAX_LENGTH (size)
ADDIU A1, A1, lo(DMA_MAX_LENGTH) //A1 = DMA_MAX_LENGTH (size)
LUI A0, 0x802D //A0 = PAYLOAD_RAM (dest)
JAL	DMA_FUNC
ADDIU A0, A0, 0x0000 //A0 = PAYLOAD_RAM (dest) + offset
LW RA, 0x0014 (SP) //pop ra from the stack
JR RA
ADDIU SP, SP, 0x18 //deallocate stack space



.headersize PAYLOAD_RAM - PAYLOAD_ROM
.org PAYLOAD_RAM



StartRAMData:

.include "CustomCode/BUILD_FILES.asm"
//.include "Assets/BUILD_DISPLAYLISTS.asm"

EndRAMData:




.headersize 0
.align 0x10


.close