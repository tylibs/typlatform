// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#ifndef TINY_CORE_CONFIG_H_
#define TINY_CORE_CONFIG_H_

#define TINY_CORE_CONFIG_H_IN

/**
 * Include project and platform specific header files in the following order:
 *
 * 1. Project specific header file (`TINY_PROJECT_CORE_CONFIG_FILE`)
 * 2. Platform specific header file (`TINY_PLATFORM_CORE_CONFIG_FILE`)
 * 3. Default config values as specified by `config/{module}.h`
 */

#ifdef TINY_PROJECT_CORE_CONFIG_FILE
#include TINY_PROJECT_CORE_CONFIG_FILE
#elif defined(TINY_CONFIG_CORE_USER_CONFIG_HEADER_ENABLE)
// This configuration header file should be provided by the user when
// TINY_CONFIG_CORE_USER_CONFIG_HEADER_ENABLE is defined to 1.
#include "openthread-core-user-config.h"
#endif

#ifdef TINY_PLATFORM_CORE_CONFIG_FILE
#include TINY_PLATFORM_CORE_CONFIG_FILE
#endif

#ifndef TINY_CONFIG_VERSION
#define TINY_CONFIG_VERSION TINY_VERSION_1_0
#endif

#include "config/logging.h"
#include "config/misc.h"

#undef TINY_CORE_CONFIG_H_IN

#endif // TINY_CORE_CONFIG_H_
