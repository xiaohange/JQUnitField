//
//  MyViewController.m
//  JQUnitFieldDemo
//
//  Created by 韩俊强 on 2017/5/19.
//  Copyright © 2017年 HaRi. All rights reserved.
//

#import "MyViewController.h"
#import "JQUnitField.h"

@interface MyViewController ()<JQUnitFieldDelegate>

@property (nonatomic, strong) JQUnitField *unitField;

@end

@implementation MyViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.title = @"纯代码";
    
    _unitField = [[JQUnitField alloc]initWithFrame:CGRectMake(50, 100, [UIScreen mainScreen].bounds.size.width-100, 40)];
    _unitField.inputUnitCount = 6;
    _unitField.delegate = self;
    _unitField.secureTextEntry = YES; // 密文
    
   // 检测数据变化
   [_unitField addTarget:self action:@selector(unitFieldEditingChanged:) forControlEvents:UIControlEventEditingChanged];
    
    [self.view addSubview:_unitField];
}

// 检测数据变化
- (void)unitFieldEditingChanged:(JQUnitField *)sender
{
    NSLog(@"%@", sender.text); // 我们想要的数据
}

#pragma Mark --- JQUnitFieldDelegate ---
- (BOOL)unitField:(JQUnitField *)uniField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string
{
    return YES;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view.window endEditing:YES];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
