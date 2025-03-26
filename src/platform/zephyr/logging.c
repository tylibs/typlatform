// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#include <stdarg.h>
#include <stdio.h>

#include "platform-zephyr.h"
#include "tinyplatform/logging.h"

#define LOG_MODULE_NAME tinyplatform
#define LOG_LEVEL LOG_LEVEL_DBG
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(LOG_MODULE_NAME);

#include "platform-zephyr.h"

/* Convert OT log level to zephyr log level. */
static inline int log_translate(tinyLogLevel aLogLevel)
{
    switch (aLogLevel)
    {
    case TINY_LOG_LEVEL_NONE:
    case TINY_LOG_LEVEL_ERROR:
        return LOG_LEVEL_ERR;
    case TINY_LOG_LEVEL_WARN:
        return LOG_LEVEL_WRN;
    case TINY_LOG_LEVEL_INFO:
        return LOG_LEVEL_INF;
    case TINY_LOG_LEVEL_DEBG:
        return LOG_LEVEL_DBG;
    default:
        break;
    }

    return -1;
}

void tinyPlatLog(tinyLogLevel aLogLevel, const char *aTag, const char *aFormat, ...)
{
    ARG_UNUSED(aTag);
#if defined(CONFIG_TINYPLATFORM_LOG)
    int     level = log_translate(aLogLevel);
    va_list param_list;

    if (level < 0)
    {
        return;
    }

    va_start(param_list, aFormat);
    log_generic(level, aFormat, param_list);
    va_end(param_list);
#else
    ARG_UNUSED(aLogLevel);
    ARG_UNUSED(aFormat);
#endif
}
