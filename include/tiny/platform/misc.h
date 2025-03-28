// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   This file includes platform abstractions for miscellaneous behaviors.
 */

#ifndef TY_PLATFORM_MISC_H_
#define TY_PLATFORM_MISC_H_

#include <stdint.h>

#include <tiny/instance.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup plat-misc
 *
 * @brief
 *   This module includes platform abstractions for miscellaneous behaviors.
 *
 * @{
 */

/**
 * Performs a software reset on the platform, if supported.
 *
 * @param[in] aInstance  The OpenThread instance structure.
 */
void tyPlatReset(tinyInstance *aInstance);

/**
 * Sleep for a given number of milliseconds.
 *
 * @param[in] aSleepMs  The number of milliseconds to sleep.
 */
void tyPlatThreadSleepMs(uint32_t aSleepMs);

/**
 * @}
 */

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TY_PLATFORM_MISC_H_
