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
	float posX;            		  // Offset: 0x10 - Position X
	float posY;            		  // Offset: 0x14 - Position Y
	float posZ;            		  // Offset: 0x18 - Position Z
	float rotX;            		  // Offset: 0x1C - Rotation X
	float rotY;            		  // Offset: 0x20 - Rotation Y
	float rotZ;            		  // Offset: 0x24 - Rotation Z
	float rotOrAnimX;              // Offset: 0x28 - Rotation/animation value X
	float rotOrAnimY;              // Offset: 0x2C - Rotation/animation value Y
	float rotOrAnimZ;              // Offset: 0x30 - Rotation/animation value Z
	float effectValue;            // Offset: 0x34 - Effect parameter value (used to store 50.0, etc.)
	int Unk38;            		  // Offset: 0x38
	int *modelPtr;            	  // Offset: 0x3C
	void* Unk40;            	  // Offset: 0x40 - Secondary object/data pointer (Particle effects store g_GetEffectAngle result at ->0x20)
	int Unk44;            		  // Offset: 0x44
	int Unk48;            		  // Offset: 0x48
	int Unk4C;            		  // Offset: 0x4C
	int Unk50;            		  // Offset: 0x50
	int Unk54;            		  // Offset: 0x54
	int Unk58;            		  // Offset: 0x58
	float posYCopy;               // Offset: 0x5C - Y position copy (used in gravity effects)
	float velocityX;              // Offset: 0x60 - Velocity X (checked for collision detection)
	float velocityY;              // Offset: 0x64 - Velocity Y
	float velocityXZ;             // Offset: 0x68 - Velocity X or Z component (checked for collision)
	float velocityZ;              // Offset: 0x6C - Velocity Z (checked for collision detection)
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
	const float X;           // Offset: 0x58
	const float Y;           // Offset: 0x5C
	const float Z;           // Offset: 0x60
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
	int num;                      // 0x00
	int num2;                     // 0x04
	int u1;                       // 0x08
	int param;                    // 0x0C
	float position[3];            // 0x10-0x18
	float angle[3];               // 0x1C-0x24
	float scale[3];               // 0x28-0x30
	short visible;                // 0x34
	short u7;                     // 0x36
	int modelDisplayListID;       // 0x38 - Which DL of the model to display
	long modelData_pointer;       // 0x3C - Pointer to ModelData struct
	long animation_pointer1;      // 0x40
	long animation_pointer2;      // 0x44
	long animation_pointer3;      // 0x48
	long animation_pointer4;      // 0x4C
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

typedef enum RivalBodyPartType
{
    RIVAL_PART_BODY = 0,
    RIVAL_PART_FACE,
	RIVAL_PART_HEAD,
	RIVAL_PART_HEAD_BALL,
	RIVAL_PART_SHOULDER_L,
    RIVAL_PART_ARM_L,
    RIVAL_PART_HAND_L,
	RIVAL_PART_SHOULDER_RL,
    RIVAL_PART_ARM_R,
    RIVAL_PART_HAND_R,    
    RIVAL_PART_LEG_L,
    RIVAL_PART_FOOT_L,
    RIVAL_PART_LEG_R,
    RIVAL_PART_FOOT_R,
}
RivalBodyPartType;

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
	int num;						// 0x00
	int type;						// 0x04
	int u1;							// 0x08
	int u2;							// 0x0C
	int flag;						// 0x10
	int u4;							// 0x14
	int u5;							// 0x18
	int u6;							// 0x1C
	int u7;							// 0x20
	int u8;							// 0x24
	int objectID;					// 0x28 - Check ObjectVars.h for a list of object IDs
	int u10;						// 0x2C
	int u11;						// 0x30
	float radius;					// 0x34
	float unk_float;				// 0x38
	int u12;						// 0x3C
	Object *ObjectPointer;			// 0x40 - Pointer to the Object this LevelClass is spawning
	LevelClass *CollisionPointer; 	// 0x44 - Pointer to the collision LevelClass
	int u13;						// 0x48
	float unk_vector[3];			// 0x4C - 0x54
	int u14[4];						// 0x58 - 0x64
	float unk_float1;				// 0x68
	float unk_float2;				// 0x6C
	float unk_float3;				// 0x70
	float unk_float4;				// 0x74
	long unk_pointer2;				// 0x78
	long unk_pointer3;				// 0x7C
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
	int bombExplosionLevel;
	int controlType;              // 0 = None, 1 = Player, 2 = AI, 3 = Dead (No Input)
	LevelClass *PlayerLevelClass; // Pointer to the LevelClass this Player is controlling
	LevelClass *HeldLevelClass;   // Pointer to the LevelClass of the held object
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
	int world;
	int stage;
	int u1;
	int difficulty; //0 Easy, 1 Hard
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
	char customVerifyNumbers[4][9];
	int customPartSetID[4];
	int loadedPlayerCount;
	// more possibly here
}
VSGame;

typedef struct PlayerPointer
{
	int count;
	Object *playerObject;
	void* attachmentModelPtr;
	int* modelPart;
}
PlayerPointer;

typedef struct Bomb
{
	short num;                     //0x00
	short flag;                    //0x02
	int u1;                        //0x04
	int u2;                        //0x08
	int u3;                        //0x0C
	int u4;                        //0x10
	long next_bomb_ptr;            //0x14
	long unk_ptr1;                 //0x18
	LevelClass *BombLvlClass;      //0x1C
	Object *BombObj;               //0x20
	int u5;                        //0x24
	int u6;                        //0x28
	int u7;                        //0x2C
	long unk_ptr4;                 //0x30
	long unk_ptr5;                 //0x34
	int u8;                        //0x38
	int u9;                        //0x3C
	float position[3];             //0x40-0x48
	int u10;                       //0x4C
	int u11;                       //0x50
	int u12;                       //0x54
	int u13;                       //0x58
	int u14;                       //0x5C
	short inflate_timer;           //0x60
	short u15;                     //0x62
	int state_flag;                //0x64
	short explode_timer;           //0x68
	short unk_flag2;               //0x6A
	int u16;                       //0x6C
	int u17;                       //0x70
	int unk_flag3;                 //0x74
	float unk_float2[4];           //0x78-0x84
}
Bomb;

// HeldObject flag bits (used to select throw handlers)
#define HELD_FLAG_PLAYER 0x1   // Hold another player/rival
#define HELD_FLAG_BOMB   0x2   // Hold a bomb
#define HELD_FLAG_ENTITY 0x4   // Hold a regular enemy
#define HELD_FLAG_ITEM   0x8   // Hold an item

typedef struct HeldObject
{
	int num;                      // 0x00
	int u0;                       // 0x04
	int flag;                     // 0x08
	LevelClass *heldLvlClass;     // 0x0C
	short pickUpTimer;            // 0x10
	int u1;                       // 0x14
	int u2;                       // 0x18
	float offsetTargetX;          // 0x1C
	float offsetTargetDist;       // 0x20
	float offsetTargetZ;          // 0x24
	float offsetTargetY;          // 0x28
	float offsetTargetSpeed;      // 0x2C
}
HeldObject;


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
	void* modelData;
	int u1;
	int count;
}
ModelAlloc;

#define CONTAINER_BILLBOARD 0x2000
#define CONTAINER_DRAW      0x0004

typedef struct ContainerObjectAlloc
{
	short modelID;
	short collisionType;
	short u1;
	short particleEffectID;
	int flag;
}
ContainerObjectAlloc;

typedef struct ContainerObject ContainerObject;

typedef struct ContainerObject
{
	short num;                           // 0x00
	short flag;                          // 0x02 - Gets set to 1 when destroyed
	ContainerObject *nextContainer;      // 0x04 - Pointer to next container for collision loop
	ContainerObject *containerDataStart; // 0x08 - Pointer to start of container data array
	Object *containerObject;             // 0x0C
	Object *containerObject2;            // 0x10 - Can have two objects
	short u2;                            // 0x14
	short u3;                            // 0x16
	short u4;                            // 0x18
	short containerType;                 // 0x1A - 0x20 for the first, 0x40 for the second or 0x60 for third allocated container type
	float renderPosition[3];             // 0x1C-0x24 - Position used for rendering, not collision
}
ContainerObject;

// Enemy Attack Check Behaviors (0x51 - attackBehavior field)
// Determines when/if attack should trigger
#define ENEMY_ATTACK_CHECK_DISABLED         0x00  // Never attack
#define ENEMY_ATTACK_CHECK_TIMER            0x01  // Attack based on timer
#define ENEMY_ATTACK_CHECK_SIGHT            0x02  // Attack when player is in line of sight
#define ENEMY_ATTACK_CHECK_PROXIMITY_LARGE  0x03  // Attack when player within large radius
#define ENEMY_ATTACK_CHECK_PROXIMITY_SMALL  0x04  // Attack when player within small radius

// Enemy Attack Param Behaviors (0x50 - attackParam field)
// Determines how the attack executes (indexed into prep/execute tables)
#define ENEMY_ATTACK_DISABLED               0x00  // No attack
#define ENEMY_ATTACK_THROW                  0x01  // Throw projectile at player
#define ENEMY_ATTACK_SPAWN                  0x02  // Spawn clones or minions
#define ENEMY_ATTACK_NO_TARGET              0x03  // Attack without targeting player
#define ENEMY_ATTACK_CHASE                  0x04  // Chase player aggressively
#define ENEMY_ATTACK_SQUISHY                0x05  // Squash/stretch animation attack
#define ENEMY_ATTACK_CHASE_2                0x06  // Alternative chase behavior
#define ENEMY_ATTACK_HOMING		            0x07  // Homing dive attack
#define ENEMY_ATTACK_CHASE_FAST             0x08  // Fast chase behavior
#define ENEMY_ATTACK_NO_TARGET_INFINITE     0x09  // Continuous untargeted attack 

typedef struct EnemyAlloc
{
	short behaviour;
	short modelID;
}
EnemyAlloc;

typedef struct EnemyHeader EnemyHeader;

typedef struct EnemyRuntimeData
{
    int slotID;          		 // 0x00 - Slot ID assigned during allocation
    int activeFlag;      		 // 0x04 - State (0 = empty slot/level init, 1 = active, 2 = cleanup/level exit)
    int objectHandle;    		 // 0x08 - Object handle (returned from spawn function)
    int state;           		 // 0x0C - Movement state (0 = frozen, 1 = moving)
    EnemyHeader* enemyHeader;	 // 0x10 - Pointer to full enemy instance
}
EnemyRuntimeData;

typedef struct EnemyObject
{
    int u0;                      // 0x00
    int u1;                      // 0x04
    int u2;                      // 0x08
    int u3;                      // 0x0C
	int flags;                   // 0x10 - Stun check 0x40
    int u4[3];                   // 0x14-0x1F
    int u8;                      // 0x20
    int u9;                      // 0x24
    int modelID;                 // 0x28 - Enemy model ID
    int u11;                     // 0x2C
    int animationState;          // 0x30 - Animation state value
    float radius;                // 0x34
    float f2;                    // 0x38
    int u15;                     // 0x3C
    Object* objectPointer;       // 0x40
    int u17;                     // 0x44
    int u18;                     // 0x48
    int u19[3];                  // 0x4C-0x57
    float posX;                  // 0x58
    float posY;                  // 0x5C
    float posZ;                  // 0x60
    int u23;                     // 0x64
    float movementFloat[3];      // 0x68-0x70
    float f4;                    // 0x74
    LevelClass* levelClassPtr1;  // 0x78
    LevelClass* levelClassPtr2;  // 0x7C
}
EnemyObject;

typedef struct Enemy
{
    EnemyObject* enemyObject;    // 0x14 - Pointer to EnemyObject (0x80 bytes) [func param base]
    int u6;                      // 0x18
    int flags1;                  // 0x1C - Bit flags (bit 0 cleared during attack setup)
    int flags2;                  // 0x20 - Bit flags (bits 0 and 3 checked for attack conditions)
    int gridnumSN;               // 0x24 - North-South grid number
    int u10;                     // 0x28
    int gridnumEW;               // 0x2C - East-West grid number
    short movementDir;           // 0x30 - 0x0000 West, 0x4000 North, 0x8000 East, 0xC000 South (low byte used as anim flags)
    short movementFlags;         // 0x32
    int animCounter;	         // 0x34 - Counter for animation state machine
    int u14;                     // 0x38
    int u15;                     // 0x3C
    float speed;                 // 0x40
    int u17;                     // 0x44
    int u18;                     // 0x48
    float u19;                   // 0x4C
    char attackType;             // 0x50 - Attack execution type (ENEMY_ATTACK_*: THROW, SPAWN, CHASE, etc.) - indexed into prep/execute tables
    char attackCheck;            // 0x51 - Attack condition check (ENEMY_ATTACK_CHECK_*: DISABLED, TIMER, SIGHT, PROXIMITY_LARGE, PROXIMITY_SMALL)
    short attackCooldown;        // 0x52 - Frames between attacks (prevents spam)
    int movementTimer1;          // 0x54
    int u22;                     // 0x58
    int attackState;             // 0x5C - State machine: 0=idle, 1=preparing, 2=attacking, 3=cooldown
	int attackTimer;             // 0x60 - Counter for attack timing (checks >= 0x1E)
    float animationTimer;        // 0x64 - Timer for squash/stretch animation (0-45, modifies enemyObject->objectPointer->scale[0] and scale[2])
    int u24[6];                  // 0x68-0x7F
    char collideFlags;           // 0x80 - Bit flags (0x01 = unknown, 0x10 = can be stunned by bomb kick/throw, ??? 0x20 = enable special terrain interaction ???)
    char currentHealth;          // 0x81 - Current health points (decreases when damaged)
    short stunTimer;       		 // 0x82 - Counts down when enemy is stunned
    float u33;                   // 0x84
    float u34;                   // 0x88
    char invincibilityFlag;      // 0x8C - Invincibility (0x01 = cannot take damage or be stunned)
    char attachedParticleID;     // 0x8D - Particle effect ID attached to enemy from g_ParticleEffects (0xFF = none)
    char actionFlags;            // 0x8E - Action state (0 = idle, 1 = stunned, 2 = attacking, 3 = taking damage)
    char u35_3;                  // 0x8F
    short itemDropChance;		 // 0x90 - compared vs g_thresholdPercentage for item drop
    short itemDrop;              // 0x92 - Item type to spawn when defeated (loaded from behavior file byte 0x13)
    int u37;                     // 0x94
    int slotIDBehavior;          // 0x98 - Index into g_EnemySlots array (used to get behavior ID)
    int u39;                     // 0x9C
    EnemyRuntimeData* runtimeDataPtr; // 0xA0 - Pointer back to EnemyRuntimeData
}
Enemy;

typedef struct EnemyHeader
{
    int activeFlag;              // 0x00 - State (0 = inactive, 2 = active/loading)
    int offscreenRespawnTimer;   // 0x04 - Counter for proximity-based behavior loading
    float spawnPosX;             // 0x08
    float spawnPosY;             // 0x0C
    float spawnPosZ;             // 0x10
    Enemy enemy;				 // 0x14 - Pointer to Enemy (0xA4 bytes) [func param base + 0x18]
}
EnemyHeader;


typedef struct SFXChannel
{
	float location[3]; // Location of the sound
	int isDirectional; // If true, the sound is directional (Unconfirmed)
	int soundID; // -1 = no sound allocated
}
SFXChannel;

typedef struct ParticleEffect
{
    int activeFlag;        // 0x00 - -1 (FFFFFFFF) when free/inactive, 1 or 2 when active
    int field04;           // 0x04 - -1 (FFFFFFFF) when free, otherwise some handle/ID
    int effectType;        // 0x08 - Effect type/ID
    int field0C;           // 0x0C - Unknown field
    float posX;            // 0x10 - X position
    float posY;            // 0x14 - Y position
    float posZ;            // 0x18 - Z position
    void* parentObject;    // 0x1C - Pointer to parent object (can be null)
    LevelClass* levelClass;// 0x20 - Pointer to LevelClass object (spawned via g_CreateGameObject/Ex)
}
ParticleEffect;

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
	short u1;
	short u2;
}
ComputerPlayerMovement;

typedef struct RivalValues
{
	int heartCount;
	int bombCount;
	int bombExplosionLevel;
	int u1;
	float speedValues[3];
	int modelID;	
}
RivalValues;

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