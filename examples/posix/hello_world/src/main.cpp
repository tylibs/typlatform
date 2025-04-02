// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   TyPlatform simplest example: Hello World
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <ty/instance.h>
#include <ty/logging.h>

extern "C" int main(void)
{
    tinyInstance *instance;
    instance = tinyInstanceInitSingle();
    // Initialize the settings subsystem
    while (true)
    {
        tyLogInfo("%s", "Hello, World!");
        // next event in 1 second
        sleep(1);
    }
    tinyInstanceFinalize(instance);
    return 0;
}
