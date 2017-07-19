// Copyright 2017 The Park Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file.

#ifndef PARK_INCLUDE_NETWORK_H_
#define PARK_INCLUDE_NETWORK_H

#include <string>
#include "park/status.h"

namespace park{

class Adaptor{
public:
    virtual Status send(Message *m) = 0;
    virtual Status receive(Message *m) = 0;
};


class Network{
public:
    Network();
    Network(Adaptor *adp);
private:
    Network(const Network& n) = delete;
    Network& operator=(const Network& n) = delete;
    Adaptor *adaptor;
};

} // namespace park

#endif // PARK_INCLUDE_NETWORK_H_