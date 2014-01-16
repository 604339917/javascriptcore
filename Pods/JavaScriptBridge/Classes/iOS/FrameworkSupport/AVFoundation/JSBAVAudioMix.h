#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CMBase.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMTimeRange.h>
#import <MediaToolbox/MTAudioProcessingTap.h>

@import AVFoundation;
@import JavaScriptCore;

@protocol JSBNSObject;

@protocol JSBAVAudioMix <JSExport, JSBNSObject>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

@property (nonatomic, readonly) CMPersistentTrackID trackID;
@property (nonatomic, copy, readonly) NSArray *inputParameters;
@property (nonatomic, copy, readonly) NSString *audioTimePitchAlgorithm;
@property (nonatomic, retain, readonly) __attribute__ ((NSObject)) MTAudioProcessingTapRef audioTapProcessor;

#pragma clang diagnostic pop

@end
