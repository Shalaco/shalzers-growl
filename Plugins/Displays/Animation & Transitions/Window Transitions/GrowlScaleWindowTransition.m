//
//  GrowlScaleWindowTransition.m
//  Growl
//
//  Created by rudy on 12/10/05.
//  Copyright 2005 The Growl Project. All rights reserved.
//

#import "GrowlScaleWindowTransition.h"


@implementation GrowlScaleWindowTransition

- (id) initWithWindow:(NSWindow *)inWindow {
	self = [super initWithWindow:inWindow];
	if (!self)
		return nil;
	return self;
}

- (void) setFromOrigin:(NSPoint)from toOrigin:(NSPoint)to {
	startingPoint = from;
	endingPoint = to;
	xDistance = (to.x - from.x);
	yDistance = (to.y - from.y);
	
	NSLog(@"%f %f\n", xDistance, yDistance);
}

- (void) drawTransitionWithWindow:(NSWindow *)aWindow progress:(GrowlAnimationProgress)progress {
	if (aWindow) {
		NSSize newSize;
		NSRect newFrame = [aWindow frame];
		float deltaX = progress * xDistance;
		float deltaY = progress * yDistance;
		switch (direction) {
			default:
			case GrowlForwardTransition:
				newSize.width = startingPoint.x + deltaX;
				newSize.height = startingPoint.y + deltaY;
				break;
			case GrowlReverseTransition:
				newSize.width = endingPoint.x - deltaX;
				newSize.height = endingPoint.y - deltaY;
				break;
		}
		newFrame.size.height = newSize.height;
		newFrame.size.width = newSize.width;

		[aWindow setFrame:newFrame display:YES];
		[aWindow setViewsNeedDisplay:YES];
	}
}

@end