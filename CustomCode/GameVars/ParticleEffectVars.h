#include "../MainInclude.h"

// Stop IDs with "_LOOP" manually via g_StopParticleEffect when needed
// Effect IDs
#define PARTICLE_EFFECT_BOMB_HIT                  0x00  // Bomb Bump Effect
#define PARTICLE_EFFECT_PICKUP                    0x01  // Blue Pickup Effect
#define PARTICLE_EFFECT_GEM_PICKUP                0x02  // Effect when picking up a gem
#define PARTICLE_EFFECT_CONTAINER_BREAK           0x03  // Cross/X Pattern Effect on container break
#define PARTICLE_EFFECT_DIAMOND                   0x04  // Blue-Yellow Diamond Effect
#define PARTICLE_EFFECT_SEEING_STARS_LOOP         0x05  // Seeing Stars Effect on stun
#define PARTICLE_EFFECT_TRANSPARENT_HEART         0x06  // Transparent Heart Effect floating upwards
#define PARTICLE_EFFECT_FLAME                     0x07  // Flame Effect
#define PARTICLE_EFFECT_FLAME_HUGE                0x08  // Huge Flame Effect
#define PARTICLE_EFFECT_3D_EXPLOSION_1            0x09  // 3D Explosion Effect - Does Damage!
#define PARTICLE_EFFECT_3D_EXPLOSION_2            0x0A  // 3D Explosion Effect - Does Damage!
#define PARTICLE_EFFECT_EXIT_ARROW_LOOP           0x0B  // Exit Arrow Effect
#define PARTICLE_EFFECT_SMOKE_PUFF                0x0C  // Single Smoke Puff Effect
#define PARTICLE_EFFECT_SMOKE_PUFF_AREA           0x0D  // Multipe Smoke Puff Effects around area
#define PARTICLE_EFFECT_SMOKE_PUFF_AREA_LARGE     0x0E  // Larger Multipe Smoke Puff Effects around area
#define PARTICLE_EFFECT_SMOKE_PUFF_STACKED_LARGE  0x0F  // Large Stacked Smoke Puff Effect
#define PARTICLE_EFFECT_SMOKE_PUFF_AREA_LARGE_2   0x10  // Another Large Multipe Smoke Puff Effects around area
#define PARTICLE_EFFECT_GLASS_SHATTER_1           0x11  // Glass Shatter Effect 1
#define PARTICLE_EFFECT_GLASS_SHATTER_2           0x12  // Glass Shatter Effect 2
#define PARTICLE_EFFECT_EXPLOSION_LARGE           0x13  // Large 2D Explosion Effect - No Damage!
#define PARTICLE_EFFECT_EXPLOSION                 0x14  // 2D Explosion Effect - No Damage!
#define PARTICLE_EFFECT_APPEARANCE_FLASH_LOOP     0x15  // Appearance Flash Effect e.g. spawning as ghost in multiplayer
#define PARTICLE_EFFECT_SOFT_SMOKE_PUFF_AREA      0x16  // Soft Smoke Puff Effect around area
#define PARTICLE_EFFECT_SOFT_SMOKE_PUFF_STACKED   0x17  // Soft Stacked Smoke Puff Effect
#define PARTICLE_EFFECT_SMOKE_PUFF_BLACK          0x18  // Black Smoke Puff Effect
#define PARTICLE_EFFECT_SMOKE_PUFF_SMALL          0x19  // Single small Smoke Puff Effect
#define PARTICLE_EFFECT_GLASS_SHATTER_LARGE       0x1A  // Large Glass Shatter Effect

#define PARTICLE_EFFECT_EXIT_ARROW_W_LOOP         0x25  // Exit Arrow Effect pointing West
#define PARTICLE_EFFECT_EXIT_ARROW_S_LOOP         0x26  // Exit Arrow Effect pointing South
#define PARTICLE_EFFECT_EXIT_ARROW_E_LOOP         0x27  // Exit Arrow Effect pointing East
#define PARTICLE_EFFECT_EXIT_ARROW_N_LOOP         0x28  // Exit Arrow Effect pointing North
