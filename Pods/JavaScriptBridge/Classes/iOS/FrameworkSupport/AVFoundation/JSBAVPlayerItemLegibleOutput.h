#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CMTime.h>
#import <CoreVideo/CVPixelBuffer.h>

@import AVFoundation;
@import JavaScriptCore;

@protocol JSBAVPlayerItemOutput;

@protocol JSBAVPlayerItemLegibleOutput <JSExport, JSBAVPlayerItemOutput>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

@property (nonatomic, readwrite) NSTimeInterval advanceIntervalForDelegateInvocation;
@property (nonatomic, readonly, readonly) dispatch_queue_t delegateQueue;
@property (nonatomic, readonly, readonly) id delegate;
@property (nonatomic, readwrite) BOOL suppressesPlayerRendering;
@property (nonatomic, copy) NSString *textStylingResolution;

- (void)setDelegate:(id <AVPlayerItemLegibleOutputPushDelegate>)delegate queue:(dispatch_queue_t)delegateQueue;
- (id)initWithMediaSubtypesForNativeRepresentation:(NSArray *)subtypes;

#pragma clang diagnostic pop

@end
