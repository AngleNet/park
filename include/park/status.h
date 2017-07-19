// Copyright 2017 The Park Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file.

#ifndef PARK_INCLUDE_STATUS_H_
#define PARK_INCLUDE_STATUS_H_

namespace park{

enum class Status: int{
    // Everything went well.
    kSuccess = 0,

    // Valid values are in [kSuccess, kNumStatus)
    kNumStatus,  
};

const char* StatusToCString(Status status) noexcept;

} // namespace park

#endif // PARK_INCLUDE_STATUS_H_