//
//  TypeDefHeader.h
//  MyGame
//
//  Created by laiwan on 16/5/11.
//
//

#ifndef FGTypeDefHeader_h
#define FGTypeDefHeader_h

#include <iostream>
#include <string>

using namespace std;


//登录时返回的数据
struct loginOrSwitchResult{
    //成功登录后，errmsg为“”。只有未成功登录时，errmsg才有值，为失败原因。
    // std::string errmsg;

    
    //错误码。为0时说明登录成功，否则失败
    int errCode;
      //以下字符串只有在成功登录后才有值。
    std::string uid;
    std::string token;
    std::string username;
    bool gamecenter;
    bool facebook;
    bool mutantbox;
    bool isLogin;
};

//获取套餐信息时返回数据
struct productListResult{
    int errCode;
    std::string list;
};

//购买时返回的数据
struct purchaseResult{
    int errCode;
    std::string order;
    //std::string errmsg;
    //std::string transactionState;
    //std::string receipt;
};

struct logoutResult{
    int errCode;
};

//绑定时返回的数据,同登录切换
struct bindingResult{
   
     int errCode;
    //以下字符串只有在成功登录后才有值。
    std::string uid;
    std::string token;
    std::string username;
    bool gamecenter;
    bool facebook;
    bool mutantbox;
};

//返回facebook相关的分享邀请送礼是否成功
struct shareInviteGiftResult{
    int errCode;
    //以下值用来区分是分享还是邀请还是送礼
    bool isShare;
    bool isInvite;
    bool isGift;
};


struct userInfo{
     int errCode;
   // std::string errmsg;
    std::string uid;
    std::string email;
    std::string username;
};


////以下为事件对应的参数列表（这些参数均供游戏内事件使用,并由游戏负责使用）

//玩家级别----对应事件FGSDKAppEventNameAchievedLevel，必选参数
const string FGSDKAppEventParameterNameLevel = "fg_level";
//得分----对应事件FGSDKAppEventNameAchievedLevel,可选参数
const string FGSDKAppEventParameterNameScore = "fg_score";

//内容----对应事件FGSDKAppEventNameCompletedTutorial，必选参数
const string FGSDKAppEventParameterNameContent = "fg_content";
//成功----对应事件FGSDKAppEventNameCompletedTutorial，必选参数
const string FGSDKAppEventParameterNameSuccess = "fg_success";

//说明或描述----对应事件FGSDKAppEventNameUnlockedAchievement，必选参数
const string FGSDKAppEventParameterNameDescription = "fg_description";



#endif /* TypeDefHeader_h */
