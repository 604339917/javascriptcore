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
	class_addProtocol([UIButton class], @protocol(UIButtonExport));
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setTitle:@"Test Button" forState:UIControlStateNormal];
    [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    button.frame = CGRectMake(110, 50, 100, 50);
    [button addTarget:self action:@selector(tap:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
}

- (void)tap:(id)sender
{
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

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    
}

@end
