#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdbool.h>
#include <stdio.h>
#include "DefVars.h"

//Controller Flags
#define 	CONT_PLUGGED_OUT	0x8000 

//Button Flags
#define 	BTN_A				0x8000 
#define 	BTN_B				0x4000 
#define 	BTN_Z				0x2000 
#define 	BTN_START			0x1000 
#define 	BTN_DUP				0x0800 
#define 	BTN_DDOWN			0x0400 
#define 	BTN_DLEFT			0x0200 
#define 	BTN_DRIGHT			0x0100 
#define 	BTN_L				0x0020 
#define 	BTN_R				0x0010 
#define 	BTN_CUP				0x0008 
#define 	BTN_CDOWN			0x0004 
#define 	BTN_CLEFT			0x0002 
#define 	BTN_CRIGHT			0x0001

typedef struct Controller
{
	uint		Flags;
	ushort		Button;
	char		AnalogX;
	char		AnalogY;
}
Controller;



typedef struct Object
{
	int		num;
	int 	num2;
	int 	u1;
	int 	u2;
	float 	position[3];
	int 	u3;
	float 	direction_angle;
	int 	u6;
	float 	scale[3];
	int 	u7;
	int 	u8;
	int 	u9;
	int 	u10;
	int 	u11;
	float 	unk_float1;
	float 	unk_float2;
	int 	u12;
	long 	unk_pointer1;
	int 	u13;
	float 	unk_vector[3];
	int 	u14[6];
	float 	unk_float3;
	float 	unk_float4;
	long 	unk_pointer2;
	long 	unk_pointer3;

	// not finalized
}
Object;

typedef struct LevelClass
{
	int		num;
	int 	type;
	int 	u1;
	int 	u2;
	int 	u3;
	int 	u4;
	int 	u5;
	int 	u6;
	int 	u7;
	int 	u8;
	int 	u9;
	int 	u10;
	int 	u11;
	float 	unk_float1;
	float 	unk_float2;
	int 	u12;
	Object  *ObjectPointer; //Pointer to the Object this LevelClass is spawning
	long 	unk_pointer1;
	int 	u13;
	float 	unk_vector[3];
	int 	u14[6];
	float 	unk_float3;
	float 	unk_float4;
	long 	unk_pointer2;
	long 	unk_pointer3;
}
LevelClass;

//Player Flag
#define IS_ON_SLOPE					0x00000010  
#define DISALLOW_USER_INPUT			0x00000020
#define THROWING_OBJECT				0x00000040
#define PICKING_UP_OBJECT			0x00000080
#define KICKING_BOMB				0x00000100
#define HAS_BOMB_BELOW				0x00000200
#define IS_KNOCKED_OUT				0x00001000
#define HAS_OBJECT_IN_HAND			0x00008000
#define IS_INTANGIBLE				0x00010000
#define IS_HURT_SPINNING			0x00020000
#define CAN_ONLY_TURN				0x00400000
#define IS_IN_CUTSCENE				0x02000000

//Bomb Types
#define BOMB_TYPE_NORMAL		0  
#define BOMB_TYPE_RED			1  
#define BOMB_TYPE_REMOTE		2  
#define BOMB_TYPE_RED_REMOTE	3  
#define BOMB_TYPE_NORMAL_RED	4

//Virus Types
#define VIRUS_TYPE_NONE			0x00
#define VIRUS_TYPE_FAST			0x01
#define VIRUS_TYPE_STUCK		0x02
#define VIRUS_TYPE_SLOW			0x04
#define VIRUS_TYPE_NO_BOMBS		0x08
#define VIRUS_TYPE_INVERTED		0x20
#define VIRUS_TYPE_ON_FIRE		0x80

typedef struct Player
{
	float 	direction_angle[4];
	int		flag;
	int 	energy;
	short 	u1;
	char 	u2;
	char 	bomb_type;
	int 	bomb_count;
	int 	u4;
	int 	u5;
	LevelClass  *PlayerLevelClass; //Pointer to the LevelClass this Player is controlling
	int 	u6;
	int 	u7;
	int 	u8;
	int 	u9;
	int 	u10;
	int 	u11;
	int 	animation_type;
	short 	u12;
	char 	u12a;
	char 	virus_type;
	int 	u13;
	int 	u14;
	int 	u15;
	float 	direction_angle2[4];
	int 	u16[11];
	short   u17[2];
	int 	u18[6];
	long   	pointer1;
	int 	u19[5];
}
Player;


typedef struct Game
{
	int		flag;
	int 	lives;
	int 	u2;
	int 	gems;
	int 	u4;
	int 	u5;
	int 	time_target;
	int 	u7;
	int 	time_elapsed;
	float 	delta_time;
	int 	seconds_elapsed;
	int 	u11;
	int 	u12;
	int 	u13;
	int 	u14;
	int 	u15;
	//more possibly here
}
Game;


typedef struct Bomb
{
	short 	num;
	short	flag;
	int 	u1;
	int 	u2;
	int 	u3;
	int 	u4;
	long   	next_bomb_ptr;
	long 	unk_ptr1;
	long 	unk_ptr2;
	long 	unk_ptr3;
	int 	u5;
	int 	u6;
	int 	u7;
	long 	unk_ptr4;
	long 	unk_ptr5;
	int 	u8;
	int 	u9;
	float 	position[3];
	int 	u10;
	int 	u11;
	int 	u12;
	int 	u13;
	int 	u14;
	short 	inflate_timer;
	short 	u15;
	int 	unk_flag1;
	short 	explode_timer;
	short 	unk_flag2;
	int 	u16;
	int 	u17;
	int 	unk_flag3;
	float 	unk_float2[4];
}
Bomb;


#endif