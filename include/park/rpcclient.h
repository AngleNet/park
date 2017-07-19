// Copyright 2017 The Park Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found
// in the LICNESE file.

#ifndef PARK_INCLUDE_RPCCLIENT_H_
#define PARK_INCLUDE_RPCCLIENT_H_

#include <vector>
#include "park/function.h"
#include "park/mode.h"
#include "park/network.h"
#include "park/parameter.h"
#include "park/status.h"

namespace park{

class RPCClient{
    public:
        //Create a client and initiate the network module.
        RPCClient(Network *network);
        Status registerRPC(Function* func, ServiceMode mode);
        // Call RPC synchronously.
        Status callRPC(Function* func, std::vector<Parameter*> params, Parameter* retVal);
        // Call RPC asynchronously.
        Status submitRPC(Function* func, std::vector<Parameter*> params, Parameter* retVal, 
                         CallBack* call, CallBack* timeoutCallBack, int timeout);
        ~RPCClient();
    private:
        RPCClient(const RPCClient& client){};
        RPCClient& operator=(const RPCClient& client){};
};

} // namespace park
#endif // PARK_INCLUDE_RPCCLIENT_H_