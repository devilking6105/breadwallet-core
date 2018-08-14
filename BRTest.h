//
// BRTest.h
//
//  Created by Igor Guerrero on 8/7/2018
//  Copyright (c) 2018 Hodl Wallet INC.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
#ifndef BRTest_h
#define BRTest_h

#ifdef __cplusplus
extern "C" {
#endif

#if BITCOIN_TESTNET
#pragma message "Testnet Tests"
#else
#pragma message "Mainnet Tests (should not work)"
#endif

#define test_log(...) _test_log(__VA_ARGS__)
#define test_error_log(...) _test_error_log(__VA_ARGS__)

#if defined(TARGET_OS_MAC)
#include <Foundation/Foundation.h>
#define _test_log(...) NSLog(__VA_ARGS__)
#define _test_error_log(...) NSLog(__VA_ARGS__)
#elif defined(__ANDROID__)
#include <android/log.h>
#define _test_log(...) __android_log_print(ANDROID_LOG_INFO, "brcore", __VA_ARGS__)
#define _test_error_log(...) __android_log_print(ANDROID_LOG_ERROR, "brcore:error", __VA_ARGS__)
#else
#include <stdio.h>
#define _test_log(...) printf(__VA_ARGS__)
#define _test_error_log(...) printf(__VA_ARGS__)
#endif

#if BITCOIN_TESTNET
#define BR_CHAIN_PARAMS BRTestNetParams
#else
#define BR_CHAIN_PARAMS BRMainNetParams
#endif

#define SKIP_BIP38 1

int BRCoreTests();

#ifdef __cplusplus
}
#endif

#endif // BRTest_h
