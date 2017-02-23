//
//  AsistantHeader.h
//  LoginAndRegisterDemo
//
//  Created by laiwan on 16/4/9.
//  Copyright © 2016年 laiwan. All rights reserved.
//

#ifndef FGAssistantHeader_h
#define FGAssistantHeader_h



#if TARGET_IPHONE_SIMULATOR
#define SIMULATOR 1
#else
#define SIMULATOR 0
#endif

//#ifdef DEBUG_MODE
//#define LOG_CUSTOM(_format_,_argu_) NSLog(_format_,_argu_)
//#else
//#define LOG_CUSTOM(_format_,_argu_)
//#endif


//#define NSLog(format, ...) do{fprintf(stderr,"<%s : %d> %s\n",[[[NSString stringWithUTF8String:__FILE__]lastPathComponent]UTF8String],__LINE__, __func__);\
    (NSLog)((format), ##__VA_ARGS__); \
    fprintf(stderr,"\n ------------------\n/Hello QinZhenzhao!\\\n\\ my Macro Log ~   /\n ------------------\n            \\\n             \\   ^__^\n                 (OO)__________\n                 (__)\\          )\\/\\\n                     ||_______ _)\n                     ||       W |\n       Qzz           ww        ww\n");}while(0)


#define LOG_CUSTOM(_format_,...) if([FGPlatformManager sharedInstance].mode == sandBox){NSLog((_format_),##__VA_ARGS__);}


#define SAVE_TO_SANDBOX(_dic_)  [[NSUserDefaults standardUserDefaults]setObject:_dic_ forKey:@"userLocalInfoDic"];\
[[NSUserDefaults standardUserDefaults]synchronize]\


#define GET_SANDBOX_DIC [[NSUserDefaults standardUserDefaults]objectForKey:@"userLocalInfoDic"]


#define MAINTHREAD_ALERT(_alertStr_) if([FGPlatformManager sharedInstance].needFloatAlert){\
dispatch_async(dispatch_get_main_queue(), ^{[FGFloatAlertView floatAlertViewWithLayoutAndText:_alertStr_ color:nil completionHandler:nil];});}

typedef enum{
    NoChannel = 0,
    GameCenter,
    FaceBook,
    MutantBox
}SDKChannelName;

typedef enum{
    ///////////常用事件。以下事件由游戏负责埋点,无参数的，除了FGSDKAppEventNameActivatedApp外，均传空map.
    FGSDKAppEventNameActivatedApp = 0,   //应用启动事件。必须上报。无参数（传nil）。在AppDelegate的applicationDidBecomeActive：里面调用.                                       （世界大战，美美）
    
    FGSDKAppEventNameAchievedLevel,  //玩家达到特定等级事件。对应必选参数：键FGSDKAppEventParameterNameLevel，值为玩家等级（整数字符串）；可选参数：键FGSDKAppEventParameterNameScore，值为得分（整数字符串）                       （世界大战，美美）
    FGSDKAppEventNameCompletedTutorial,//完成教程事件（在强指引教程完成后埋点）。对应必选参数：键FGSDKAppEventParameterNameSuccess，值为字符串，“0”代表失败，“1”代表成功；键FGSDKAppEventParameterNameContentID,值为教程标识符（字符串）                   （世界大战,美美。美美对应事件：上方的接待结束，回到店铺时）。
    FGSDKAppEventNameUnlockedAchievement,//解锁成就事件。对应可选参数：FGSDKAppEventParameterNameDescription，值为描述性字符串                               （无）
    FGSDKAppEventNameLoginGame,  //登录游戏成功事件（在check user成功后埋点）。无参数    （世界大战，美美）
    FGSDKAppEventNameEnterGameInterface, //进入游戏主界面（载入界面结束，进入玩家可操作界面后埋点）。无参数。  //                                                                      （世界大战）
    FGSDKAppEventNameCreateNicknameSuccess, //玩家创建昵称成功。无参数。               （世界大战，美美）
    FGSDKAppEventNameCreateNicknameRandom, //玩家通过随机取名还是通过手动输入名称来取名（使用随机取名成功时上报，手动取名成功不上报）。无参数。                                              （世界大战，美美）
    FGSDKAppEventNameTutorialSkipButtonClicked, //昵称创建前前用户是否点击了跳过剧情按钮（点击第一次时上报，全程没有点击则不上报）。无参数。                                                  （世界大战）
    FGSDKAppEventNameTutorialLetsGoButtonNotClicked, //昵称创建前用户是否点击了任务界面中的“Let's go”，没有点击时上报，点击过至少一次则不上报。无参数。                                        （世界大战）
    FGSDKAppEventNameEnterFirstBattle,//在片头动画播放完毕，新玩家开始第一场战斗时上报。无参数。（世界大战）
    
    
 
    
    
    //////////以下事件由SDK负责埋点,游戏不需要处理！！！！///////
    //在SDK内部的mutantbox页面开始注册新账号
    FGSDKAppEventNameRegisterNewAccountOnPlatformStart,
    //在SDK内部的mutantbox页面注册新账号成功
    FGSDKAppEventNameRegisterNewAccountOnPlatformSuccess,
    //开始登陆平台。这个事件在客户端利用第三方渠道（获取不到时生成游客账号）向平台服务器请求玩家UID时上报
    FGSDKAppEventNameLoginOnPlatformStart,
    //登陆平台成功。
    FGSDKAppEventNameLoginOnPlatformSuccess,
    //在平台注册成功。将利用第三方渠道（或游客）生成一个新的UID，完成注册事件。对应可选参数：键FGSDKAppEventParameterNameRegistrationMethod,值为@“facebook”、@“gamecenter”、@“guest”之一
    FGSDKAppEventNameRegisterOnPlatformSuccess,
    // FGSDKAppEventNameInitiatedCheckout,//开始结账事件。对应可选参数：键FGSDKAppEventParameterNameContentType，@"product" 或 @"product_group"；FGSDKAppEventParameterNamePaymentInfoAvailable，值为int类型，0代表否，1代表是；FGSDKAppEventParameterNameNumItems，值为商品数量（int型）；FGSDKAppEventParameterNameCurrency，值为货币代号，采用ISO 4217 代码，例如：EUR、USD、JPY等;FGSDKAppEventParameterNameContentID,值为产品标识符；
    //支持valueToSum参数（购物车内商品总价）
    // FGSDKAppEventNamePurchased,//购买事件。对应参数：键FGSDKAppEventParameterNameContentType，值为商品名；FGSDKAppEventParameterNameCurrency（必选键值对），值为货币代号，采用ISO 4217 代码，例如：EUR、USD、JPY等;FGSDKAppEventParameterNameContentID,值为产品标识符；
    //支持valueToSum参数（购买单价）
    

    
    
    
     //////////以下事件为美美小店专用事件，由美美小店负责上报///////
    FGSDKAppEventNameFirstDialog,//对话开始事件。
    FGSDKAppEventNameServeCustomer,//接待顾客换装。
    FGSDKAppEventNameConfirmChoice,//试衣结束。
    FGSDKAppEventNameTapToMall,//玩家是否点击前往商城。
    FGSDKAppEventNameTapToContinue,//玩家是否继续游戏。
    FGSDKAppEventNameTapToPay,//玩家是否在商城完成购买。
    FGSDKAppEventNameBackToBoutiqueAndServeCustomer,//玩家购买完成是否返回接待顾客。
    //新增两个事件
    FGSDKAppEventNameChapterAchieved,//玩家到达各个章节
    FGSDKAppEventBacktoboutique,//上方的接待结束，回到店铺时

    //美美广告相关
    FGSDKAppEventNameNoADPurchased,//购买“去广告”套餐。1. 购买套餐的用户数以及次数（如果每个月都需要重新购买“去广告”，则每次购买都需要触发这个事件）    2.需要记录玩家的购买时间（精确到天？）
    FGSDKAppEventNameStartAD,//开始观看广告。1. 观看广告的用户数，以及次数     2. 开始观看广告的时间（时间统一转换为西八区）   3. 广告位类型
    FGSDKAppEventNameCutUpAD,//点击广告关闭按钮。1. 观看广告的用户数，以及次数     2. 广告位类型
    FGSDKAppEventNameTapAD,//点击广告。 1. 点击广告的用户数，以及次数      2. 广告位类型
    FGSDKAppEventNameRewardFromAD,//对话开始事件。1. 获得奖励的用户数，以及次数    2. 获得的游戏内道具的类型      3. 获得的游戏内道具的数量
   
}FGSDKLogEventName;


typedef enum {
    
       //FGChinese,
    FGArabic,   //阿拉伯语,ar
    FGCzech,    //捷克语,cs
    FGGerman,   //德语,de
    FGGreek,     //希腊语,el
    FGEnglish,  //英语，en
    FGFrench,    //法语,fr
    FGHungarian,  //匈牙利语,hu
    FGItalian,     //意大利语,it
    FGPolish,    //波兰语,pl
    FGPortuguese,//葡萄牙语,pt
    FGRomanian,   //罗马尼亚语,ro
    FGTurkish,     //土耳其语,tr
   
    
}FGPreferredLanguage;

#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

#define HORIZANTAL_MARGIN 0
#define VERTICAL_MARGIN 0

#endif /* AssistantHeader_h */
