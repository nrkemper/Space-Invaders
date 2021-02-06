//
//  InvaderWindowDelegate.m
//  Space Invaders
//
//  Created by Nicholas Kemp on 2021-02-06.
//  Copyright © 2021 Nicholas Kemp. All rights reserved.
//

#import "InvaderWindowDelegate.h"

#import <AppKit/NSWindow.h>
#import <Foundation/NSNotification.h>
#import <Foundation/NSGeometry.h>

#include "sys.h"
#include "vid.h"

@implementation InvaderWindowDelegate

-(NSSize)windowWillResize: (NSWindow *) sender toSize:(NSSize) frameSize
{
        int     maxwidth, maxheight;
        int     newwidth, newheight;
        
        newwidth = frameSize.width;
        newheight = frameSize.height;
        
        SYS_GetMaxXY(&maxwidth, &maxheight);
        
        if(newwidth > maxwidth)
                newwidth = maxwidth;
        
        //FIXME: implement minwidth
        //if (newwidth < minwidth)
        
        if(newheight > maxheight)
                newheight = maxheight;
        
        //FIXME: implement minheight
        //if (newheight < minheight)
        
        VID_Resize(newwidth, newheight);
        
        return NSMakeSize(newwidth, newheight);
}

-(void)windowWillEnterFullscreen: (NSNotification *) notification
{
        int     newwidth, newheight;
        
        //FIXME: set the appropriate resolution
        SYS_GetMaxXY(&newwidth, &newheight);
        VID_Resize(newwidth, newheight);
}

-(void)windowWillExitFullscreen: (NSNotification *) notification
{
        
}

-(void)windowWillMiniaturize: (NSNotification *) notification
{
        //go into sleep mode
}

-(void)windowDidExpose: (NSNotification *) notification
{
        //redraw
}

-(void)windowWillClose: (NSNotification *) notification
{
        //terminate
}

@end
