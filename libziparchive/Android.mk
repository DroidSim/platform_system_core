#
# Copyright (C) 2013 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

include external/stlport/libstlport.mk
LOCAL_CPP_EXTENSION := .cc

LOCAL_SRC_FILES := \
	zip_archive.h \
	zip_archive.cc

LOCAL_STATIC_LIBRARIES := libz
LOCAL_MODULE:= libziparchive

LOCAL_C_INCLUDES += external/zlib

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := ziparchive-tests
LOCAL_CPP_EXTENSION := .cc
LOCAL_CFLAGS += \
    -DGTEST_OS_LINUX_ANDROID \
    -DGTEST_HAS_STD_STRING
LOCAL_SRC_FILES := zip_archive_test.cc
LOCAL_LDFLAGS := -llog
LOCAL_STATIC_LIBRARIES := libziparchive libz libgtest libgtest_main
include $(BUILD_NATIVE_TEST)
