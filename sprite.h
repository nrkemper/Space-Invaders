//
//  sprite.h
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-09-29.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "invaderlib.h"

struct rowdef_s
{
        byte     *data;
};

struct spritedef_s
{
        char                    name[32];
        int                     id;
        int                     width, height;
        struct rowdef_s         *rows;
};

void D_SpriteXFlip ();
void D_SpriteYFlip ();
void D_SpriteXStretch ();
void D_SpriteYStretch ();
#endif /* sprite_h */
