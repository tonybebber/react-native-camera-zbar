#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "CameraFocusSquareOld.h"

@class RCTCameraOldManager;

@interface RCTCameraOld : UIView

- (id)initWithManager:(RCTCameraOldManager*)manager bridge:(RCTBridge *)bridge;

@end
