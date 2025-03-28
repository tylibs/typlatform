// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file includes functions for debugging.
 */

#ifndef DEBUG_HPP_
#define DEBUG_HPP_

#include "ty/ty-core-config.h"

#include <ctype.h>
#include <stdio.h>

#if TY_CONFIG_ASSERT_ENABLE

#if TY_CONFIG_PLATFORM_ASSERT_MANAGEMENT

#include <openthread/platform/misc.h>

/**
 * Allow the build system to provide a custom file name.
 */
#ifndef FILE_NAME
#define FILE_NAME __FILE__
#endif

#define TY_ASSERT(cond)                            \
    do                                             \
    {                                              \
        if (!(cond))                               \
        {                                          \
            tyPlatAssertFail(FILE_NAME, __LINE__); \
            while (1)                              \
            {                                      \
            }                                      \
        }                                          \
    } while (0)

#elif defined(__APPLE__) || defined(__linux__)

#include <assert.h>

#define TY_ASSERT(cond) assert(cond)

#else // TY_CONFIG_PLATFORM_ASSERT_MANAGEMENT

#define TY_ASSERT(cond) \
    do                  \
    {                   \
        if (!(cond))    \
        {               \
            while (1)   \
            {           \
            }           \
        }               \
    } while (0)

#endif // TY_CONFIG_PLATFORM_ASSERT_MANAGEMENT

#else // TY_CONFIG_ASSERT_ENABLE

#define TY_ASSERT(cond)

#endif // TY_CONFIG_ASSERT_ENABLE

/**
 * Checks a given status (which is expected to be successful) against zero (0) which indicates success,
 * and `TY_ASSERT()` if it is not.
 *
 * @param[in]  aStatus     A scalar status to be evaluated against zero (0).
 */
#define SuccessOrAssert(aStatus) \
    do                           \
    {                            \
        if ((aStatus) != 0)      \
        {                        \
            TY_ASSERT(false);    \
        }                        \
    } while (false)

/**
 * @def AssertPointerIsNotNull
 *
 * Asserts that a given pointer (API input parameter) is not `nullptr`. This macro checks the pointer only
 * when `TY_CONFIG_ASSERT_CHECK_API_POINTER_PARAM_FOR_NULL` is enabled. Otherwise it is an empty macro.
 *
 * @param[in]  aPointer   The pointer variable (API input parameter) to check.
 */
#if TY_CONFIG_ASSERT_CHECK_API_POINTER_PARAM_FOR_NULL
#define AssertPointerIsNotNull(aPointer) TY_ASSERT((aPointer) != nullptr)
#else
#define AssertPointerIsNotNull(aPointer)
#endif

#endif // DEBUG_HPP_
