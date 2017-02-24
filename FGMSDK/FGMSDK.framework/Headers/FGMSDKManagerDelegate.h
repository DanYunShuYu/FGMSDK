//
//  FGMSDKManager.h
//  FGSDKDemo
//
//  Created by laiwan on 16/4/28.
//  Copyright © 2016年 laiwan. All rights reserved.
//

#ifndef FGMSDKMANAGERDELEGATE_H
#define FGMSDKMANAGERDELEGATE_H

#include <iostream>
#include <string>
#include <map>
#include "FGAssistantHeader.h"
#include "FGTypeDefHeader.h"


using namespace std;


class FGMSDKManagerDelegate{
    
public:

    //自动登录接口。三个参数为渠道优先级
     void login(SDKChannelName firstChannel,SDKChannelName secondChannel,SDKChannelName thirdChannel);
    //测试接口。三个参数为渠道优先级
     void loginByTest(SDKChannelName firstChannel,SDKChannelName secondChannel,SDKChannelName thirdChannel);
     void logout();
     void bindingAccount(SDKChannelName channelName);
     void switchAccount(SDKChannelName channelName);
    
    //新增接口，用来区分登录与切换。token失效时需要展示三个渠道的登录界面，并调用该方法
     void loginAccount(SDKChannelName channelName);
    
    //新增接口，注册一个游客账号并登陆。
    void guestLogin();
    
    //购买接口。productID商品名   transmissionParameter透传参数
     void purchaseWithProductID(string productID,string transmissionParameter,string price);
    
    
     //常用事件埋点。
    void logEventWithParameters(FGSDKLogEventName eventName,map<string,string>passMap);
    
    //自定义事件埋点
    void logEventWithParametersCustom(string eventName,float value,map<string,string>passMap);
    
    //设置游戏语言。保留功能
    void setPreferredLanguage(FGPreferredLanguage language);
    
    //加载客服工单
    void loadFAQ();

    //分享到facebook接口
    void share(string title,string description,string imageURL,string contentURL);
    
    //邀请facebook好友接口
    void invite(string appLinkURL,string appInvitePreviewImageURL);
    
    //给facebook好友送礼接口
    void gift();
    
    
    
    
    
    //暂时没啥用
    void getUserInfo();
    //获取套餐信息。暂时没啥用
    void getProductList();
    
    
    

    
   
    
    /**
     
      以下是回调函数
     
     **/
    //得到登录或者切换账号结果后被调用
    virtual void getLoginOrSwitchResult(loginOrSwitchResult res);
    //得到内购结果后被调用
    virtual void getPurchaseResult(purchaseResult res);
    //得到绑定结果后被调用
    virtual void getBindingResult(bindingResult res);
    //得到切换账号结果后被调用
  //  virtual void getSwitchAccountResult(switchResult res);
    //获取当前用户所有信息
    virtual void getUserInfoResult(userInfo res);
    
    virtual void getProductListResult(productListResult res);
    
    virtual void getLogoutResult(logoutResult res);
    
    virtual void getShareInviteGiftResult(shareInviteGiftResult res);
    
private:
   // FGMSDKManagerDelegate(){}
   // static const FGMSDKManagerDelegate *m_Instance;
    
};

#endif
