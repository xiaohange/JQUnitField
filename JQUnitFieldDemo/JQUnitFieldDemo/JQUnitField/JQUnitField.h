//
//  JQUnitField.h
//  JQUnitField
//
//  Created by 韩俊强 on 16/11/22.
//  Copyright © 2016年 韩俊强. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef NSFoundationVersionNumber_iOS_9_x_Max
    UIKIT_EXTERN NSNotificationName const JQUnitFieldDidBecomeFirstResponderNotification;
    UIKIT_EXTERN NSNotificationName const JQUnitFieldDidResignFirstResponderNotification;
#else
    UIKIT_EXTERN NSString *const JQUnitFieldDidBecomeFirstResponderNotification;
    UIKIT_EXTERN NSString *const JQUnitFieldDidResignFirstResponderNotification;
#endif

typedef NS_ENUM(NSUInteger, JQKeyboardType) {
    JQKeyboardTypeNumberPad,   // 纯数字键盘
    JQKeyboardTypeASCIICapable // ASCII 字符键盘
};

@protocol JQUnitFieldDelegate;

IB_DESIGNABLE

@interface JQUnitField : UIControl

@property (nullable, nonatomic, weak) id<JQUnitFieldDelegate> delegate;

/** 保留的用户输入的字符串 **/
@property (nullable, nonatomic, copy, readonly) NSString *text;

/** 密文输入,默认值为 NO. */
@property (nonatomic, assign, getter=isSecureTextEntry) IBInspectable BOOL secureTextEntry;

#if TARGET_INTERFACE_BUILDER

/** 目前允许的输入单元个数区间控制在 1 ~ 9 个,超过该范围都将被忽略。 */
@property (nonatomic, assign) IBInspectable NSUInteger inputUnitCount;
#else
@property (nonatomic, assign, readonly) NSUInteger inputUnitCount;
#endif

#if TARGET_INTERFACE_BUILDER
@property (nonatomic, assign) IBInspectable NSInteger defaultKeyboardType;
@property (nonatomic, assign) IBInspectable NSInteger defaultReturnKeyType;
#else
@property (nonatomic, assign) JQKeyboardType defaultKeyboardType;  // 默认为JQKeyboardTypeNumberPad。
@property (nonatomic, assign) UIReturnKeyType defaultReturnKeyType;// 默认为 UIReturnKeyDone。
#endif


/** 每个 Unit 之间的距离，默认为 0
    ┌┈┈┈┬┈┈┈┬┈┈┈┬┈┈┈┐
    ┆ 1 ┆ 2 ┆ 3 ┆ 4 ┆       unitSpace is 0.
    └┈┈┈┴┈┈┈┴┈┈┈┴┈┈┈┘
    ┌┈┈┈┐┌┈┈┈┐┌┈┈┈┐┌┈┈┈┐
    ┆ 1 ┆┆ 2 ┆┆ 3 ┆┆ 4 ┆    unitSpace is 6
    └┈┈┈┘└┈┈┈┘└┈┈┈┘└┈┈┈┘    
 */
@property (nonatomic, assign) IBInspectable CGFloat unitSpace;

// 设置边框圆角
@property (nonatomic, assign) IBInspectable CGFloat borderRadius;

// 设置边框宽度，默认为 1。
@property (nonatomic, assign) IBInspectable CGFloat borderWidth;

// 设置文本字体
@property (nonatomic, strong) IBInspectable UIFont *textFont;

// 设置文本颜色，默认为黑色。
@property (null_resettable, nonatomic, strong) IBInspectable UIColor *textColor;

@property (null_resettable, nonatomic, strong) IBInspectable UIColor *tintColor;

/**
 如果需要完成一个 unit 输入后显示地指定已完成的 unit 颜色，可以设置该属性。默认为 nil。
 注意：该属性仅在`unitSpace`属性值大于 2 时有效。在连续模式下，不适合颜色跟踪。可以考虑使用`cursorColor`替代
 */
@property (nullable, nonatomic, strong) IBInspectable UIColor *trackTintColor;

// 用于提示输入的焦点所在位置，设置该值后会产生一个光标闪烁动画，如果设置为空，则不生成光标动画。
@property (nullable, nonatomic, strong) IBInspectable UIColor *cursorColor;

// 当输入完成后，是否需要自动取消第一响应者。默认为 NO。
@property (nonatomic, assign) IBInspectable BOOL autoResignFirstResponderWhenInputFinished;

- (instancetype)initWithInputUnitCount:(NSUInteger)count;

@end

@protocol JQUnitFieldDelegate <NSObject>

@optional

- (BOOL)unitField:(JQUnitField *)uniField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
