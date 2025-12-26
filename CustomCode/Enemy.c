#include "MainInclude.h"

void OnEnemySpawned_Hook(Enemy *enemy, short arg1, short arg2)
{
    // Call original spawn finalization
    g_FinalizeEnemySpawn(enemy, arg1, arg2);


    // Make Enemy harder!
    enemy->speed *= 1.25f;  // Speed mod on spawn
    enemy->currentHealth *= 3;  // Set health
    enemy->itemDropChance *= 0.5f;

//    EnemyObject* enmobj = (EnemyObject*)((char*)enemy->enemyObject);

//    enmobj->objectPointer->scale[0] *= 1.5f;
//    enmobj->objectPointer->scale[1] *= 1.5f;
//    enmobj->objectPointer->scale[2] *= 1.5f;
//    enmobj->radius *= 1.5f;

}



// Recreated func_8028304C as the original only takes parameters via registers s0/s1
void EnemyStun(Enemy* enemy, int stunType)
{
    // Check if enemy can be stunned (0x10 flag)
    if (!(enemy->collideFlags & 0x10))
    {
        return;
    }

    // Check if already in stun state
    if ((enemy->actionFlags & 0xF) == 1)
    {
        return;
    }

    // Cancel attack if active
    if (enemy->attackState != 0)
    {
        func_8028805C(enemy);
    }

    EnemyObject* enemyObject = enemy->enemyObject;
    enemy->movementTimer1 = 0;

    // Call animation function
    func_80229E38(enemyObject->objectPointer, 1, 0);

    // Only do sound/effect if not already stunned
    if ((enemy->actionFlags & 0xF) != 1)
    {
        // Stop any existing sound effect
        if (enemy->attachedParticleID != -1)
        {
            g_StopParticleEffect((int)enemy->attachedParticleID);
            enemy->attachedParticleID = -1;
        }

        // Spawn stun effect and play sound
        enemy->attachedParticleID = g_SpawnParticleEffect(PARTICLE_EFFECT_SEEING_STARS_LOOP, 0.0f, 130.0f, 0.0f, (LevelClass*)enemyObject);
    }

    // Set stun animation state
    func_80282430(enemy, 0xF, 1);

    // Update enemy state
    int state = func_802824B4(enemy);
    func_802313DC(enemyObject, state);

    // Set velocity to zero if flag 0x1E is set
    if (enemy->movementFlags != 0)
    {
        enemy->animCounter = 2;
        enemyObject->movementFloat[0] = 0.0f;
        enemyObject->movementFloat[1] = 0.0f;
        enemyObject->movementFloat[2] = -1.0f;
    }

    // Set stun timer based on stun type
    if (stunType == 0)
    {
        enemy->stunTimer = 0x258;  // 600 frames
    }
    else if (stunType == 1)
    {
        enemy->stunTimer = 0x12C;  // 300 frames
    }
    else if (stunType == 2)
    {
        enemy->stunTimer = 0x78;   // 120 frames
    }
}


// Enemy Damage Handler Implementation  
// Returns: 1 = damaged, 2 = killed (health reached 0), 4 = no damage (invulnerable)
int EnemyDamagedCheck_Hook()
{
    register Enemy *enemy asm("s2");
    EnemyObject *enemyObject = (EnemyObject*)enemy->enemyObject;
    int s4 = 0;

    /* if (*(u8 *)(s2 + 0x78) != 0) */
    if (enemy->invincibilityFlag != 0) 
    {
        return 1;
    }

    int stunCheck = enemyObject->flags;

    /* if (!(v0 & 0x40)) */
    if (!(stunCheck & 0x40))
    {
        goto L80284ECC;
    }

    /* health decrement */
    enemy->currentHealth--;
    if (enemy->currentHealth == 0)
    {
        return 2;
    }
    if (stunCheck & 0x2000)
    {
        enemy->currentHealth--;
        if (enemy->currentHealth == 0)
        {
            return 2;
        }
    }
    if (stunCheck & 0x4000)
    {
        enemy->currentHealth--;
        if (enemy->currentHealth == 0)
        {
            return 2;
        }
    }

    Object* obj = (Object*)enemyObject->objectPointer;

    if (g_EnemySlots[enemy->slotIDBehavior].behaviour == BEHAVIOR_BATTLE_TEAM_GEMS)
    {
        g_PlayLocalSound(0x1EB,obj->position[0],obj->position[1],obj->position[2]);

        g_SpawnParticleEffect(PARTICLE_EFFECT_SOFT_SMOKE_PUFF_AREA,obj->position[0],obj->position[1] + 140.0f,obj->position[2],0);

        g_SpawnParticleEffect(PARTICLE_EFFECT_GLASS_SHATTER_1,obj->position[0],obj->position[1] + 140.0f,obj->position[2],0);
    }
    else
    {
        g_PlayLocalSound(0x167,obj->position[0],obj->position[1],obj->position[2]);
    }

    if (enemy->attackState != 0)
    {
        func_8028805C(enemy);
    }

    if ((enemy->actionFlags&0xF) == 1)
    {
        enemy->movementTimer1 = 0;

        if (enemy->attachedParticleID != -1)
        {
            g_StopParticleEffect((int)enemy->attachedParticleID);
            enemy->attachedParticleID = -1;
        }
    }

    func_80282430(enemy, 0xF, 3);

    enemy->invincibilityFlag = 1;
    enemy->stunTimer = 0x3C;

    func_80231408(enemyObject, 0x40000);

    return 1;

L80284ECC:
    s4 = 0;

    if (stunCheck & 0x2000)
    {
        if (stunCheck & 0x400)
        {
            if ((enemy->collideFlags&0xF) == 0)
            {
                s4 = 1;
            }
            else if ((enemy->collideFlags&0xF) == 1)
            {
                EnemyStun(enemy, 0);
            }
        }
    }
    else
    {
        if ((stunCheck & 0x2) && (stunCheck & 0x400))
        {
            EnemyStun(enemy, 1);
        }
        else if (((s32)(stunCheck << 14) < 0) || (stunCheck & 0x4))
        {
            /* nothing */
        }
        else if (stunCheck & 0x200)
        {
            EnemyStun(enemy, 0);
        }
        else if (stunCheck & 0x400)
        {
            EnemyStun(enemy, 1);
        }
        else if (stunCheck & 0x800)
        {
            EnemyStun(enemy, 2);
        }
    }

    if (s4)
    {
        return 4;
    }

    return 1;    
}

void OnEnemyHealthChanged_Hook(void* enemyObjectFieldPtr)
{
    Enemy* enemy = (Enemy*)((char*)enemyObjectFieldPtr);
    
    // Health already decremented, modify if alive
    if (enemy->currentHealth > 0)
    {
//        enemy->enemyObject->objectPointer->scale[0] *= 1.15f;
//        enemy->enemyObject->objectPointer->scale[2] *= 1.15f;
        enemy->speed *= 1.15f;
    }
}
