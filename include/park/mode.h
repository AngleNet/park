// Copyright 2017 The Park Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be 
// found in the LICENSE file.

#ifndef PARK_INCLUDE_MODE_H_
#define PARK_INCLUDE_MODE_H_ 

namespace park{

enum ServiceMode{
    AT_LEAST_ONCE = 0,
    AT_MOST_ONCE = 1,
    EXACTLY_ONCE = 2,
    NUM_MODES = 3,
};

} // namespace park

#endif // PARK_INCLUDE_MODE_H_