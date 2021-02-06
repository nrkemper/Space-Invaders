//
//  InvaderView.m
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-12-20.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#import "InvaderView.h"

#import <AppKit/NSImage.h>
#import <AppKit/NSBitmapImageRep.h>

#include "vid.h"
#include "invaderlib.h"

@implementation InvaderView

- (void)drawRect: (NSRect)dirtyRect
{
        NSImage                 *image;
        NSBitmapImageRep        *imagerep;
        int                     width, height;
        byte                    *buffer;
        
        width = vid.width;
        height = vid.height;
        buffer = vid.buffer;
        
        imagerep = [[NSBitmapImageRep alloc] initWithBitmapDataPlanes:(unsigned char**)&buffer
                                                           pixelsWide:width
                                                           pixelsHigh:height
                                                        bitsPerSample:8
                                                      samplesPerPixel:4//FIXME: make dynamic
                                                             hasAlpha:YES
                                                             isPlanar:NO
                                                       colorSpaceName:NSCalibratedRGBColorSpace
                                                         bitmapFormat:NSBitmapFormatThirtyTwoBitLittleEndian
                                                          bytesPerRow:0
                                                         bitsPerPixel:0];
        
        image = [[NSImage alloc] init];
        [image addRepresentation:imagerep];
        [image drawInRect:dirtyRect];
        
        //cleanup
        [image autorelease];
        [imagerep autorelease];
}

@end
