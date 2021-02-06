//
//  InvaderApplication.m
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-12-18.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#import "InvaderApplication.h"

#include "sys.h"

InvaderApplication       *SpaceInvaders;

@implementation InvaderApplication


+ (id) sharedApplication
{
        //FIXME: singleton
        return [super sharedApplication];
}

//Main run loop
- (void) run
{
        //FIXME: implement framerate
        long int        curtime;
        SYS_GetTime();
        is_active = YES;
        
        while (is_active)
        {
                [self pollEvents];
                [self updateWindows];
        }
}

- (void) pollEvents
{
        NSEvent        *event;
        
        for (;;)
        {
                event = [self nextEventMatchingMask:NSEventMaskAny
                                                untilDate:[NSDate distantFuture]
                                                inMode:NSDefaultRunLoopMode
                                                dequeue:YES];
                
                if (event == nil)
                        break;
                
                [self sendEvent: event];
        }
}

- (void) terminate
{
        is_active = NO;
        [super terminate: self];
}

@end
