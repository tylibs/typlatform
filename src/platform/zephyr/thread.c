// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   This file includes platform abstractions for threadellaneous behaviors.
 */
#include "ty/ty-core-config.h"

#include "ty/platform/thread.h"

#include "zephyr/kernel.h"

void tyPlatDelay(uint32_t aSleepMs)
{
    k_msleep(aSleepMs);
}
