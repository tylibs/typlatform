// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#ifndef TINY_COMMON_UTILS_CODE_UTILS_HPP_
#define TINY_COMMON_UTILS_CODE_UTILS_HPP_

#include <tiny/error.h>
#include <tiny/platform/toolchain.h>

#include "arg_macros.hpp"

/**
 * Calculates the number of elements in an array.
 *
 * @param[in] aArray  Name of the array variable.
 *
 * @returns Number of elements in the array.
 */
#define TINY_ARRAY_LENGTH(aArray) (sizeof(aArray) / sizeof(aArray[0]))

/**
 * Returns a pointer to end of a given array (pointing to the past-the-end element).
 *
 * Note that the past-the-end element is a theoretical element that would follow the last element in the array. It does
 * not point to an actual element in array, and thus should not be dereferenced.
 *
 * @param[in]    Name of the array variable
 *
 * @returns Pointer to the past-the-end element.
 */
#define TINY_ARRAY_END(aArray) (&aArray[TINY_ARRAY_LENGTH(aArray)])

/**
 * Returns a pointer aligned by @p aAlignment.
 *
 * @param[in] aPointer      A pointer to contiguous space.
 * @param[in] aAlignment    The desired alignment.
 *
 * @returns The aligned pointer.
 */
#define TINY_ALIGN(aPointer, aAlignment) \
    ((void *)(((uintptr_t)(aPointer) + (aAlignment) - 1UL) & ~((uintptr_t)(aAlignment) - 1UL)))

// Calculates the aligned variable size.
#define TINY_ALIGNED_VAR_SIZE(size, align_type) (((size) + (sizeof(align_type) - 1)) / sizeof(align_type))

// Allocate the structure using "raw" storage.
#define TINY_DEFINE_ALIGNED_VAR(name, size, align_type) \
    align_type name[(((size) + (sizeof(align_type) - 1)) / sizeof(align_type))]

/**
 * Returns the smaller of @p a and @p b.
 */
#define TINY_MIN(a, b) ((b) < (a) ? (b) : (a))

/**
 * Returns the greater of @p a and @p b.
 */
#define TINY_MAX(a, b) ((a) < (b) ? (b) : (a))

/**
 * Checks for the specified status, which is expected to commonly be successful, and branches to the local
 * label 'exit' if the status is unsuccessful.
 *
 * @param[in]  aStatus     A scalar status to be evaluated against zero (0).
 */
#define SuccessOrExit(aStatus) \
    do                         \
    {                          \
        if ((aStatus) != 0)    \
        {                      \
            goto exit;         \
        }                      \
    } while (false)

/**
 * Checks for the specified condition, which is expected to commonly be true, and both executes @a ... and
 * branches to the local label 'exit' if the condition is false.
 *
 * @param[in]  aCondition  A Boolean expression to be evaluated.
 * @param[in]  aAction     An optional expression or block to execute when the assertion fails.
 */
#define VerifyOrExit(...)                   \
    do                                      \
    {                                       \
        if (!(TINY_FIRST_ARG(__VA_ARGS__))) \
        {                                   \
            TINY_SECOND_ARG(__VA_ARGS__);   \
            goto exit;                      \
        }                                   \
    } while (false)

/**
 * Unconditionally executes @a ... and branches to the local label 'exit'.
 *
 * @note The use of this interface implies neither success nor failure for the overall exit status of the enclosing
 *       function body.
 *
 * @param[in]  ...         An optional expression or block to execute when the assertion fails.
 */
#define ExitNow(...) \
    do               \
    {                \
        __VA_ARGS__; \
        goto exit;   \
    } while (false)

/*
 * Executes the `statement` and ignores the return value.
 *
 * This is primarily used to indicate the intention of developer that the return value of a function/method can be
 * safely ignored.
 *
 * @param[in]  aStatement  The function/method to execute.
 */
#define IgnoreReturnValue(aStatement) \
    do                                \
    {                                 \
        if (aStatement)               \
        {                             \
        }                             \
    } while (false)

/**
 * Ignores an error explicitly.
 *
 * This is primarily used to indicate the intention of developer that
 * the error can be safely ignored or there is guaranteed to be no error.
 *
 * @param[in]  aError  The error to be ignored.
 */
static inline void IgnoreError(tinyError aError)
{
    TINY_UNUSED_VARIABLE(aError);
}

#endif // TINY_COMMON_UTILS_CODE_UTILS_HPP_
