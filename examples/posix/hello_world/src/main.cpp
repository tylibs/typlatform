// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   TinyPlatform simplest example: Hello World
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <tiny/instance.h>
#include <tiny/logging.h>

extern "C" int main(void)
{
    tinyInstance *instance;
    instance = tinyInstanceInitSingle();
    // Initialize the settings subsystem
    while (true)
    {
        tinyLogCritPlat("%s", "Hello, World!");
        // next event in 1 second
        sleep(1);
    }
    tinyInstanceFinalize(instance);
    return 0;
}
