//
//  vid.h
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-12-18.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#ifndef __VID_H__
#define __VID_H__

#include "invaderlib.h"

typedef struct viddef_s
{
        int     x;
        int     y;
        int     width;
        int     height;
        int     bpp;
        byte    *buffer;
} viddef_t;

typedef struct resolution_s
{
        int     width;
        int     height;
} resolution_t;

typedef enum resmode_e
{
        RES_ORIG,
        RES_NES,
        RES_SNES,
        RES_PS1,
        RES_N64
} resmode_t;

float   aspect_ratio [10];


void VID_Init (int x, int y, int width, int height);
void VID_GetMaxXY (int *x, int *y);
void VID_GetWidth (void);
void VID_GetHeight (void);
void VID_Resize (int width, int height);
void VID_Move (int x, int y);
void VID_Minimize (void);
void VID_ToggleFullscreen (void);
void VID_Update (void);
void VID_Destroy (void);

extern viddef_t         vid;
extern byte             *memory;
#endif /* __VID_H__ */
