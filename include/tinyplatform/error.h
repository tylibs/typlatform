// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *  This file defines the errors
 */

#ifndef TINYPLATFORM_ERROR_H_
#define TINYPLATFORM_ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Represents error codes
 */
typedef enum tbError
{
    /**
     * No error.
     */
    TI_ERROR_NONE = 0,

    /**
     * Operational failed.
     */
    TI_ERROR_SUBSCRIBER_COUNT_EXCEEDED = 1,

    /**
     * The number of defined errors.
     */
    TI_NUM_ERRORS,

    /**
     * Generic error (should not use).
     */
    TI_ERROR_GENERIC = 255,
} tbError;

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TINYPLATFORM_ERROR_H_
