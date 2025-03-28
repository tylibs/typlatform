// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file includes compile-time configurations for the logging service.
 */

#ifndef CONFIG_LOGGING_H_
#define CONFIG_LOGGING_H_

/**
 * @addtogroup config-logging
 *
 * @brief
 *   This module includes configuration variables for the Logging service.
 *
 * @{
 */

/**
 * @def TY_CONFIG_LOG_OUTPUT
 *
 * Selects if, and where the LOG output goes to.
 *
 * There are several options available
 * - @sa TY_CONFIG_LOG_OUTPUT_NONE
 * - @sa TY_CONFIG_LOG_OUTPUT_DEBUG_UART
 * - @sa TY_CONFIG_LOG_OUTPUT_APP
 * - @sa TY_CONFIG_LOG_OUTPUT_PLATFORM_DEFINED
 * - and others
 *
 * Note:
 *
 * 1) Because the default is: TY_CONFIG_LOG_OUTPUT_PLATFORM_DEFINED
 *    The platform is expected to provide at least a stub for `tyPlatLog()`.
 *
 * 2) This is effectively an ENUM so it can be if/else/endif at compile time.
 */
#ifndef TY_CONFIG_LOG_OUTPUT
#define TY_CONFIG_LOG_OUTPUT TY_CONFIG_LOG_OUTPUT_PLATFORM_DEFINED
#endif

/** Log output goes to the bit bucket (disabled) */
#define TY_CONFIG_LOG_OUTPUT_NONE 0
/** Log output goes to the debug uart - requires TY_CONFIG_ENABLE_DEBUG_UART to be enabled */
#define TY_CONFIG_LOG_OUTPUT_DEBUG_UART 1
/** Log output goes to the "application" provided tyPlatLog() in NCP and CLI code */
#define TY_CONFIG_LOG_OUTPUT_APP 2
/** Log output is handled by a platform defined function */
#define TY_CONFIG_LOG_OUTPUT_PLATFORM_DEFINED 3

/**
 * @def TY_CONFIG_LOG_LEVEL
 *
 * The log level (used at compile time). If `TY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE` is set, this defines the most
 * verbose log level possible. See `TY_CONFIG_LOG_LEVEL_INIT` to set the initial log level.
 */
#ifndef TY_CONFIG_LOG_LEVEL
#define TY_CONFIG_LOG_LEVEL TY_LOG_LEVEL_CRIT
#endif

/**
 * @def TY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
 *
 * Define as 1 to enable dynamic log level control.
 *
 * Note that the TY_CONFIG_LOG_LEVEL determines the log level at
 * compile time. The dynamic log level control (if enabled) only allows
 * decreasing the log level from the compile time value.
 */
#ifndef TY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
#define TY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE 0
#endif

/**
 * @def TY_CONFIG_LOG_LEVEL_INIT
 *
 * The initial log level used when OpenThread is initialized. See
 * `TY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE`.
 */
#ifndef TY_CONFIG_LOG_LEVEL_INIT
#define TY_CONFIG_LOG_LEVEL_INIT TY_CONFIG_LOG_LEVEL
#endif

/**
 * @def TY_CONFIG_LOG_PKT_DUMP
 *
 * Define to enable dump logs (of packets).
 */
#ifndef TY_CONFIG_LOG_PKT_DUMP
#define TY_CONFIG_LOG_PKT_DUMP 1
#endif

/**
 * @def TY_CONFIG_LOG_CLI
 *
 * Define to enable CLI logging and `tyLogCli()` OT function.
 */
#ifndef TY_CONFIG_LOG_CLI
#define TY_CONFIG_LOG_CLI 1
#endif

/**
 * @def TY_CONFIG_LOG_PLATFORM
 *
 * Define to enable platform logging and `tyLog{Level}Plat()` OT functions.
 */
#ifndef TY_CONFIG_LOG_PLATFORM
#define TY_CONFIG_LOG_PLATFORM 1
#endif

/**
 * @def TY_CONFIG_LOG_PREPEND_UPTIME
 *
 * Define as 1 to prepend the current uptime to all log messages.
 */
#ifndef TY_CONFIG_LOG_PREPEND_UPTIME
#define TY_CONFIG_LOG_PREPEND_UPTIME 0
#endif

/**
 * @def TY_CONFIG_LOG_PREPEND_LEVEL
 *
 * Define to prepend the log level to all log messages.
 */
#ifndef TY_CONFIG_LOG_PREPEND_LEVEL
#define TY_CONFIG_LOG_PREPEND_LEVEL 1
#endif

/**
 * @def TY_CONFIG_LOG_SUFFIX
 *
 * Define suffix to append at the end of logs.
 */
#ifndef TY_CONFIG_LOG_SUFFIX
#define TY_CONFIG_LOG_SUFFIX ""
#endif

/**
 * @def TY_CONFIG_LOG_SRC_DST_IP_ADDRESSES
 *
 * If defined as 1 when IPv6 message info is logged in mesh-forwarder, the source and destination IPv6 addresses of
 * messages are also included.
 */
#ifndef TY_CONFIG_LOG_SRC_DST_IP_ADDRESSES
#define TY_CONFIG_LOG_SRC_DST_IP_ADDRESSES 1
#endif

/**
 * @def TY_CONFIG_LOG_MAX_SIZE
 *
 * The maximum log string size (number of chars).
 */
#ifndef TY_CONFIG_LOG_MAX_SIZE
#define TY_CONFIG_LOG_MAX_SIZE 150
#endif

/**
 * @}
 */

#endif // CONFIG_LOGGING_H_
