/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "libbacktrace"

#include <backtrace/backtrace.h>

#include "Backtrace.h"

class StubImpl : public BacktraceImpl {
public:
  StubImpl() { };
  virtual ~StubImpl() { };

  virtual bool Unwind(size_t) { assert(0); }

  virtual std::string GetFunctionNameRaw(uintptr_t, uintptr_t*) { return ""; }
};

//-------------------------------------------------------------------------
// C++ object creation functions.
//-------------------------------------------------------------------------
Backtrace* CreateCurrentObj(backtrace_map_info_t* map_info) {
  return new BacktraceCurrent(new StubImpl(), map_info);
}

Backtrace* CreatePtraceObj(pid_t pid, pid_t tid, backtrace_map_info_t* map_info) {
  return new BacktracePtrace(new StubImpl(), pid, tid, map_info);
}

Backtrace* CreateThreadObj(pid_t tid, backtrace_map_info_t* map_info) {
  StubImpl* stub = new StubImpl();
  return new BacktraceThread(stub, stub, tid, map_info);
}
