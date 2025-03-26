// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   This file includes the platform abstraction for the debug log service.
 */
#include <esp_log.h>
#include <stdarg.h>
#include <stdio.h>
#include <tiny/platform/toolchain.h>

#include "platform-esp.h"
#include "tiny/logging.h"
#if (TINY_CONFIG_LOG_OUTPUT == TINY_CONFIG_LOG_OUTPUT_PLATFORM_DEFINED) || \
    (TINY_CONFIG_LOG_OUTPUT == TINY_CONFIG_LOG_OUTPUT_NCP_SPINEL)
TINY_TOOL_WEAK void tinyPlatLog(tinyLogLevel log_level, const char *logRegion, const char *format, ...)
{
    va_list args;

    va_start(args, format);

    switch (log_level)
    {
    case TINY_LOG_LEVEL_CRIT:
        if (LOG_LOCAL_LEVEL >= ESP_LOG_ERROR)
        {
            esp_log_write(ESP_LOG_ERROR, logRegion, LOG_COLOR_E "E(%u) %s:", esp_log_timestamp(), logRegion);
            esp_log_writev(ESP_LOG_ERROR, logRegion, format, args);
            esp_log_write(ESP_LOG_ERROR, logRegion, LOG_RESET_COLOR "\n");
        }
        break;
    case TINY_LOG_LEVEL_WARN:
        if (LOG_LOCAL_LEVEL >= ESP_LOG_WARN)
        {
            esp_log_write(ESP_LOG_WARN, logRegion, LOG_COLOR_W "W(%u) %s:", esp_log_timestamp(), logRegion);
            esp_log_writev(ESP_LOG_WARN, logRegion, format, args);
            esp_log_write(ESP_LOG_WARN, logRegion, LOG_RESET_COLOR "\n");
        }
        break;
    case TINY_LOG_LEVEL_NOTE:
    case TINY_LOG_LEVEL_INFO:
        if (LOG_LOCAL_LEVEL >= ESP_LOG_INFO)
        {
            esp_log_write(ESP_LOG_INFO, logRegion, LOG_COLOR_I "I(%u) %s:", esp_log_timestamp(), logRegion);
            esp_log_writev(ESP_LOG_INFO, logRegion, format, args);
            esp_log_write(ESP_LOG_INFO, logRegion, LOG_RESET_COLOR "\n");
        }
        break;
    default:
        if (LOG_LOCAL_LEVEL >= ESP_LOG_DEBUG)
        {
            esp_log_write(ESP_LOG_DEBUG, logRegion, LOG_COLOR_D "D(%u) %s:", esp_log_timestamp(), logRegion);
            esp_log_writev(ESP_LOG_DEBUG, logRegion, format, args);
            esp_log_write(ESP_LOG_DEBUG, logRegion, LOG_RESET_COLOR "\n");
        }
        break;
    }
    va_end(args);
}
#endif
