#ifndef STRUCT_H_
#define STRUCT_H_

#include "../MainInclude.h"

// Controller Flags
#define CONT_PLUGGED_OUT 0x8000

// Button Flags
#define BTN_A           0x8000
#define BTN_B           0x4000
#define BTN_Z           0x2000
#define BTN_START       0x1000
#define BTN_DUP         0x0800
#define BTN_DDOWN       0x0400
#define BTN_DLEFT       0x0200
#define BTN_DRIGHT      0x0100
#define BTN_L           0x0020
#define BTN_R           0x0010
#define BTN_CUP         0x0008
#define BTN_CDOWN       0x0004
#define BTN_CLEFT       0x0002
#define BTN_CRIGHT      0x0001

typedef struct Controller
{
	uint Flags;
	ushort Button;
	char AnalogX;
	char AnalogY;
}
Controller;

typedef struct ControllerCopy
{
	ushort Button;
	char AnalogX;
	char AnalogY;
	ushort padding;
}
ControllerCopy;

typedef struct ControllerBuffer
{
	ushort Button;
	ushort padding;
	char AnalogX;
	char AnalogY;
}
ControllerBuffer;

typedef struct LevelLoader
{
	int flag;		 // Offset: 0x00
	int levelID;	 // Offset: 0x04
	int spawnID;	 // Offset: 0x08
	int levelIDCopy; // Offset: 0x0C
	int spawnIDCopy; // Offset: 0x10
	int u1;             // Offset: 0x14
	int u2;             // Offset: 0x18
	int u3;             // Offset: 0x1C
	int u4;             // Offset: 0x20
	float u5;		 // Offset: 0x24
	int u6;             // Offset: 0x28
	int u7;             // Offset: 0x2C
	int u8;             // Offset: 0x30
	int u9;             // Offset: 0x34
	int u10;		 // Offset: 0x38
	int u11;		 // Offset: 0x3C
	int u12;		 // Offset: 0x40
	int u13;		 // Offset: 0x44
	int u14;		 // Offset: 0x48
	int u15;		 // Offset: 0x4C
}
LevelLoader;

typedef struct ModelData
{
	int modelFlags;            	  // Offset: 0x00
	int Unk04;            		  // Offset: 0x04
	int Unk08;            		  // Offset: 0x08
	int visibilityAnimationFlags; // Offset: 0x0C
	float posX;            		  // Offset: 0x10
	float posY;            		  // Offset: 0x14
	float posZ;            		  // Offset: 0x18
	float rotX;            		  // Offset: 0x1C
	float rotY;            		  // Offset: 0x20
	float rotZ;            		  // Offset: 0x22
	float scaleX;            	  // Offset: 0x24
	float scaleY;            	  // Offset: 0x28
	float scaleZ;            	  // Offset: 0x2C
	int Unk30;            		  // Offset: 0x30
	int Unk34;            		  // Offset: 0x34
	int Unk38;            		  // Offset: 0x38
	int *modelPtr;            	  // Offset: 0x3C
	int Unk40;            		  // Offset: 0x40
	int Unk44;            		  // Offset: 0x44
	int Unk48;            		  // Offset: 0x48
	int Unk4C;            		  // Offset: 0x4C
}
ModelData;

typedef struct ModelEntry
{
	int ID;            		 // Offset: 0x00
	int Unk1;            	 // Offset: 0x04
	int Unk2;            	 // Offset: 0x08
	int Unk3;            	 // Offset: 0x0C
	int Unk4;            	 // Offset: 0x10
	int Unk5;            	 // Offset: 0x14
	int Unk6;            	 // Offset: 0x18
	int Unk7;            	 // Offset: 0x1C
	int Unk8;            	 // Offset: 0x20
	int Unk9;            	 // Offset: 0x24
	int Unk10;            	 // Offset: 0x28
	int Unk11;            	 // Offset: 0x2C
	int Unk12;            	 // Offset: 0x30
	float Unk13;             // Offset: 0x34
	float Unk14;             // Offset: 0x38
	int Unk15;            	 // Offset: 0x3C
	ModelData *ModelDataPtr; // Offset: 0x40
	int Unk17;            	 // Offset: 0x44
	int Unk18;            	 // Offset: 0x48
	int Unk19;            	 // Offset: 0x4C
	int Unk20;            	 // Offset: 0x50
	int Unk21;            	 // Offset: 0x54
	const float X;             // Offset: 0x58
	const float Y;             // Offset: 0x5C
	const float Z;             // Offset: 0x60
	int Unk25;            	 // Offset: 0x64
	int Unk26;            	 // Offset: 0x68
	float VelocityY;		 // Offset: 0x6C
	float Unk28;             // Offset: 0x70
	float Unk29;             // Offset: 0x74
	int *Unk30;            	 // Offset: 0x78
	int *Unk31;            	 // Offset: 0x7C
}
ModelEntry;

typedef struct Object Object;

typedef struct Object
{
	int num;
	int num2;
	int u1;
	int param;
	float position[3];
	float angle[3];
	float scale[3];
	short visible;
	short u7;
	int u8;
	long modelData_pointer;
	long animation_pointer1;
	long animation_pointer2;
	long animation_pointer3;
	long animation_pointer4;
}
Object;

#define OBJECT_FLAG_VISIBLE 0x0001

typedef enum BodyPartType
{
    CUSTOM_PART_BODY = 0,
    CUSTOM_PART_BELT,
    CUSTOM_PART_ARM_L,
    CUSTOM_PART_HAND_L,
    CUSTOM_PART_ARM_R,
    CUSTOM_PART_HAND_R,
    CUSTOM_PART_FACE,
    CUSTOM_PART_HEAD,
    CUSTOM_PART_HEAD_BALL,
    CUSTOM_PART_LEG_L,
    CUSTOM_PART_FOOT_L,
    CUSTOM_PART_LEG_R,
    CUSTOM_PART_FOOT_R,
}
BodyPartType;

typedef enum CustomPartSet
{
    CUSTOM_PART_SET_NONE = 0,
    CUSTOM_PART_SET_KNIGHT,
    CUSTOM_PART_SET_DRAGON,
    CUSTOM_PART_SET_IRON,
    CUSTOM_PART_SET_CAT,
    CUSTOM_PART_SET_GIRL,
	CUSTOM_PART_SET_COOL,
	CUSTOM_PART_SET_CHICKEN,
	CUSTOM_PART_SET_SAMURAI,
	CUSTOM_PART_SET_CLOWN,
	CUSTOM_PART_SET_GOLD
}
CustomPartSet;

typedef struct CustomParts
{
	int customHeadID;
	int customBodyID;
	int customArmsID;
	int customLegsID;
}
CustomParts;

typedef struct LevelClass LevelClass;

typedef struct LevelClass
{
	int num;
	int type;
	int u1;
	int u2;
	int flag;
	int u4;
	int u5;
	int u6;
	int u7;
	int u8;
	int u9;
	int u10;
	int u11;
	float radius;
	float unk_float2;
	int u12;
	Object *ObjectPointer; // Pointer to the Object this LevelClass is spawning
	LevelClass *CollisionPointer; // Pointer to the collision LevelClass
	int u13;
	float unk_vector[3];
	int u14[6];
	float unk_float3;
	float unk_float4;
	long unk_pointer2;
	long unk_pointer3;
}
LevelClass;

typedef struct GlobalPlayerState
{
	int control_flag;	//2 when any player is seeing stars
	int player_counter;	//Current loop_count for which player is being processed
	int swap_curse_flag; // 0x1 = swap_total_timer run, 0x11 = swap_total_timer + swap_timer run
	int swap_total_timer; //When reaching 0, stops the swap curse timers
	int swap_timer; //When reaching 0, gets set to 0x12C and a players swap their positions
	int u3;
	int walk_speed_store[4];	//From PlayerData->animation_type, used to store the walk speed when coming to a stop
	int u7;
	int u8;
	int cutscene_timer;
	int u9;
	int u10;
	int u11;
	int u12;	
	float movement_speed; // Speed of the cutscene movement
	float destination_position[2]; // XY-Position to move towards in cutscene
	float stick_rotation[4]; // Updates when freeing yourself from seeing stars
	int u17;
	float unknown_float1;
	int u19;
	int u20;
	int u21;
	int u22;
	int u23;
	int u24;
	int u25;
	int u26;
	int u27;
	int u28;
	int u29;
	int u30;
	float animation_frame_store[4]; //??? Stores the animation frame when coming to a stop ???
	int u34;
	float unknown_float2;
}
GlobalPlayerState;


// Player Flag
#define IS_ON_SLOPE             0x00000010
#define DISALLOW_USER_INPUT     0x00000020
#define THROWING_OBJECT         0x00000040
#define PICKING_UP_OBJECT       0x00000080
#define KICKING_BOMB            0x00000100
#define HAS_BOMB_BELOW          0x00000200
#define CUTSCENE_MOVEMENT       0x00000400
#define IS_KNOCKED_OUT          0x00001000
#define HAS_OBJECT_IN_HAND      0x00008000
#define IS_INTANGIBLE           0x00010000
#define IS_HURT_SPINNING        0x00020000
#define CAN_ONLY_TURN           0x00400000
#define IS_IN_CUTSCENE          0x02000000

// Bomb Types
#define BOMB_TYPE_NORMAL        0x0000
#define BOMB_TYPE_RED           0x0001
#define BOMB_TYPE_REMOTE        0x0002
#define BOMB_TYPE_NORMAL_RED    0x0004
#define BOMB_TYPE_FULL_POWER    0x0100
#define BOMB_TYPE_DEFAULT       0x0200
#define BOMB_TYPE_HUGE          0x0800

// Virus Types
#define VIRUS_TYPE_NONE         0x00
#define VIRUS_TYPE_FAST         0x01
#define VIRUS_TYPE_STUCK        0x02
#define VIRUS_TYPE_SLOW         0x04
#define VIRUS_TYPE_NO_BOMBS     0x08
#define VIRUS_TYPE_INVERTED     0x20
#define VIRUS_TYPE_ON_FIRE      0x80

// Player Move Speeds
#define PLAYER_MOVE_SPEED_WALK  21.0f
#define PLAYER_MOVE_SPEED_RUN   60.0f

typedef struct Player
{
	float spawnLocation[3];
	float directionAngle;
	int flag;
	int heartCount;
	short u1;
	short bombType;
	int bombCount;
	int u2;
	int controlType;              // 0 = None, 1 = Player, 2 = AI, 3 = Dead (No Input)
	LevelClass *PlayerLevelClass; // Pointer to the LevelClass this Player is controlling
	int u6;
	LevelClass *OtherClass;
	int u8;
	int u9;
	int u10;
	int u11;
	int animationType;
	int collisionEnabled;
	int u13;
	int u14;
	int u15;
	float directionAngle2[4];
	short u12;
	char timerA_Enabled; // virusType has to be set for this to work
	char virusType;
	float virusFloat1;
	float virusFloat2;
	int timer2;
	int virusTimer;
	int u16[5];
	int timerA;
	short unkType;
	short unkType1;
	int unkType2;
	int u17[5];
	LevelClass *ComputationLevelClass;
	int u20[3];
	float unknownFloat1;
	int u21;
}
Player;

typedef struct Game
{
	int state;
	int u1[3];
	int flag;
	int life_count;
	int continue_count;
	int gem_count;
	int u4;
	int u5;
	int time_target;
	int u7;
	int time_elapsed;
	float delta_time;
	int seconds_elapsed;
	int u8[6];
}
Game;

typedef struct VSGame
{
	int menuSelection; //0 Single Battle, 1 Team Battle, 2 Options
	int controlType[4]; //0 Off, 1 MAN, 2 COM, 3 CUSTOM, 4 NOTHING
	int levelCOM[4]; //0-2
	int battleCount;
	int timeLimit; //6 Infinite
	int minutesLeft;
	int secondsLeft;
	int nextSecondFrameTimer;
	int isSuddenDeathEnabled;
	int isGhostEnabled;
	int isCustomToggled[4];
	CustomParts customParts[4];
	int teamAssignment[4]; //0 Blue Team, 1 Red Team
	int selectedLevel;
	int playerWinScore[4];
	int playerState[4]; //0 Alive, 2 Dead, 8 CPU
	char customVerifyNumbersP1[9];
	char customVerifyNumbersP2[9];
	char customVerifyNumbersP3[9];
	char customVerifyNumbersP4[9];
	int customPartSetID[4];
	// more possibly here
}
VSGame;

typedef struct PlayerPointer
{
	int flag;
	Object *playerObject;
	long playermodelSetup1;
	long playermodelSetup2;
}
PlayerPointer;

typedef struct Bomb
{
	short num;
	short flag;
	int u1;
	int u2;
	int u3;
	int u4;
	long next_bomb_ptr;
	long unk_ptr1;
	long unk_ptr2;
	long unk_ptr3;
	int u5;
	int u6;
	int u7;
	long unk_ptr4;
	long unk_ptr5;
	int u8;
	int u9;
	float position[3];
	int u10;
	int u11;
	int u12;
	int u13;
	int u14;
	short inflate_timer;
	short u15;
	int unk_flag1;
	short explode_timer;
	short unk_flag2;
	int u16;
	int u17;
	int unk_flag3;
	float unk_float2[4];
}
Bomb;

typedef struct PickupState
{
	int flag;
	LevelClass *PickupLevelClass;
	short pickupTimer;
	short u1;
	int u2;
	int u3;
	float offsetTargetX;
	float offsetTargetDist;
	float offsetTargetZ;
	float offsetTargetY;
	float offsetTargetSpeed;
	int u4;
	int u5;
}
PickupState;

typedef struct ModelAlloc
{
	int modelID;
	long modelData;
	int u1;
	int count;
}
ModelAlloc;

#define CONTAINER_BILLBOARD 0x2000

typedef struct ContainerObjectAlloc
{
	short modelID;
	short collisionType;
	short u1;
	short u2;
	int flag;
}
ContainerObjectAlloc;

typedef struct EnemyAlloc
{
	short behaviour;
	short modelID;
}
EnemyAlloc;

typedef struct SFXChannel
{
	float location[3]; // Location of the sound
	int isDirectional; // If true, the sound is directional (Unconfirmed)
	int soundID; // -1 = no sound allocated
}
SFXChannel;

typedef struct SFXStruct
{
    long pointer;
    short flag1;
    short flag2;
    short flag3;
    short controlFlag; //0x1000 Play, 0x2000 Stop
    short soundID;
    short playFlag;
    int timer;
    short flag4;
    short flag5;
    int unknown1;
    short flag6;
    short flag7;
}
SFXStruct;

typedef struct CameraValues
{
	float aheadOffset;
	float aheadChangeDelay;
	float u1[4];
	float downAngle;
	float downAngleMapEdge;
	float u2;
	float u3;
	float map;
	float mapEdges;
}
CameraValues;

// CPU Attack Types
#define ATTACK_TYPE_BOMBERMAN   -1
#define ATTACK_TYPE_SIRIUS_1    0
#define ATTACK_TYPE_ARTEMIS     1
#define ATTACK_TYPE_ORION       2
#define ATTACK_TYPE_REGULUS     3
#define ATTACK_TYPE_UNKNOWN     4
#define ATTACK_TYPE_STOP        5
#define ATTACK_TYPE_ALTAIR      6
#define ATTACK_TYPE_SIRIUS_2    7
#define ATTACK_TYPE_SIRIUS_3    8

typedef struct ComputerPlayerMovement
{
	float moveDirection;
	float f1;
	float moveSpeed;
	float f2;
}
ComputerPlayerMovement;

typedef struct ComputerPlayerController
{
	int behaviorFlag;
	int u1;
	int u2;
	int u3;
	int u4;
	int attackType;
	LevelClass *pointer1;
	LevelClass *pointer2;
	float f1;
	float f2;
	float f3;
	float f4;
	float f5;
	float f6;
	int u5;
	int u6;
	int u7;
	float f7;
	float f8;
	float f9;
	int u8;
	int u9;
	int u10;
	float f10;
	float f11;
	float f12;
	int u11;
	int u12;
	int u13;
	int u14;
	int u15;
	float f13;
	float f14;
	int u16;
	int u17;
	int u18;
	int u19;
	int u20;
	long unknown_pointer;
	ComputerPlayerMovement *moveDirection;
	int uValues[32];
	int behaviorTimer;
	int u21;
}
ComputerPlayerController;

typedef struct BoolStruct
{
	int someBool1;
	int someBool2;
	int someBool3;
	int someBool4;
}
BoolStruct;

#endif