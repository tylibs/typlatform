// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file includes functions for debugging.
 */

#ifndef DEBUG_HPP_
#define DEBUG_HPP_

#include "tiny/tiny-core-config.h"

#include <ctype.h>
#include <stdio.h>

#if TINY_CONFIG_ASSERT_ENABLE

#if TINY_CONFIG_PLATFORM_ASSERT_MANAGEMENT

#include <openthread/platform/misc.h>

/**
 * Allow the build system to provide a custom file name.
 */
#ifndef FILE_NAME
#define FILE_NAME __FILE__
#endif

#define TINY_ASSERT(cond)                            \
    do                                               \
    {                                                \
        if (!(cond))                                 \
        {                                            \
            tinyPlatAssertFail(FILE_NAME, __LINE__); \
            while (1)                                \
            {                                        \
            }                                        \
        }                                            \
    } while (0)

#elif defined(__APPLE__) || defined(__linux__)

#include <assert.h>

#define TINY_ASSERT(cond) assert(cond)

#else // TINY_CONFIG_PLATFORM_ASSERT_MANAGEMENT

#define TINY_ASSERT(cond) \
    do                    \
    {                     \
        if (!(cond))      \
        {                 \
            while (1)     \
            {             \
            }             \
        }                 \
    } while (0)

#endif // TINY_CONFIG_PLATFORM_ASSERT_MANAGEMENT

#else // TINY_CONFIG_ASSERT_ENABLE

#define TINY_ASSERT(cond)

#endif // TINY_CONFIG_ASSERT_ENABLE

/**
 * Checks a given status (which is expected to be successful) against zero (0) which indicates success,
 * and `TINY_ASSERT()` if it is not.
 *
 * @param[in]  aStatus     A scalar status to be evaluated against zero (0).
 */
#define SuccessOrAssert(aStatus) \
    do                           \
    {                            \
        if ((aStatus) != 0)      \
        {                        \
            TINY_ASSERT(false);  \
        }                        \
    } while (false)

/**
 * @def AssertPointerIsNotNull
 *
 * Asserts that a given pointer (API input parameter) is not `nullptr`. This macro checks the pointer only
 * when `TINY_CONFIG_ASSERT_CHECK_API_POINTER_PARAM_FOR_NULL` is enabled. Otherwise it is an empty macro.
 *
 * @param[in]  aPointer   The pointer variable (API input parameter) to check.
 */
#if TINY_CONFIG_ASSERT_CHECK_API_POINTER_PARAM_FOR_NULL
#define AssertPointerIsNotNull(aPointer) TINY_ASSERT((aPointer) != nullptr)
#else
#define AssertPointerIsNotNull(aPointer)
#endif

#endif // DEBUG_HPP_
