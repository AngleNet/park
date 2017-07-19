// Copyright 2017 The Park Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file.

#ifndef PARK_COMMON_TCPADAPTOR_H_
#define PARK_COMMON_TCPADAPTOR_H_

#include "park/network.h"
#include <string>

namespace park{

typedef struct {
    std::string addr,
    unsigned port
}NetAddress;

class TCPAdaptor: public Adaptor{
public:
    TCPAdaptor(std::string name);
    TCPAdaptor(std::string name, NetAddress *local)
    Status connect(NetAddress *remote);
    Status accept();
    Status send(Message *m) override;
    Status receive(Message *m) override;
    ~TCPAdaptor();
private:
    NetAddress *locl;
    NetAddress *remote;
    Thread *sender;
    Thread *receiver;
};
} // namespace park

#endif // PARK_COMMON_TCPADAPTOR_H_