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

const char *TAG = "main";

/*****************************************************************************/

void app_main()
{
    while (true)
    {
        ESP_LOGI(TAG, "Publish HELLO_WORLD event");

        // next event in 1 second
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
