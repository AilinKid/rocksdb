//  Copyright (c) 2011-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under both the GPLv2 (found in the
//  COPYING file in the root directory) and Apache 2.0 License
//  (found in the LICENSE.Apache file in the root directory).
//

#include <assert.h>
#include <sstream>
#include "port/port.h"
#include "util/perf_level_imp.h"

namespace rocksdb {

#if defined(IOS_CROSS_COMPILE)
PerfLevel perf_level = kEnableCount;
#else
__thread PerfLevel perf_level = kEnableCount;
#endif

void SetPerfLevel(PerfLevel level) {
  assert(level > kUninitialized);
  assert(level < kOutOfBounds);
  perf_level = level;
}

PerfLevel GetPerfLevel() {
  return perf_level;
}

}  // namespace rocksdb
