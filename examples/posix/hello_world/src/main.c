// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   TinyPlatform simplest example: Hello World
 */

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

const char *TAG = "main";
/*****************************************************************************
 * Tiny Bus Definitions for the main Module
 *****************************************************************************/

/*****************************************************************************/

int main(void)
{
    while (true)
    {
        // next event in 1 second
        sleep(1);
    }
    return 0;
}
