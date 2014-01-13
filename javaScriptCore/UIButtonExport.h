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
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state;
@end
