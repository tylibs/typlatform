// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   This file includes platform abstractions for miscellaneous behaviors.
 */

#include "tiny/tiny-core-config.h"

#include "zephyr/kernel.h"

void tyPlatThreadSleepMs(uint32_t aSleepMs)
{
    k_msleep(aSleepMs);
}
