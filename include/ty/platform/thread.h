// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   This file includes platform abstractions for threadellaneous behaviors.
 */

#ifndef TY_PLATFORM_THREAD_H_
#define TY_PLATFORM_THREAD_H_

#include <stdint.h>

#include <ty/instance.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup plat-thread
 *
 * @brief
 *   This module includes platform abstractions for thread behaviors.
 *
 * @{
 */

/**
 * Sleep for a given number of milliseconds.
 *
 * @param[in] aSleepMs  The number of milliseconds to sleep.
 */
void tyPlatDelay(uint32_t aSleepMs);

/**
 * @}
 */

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TY_PLATFORM_THREAD_H_
