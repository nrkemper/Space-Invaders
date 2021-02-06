//
//  InvaderWindowDelegate.h
//  Space Invaders
//
//  Created by Nicholas Kemp on 2021-02-06.
//  Copyright © 2021 Nicholas Kemp. All rights reserved.
//

#ifndef __INVADERWINDOWDELEGATE_H__
#define __INVADERWINDOWDELEGATE_H__

//#import <AppKit/NSWindowController.h>
#import <AppKit/NSWindow.h>
#import <Foundation/NSGeometry.h>
#import <Foundation/NSNotification.h>

@interface InvaderWindowDelegate : NSObject <NSWindowDelegate>

-(NSSize)windowWillResize: (NSWindow *) sender toSize:(NSSize) frameSize;
-(void)windowWillEnterFullscreen: (NSNotification *) notification;
-(void)windowWillExitFullscreen: (NSNotification *) notification;
-(void)windowWillMiniaturize: (NSNotification *) notification;
-(void)windowDidExpose: (NSNotification *) notification;
-(void)windowWillClose: (NSNotification *) notification;

@end
#endif /* __INVADERWINDOWDELEGATE_H__ */
