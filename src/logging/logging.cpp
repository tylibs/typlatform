
// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file implements the OpenThread logging related APIs.
 */
#include "ty/ty-core-config.h"

#include "ty/common/code_utils.hpp"
#include "ty/common/debug.hpp"

#include "common/string.hpp"

#include "instance/instance.hpp"
#include "ty/log.hpp"

using namespace ty;

tyLogLevel tyLoggingGetLevel(void)
{
    return static_cast<tyLogLevel>(Instance::GetLogLevel());
}

#if TY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
tinyError tyLoggingSetLevel(tyLogLevel aLogLevel)
{
    Error error = kErrorNone;

    VerifyOrExit(aLogLevel <= kLogLevelDebg && aLogLevel >= kLogLevelNone, error = kErrorInvalidArgs);
    Instance::SetLogLevel(static_cast<LogLevel>(aLogLevel));

exit:
    return error;
}
#endif

void tyLogCritPlat(const char *aModuleName, const char *aFormat, ...)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_CRIT) && TY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(aModuleName, kLogLevelCrit, aFormat, args);
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aFormat);
    TY_UNUSED_VARIABLE(kPlatformModuleName);
#endif
}

void tyLogWarnPlat(const char *aModuleName, const char *aFormat, ...)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_WARN) && TY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(aModuleName, kLogLevelWarn, aFormat, args);
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aFormat);
#endif
}

void tyLogNotePlat(const char *aModuleName, const char *aFormat, ...)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_NOTE) && TY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(aModuleName, kLogLevelNote, aFormat, args);
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aFormat);
#endif
}

void tyLogInfoPlat(const char *aModuleName, const char *aFormat, ...)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_INFO) && TY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(aModuleName, kLogLevelInfo, aFormat, args);
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aFormat);
#endif
}

void tyLogDebgPlat(const char *aModuleName, const char *aFormat, ...)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_DEBG) && TY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(aModuleName, kLogLevelDebg, aFormat, args);
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aFormat);
#endif
}

tinyError tyLogGenerateNextHexDumpLine(tyLogHexDumpInfo *aInfo)
{
    AssertPointerIsNotNull(aInfo);

    return GenerateNextHexDumpLine(*aInfo);
}
