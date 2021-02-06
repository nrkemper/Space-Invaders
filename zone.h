//
//  zone.h
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-09-30.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#ifndef __ZONE_H__
#define __ZONE_H__

#include "invaderlib.h"

typedef struct memblock_s
{
        uint32_t        size;
        boolean         is_free;
} memblock_t;

void Z_MemoryInit (void);
void Z_MemoryDestroy (void);
#endif /* __ZONE_H__ */
