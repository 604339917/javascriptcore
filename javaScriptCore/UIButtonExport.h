//
//  UIButtonExport.h
//  javaScriptCore
//
//  Created by 紫空 on 14-1-13.
//  Copyright (c) 2014年 zikong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

@protocol UIButtonExport <JSExport>
@property(nonatomic, readonly, retain) UILabel *titleLabel;
@property(nonatomic, retain) UIColor *tintColor;
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state;
+ (id)buttonWithType:(UIButtonType)buttonType;
- (void)setBackgroundImage:(UIImage *)image forState:(UIControlState)state;
- (void)setImage:(UIImage *)image forState:(UIControlState)state;
- (void)setTitle:(NSString *)title forState:(UIControlState)state;
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;
- (void)removeTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;
@end