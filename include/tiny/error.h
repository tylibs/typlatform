// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *  This file defines the errors
 */

#ifndef TY_ERROR_H_
#define TY_ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Represents error codes
 */
typedef enum tinyError
{
    /**
     * No error.
     */
    TY_ERROR_NONE = 0,

    /**
     * Operational failed.
     */
    TY_ERROR_SUBSCRIBER_COUNT_EXCEEDED = 1,

    /**
     * Not found.
     */
    TY_ERROR_NOT_FOUND = 2,

    /**
     * No Buffers.
     */
    TY_ERROR_NO_BUFS = 3,

    /**
     * Invalid Args
     */
    TY_ERROR_INVALID_ARGS = 4,

    /**
     * Invalid Args
     */
    TY_ERROR_PARSE = 5,

    /**
     * Invalid Args
     */
    TY_ERROR_FAILED = 6,

    /**
     * The number of defined errors.
     */
    TY_NUM_ERRORS,

    /**
     * Generic error (should not use).
     */
    TY_ERROR_GENERIC = 255,
} tinyError;

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TY_ERROR_H_
