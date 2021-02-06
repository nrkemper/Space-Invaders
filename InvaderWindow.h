//
//  InvaderWindow.h
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-12-18.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#ifndef __INVADERWINDOW_H__
#define __INVADERWINDOW_H__

#import <Appkit/NSWindow.h>

@interface InvaderWindow : NSWindow

- (BOOL) canBecomeMainWindow;
- (BOOL) canBecomeKeyWindow;

@end

#endif /* __INVADERWINDOW_H__ */
