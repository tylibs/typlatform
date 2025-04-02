// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   This file includes Tiny logging related definitions.
 */

#ifndef TY_LOGGING_H_
#define TY_LOGGING_H_

#include <stdarg.h>
#include <ty/error.h>
#include <ty/platform/toolchain.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup api-logging
 *
 * @brief
 *   This module includes Tiny logging related definitions.
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

/**
 * Returns the current log level.
 *
 * If dynamic log level feature `TY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE` is enabled, this function returns the
 * currently set dynamic log level. Otherwise, this function returns the build-time configured log level.
 *
 * @returns The log level.
 */
tyLogLevel tyLoggingGetLevel(void);

/**
 * Sets the log level.
 *
 * @note This function requires `TY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE=1`.
 *
 * @param[in]  aLogLevel               The log level.
 *
 * @retval TY_ERROR_NONE            Successfully updated log level.
 * @retval TY_ERROR_INVALID_ARGS    Log level value is invalid.
 */
tinyError tyLoggingSetLevel(tyLogLevel aLogLevel);

/**
 * Emits a log message at critical log level.
 *
 * Is intended for use by platform. If `TY_CONFIG_LOG_PLATFORM` is not set or the current log
 * level is below critical, this function does not emit any log message.
 *
 * @param[in]  aModuleName  The module name.
 * @param[in]  aFormat      The format string.
 * @param[in]  ...          Arguments for the format specification.
 */
void tyLogCritPlat(const char *aModuleName, const char *aFormat, ...) TY_TOOL_PRINTF_STYLE_FORMAT_ARG_CHECK(2, 3);

/**
 * Emits a log message at warning log level.
 *
 * Is intended for use by platform. If `TY_CONFIG_LOG_PLATFORM` is not set or the current log
 * level is below warning, this function does not emit any log message.
 *
 * @param[in]  aModuleName  The module name.
 * @param[in]  aFormat      The format string.
 * @param[in]  ...          Arguments for the format specification.
 */
void tyLogWarnPlat(const char *aModuleName, const char *aFormat, ...) TY_TOOL_PRINTF_STYLE_FORMAT_ARG_CHECK(2, 3);

/**
 * Emits a log message at note log level.
 *
 * Is intended for use by platform. If `TY_CONFIG_LOG_PLATFORM` is not set or the current log
 * level is below note, this function does not emit any log message.
 *
 * @param[in]  aModuleName  The module name.
 * @param[in]  aFormat      The format string.
 * @param[in]  ...          Arguments for the format specification.
 */
void tyLogNotePlat(const char *aModuleName, const char *aFormat, ...) TY_TOOL_PRINTF_STYLE_FORMAT_ARG_CHECK(2, 3);

/**
 * Emits a log message at info log level.
 *
 * Is intended for use by platform. If `TY_CONFIG_LOG_PLATFORM` is not set or the current log
 * level is below info, this function does not emit any log message.
 *
 * @param[in]  aModuleName  The module name.
 * @param[in]  aFormat      The format string.
 * @param[in]  ...          Arguments for the format specification.
 */
void tyLogInfoPlat(const char *aModuleName, const char *aFormat, ...) TY_TOOL_PRINTF_STYLE_FORMAT_ARG_CHECK(2, 3);

/**
 * Emits a log message at debug log level.
 *
 * Is intended for use by platform. If `TY_CONFIG_LOG_PLATFORM` is not set or the current log
 * level is below debug, this function does not emit any log message.
 *
 * @param[in]  aModuleName  The module name.
 * @param[in]  aFormat      The format string.
 * @param[in]  ...          Arguments for the format specification.
 */
void tyLogDebgPlat(const char *aModuleName, const char *aFormat, ...) TY_TOOL_PRINTF_STYLE_FORMAT_ARG_CHECK(2, 3);

#define TY_LOG_HEX_DUMP_LINE_SIZE 73 ///< Hex dump line string size.

/**
 * Represents information used for generating hex dump output.
 */
typedef struct
{
    const uint8_t *mDataBytes;                       ///< The data byes.
    uint16_t       mDataLength;                      ///< The data length (number of bytes in @p mDataBytes)
    const char    *mTitle;                           ///< Title string to add table header (MUST NOT be `NULL`).
    char           mLine[TY_LOG_HEX_DUMP_LINE_SIZE]; ///< Buffer to output one line of generated hex dump.
    uint16_t       mIterator;                        ///< Iterator used by OT stack. MUST be initialized to zero.
} tyLogHexDumpInfo;

/**
 * Generates the next hex dump line.
 *
 * Can call this method back-to-back to generate the hex dump output line by line. On the first call the `mIterator`
 * field in @p aInfo MUST be set to zero.
 *
 * Here is an example of the generated hex dump output:
 *
 *  "==========================[{mTitle} len=070]============================"
 *  "| 41 D8 87 34 12 FF FF 25 | 4C 57 DA F2 FB 2F 62 7F | A..4...%LW.../b. |"
 *  "| 3B 01 F0 4D 4C 4D 4C 54 | 4F 00 15 15 00 00 00 00 | ;..MLMLTO....... |"
 *  "| 00 00 00 01 80 DB 60 82 | 7E 33 72 3B CC B3 A1 84 | ......`.~3r;.... |"
 *  "| 3B E6 AD B2 0B 45 E7 45 | C5 B9 00 1A CB 2D 6D 1C | ;....E.E.....-m. |"
 *  "| 10 3E 3C F5 D3 70       |                         | .><..p           |"
 *  "------------------------------------------------------------------------"
 *
 * @param[in,out] aInfo        A pointer to `tyLogHexDumpInfo` to use to generate hex dump.
 *
 * @retval TY_ERROR_NONE       Successfully generated the next line, `mLine` field in @p aInfo is updated.
 * @retval TY_ERROR_NTY_FOUND  Reached the end and no more line to generate.
 */
tinyError tyLogGenerateNextHexDumpLine(tyLogHexDumpInfo *aInfo);

/**
 * @}
 */

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TY_LOGGING_H_
