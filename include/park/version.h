// Copyright 2017 The Park Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file.

#ifndef PARK_INCLUDE_VERSION_H_
#define PARK_INCLUDE_VERSION_H_

namespace park{

// API major version number. Incremented for backward-incompatible API changes.
extern constexpr const unsigned VersionMajor = 0;
// API minor version number. Incremented for backward-compatible API changes.
extern constexpr const unsigned VersionMinor = 1;
// API patch version number. Incremented for bugfixes.
extern constexpr const unsigned VersionPatch = 0;

} // namespace park

#endif // PARK_INCLUDE_VERSION_H_