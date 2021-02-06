//
//  InvaderWindow.m
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-12-18.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#import "InvaderWindow.h"
#import "InvaderApplication.h"

@implementation InvaderWindow

- (BOOL) canBecomeKeyWindow
{
        return YES;
}

-(BOOL) canBecomeMainWindow
{
        return YES;
}

-(void) close
{
        [SpaceInvaders terminate: self];
        [super close];
}

@end
