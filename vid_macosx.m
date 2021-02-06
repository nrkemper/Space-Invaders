//
//  vid_macosx.m
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-12-18.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#include "vid.h"
#include "zone.h"
#include "sys.h"
#include "invaderdefs.h"

#import "InvaderWindow.h"
#import "InvaderView.h"

#import <AppKit/NSBitmapImageRep.h>

InvaderWindow           *window;
InvaderView             *drawsurface;
viddef_t                vid;


void VID_Init (int x, int y, int width, int height)
{
        static  BOOL    first_init = YES;
        NSRect  rect;
        
        if(x<0)
                x=0;
        
        if(y<0)
                y=0;
        
        //FIXME: resolutions
        if(width < 256)
                width = 256;
        
        if(height < 224)
                height = 224;
        
        if (first_init)
        {
                int     maxwidth, maxheight;
                
                rect = NSMakeRect(x, y, width, height);
                
                window = [[InvaderWindow alloc] initWithContentRect: rect
                                                          styleMask: NSWindowStyleMaskTitled|
                                                                        NSWindowStyleMaskResizable|  NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable
                                                            backing:NSBackingStoreBuffered
                                                              defer: NO];
                
                
                drawsurface = [[InvaderView alloc] initWithFrame: rect];
                
                [window setTitle: @(GAME_TITLE)];
                [window makeKeyAndOrderFront:nil];
                [window setContentView: drawsurface];
                
                //FIXME: create window controller
                vid.buffer = memory;//FIXME: update with memory->data
                
                //SYS_GetMaxXY(&maxwidth, &maxheight);
                //FIXME: set cache pointer
                first_init = NO;
        } else {
                
        }
        
        vid.x = x;
        vid.y = y;
        vid.width = width;
        vid.height = height;
}

void VID_GetMaxXY (int *x, int *y)
{
        
}

void VID_GetWidth (void)
{
        
}

void VID_GetHeight (void)
{
        
}

void VID_Resize (int width, int height)
{
        vid.width = width;
        vid.height = height;
}

void VID_Move (int x, int y)
{
        
}

void VID_Minimize (void)
{
}

void VID_ToggleFullscreen (void)
{
        
}

void VID_Update (void)
{
        NSRect  rect;
        int     x, y, width, height;
        
        x = 0;
        y = 0;
        width = vid.width;
        height = vid.height;
        
        rect = NSMakeRect(x, y, width, height);
        [drawsurface drawRect:rect];
}

void VID_Destroy (void)
{
        [window autorelease];
        [drawsurface autorelease];
}
