//
//  ViewController.m
//  JQUnitFieldDemo
//
//  Created by 韩俊强 on 2017/5/18.
//  Copyright © 2017年 HaRi. All rights reserved.
//

#import "ViewController.h"
#import "JQUnitField.h"

@interface ViewController ()<JQUnitFieldDelegate>

@property (weak, nonatomic) IBOutlet JQUnitField *unitField;


@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];


    _unitField.delegate = self;
}

- (BOOL)unitField:(JQUnitField *)uniField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {
    return YES;
}

- (IBAction)unitFieldEditingChanged:(JQUnitField *)sender {
    NSLog(@"%@", sender.text);
}

- (IBAction)unitFieldEditingDidBegin:(id)sender {
    NSLog(@"%s", __FUNCTION__);
}

- (IBAction)unitFieldEditingDidEnd:(id)sender {
    NSLog(@"%s", __FUNCTION__);
}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view.window endEditing:YES];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
