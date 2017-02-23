//
//  LWPlatformManager.h
//  LoginAndRegObserverMode
//
//  Created by laiwan on 16/4/12.
//  Copyright © 2016年 laiwan. All rights reserved.
//

#ifndef __cplus
#define __cplus


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FGAssistantHeader.h"




//#define LocalizedStringCustom(key) [[NSBundle bundleWithPath:[[[NSBundle mainBundle]pathForResource:@"FGMSDK" ofType:@"bundle"]stringByAppendingString:[NSString stringWithFormat:@"/%@.lproj",[[FGPlatformManager sharedInstance]getStringLanguage]]]] localizedStringForKey:key value:nil table:@"FGLocalized"]

//#define LocalizedStringCustom(_key_) [[NSBundle bundleWithPath:[[NSBundle mainBundle]pathForResource:[NSString stringWithFormat:@"%@/FGMSDK.bundle/%@.lproj",[NSBundle bundleForClass:[self class]].bundlePath,[[FGPlatformManager sharedInstance]getStringLanguage]] ofType:nil]] localizedStringForKey:_key_ value:nil table:@"FGLocalized"]


/*
NSBundle *bundle = [NSBundle bundleForClass:[self class]];
UIImage *image = [UIImage imageNamed:@"me.bundle/0.jpg" inBundle:bundle compatibleWithTraitCollection:nil];
*/

//被观察单例对象的属性keyPath
#define OBSERVED_INFO_KEYPATH @"infoDictionary"

typedef NS_ENUM(NSInteger,applicationMode) {
    sandBox,     //沙盒测试模式。默认
    production,  //产品模式
};

//typedef NS_ENUM(NSInteger,FGInterfaceStyle) {
//    blue,     //深蓝色界面。默认
//    white,    //白色风格。美美适用
//};

//枚举类型，用来判定access_token的时效性
typedef NS_ENUM(NSInteger,eFlag_Type) {
    //本地存储的用户类型。用于登录时判定是否需要拉起登录界面
    
    //本地沙盒中没有用户信息（大部分是因为用户第一次玩这个游戏（需要注册新账号），也可能是用户卸载后重装了游戏（需要从钥匙链中找以前的用户信息））。
    eFlag_None = 0,
    
    //游客
    eFlag_Guset,
    
    //用户上次是从GC登录的
    eFlag_GC,
    
    //用户上次是从FB登录的
    eFlag_FB,
    
   //用户上次是从MB登录的
    eFlag_MB,
    
    
};

//以下两个枚举变量用来定义facebook点赞的风格
typedef NS_ENUM(NSUInteger, FGSDKLikeControlStyle)
{
    /*! Displays the button and the social sentence. */
    FGSDKLikeControlStyleStandard = 0,
    /*! Displays the button and a box that contains the like count. */
    FGSDKLikeControlStyleBoxCount,
};
typedef NS_ENUM(NSUInteger, FGSDKLikeControlHorizontalAlignment)
{
    /*! The subviews are left aligned. */
    FGSDKLikeControlHorizontalAlignmentLeft,
    /*! The subviews are center aligned. */
    FGSDKLikeControlHorizontalAlignmentCenter,
    /*! The subviews are right aligned. */
    FGSDKLikeControlHorizontalAlignmentRight,
};

typedef void(^loginSwitchCallback)(int errCode,NSDictionary *result);
typedef void(^bindingCallback)(int errCode,NSDictionary *result);

typedef void(^purchaseCallback)(int errCode,NSDictionary *result);
typedef void(^logoutCallback)(int errCode);
typedef void(^shareInviteGiftCallback)(int errCode);


@interface FGPlatformManager : NSObject
//被观察的字典属性
@property (copy,nonatomic) NSDictionary *infoDictionary;


@property (assign,nonatomic) BOOL gameCenterAuthenticated;
@property (assign,nonatomic) BOOL needRegisterNewAccount;
@property (assign,nonatomic) SDKChannelName firstChannelName;
@property (assign,nonatomic) SDKChannelName secondChannelName;
@property (assign,nonatomic) SDKChannelName thirdChannelName;
@property (retain,nonatomic) NSMutableArray *managerArray;
@property (copy,nonatomic) NSString *sdk_version;
@property (copy,nonatomic) NSString *app_id;
@property (copy,nonatomic) NSString *app_key;
@property (copy,nonatomic) NSString *opgame_id;
@property (copy,nonatomic) NSString *channel_id_gamecenter;
@property (copy,nonatomic) NSString *channel_id_facebook;
@property (copy,nonatomic) NSString *channel_id_mutantbox;


//广告标示。可以用来标记唯一设备
@property (copy,nonatomic) NSString *IDFA;


@property (copy,nonatomic) NSString *apple_id;
@property (copy,nonatomic) NSString *appsflyer_dev_key;

@property (copy,nonatomic) NSString *model;
@property (copy,nonatomic) NSString *device_type;




//设置模式：沙箱或者产品，重要属性。默认sandBox
@property (assign,nonatomic) applicationMode mode;

//设置是否启用，SDK内置浮动提示框。默认NO（不启用）
@property (assign,nonatomic) BOOL needFloatAlert;

//是否启用facebook事件埋点,默认关闭
@property (assign,nonatomic) BOOL needFacebookEvent;
//是否启用appsflyer广告埋点，默认关闭
@property (assign,nonatomic) BOOL needAppsflyerEvent;
//是否启用Google广告埋点，默认关闭
@property (assign,nonatomic) BOOL needGoogleEvent;

//是否启用Firebase广告埋点，默认关闭
@property (assign,nonatomic) BOOL needFirebaseEvent;

//设置是否启用自定义网页缓存。默认不启用
@property (assign,nonatomic) BOOL useCustomCache;


//设置mutantbox相关界面的风格。
//@property (assign,nonatomic) FGInterfaceStyle style;


@property (copy,nonatomic) NSDictionary *launchOptions;

//SDK当前的语言设置。枚举类型。可以由与用户自行设置。
@property (assign,nonatomic) FGPreferredLanguage currentLanguage;
//SDK当前的语言设置。字符串类型。依赖于currentLanguage属性，不允许应用自行设置。
@property (assign,nonatomic) NSString *language;




//分享到instagram时使用
@property (nonatomic,retain) UIDocumentInteractionController *documentController;



//block属性
@property (copy,nonatomic) loginSwitchCallback loginSwitchResult;
@property (copy,nonatomic) bindingCallback bindResult;
@property (copy,nonatomic) logoutCallback logoutResult;
@property (copy,nonatomic) purchaseCallback purchaseResult;
@property (copy,nonatomic) shareInviteGiftCallback shareInviteGiftResult;


/***
 
 以下这三个接口，不管是OC还是cocos2D均需要调用。
 
 ***/

//注册应用。注册应用时将会顺便初始化本类的单例对象
+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
+ (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;


//实例化单例对象。所有的实例方法均应该由这个单例对象调用，开发者不能再创建别的对象。
+ (instancetype)sharedInstance;



/***
 
 以下为OC专用接口
 
 ***/
//主登录接口。调用此接口后游戏客户端将获得用户登录信息（openid、access_token以及用户类型：平台用户还是facebook、gamecenter用户等），并有自动登录功能。目前支持mutantbox、facebook、gamecenter用户登录；channelName是游戏首选登录渠道，可以选择gamecenter或者facebook。游戏应该在应用启动界面加载完毕后调用此方法以实现自动登录，或者因为网络原因或者服务器原因登录失败时重新调用此方法。有回调
- (void)userLoginWithFirstChannel:(SDKChannelName)firstChannel secondChannel:(SDKChannelName)secondChannel thirdChannel:(SDKChannelName)thirdChannel callback:(loginSwitchCallback)callback;

//测试专用。手动登录接口。将调出测试界面，但是不会删除本地用户信息。
- (void)userLoginByTestWithFirstChannel:(SDKChannelName)firstChannel secondChannel:(SDKChannelName)secondChannel thirdChannel:(SDKChannelName)thirdChannel;

//退出登录接口。删除本地用户信息，删除后当再次调用登录接口时将直接弹出登录界面。这个方法应该在用户注销或切换账号时（而非退出游戏时）调用。但是，gamecenter用户只能在手机设置中才能完全退出登录。facebook登录时，无法完全删除cookie。有回调
- (void)userLogoutWithCallback:(logoutCallback)callback;

//注册一个游客账号。当checkuser失败时，游戏需要展示4个登录渠道给玩家重新登录------游客，gamecenter，facebook，mutantbox
- (void)guestLoginWithCallback:(loginSwitchCallback)callback;

//绑定到某个渠道.SDK可以根据当前用户类型及绑定记录自动判断需要显示哪几个绑定按钮。如果某个渠道已被绑定过，用户应该将对应按钮禁用掉，以避免重复绑定给服务器带来额外负担。
- (void)bindingAccountTo:(SDKChannelName)channelName callback:(bindingCallback)callback;

//切换账号到某个渠道接口。有回调
- (void)switchAccountTo:(SDKChannelName)channelName callback:(loginSwitchCallback)callback;

//登录账号到某个渠道接口。有回调
- (void)loginAccountTo:(SDKChannelName)channelName callback:(loginSwitchCallback)callback;

//添加指定事件。事件类型为枚举变量，参数value和dictionary均为可选(对于购买事件，value为必选，dictionary的FGSDKAppEventParameterNameCurrency键值对必选)。其中value大于0时，表示将按照value值进行累计汇总，value为0时表示不设置此参数；dictionary不为空时，参数请参考FGSDKLogEventName枚举声明。无回调
+ (void)logEvent:(FGSDKLogEventName)eventName parameters:(NSDictionary *)dictionary;

//自定义事件接口，eventName为自定义事件名。无回调
+ (void)logCustomEvent:(NSString *)eventName value:(float)value parameters:(NSDictionary *)dictionary;

//设置游戏语言.如果游戏不支持应用内切换语言，用户不需要额外设置语言。无回调
- (void)setLanguageCustom:(FGPreferredLanguage)preferredLanguage;

//加载工单。无回调
- (void)loadFAQ;

//购买接口。字符串参数为productID，由游戏客户端向游戏服务器请求得到。有回调
- (void)purchaseWithProductID:(NSString *)productID transmissionPara:(NSString *)transmissionParameter price:(NSString *)price callback:(purchaseCallback)callback;


//分享到facebook接口。有回调
- (void)shareWithTitle:(NSString *)title description:(NSString *)description imageURL:(NSString *)imageURL contentURL:(NSString *)contentURL callback:(shareInviteGiftCallback)callback;

//邀请facebook好友接口。有回调
- (void)inviteWithAppLinkURL:(NSString *)appLinkURL appInvitePreviewImageURL:(NSString *)appInvitePreviewImageURL callback:(shareInviteGiftCallback)callback;


//给facebook好友送礼接口。有回调
- (void)giftWithCallback:(shareInviteGiftCallback)callback;

//分享一张图片到instagram
- (void)shareInstagramWithURLImage:(UIImage *)image;

//分享一张图片到Messenger
- (void)shareMessengerImage:(UIImage *)image;


//facebook点赞按钮相关
+ (UIView *)getFacebookLikeButton;
+ (void)setFacebookLikeButtonFrame:(CGRect)frame likeButton:(UIView *)likeButton;
+ (void)setFacebookLikeButtonCenter:(CGPoint)center likeButton:(UIView *)likeButton;
+ (void)setFacebookLikeObjectID:(NSString *)objectID likebutton:(UIView *)likeButton;
+ (void)setFacebookLikeButtonStyle:(FGSDKLikeControlStyle)style likeButton:(UIView *)likeButton;
+ (void)setFacebookLikeButtonHorizontalAlignment:(FGSDKLikeControlHorizontalAlignment)alignment likeButton:(UIView *)likeButton;


/*
 
 以下为SDK专用接口。
 
 */
//获取当前语言。只是为了配合宏命令使用。
- (NSString *)getStringLanguage;



@end
#endif
