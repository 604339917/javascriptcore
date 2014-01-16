#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <MediaPlayer/MediaPlayerDefines.h>
#import <MediaPlayer/MPMediaEntity.h>

@import MediaPlayer;
@import JavaScriptCore;

@protocol JSBMPMediaEntity;

@protocol JSBMPMediaItem <JSExport, JSBMPMediaEntity>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

@property (nonatomic, readonly) CGRect bounds;
@property (nonatomic, readonly) CGRect imageCropRect;

+ (NSString *)persistentIDPropertyForGroupingType:(MPMediaGrouping)groupingType;
+ (NSString *)titlePropertyForGroupingType:(MPMediaGrouping)groupingType;

#pragma clang diagnostic pop

@end
