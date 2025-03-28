// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   This file includes platform abstractions for miscellaneous behaviors.
 */

#include "ty/ty-core-config.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void tyPlatThreadSleepMs(uint32_t aSleepMs)
{
    vTaskDelay(aSleepMs / portTICK_PERIOD_MS);
}
