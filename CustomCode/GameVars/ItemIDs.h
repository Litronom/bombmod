#include "../MainInclude.h"

// Stop IDs with "_LOOP" manually via g_StopParticleEffect when needed
// Effect IDs
#define ITEM_FIREPOWER_UP                    0x00  // Firepower Up Item
#define ITEM_BOMB_UP                         0x01  // Bomb Up Item
#define ITEM_BOMBTYPE_RED                    0x02  // Red Bomb Type Item
#define ITEM_BOMBTYPE_REMOTE                 0x03  // Remote Bomb Type Item
#define ITEM_HEART                           0x04  // Heart Item
#define ITEM_SKULL                           0x05  // Skull Item
#define ITEM_EVIL                            0x06  // Evil Item
#define ITEM_GEM_BLUE                        0x07  // Blue Gem Item
#define ITEM_GEM_RED                         0x08  // Red Gem Item
#define ITEM_GOLD_CARD_1(world,level)       (0x09 + (((world) * 2 + (level)) * 3))
#define ITEM_GOLD_CARD_2(world,level)       (0x0A + (((world) * 2 + (level)) * 3))
#define ITEM_GOLD_CARD_3(world,level)       (0x0B + (((world) * 2 + (level)) * 3))
#define ITEM_GOLD_CARD_4(world,level)       (g_4thGoldCardIDs[(world)][(level)])  // Gold Card Item (30 enemies defeated) - 0x2D to 0x38
#define ITEM_CUSTOM_PART_HEAD(set)       set+0x39  // Custom Part Head Item
#define ITEM_CUSTOM_PART_BODY(set)       set+0x3F  // Custom Part Body Item
#define ITEM_CUSTOM_PART_ARMS(set)       set+0x45  // Custom Part Arms Item
#define ITEM_CUSTOM_PART_LEGS(set)       set+0x4B  // Custom Part Legs Item