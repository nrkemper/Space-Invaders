//
//  zone.c
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-12-19.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#include "zone.h"
#include "sys.h"

#include <stdlib.h>
#include <string.h>

void    *memory;

void Z_MemoryInit (void)
{
        int     maxwidth, maxheight, bufsize;
        
        SYS_GetMaxXY(&maxwidth, &maxheight);
        bufsize = maxwidth * maxheight * 4;//FIXME: make better
        
        memory = malloc (bufsize);
        memset(memory, 0xff, bufsize);
}

void Z_MemoryDestroy (void)
{
        free(memory);
}
