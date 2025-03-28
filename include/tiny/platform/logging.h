// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0
#ifndef TY_PLATFORM_LOGGING_H_
#define TY_PLATFORM_LOGGING_H_

#include <stdarg.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup plat-logging
 *
 * @brief
 *   This module includes the platform abstraction for the debug log service.
 *
 * @{
 */

/**
 * Log level None.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 */
#define TY_LOG_LEVEL_NONE 0

/**
 * Log level Critical.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 */
#define TY_LOG_LEVEL_CRIT 1

/**
 * Log level Warning.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 */
#define TY_LOG_LEVEL_WARN 2

/**
 * Log level Notice.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 */
#define TY_LOG_LEVEL_NOTE 3

/**
 * Log level Informational.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 */
#define TY_LOG_LEVEL_INFO 4

/**
 * Log level Debug.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 */
#define TY_LOG_LEVEL_DEBG 5

/**
 * Represents the log level.
 */
typedef int tyLogLevel;

#define TY_LOG_REGION_CORE "core"

/**
 * Outputs logs.
 *
 * Note that the support for log region is removed. The OT core will always emit all logs with `TY_LOG_REGION_CORE`
 * as @p aLogRegion.
 *
 * @param[in]  aLogLevel   The log level.
 * @param[in]  aLogRegion  The log region.
 * @param[in]  aFormat     A pointer to the format string.
 * @param[in]  ...         Arguments for the format specification.
 */
void tyPlatLog(tyLogLevel aLogLevel, const char *region, const char *aFormat, ...);

/**
 * Handles OpenThread log level changes.
 *
 * This platform function is called whenever the OpenThread log level changes.
 * This platform function is optional since an empty weak implementation has been provided.
 *
 * @note Only applicable when `OPENTHREAD_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE=1`.
 *
 * @param[in]  aLogLevel  The new OpenThread log level.
 */
void tyPlatLogHandleLevelChanged(tyLogLevel aLogLevel);

/**
 * @}
 */

#ifdef __cplusplus
} // extern "C"
#endif

#endif // OPENTHREAD_PLATFORM_LOGGING_H_
