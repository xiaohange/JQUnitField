# JQUnitField
JQUnitField：验证码输入框，自定义密码输入框，支持密文，支持框颜色，间隔，文本设置，闪烁光标移动，自定义键盘响应！只需要一个view就能实现哦！
### 效果如下
![](https://github.com/xiaohange/JQUnitField/blob/master/demo.gif?raw=true)
![](https://github.com/xiaohange/JQUnitField/blob/master/demo2.gif?raw=true)
## Instalation

Add the JQUnitField.h and JQUnitField.m source files to your project.

## Usage
##### Storyboard/XIB 或 纯代码两种方式，demo中是Storyboard，实现原理一样！
```
@property (nonatomic, strong) JQUnitField *unitField;
 
    _unitField = [[JQUnitField alloc]initWithFrame:CGRectMake(50, 100, [UIScreen mainScreen].bounds.size.width-100, 40)];
    
    _unitField.inputUnitCount = 6;    // 位数 1~9 
    _unitField.secureTextEntry = YES; // 密文 默认NO
    
    // ...... 还有很多自定义可以设置，这里不一一举例了
    _unitField.delegate = self;
    
   // 检测数据变化
   [_unitField addTarget:self action:@selector(unitFieldEditingChanged:) forControlEvents:UIControlEventEditingChanged];
    
    [self.view addSubview:_unitField];
    
    // 检测数据变化
- (void)unitFieldEditingChanged:(JQUnitField *)sender
{
    NSLog(@"%@", sender.text); // 我们想要的数据
}
    
```
##### JQUnitFieldDelegate 代理方法
```
#pragma Mark --- JQUnitFieldDelegate ---
- (BOOL)unitField:(JQUnitField *)uniField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string
{
    return YES;
}
```

##### 收回键盘
```
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view.window endEditing:YES];
}
```


## Other
[JQTumblrHud-高仿Tumblr App 加载指示器hud](https://github.com/xiaohange/JQTumblrHud)

[JQScrollNumberLabel：仿tumblr热度滚动数字条数](https://github.com/xiaohange/JQScrollNumberLabel)

[TumblrLikeAnimView-仿Tumblr点赞动画效果](https://github.com/xiaohange/TumblrLikeAnimView)

[JQMenuPopView-仿Tumblr弹出视图发音频、视频、图片、文字的视图](https://github.com/xiaohange/JQMenuPopView)

## Star
>iOS开发者交流群：446310206 喜欢就❤️❤️❤️star一下吧！你的支持是我更新的动力！ Love is every every every star! Your support is my renewed motivation!

## License

This code is distributed under the terms and conditions of the [MIT license](LICENSE). 