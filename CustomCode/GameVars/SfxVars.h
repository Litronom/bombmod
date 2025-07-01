#include "../MainInclude.h"

// Bomberman Voice IDs
#define SFX_BM_HA                       0x184
#define SFX_BM_HYA                      0x185
#define SFX_BM_HYE                      0x186
#define SFX_BM_YA                       0x187
#define SFX_BM_YO                       0x188
#define SFX_BM_POW                      0x189
#define SFX_BM_YOH                      0x18A
#define SFX_BM_HUH                      0x18B
#define SFX_BM_AUGH                     0x18C

#define SFX_BM_HA_EFFECT                0x18D
#define SFX_BM_HYA_EFFECT               0x18E
#define SFX_BM_HYE_EFFECT               0x18F
#define SFX_BM_YA_EFFECT                0x190
#define SFX_BM_HUH_EFFECT               0x191
#define SFX_BM_YO_EFFECT                0x192
#define SFX_BM_POW_EFFECT               0x193
#define SFX_BM_YOH_EFFECT               0x194
#define SFX_BM_HUGH_EFFECT              0x195
#define SFX_BM_AUGH_EFFECT              0x196

#define SFX_BM_YAAA                     0x1A2
#define SFX_BM_PHEW                     0x1A3
#define SFX_BM_YAY                      0x1A4
#define SFX_BM_YES                      0x1A5
#define SFX_BM_GIGGLE                   0x1A6
#define SFX_BM_QUACK_QUAAACK            0x1A7
#define SFX_BM_MEOW_MEEOOW              0x1A8
#define SFX_BM_I_AM_THE_BEST            0x1A9
#define SFX_BM_ALRIGHT                  0x1AA
#define SFX_BM_PHEW_THAT_WAS_CLOSE      0x1AC
#define SFX_BM_I_DID_IT                 0x1AD
#define SFX_BM_PIECE_OF_CAKE            0x1B1

// Artemis Voice IDs
#define SFX_ART_YOU_ARE_MINE            0x1B2
#define SFX_ART_BYE_BYE                 0x1B3
#define SFX_ART_AAAGH                   0x1B4
#define SFX_ART_AAAAAH                  0x1B5

// Orion Voice IDs
#define SFX_ORI_HUGH                    0x1B6
#define SFX_ORI_URGH                    0x1B7
#define SFX_ORI_AAAAAH                  0x1B8

// Regulus Voice IDs
#define SFX_REG_READY                   0x1B9
#define SFX_REG_URGH                    0x1BA
#define SFX_UNK_READY2                  0x23E
#define SFX_UNK_READY3                  0x23F
#define SFX_UNK_REA                     0x2A6

// Altair Voice IDs
#define SFX_ALT_I_WILL_FINISH_YOU       0x1BE
#define SFX_ALT_YOU_WANNA_FIGHT_ME      0x1BF
#define SFX_ALT_HAH                     0x1C0
#define SFX_ALT_URGH                    0x1C1
#define SFX_ALT_PLAYTIME_IS_OVER        0x1C2
#define SFX_ALT_YOU_WILL_PAY            0x1C3
#define SFX_ALT_UUAAAGH                 0x1C4
#define SFX_ALT_UGH                     0x1C5
#define SFX_ALT_PLAYTIME_IS_OVER2       0x1CA
#define SFX_ALT_YOU_WILL_PAY_EFFECT     0x255
#define SFX_ALT_UGH_EFFECT              0x257
#define SFX_ALT_HAH_EFFECT              0x25B
#define SFX_ALT_UUAAAGH_EFFECT          0x262
#define SFX_ALT_YOU_WANNA_FIGHT_ME2     0x267
#define SFX_ALT_YOU_WANNA_FIGHT_ME3     0x268
#define SFX_ALT_PLAYTIME_IS_OVER3       0x269
#define SFX_ALT_PLAYTIME_IS_OVER4       0x26A
#define SFX_ALT_YOU_WILL_PAY2           0x26B
#define SFX_ALT_YOU_WILL_PAY3           0x26C
#define SFX_ALT_UGH2                    0x27A
#define SFX_ALT_HAH2                    0x27B

// Sirius Voice IDs
#define SFX_SIR_HAHAHAHA                0x1C6
#define SFX_SIR_YA                      0x1C7
#define SFX_SIR_GIVE_IT_UP              0x1C8
#define SFX_SIR_HAA                     0x1C9
#define SFX_SIR_I_GUESS_I_BETTER_HELP   0x1CB
#define SFX_SIR_GYUH                    0x1CD
#define SFX_SIR_NOOOO                   0x1CE
#define SFX_SIR_HAHAHAHA_EFFECT         0x265
#define SFX_SIR_NOOOOOO_EFFECT          0x2A2
#define SFX_SIR_NOOOO2                  0x2A5
#define SFX_SIR_NOOOO3                  0x2B3

// Spellmaker Voice IDs
#define SFX_SM_HAHAHAAAA                0x1CF
#define SFX_SM_HUHUHUHAHAHAA            0x1D0
#define SFX_SM_HUAAAAAGH                0x1D1
#define SFX_SM_WELCOME                  0x1D2
#define SFX_SM_JUSTICE                  0x1D3
#define SFX_SM_SUN                      0x1D4
#define SFX_SM_MOON                     0x1D5
#define SFX_SM_DEATH                    0x1D6
#define SFX_SM_LOVERS                   0x1D7
#define SFX_SM_EVIL                     0x1D8
#define SFX_SM_STAR                     0x1D9
#define SFX_SM_WORLD                    0x1DA
#define SFX_SM_YAHAHAHAHAHAHA           0x1DB

// Announcer Voice IDs
#define SFX_ANNOUNCER_READY_GO          0x1DC
#define SFX_ANNOUNCER_DRAW              0x1DD
#define SFX_ANNOUNCER_GAME              0x1DE
#define SFX_ANNOUNCER_HURRY_UP          0x1E0
#define SFX_ANNOUNCER_TIMES_UP          0x1E1
#define SFX_ANNOUNCER_READY_GO_EFFECT   0x1E4
#define SFX_ANNOUNCER_GAME_EFFECT       0x1E5
#define SFX_ANNOUNCER_HURRY_UP_EFFECT   0x1E9

// Bomb Sound Effects
#define SFX_BOMB_PLACED                 0x00A
#define SFX_BOMB_EXPLOSION_LVL1         0x00B
#define SFX_BOMB_EXPLOSION_LVL2         0x00C
#define SFX_BOMB_EXPLOSION_LVL3         0x00D
#define SFX_BOMB_EXPLOSION_BIG          0x00E

#define SFX_BOMB_RED_EXPLOSION_LVL1     0x00F
#define SFX_BOMB_RED_EXPLOSION_LVL2     0x010
#define SFX_BOMB_RED_EXPLOSION_LVL3     0x011
#define SFX_BOMB_RED_EXPLOSION_BIG      0x015

#define SFX_BOMB_PUMP_FIRST             0x016
#define SFX_BOMB_PUMP_SECOND            0x017
#define SFX_BOMB_PUMP_DONE              0x01A

#define SFX_BOMB_CLANK                  0x022
#define SFX_BOMB_COLLIDE                0x023
#define SFX_BOMB_BOUNCE                 0x02D

// SFX IDs
#define SFX_SFX_BIRDS_LEFT              0x20A
#define SFX_SFX_BIRDS_RIGHT             0x20B