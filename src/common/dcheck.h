// Copyright 2017 The Park Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found 
// in the LICENSE file.

#ifndef PARK_COMMON_DCHECK_H_
#define PARK_COMMON_DCHECK_H_

#include <cassert>

#define DCHCECK(condition) assert(condition)

// Convenient wrapper over DCHECK
#define DCHECK_EQ(a, b) DCHECK((a) == (b))
// Convenient wrapper over DCHECK
#define DCHECK_NE(a, b) DCHECK((a) != (b))
// Convenient wrapper over DCHECK
#define DCHECK_GT(a, b) DCHECK((a) > (b))
// Convenient wrapper over DCHECK
#define DCHECK_LT(a, b) DCHECK((a) < (b))
// Convenient wrapper over DCHECK
#define DCHECK_GE(a, b) DCHECK((a) >= (b))
// Convenient wrapper over DCHECK
#define DCHECK_LE(a, b) DCHECK((a) <= (b))

#endif // PARK_COMMON_DCHECK_H_