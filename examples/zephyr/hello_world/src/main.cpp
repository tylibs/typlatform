// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   TinyPlatform simplest example: Hello World
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <tiny/instance.h>
#include <tiny/logging.h>
#include <tiny/platform/toolchain.h>

#define LOG_MODULE_NAME main
LOG_MODULE_REGISTER(main);
const char *TAG = "main";

/*****************************************************************************/

extern "C" int main(void)
{
    tinyInstance *instance;
    instance = tinyInstanceInitSingle();

    while (true)
    {
        tinyLogInfoPlat("%s", "Hello, World!");
        // next event in 1 second
        k_sleep(K_SECONDS(1));
    }
    tinyInstanceFinalize(instance);
    return 0;
}
