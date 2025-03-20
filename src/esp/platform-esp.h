// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#ifndef TINYPLATFORM_PLATFORM_ESP_H_
#define TINYPLATFORM_PLATFORM_ESP_H_

#include "tinyplatform-esp-config.h"
#include <stdint.h>
#include "tinyplatform/error.h"
#include "tinyplatform/toolchain/toolchain.h"

/**
 * This function initializes the scheduler service.
 *
 */
tbError tbPlatformSchedulerInit(void);

#endif // TINYPLATFORM_PLATFORM_ESP_H_
