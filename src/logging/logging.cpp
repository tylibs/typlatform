
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

tinyLogLevel tinyLoggingGetLevel(void)
{
    return static_cast<tinyLogLevel>(Instance::GetLogLevel());
}

#if TINY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
tinyError tinyLoggingSetLevel(tinyLogLevel aLogLevel)
{
    Error error = kErrorNone;

    VerifyOrExit(aLogLevel <= kLogLevelDebg && aLogLevel >= kLogLevelNone, error = kErrorInvalidArgs);
    Instance::SetLogLevel(static_cast<LogLevel>(aLogLevel));

exit:
    return error;
}
#endif

static const char kPlatformModuleName[] = "Platform";

void tinyLogCritPlat(const char *aFormat, ...)
{
#if TINY_SHOULD_LOG_AT(TINY_LOG_LEVEL_CRIT) && TINY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(kPlatformModuleName, kLogLevelCrit, aFormat, args);
    va_end(args);
#else
    TINY_UNUSED_VARIABLE(aFormat);
    TINY_UNUSED_VARIABLE(kPlatformModuleName);
#endif
}

void tinyLogWarnPlat(const char *aFormat, ...)
{
#if TINY_SHOULD_LOG_AT(TINY_LOG_LEVEL_WARN) && TINY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(kPlatformModuleName, kLogLevelWarn, aFormat, args);
    va_end(args);
#else
    TINY_UNUSED_VARIABLE(aFormat);
#endif
}

void tinyLogNotePlat(const char *aFormat, ...)
{
#if TINY_SHOULD_LOG_AT(TINY_LOG_LEVEL_NOTE) && TINY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(kPlatformModuleName, kLogLevelNote, aFormat, args);
    va_end(args);
#else
    TINY_UNUSED_VARIABLE(aFormat);
#endif
}

void tinyLogInfoPlat(const char *aFormat, ...)
{
#if TINY_SHOULD_LOG_AT(TINY_LOG_LEVEL_INFO) && TINY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(kPlatformModuleName, kLogLevelInfo, aFormat, args);
    va_end(args);
#else
    TINY_UNUSED_VARIABLE(aFormat);
#endif
}

void tinyLogDebgPlat(const char *aFormat, ...)
{
#if TINY_SHOULD_LOG_AT(TINY_LOG_LEVEL_DEBG) && TINY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    Logger::LogVarArgs(kPlatformModuleName, kLogLevelDebg, aFormat, args);
    va_end(args);
#else
    TINY_UNUSED_VARIABLE(aFormat);
#endif
}

void tinyDumpCritPlat(const char *aText, const void *aData, uint16_t aDataLength)
{
#if TINY_SHOULD_LOG_AT(TINY_LOG_LEVEL_CRIT) && TINY_CONFIG_LOG_PLATFORM && TINY_CONFIG_LOG_PKT_DUMP
    Logger::DumpInModule(kPlatformModuleName, kLogLevelCrit, aText, aData, aDataLength);
#else
    TINY_UNUSED_VARIABLE(aText);
    TINY_UNUSED_VARIABLE(aData);
    TINY_UNUSED_VARIABLE(aDataLength);
#endif
}

void tinyDumpWarnPlat(const char *aText, const void *aData, uint16_t aDataLength)
{
#if TINY_SHOULD_LOG_AT(TINY_LOG_LEVEL_WARN) && TINY_CONFIG_LOG_PLATFORM && TINY_CONFIG_LOG_PKT_DUMP
    Logger::DumpInModule(kPlatformModuleName, kLogLevelWarn, aText, aData, aDataLength);
#else
    TINY_UNUSED_VARIABLE(aText);
    TINY_UNUSED_VARIABLE(aData);
    TINY_UNUSED_VARIABLE(aDataLength);
#endif
}

void tinyDumpNotePlat(const char *aText, const void *aData, uint16_t aDataLength)
{
#if TINY_SHOULD_LOG_AT(TINY_LOG_LEVEL_NOTE) && TINY_CONFIG_LOG_PLATFORM && TINY_CONFIG_LOG_PKT_DUMP
    Logger::DumpInModule(kPlatformModuleName, kLogLevelNote, aText, aData, aDataLength);
#else
    TINY_UNUSED_VARIABLE(aText);
    TINY_UNUSED_VARIABLE(aData);
    TINY_UNUSED_VARIABLE(aDataLength);
#endif
}

void tinyDumpInfoPlat(const char *aText, const void *aData, uint16_t aDataLength)
{
#if TINY_SHOULD_LOG_AT(TINY_LOG_LEVEL_INFO) && TINY_CONFIG_LOG_PLATFORM && TINY_CONFIG_LOG_PKT_DUMP
    Logger::DumpInModule(kPlatformModuleName, kLogLevelInfo, aText, aData, aDataLength);
#else
    TINY_UNUSED_VARIABLE(aText);
    TINY_UNUSED_VARIABLE(aData);
    TINY_UNUSED_VARIABLE(aDataLength);
#endif
}

void tinyDumpDebgPlat(const char *aText, const void *aData, uint16_t aDataLength)
{
#if TINY_SHOULD_LOG_AT(TINY_LOG_LEVEL_DEBG) && TINY_CONFIG_LOG_PLATFORM && TINY_CONFIG_LOG_PKT_DUMP
    Logger::DumpInModule(kPlatformModuleName, kLogLevelDebg, aText, aData, aDataLength);
#else
    TINY_UNUSED_VARIABLE(aText);
    TINY_UNUSED_VARIABLE(aData);
    TINY_UNUSED_VARIABLE(aDataLength);
#endif
}

void tinyLogPlat(tinyLogLevel aLogLevel, const char *aPlatModuleName, const char *aFormat, ...)
{
#if TINY_CONFIG_LOG_PLATFORM
    va_list args;

    va_start(args, aFormat);
    tinyLogPlatArgs(aLogLevel, aPlatModuleName, aFormat, args);
    va_end(args);
#else
    TINY_UNUSED_VARIABLE(aLogLevel);
    TINY_UNUSED_VARIABLE(aPlatModuleName);
    TINY_UNUSED_VARIABLE(aFormat);
#endif
}

void tinyLogPlatArgs(tinyLogLevel aLogLevel, const char *aPlatModuleName, const char *aFormat, va_list aArgs)
{
#if TINY_SHOULD_LOG && TINY_CONFIG_LOG_PLATFORM
    tiny::String<kMaxLogModuleNameLength> moduleName;

    TINY_ASSERT(aLogLevel >= kLogLevelNone && aLogLevel <= kLogLevelDebg);

    moduleName.Append("P-%s", aPlatModuleName);
    Logger::LogVarArgs(moduleName.AsCString(), static_cast<LogLevel>(aLogLevel), aFormat, aArgs);
#else
    TINY_UNUSED_VARIABLE(aLogLevel);
    TINY_UNUSED_VARIABLE(aPlatModuleName);
    TINY_UNUSED_VARIABLE(aFormat);
    TINY_UNUSED_VARIABLE(aArgs);
#endif
}

void tinyLogCli(tinyLogLevel aLogLevel, const char *aFormat, ...)
{
#if TINY_SHOULD_LOG && TINY_CONFIG_LOG_CLI
    static const char kCliModuleName[] = "Cli";

    va_list args;

    TINY_ASSERT(aLogLevel >= kLogLevelNone && aLogLevel <= kLogLevelDebg);
    VerifyOrExit(aLogLevel >= kLogLevelNone && aLogLevel <= kLogLevelDebg);

    va_start(args, aFormat);
    Logger::LogVarArgs(kCliModuleName, static_cast<LogLevel>(aLogLevel), aFormat, args);
    va_end(args);
exit:
#else
    TINY_UNUSED_VARIABLE(aLogLevel);
    TINY_UNUSED_VARIABLE(aFormat);
#endif
    return;
}

tinyError tinyLogGenerateNextHexDumpLine(tinyLogHexDumpInfo *aInfo)
{
    AssertPointerIsNotNull(aInfo);

    return GenerateNextHexDumpLine(*aInfo);
}
