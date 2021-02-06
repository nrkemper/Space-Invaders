//
//  main.m
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-09-28.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#import "sys.h"
#import "vid.h"
#import "zone.h"
#import "InvaderApplication.h"
#include <stdio.h>

int main(int argc, const char * argv[])
{
        Z_MemoryInit();
        
        VID_Init (250, 250, 250, 250);
        VID_Update ();
        
        SpaceInvaders = [InvaderApplication sharedApplication];
        [SpaceInvaders setActivationPolicy:NSApplicationActivationPolicyRegular];
        [SpaceInvaders run];
        
        VID_Destroy();
        Z_MemoryDestroy();
        return 0;
}
