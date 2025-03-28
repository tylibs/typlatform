// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#include "ty/platform/logging.h"
#include <stdarg.h>
#include <stdio.h>
#include <syslog.h>

#include "platform-posix.h"
#include "ty/logging.h"
#include "ty/platform/toolchain.h"

void tyPlatLog(tyLogLevel aLogLevel, const char *aTag, const char *aFormat, ...)
{
#if defined(CONFIG_TYPLATFORM_LOG)
    va_list args;

    switch (aLogLevel)
    {
    case TY_LOG_LEVEL_NONE:
        aLogLevel = LOG_ALERT;
        break;
    case TY_LOG_LEVEL_CRIT:
        aLogLevel = LOG_CRIT;
        break;
    case TY_LOG_LEVEL_WARN:
        aLogLevel = LOG_WARNING;
        break;
    case TY_LOG_LEVEL_INFO:
        aLogLevel = LOG_INFO;
        break;
    case TY_LOG_LEVEL_DEBG:
        aLogLevel = LOG_DEBUG;
        break;
    default:
        aLogLevel = LOG_DEBUG;
        break;
    }

    printf("%s: ", aTag);
    va_start(args, aFormat);
#if defined(CONFIG_TYPLATFORM_SYSLOG)
    vsyslog(aLogLevel, aFormat, args);
#else
    vprintf(aFormat, args);
    printf("\n");
#endif
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aLogLevel);
    TY_UNUSED_VARIABLE(aTag);
    TY_UNUSED_VARIABLE(aFormat);
#endif
}
