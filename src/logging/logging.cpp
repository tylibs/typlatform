
// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file implements the OpenThread logging related APIs.
 */
#include "tiny/tiny-core-config.h"

#include "tiny/common/code_utils.hpp"
#include "tiny/common/debug.hpp"

#include "common/string.hpp"

#include "instance/instance.hpp"
#include "tiny/log.hpp"

using namespace tiny;

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

static const char kPlatformModuleName[] = "Platform";

void tyLogCritPlat(const char *aFormat, ...)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_CRIT) && TY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(kPlatformModuleName, kLogLevelCrit, aFormat, args);
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aFormat);
    TY_UNUSED_VARIABLE(kPlatformModuleName);
#endif
}

void tyLogWarnPlat(const char *aFormat, ...)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_WARN) && TY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(kPlatformModuleName, kLogLevelWarn, aFormat, args);
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aFormat);
#endif
}

void tyLogNotePlat(const char *aFormat, ...)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_NOTE) && TY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(kPlatformModuleName, kLogLevelNote, aFormat, args);
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aFormat);
#endif
}

void tyLogInfoPlat(const char *aFormat, ...)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_INFO) && TY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(kPlatformModuleName, kLogLevelInfo, aFormat, args);
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aFormat);
#endif
}

void tyLogDebgPlat(const char *aFormat, ...)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_DEBG) && TY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(kPlatformModuleName, kLogLevelDebg, aFormat, args);
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aFormat);
#endif
}

void tinyDumpCritPlat(const char *aText, const void *aData, uint16_t aDataLength)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_CRIT) && TY_CONFIG_LOG_PLATFORM && TY_CONFIG_LOG_PKT_DUMP
    Logger::DumpInModule(kPlatformModuleName, kLogLevelCrit, aText, aData, aDataLength);
#else
    TY_UNUSED_VARIABLE(aText);
    TY_UNUSED_VARIABLE(aData);
    TY_UNUSED_VARIABLE(aDataLength);
#endif
}

void tinyDumpWarnPlat(const char *aText, const void *aData, uint16_t aDataLength)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_WARN) && TY_CONFIG_LOG_PLATFORM && TY_CONFIG_LOG_PKT_DUMP
    Logger::DumpInModule(kPlatformModuleName, kLogLevelWarn, aText, aData, aDataLength);
#else
    TY_UNUSED_VARIABLE(aText);
    TY_UNUSED_VARIABLE(aData);
    TY_UNUSED_VARIABLE(aDataLength);
#endif
}

void tinyDumpNotePlat(const char *aText, const void *aData, uint16_t aDataLength)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_NOTE) && TY_CONFIG_LOG_PLATFORM && TY_CONFIG_LOG_PKT_DUMP
    Logger::DumpInModule(kPlatformModuleName, kLogLevelNote, aText, aData, aDataLength);
#else
    TY_UNUSED_VARIABLE(aText);
    TY_UNUSED_VARIABLE(aData);
    TY_UNUSED_VARIABLE(aDataLength);
#endif
}

void tinyDumpInfoPlat(const char *aText, const void *aData, uint16_t aDataLength)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_INFO) && TY_CONFIG_LOG_PLATFORM && TY_CONFIG_LOG_PKT_DUMP
    Logger::DumpInModule(kPlatformModuleName, kLogLevelInfo, aText, aData, aDataLength);
#else
    TY_UNUSED_VARIABLE(aText);
    TY_UNUSED_VARIABLE(aData);
    TY_UNUSED_VARIABLE(aDataLength);
#endif
}

void tinyDumpDebgPlat(const char *aText, const void *aData, uint16_t aDataLength)
{
#if TY_SHOULD_LOG_AT(TY_LOG_LEVEL_DEBG) && TY_CONFIG_LOG_PLATFORM && TY_CONFIG_LOG_PKT_DUMP
    Logger::DumpInModule(kPlatformModuleName, kLogLevelDebg, aText, aData, aDataLength);
#else
    TY_UNUSED_VARIABLE(aText);
    TY_UNUSED_VARIABLE(aData);
    TY_UNUSED_VARIABLE(aDataLength);
#endif
}

void tyLogPlat(tyLogLevel aLogLevel, const char *aPlatModuleName, const char *aFormat, ...)
{
#if TY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    tyLogPlatArgs(aLogLevel, aPlatModuleName, aFormat, args);
    va_end(args);
#else
    TY_UNUSED_VARIABLE(aLogLevel);
    TY_UNUSED_VARIABLE(aPlatModuleName);
    TY_UNUSED_VARIABLE(aFormat);
#endif
}

void tyLogPlatArgs(tyLogLevel aLogLevel, const char *aPlatModuleName, const char *aFormat, va_list aArgs)
{
#if TY_SHOULD_LOG && TY_CONFIG_LOG_PLATFORM
    tiny::String<kMaxLogModuleNameLength> moduleName;

    TY_ASSERT(aLogLevel >= kLogLevelNone && aLogLevel <= kLogLevelDebg);

    moduleName.Append("P-%s", aPlatModuleName);
    Logger::LogVarArgs(moduleName.AsCString(), static_cast<LogLevel>(aLogLevel), aFormat, aArgs);
#else
    TY_UNUSED_VARIABLE(aLogLevel);
    TY_UNUSED_VARIABLE(aPlatModuleName);
    TY_UNUSED_VARIABLE(aFormat);
    TY_UNUSED_VARIABLE(aArgs);
#endif
}

void tyLogCli(tyLogLevel aLogLevel, const char *aFormat, ...)
{
#if TY_SHOULD_LOG && TY_CONFIG_LOG_CLI
    static const char kCliModuleName[] = "Cli";

    va_list args;

    TY_ASSERT(aLogLevel >= kLogLevelNone && aLogLevel <= kLogLevelDebg);
    VerifyOrExit(aLogLevel >= kLogLevelNone && aLogLevel <= kLogLevelDebg);

    va_start(args, aFormat);
    Logger::LogVarArgs(kCliModuleName, static_cast<LogLevel>(aLogLevel), aFormat, args);
    va_end(args);
exit:
#else
    TY_UNUSED_VARIABLE(aLogLevel);
    TY_UNUSED_VARIABLE(aFormat);
#endif
    return;
}

tinyError tyLogGenerateNextHexDumpLine(tyLogHexDumpInfo *aInfo)
{
    AssertPointerIsNotNull(aInfo);

    return GenerateNextHexDumpLine(*aInfo);
}
