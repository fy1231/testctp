//以下是mduserhandle.h文件

#include "ThostFtdcMdApi.h"

#include <stdio.h>
 

class CMduserHandler : public CThostFtdcMdSpi

{

private:

  CThostFtdcMdApi *m_mdApi;

 

public:

  void connect()

  {

//创建并初始化API

      m_mdApi = CThostFtdcMdApi::CreateFtdcMdApi(".//flow_md/", true, true);

      m_mdApi->RegisterSpi(this);

      m_mdApi->RegisterFront("tcp://180.168.146.187:10131");

      m_mdApi->Init();

  }

 

//登陆

  void login()

  {

      CThostFtdcReqUserLoginField t = {0};

      while (m_mdApi->ReqUserLogin(&t, 1)!=0) ;

  }

 

// 订阅行情

  void subscribe()

  {

      char **ppInstrument=new char * [50];

      ppInstrument[0] = "i2201";

      while (m_mdApi->SubscribeMarketData(ppInstrument, 1)!=0) ;

  }

 

  //接收行情

  void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)

  {

          printf("OnRtnDepthMarketData\n");

  }

};
