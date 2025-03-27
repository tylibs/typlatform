// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#include "tiny/platform/logging.h"
#include <stdarg.h>
#include <stdio.h>
#include <syslog.h>

#include "platform-posix.h"
#include "tiny/logging.h"
#include "tiny/platform/toolchain.h"

void tinyPlatLog(tinyLogLevel aLogLevel, const char *aTag, const char *aFormat, ...)
{
#if defined(CONFIG_TINYPLATFORM_LOG)
    va_list args;

    switch (aLogLevel)
    {
    case TINY_LOG_LEVEL_NONE:
        aLogLevel = LOG_ALERT;
        break;
    case TINY_LOG_LEVEL_CRIT:
        aLogLevel = LOG_CRIT;
        break;
    case TINY_LOG_LEVEL_WARN:
        aLogLevel = LOG_WARNING;
        break;
    case TINY_LOG_LEVEL_INFO:
        aLogLevel = LOG_INFO;
        break;
    case TINY_LOG_LEVEL_DEBG:
        aLogLevel = LOG_DEBUG;
        break;
    default:
        aLogLevel = LOG_DEBUG;
        break;
    }

    printf("%s: ", aTag);
    va_start(args, aFormat);
#if defined(CONFIG_TINYPLATFORM_SYSLOG)
    vsyslog(aLogLevel, aFormat, args);
#else
    vprintf(aFormat, args);
    printf("\n");
#endif
    va_end(args);
#else
    TINY_UNUSED_VARIABLE(aLogLevel);
    TINY_UNUSED_VARIABLE(aTag);
    TINY_UNUSED_VARIABLE(aFormat);
#endif
}
