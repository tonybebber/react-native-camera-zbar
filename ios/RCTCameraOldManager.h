#import <React/RCTViewManager.h>
#import <AVFoundation/AVFoundation.h>

@class RCTCameraOld;

typedef NS_ENUM(NSInteger, RCTCameraOldAspect) {
  RCTCameraOldAspectFill = 0,
  RCTCameraOldAspectFit = 1,
  RCTCameraOldAspectStretch = 2
};

typedef NS_ENUM(NSInteger, RCTCameraOldCaptureSessionPreset) {
  RCTCameraOldCaptureSessionPresetLow = 0,
  RCTCameraOldCaptureSessionPresetMedium = 1,
  RCTCameraOldCaptureSessionPresetHigh = 2,
  RCTCameraOldCaptureSessionPresetPhoto = 3,
  RCTCameraOldCaptureSessionPreset480p = 4,
  RCTCameraOldCaptureSessionPreset720p = 5,
  RCTCameraOldCaptureSessionPreset1080p = 6
};

typedef NS_ENUM(NSInteger, RCTCameraOldCaptureMode) {
  RCTCameraOldCaptureModeStill = 0,
  RCTCameraOldCaptureModeVideo = 1
};

typedef NS_ENUM(NSInteger, RCTCameraOldCaptureTarget) {
  RCTCameraOldCaptureTargetMemory = 0,
  RCTCameraOldCaptureTargetDisk = 1,
  RCTCameraOldCaptureTargetTemp = 2,
  RCTCameraOldCaptureTargetCameraRoll = 3
};

typedef NS_ENUM(NSInteger, RCTCameraOldOrientation) {
  RCTCameraOldOrientationAuto = 0,
  RCTCameraOldOrientationLandscapeLeft = AVCaptureVideoOrientationLandscapeLeft,
  RCTCameraOldOrientationLandscapeRight = AVCaptureVideoOrientationLandscapeRight,
  RCTCameraOldOrientationPortrait = AVCaptureVideoOrientationPortrait,
  RCTCameraOldOrientationPortraitUpsideDown = AVCaptureVideoOrientationPortraitUpsideDown
};

typedef NS_ENUM(NSInteger, RCTCameraOldType) {
  RCTCameraOldTypeFront = AVCaptureDevicePositionFront,
  RCTCameraOldTypeBack = AVCaptureDevicePositionBack
};

typedef NS_ENUM(NSInteger, RCTCameraOldFlashMode) {
  RCTCameraOldFlashModeOff = AVCaptureFlashModeOff,
  RCTCameraOldFlashModeOn = AVCaptureFlashModeOn,
  RCTCameraOldFlashModeAuto = AVCaptureFlashModeAuto
};

typedef NS_ENUM(NSInteger, RCTCameraOldTorchMode) {
  RCTCameraOldTorchModeOff = AVCaptureTorchModeOff,
  RCTCameraOldTorchModeOn = AVCaptureTorchModeOn,
  RCTCameraOldTorchModeAuto = AVCaptureTorchModeAuto
};

@interface RCTCameraOldManager : RCTViewManager<AVCaptureMetadataOutputObjectsDelegate, AVCaptureFileOutputRecordingDelegate>

@property (nonatomic, strong) dispatch_queue_t sessionQueue;
@property (nonatomic, strong) AVCaptureSession *session;
@property (nonatomic, strong) AVCaptureDeviceInput *audioCaptureDeviceInput;
@property (nonatomic, strong) AVCaptureDeviceInput *videoCaptureDeviceInput;
@property (nonatomic, strong) AVCaptureStillImageOutput *stillImageOutput;
@property (nonatomic, strong) AVCaptureMovieFileOutput *movieFileOutput;
@property (nonatomic, strong) AVCaptureMetadataOutput *metadataOutput;
@property (nonatomic, strong) id runtimeErrorHandlingObserver;
@property (nonatomic, assign) NSInteger presetCamera;
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;
@property (nonatomic, assign) NSInteger videoTarget;
@property (nonatomic, assign) NSInteger orientation;
@property (nonatomic, assign) BOOL mirrorImage;
@property (nonatomic, strong) NSArray* barCodeTypes;
@property (nonatomic, strong) RCTPromiseResolveBlock videoResolve;
@property (nonatomic, strong) RCTPromiseRejectBlock videoReject;
@property (nonatomic, strong) RCTCameraOld *camera;


- (void)changeOrientation:(NSInteger)orientation;
- (AVCaptureDevice *)deviceWithMediaType:(NSString *)mediaType preferringPosition:(AVCaptureDevicePosition)position;
- (void)capture:(NSDictionary*)options resolve:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject;
- (void)getFOV:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject;
- (void)hasFlash:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject;
- (void)initializeCaptureSessionInput:(NSString*)type;
- (void)stopCapture;
- (void)startSession;
- (void)stopSession;
- (void)focusAtThePoint:(CGPoint) atPoint;
- (void)zoom:(CGFloat)velocity reactTag:(NSNumber *)reactTag;


@end
