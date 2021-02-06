//
//  sys_macosx.m
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-12-19.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#include "sys.h"
#import <AppKit/NSScreen.h>

void SYS_GetTime (void)
{
        
}

void SYS_GetMaxXY (int *width, int *height)
{
        *width = [[NSScreen mainScreen] frame].size.width;
        *height = [[NSScreen mainScreen] frame].size.height;
}
