// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0
#ifndef PLATFORM_ZEPHYR_H_
#define PLATFORM_ZEPHYR_H_

#include "tinyplatform-config.h"
#include <stdint.h>
#include "tiny/error.h"
#include "tiny/toolchain.h"

/**
 * This function initializes the scheduler service.
 *
 */
tinyError tiPlatformSchedulerInit(void);

#endif // PLATFORM_ZEPHYR_H_
