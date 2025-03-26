// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief Macros to abstract toolchain specific capabilities
 *
 * This file contains various macros to abstract compiler capabilities that
 * utilize toolchain specific attributes and/or pragmas.
 */

#ifndef TINY_INCLUDE_TOOLCHAIN_H_
#define TINY_INCLUDE_TOOLCHAIN_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// =========== TOOLCHAIN SELECTION : START ===========

#if defined(__GNUC__) || defined(__clang__) || defined(__CC_ARM) || defined(__TI_ARM__)

// https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html
// http://www.keil.com/support/man/docs/armcc/armcc_chr1359124973480.htm

#define TINY_TOOL_PACKED_BEGIN
#define TINY_TOOL_PACKED_FIELD __attribute__((packed))
#define TINY_TOOL_PACKED_END __attribute__((packed))
#define TINY_TOOL_WEAK __attribute__((weak))

#define TINY_TOOL_PRINTF_STYLE_FORMAT_ARG_CHECK(aFmtIndex, aStartIndex) \
    __attribute__((format(printf, aFmtIndex, aStartIndex)))

#elif defined(__ICCARM__) || defined(__ICC8051__)

// http://supp.iar.com/FilesPublic/UPDINFO/004916/arm/doc/EWARM_DevelopmentGuide.ENU.pdf

#include "intrinsics.h"

#define TINY_TOOL_PACKED_BEGIN __packed
#define TINY_TOOL_PACKED_FIELD
#define TINY_TOOL_PACKED_END
#define TINY_TOOL_WEAK __weak

#define TINY_TOOL_PRINTF_STYLE_FORMAT_ARG_CHECK(aFmtIndex, aStartIndex)

#elif defined(__SDCC)

// Structures are packed by default in sdcc, as it primarily targets 8-bit MCUs.

#define TINY_TOOL_PACKED_BEGIN
#define TINY_TOOL_PACKED_FIELD
#define TINY_TOOL_PACKED_END
#define TINY_TOOL_WEAK

#define TINY_TOOL_PRINTF_STYLE_FORMAT_ARG_CHECK(aFmtIndex, aStartIndex)

#else

#error "Error: No valid Toolchain specified"

// Symbols for Doxygen

#define TINY_TOOL_PACKED_BEGIN
#define TINY_TOOL_PACKED_FIELD
#define TINY_TOOL_PACKED_END
#define TINY_TOOL_WEAK

#define TINY_TOOL_PRINTF_STYLE_FORMAT_ARG_CHECK(aFmtIndex, aStartIndex)

#endif

/**
 * @def TINY_UNUSED_VARIABLE
 *
 * Suppress unused variable warning in specific toolchains.
 */

/**
 * @def TINY_UNREACHABLE_CODE
 *
 * Suppress Unreachable code warning in specific toolchains.
 */

#if defined(__ICCARM__)

#include <stddef.h>

#define TINY_UNUSED_VARIABLE(VARIABLE) \
    do                                 \
    {                                  \
        if (&VARIABLE == NULL)         \
        {                              \
        }                              \
    } while (false)

#define TINY_UNREACHABLE_CODE(CODE)                                                                  \
    _Pragma("diag_suppress=Pe111") _Pragma("diag_suppress=Pe128") CODE _Pragma("diag_default=Pe111") \
        _Pragma("diag_default=Pe128")

#elif defined(__CC_ARM)

#include <stddef.h>

#define TINY_UNUSED_VARIABLE(VARIABLE) \
    do                                 \
    {                                  \
        if (&VARIABLE == NULL)         \
        {                              \
        }                              \
    } while (false)

#define TINY_UNREACHABLE_CODE(CODE) CODE

#elif defined(__TI_ARM__)

#include <stddef.h>

#define TINY_UNUSED_VARIABLE(VARIABLE) \
    do                                 \
    {                                  \
        if (&VARIABLE == NULL)         \
        {                              \
        }                              \
    } while (false)

/*
 * #112-D statement is unreachable
 * #129-D loop is not reachable
 */
#define TINY_UNREACHABLE_CODE(CODE) \
    _Pragma("diag_push") _Pragma("diag_suppress 112") _Pragma("diag_suppress 129") CODE _Pragma("diag_pop")

#else

#define TINY_UNUSED_VARIABLE(VARIABLE) \
    do                                 \
    {                                  \
        (void)(VARIABLE);              \
    } while (false)

#define TINY_UNREACHABLE_CODE(CODE) CODE

#endif
/**
 * @def TINY_FALL_THROUGH
 *
 * Suppress fall through warning in specific compiler.
 */
#if defined(__cplusplus) && (__cplusplus >= 201703L)
#define TINY_FALL_THROUGH [[fallthrough]]
#elif defined(__clang__)
#define TINY_FALL_THROUGH [[clang::fallthrough]]
#elif defined(__GNUC__) && (__GNUC__ >= 7)
#define TINY_FALL_THROUGH __attribute__((fallthrough))
#else
#define TINY_FALL_THROUGH \
    do                    \
    {                     \
    } while (false) /* fallthrough */
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* TINY_INCLUDE_TOOLCHAIN_H_ */
