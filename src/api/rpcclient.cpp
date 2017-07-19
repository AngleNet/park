// Copyright 2017 The Park Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file.

#include "park/rpcclient.h"

namespace park{

RPCClient::RPCClient(Network *network){
}
Status RPCClient::registerRPC(Function* func, ServiceMode mode){
    return SUCCESS;
}
Status RPCClient::callRPC(Function* func, vector<Parameter*>params, Parameter* retval){
    return SUCCESS;
}
Status RPCClient::submitRPC(Function* func, vector<Parameter*> params, Parameter* retVal, 
    CallBack* call, CallBack* timeoutCallBack, int timeout){
    return SUCCESS;
}
RPCClient::~RPCClient(){

}


} // namespace park