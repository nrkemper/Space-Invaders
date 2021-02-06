//
//  InvaderApplication.h
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-12-18.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#ifndef __INVADERAPPLICATION_H__
#define __INVADERAPPLICATION_H__

#import <Appkit/NSApplication.h>
#import "InvaderWindow.h"

@interface InvaderApplication : NSApplication
{
        BOOL            is_active;
}

+ (id) sharedApplication;
- (void) run;
- (void) terminate;

@end

extern InvaderApplication       *SpaceInvaders;

#endif /* __INVADERAPPLICATION_H__ */
