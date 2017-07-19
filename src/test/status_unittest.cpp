// Copyright 2017 The Park Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file.

#include "park/status.h"

#include <cstring>
#include <cstddef>
#include <unordered_set>

#include "gtest/gtest.h"    

namespace park{
    TEST(StatusTest, StatusToCString){
        std::unordered_set<const char *> values;
        for(size_t i = static_cast<size_t>(Status::kSuccess);
            i < static_cast<size_t>(Status::kNumStaus); ++i){
            const char *str = StatusToCString(static_cast<Status>(i));
            EXPECT_TRUE(std::strlen(str) > 0);
            EXPECT_TRUE(values.count(str) == 0);
            values.insert(str);
        }
    }
} // namespace park