// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#ifndef TY_CORE_CONFIG_H_
#define TY_CORE_CONFIG_H_

#define TY_CORE_CONFIG_H_IN

/**
 * Include project and platform specific header files in the following order:
 *
 * 1. Project specific header file (`TY_PROJECT_CORE_CONFIG_FILE`)
 * 2. Platform specific header file (`TY_PLATFORM_CORE_CONFIG_FILE`)
 * 3. Default config values as specified by `config/{module}.h`
 */

#ifdef TY_PROJECT_CORE_CONFIG_FILE
#include TY_PROJECT_CORE_CONFIG_FILE
#elif defined(TY_CONFIG_CORE_USER_CONFIG_HEADER_ENABLE)
// This configuration header file should be provided by the user when
// TY_CONFIG_CORE_USER_CONFIG_HEADER_ENABLE is defined to 1.
#include "openthread-core-user-config.h"
#endif

#ifdef TY_PLATFORM_CORE_CONFIG_FILE
#include TY_PLATFORM_CORE_CONFIG_FILE
#endif

#ifndef TY_CONFIG_VERSION
#define TY_CONFIG_VERSION TY_VERSION_1_0
#endif

#include "config/logging.h"
#include "config/misc.h"

#undef TY_CORE_CONFIG_H_IN

#endif // TY_CORE_CONFIG_H_
