// Copyright 2017 The Park Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file.

#include "park/status.h"

namespace park{

const char* StatusToCString(Status status) noexcept{
    switch(status){
    case Status::kSuccess:
        return "Success";
    case Status::kNumStatus:
        break;
    }
    DCHECK(false);
    return "Unknown Status";
}

} // namespace park