//
//  MainViewController.m
//  javaScriptCore
//
//  Created by 紫空 on 14-1-13.
//  Copyright (c) 2014年 zikong. All rights reserved.
//

#import "MainViewController.h"
#import "objc/runtime.h"
#import "UIButtonExport.h"
#import <JavaScriptBridge/JavaScriptBridge.h>

@interface MainViewController ()

@end

@implementation MainViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	NSBundle *mainBundle = [NSBundle mainBundle];
    NSString *path = [mainBundle pathForResource:@"MainViewController_viewDidLoad" ofType:@"js"];
    NSString *script = [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
    
    JSContext *context = [JSBScriptingSupport globalContext];
    [context evaluateScript:script];
}

- (void)tap:(id)sender
{
    @autoreleasepool {
        JSContext *context = [[JSContext alloc] init];
        context[@"makeUIColor"] = ^(NSNumber *r, NSNumber *g, NSNumber *b){
            float red = [r floatValue];
            float green = [g floatValue];
            float blue = [b floatValue];
            return [UIColor colorWithRed:(red / 255.0)
                                   green:(green / 255.0)
                                    blue:(blue / 255.0)
                                   alpha:1];
        };
        
        NSString *path = [[NSBundle mainBundle]pathForResource:@"test"ofType:@"js"];
        NSString *testScript = [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
        context[@"button"] = (UIButton *)sender;
        [context evaluateScript:testScript];
    }
    
    @autoreleasepool {
        JSContext *context = [[JSContext alloc] init];
        context.exceptionHandler = ^(JSContext *con, JSValue *exception) {
            NSLog(@"%@", exception);
            con.exception = exception;
        };
        
        context[@"log"] = ^() {
            NSArray *args = [JSContext currentArguments];
            for (id obj in args) {
                NSLog(@"%@",obj);
            }
        };
        [context evaluateScript:@"log()"];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

@end
