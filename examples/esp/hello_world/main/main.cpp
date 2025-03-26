// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   TinyPlatform simplest example: Hello World
 */

#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <tiny/instance.h>
#include <tiny/logging.h>
#include <tiny/platform/toolchain.h>

const char *TAG = "main";

/*****************************************************************************/

extern "C" void app_main()
{
    tinyInstance *instance;
    instance = tinyInstanceInitSingle();

    while (true)
    {
        tinyLogInfoPlat("%s", "Hello, World!");
        // next event in 1 second
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
    tinyInstanceFinalize(instance);
}
