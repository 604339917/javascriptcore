#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIKitDefines.h>

@import UIKit;
@import JavaScriptCore;

@protocol JSBUIPrintFormatter;

@protocol JSBUIMarkupTextPrintFormatter <JSExport, JSBUIPrintFormatter>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

@property (nonatomic, readonly, assign) UIPrintPageRenderer *printPageRenderer;
@property (nonatomic, retain) UIFont *font;
@property (nonatomic, copy) NSString *markupText;
@property (nonatomic) NSTextAlignment textAlignment;
@property (nonatomic) CGFloat maximumContentWidth;
@property (nonatomic) CGFloat maximumContentHeight;
@property (nonatomic, retain) UIColor *color;
@property (nonatomic, copy) NSAttributedString *attributedText;
@property (nonatomic, readonly) UIView *view;
@property (nonatomic) UIEdgeInsets contentInsets;
@property (nonatomic, readonly) NSInteger pageCount;
@property (nonatomic, copy) NSString *text;
@property (nonatomic) NSInteger startPage;

- (id)initWithMarkupText:(NSString *)markupText;

#pragma clang diagnostic pop

@end
