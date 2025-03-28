// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   This file includes platform abstractions for miscellaneous behaviors.
 */

#include "tiny/tiny-core-config.h"

#include <errno.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>

extern "C" void tyPlatThreadSleepMs(uint32_t aSleepMs)
{
    struct timespec ts;
    int             res;

    ts.tv_sec  = aSleepMs / 1000;
    ts.tv_nsec = (aSleepMs % 1000) * 1000000;

    do
    {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);
}
