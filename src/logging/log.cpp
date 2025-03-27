// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file implements the logging related functions.
 */

#include "tiny/log.hpp"

#include <ctype.h>

#include <tiny/platform/logging.h>

#include "common/string.hpp"

#include "instance/instance.hpp"
#include "tiny/common/code_utils.hpp"
#include "tiny/common/num_utils.hpp"
#include "tiny/common/numeric_limits.hpp"

/*
 * Verify debug UART dependency.
 *
 * It is reasonable to only enable the debug UART and not enable logs to the DEBUG UART.
 */
#if (TINY_CONFIG_LOG_OUTPUT == TINY_CONFIG_LOG_OUTPUT_DEBUG_UART) && (!TINY_CONFIG_ENABLE_DEBUG_UART)
#error "TINY_CONFIG_ENABLE_DEBUG_UART_LOG requires TINY_CONFIG_ENABLE_DEBUG_UART"
#endif

#if TINY_CONFIG_LOG_PREPEND_UPTIME && !TINY_CONFIG_UPTIME_ENABLE
#error "TINY_CONFIG_LOG_PREPEND_UPTIME requires TINY_CONFIG_UPTIME_ENABLE"
#endif

#if TINY_CONFIG_LOG_PREPEND_UPTIME && TINY_CONFIG_MULTIPLE_INSTANCE_ENABLE
#error "TINY_CONFIG_LOG_PREPEND_UPTIME is not supported under TINY_CONFIG_MULTIPLE_INSTANCE_ENABLE"
#endif

namespace tiny {

#if TINY_SHOULD_LOG

template <LogLevel kLogLevel> void Logger::LogAtLevel(const char *aModuleName, const char *aFormat, ...)
{
    va_list args;

    va_start(args, aFormat);
    LogVarArgs(aModuleName, kLogLevel, aFormat, args);
    va_end(args);
}

// Explicit instantiations
template void Logger::LogAtLevel<kLogLevelNone>(const char *aModuleName, const char *aFormat, ...);
template void Logger::LogAtLevel<kLogLevelCrit>(const char *aModuleName, const char *aFormat, ...);
template void Logger::LogAtLevel<kLogLevelWarn>(const char *aModuleName, const char *aFormat, ...);
template void Logger::LogAtLevel<kLogLevelNote>(const char *aModuleName, const char *aFormat, ...);
template void Logger::LogAtLevel<kLogLevelInfo>(const char *aModuleName, const char *aFormat, ...);
template void Logger::LogAtLevel<kLogLevelDebg>(const char *aModuleName, const char *aFormat, ...);

void Logger::LogInModule(const char *aModuleName, LogLevel aLogLevel, const char *aFormat, ...)
{
    va_list args;

    va_start(args, aFormat);
    LogVarArgs(aModuleName, aLogLevel, aFormat, args);
    va_end(args);
}

void Logger::LogVarArgs(const char *aModuleName, LogLevel aLogLevel, const char *aFormat, va_list aArgs)
{
    static const char kModuleNamePadding[] = "--------------";

    tiny::String<TINY_CONFIG_LOG_MAX_SIZE> logString;

    static_assert(sizeof(kModuleNamePadding) == kMaxLogModuleNameLength + 1, "Padding string is not correct");

#if TINY_CONFIG_LOG_PREPEND_UPTIME
    tiny::Uptime::UptimeToString(tiny::Instance::Get().Get<ot::Uptime>().GetUptime(), logString,
                                 /* aInlcudeMsec */ true);
    logString.Append(" ");
#endif

#if TINY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
    VerifyOrExit(Instance::GetLogLevel() >= aLogLevel);
#endif

#if TINY_CONFIG_LOG_PREPEND_LEVEL
    {
        static const char kLevelChars[] = {
            '-', /* kLogLevelNone */
            'C', /* kLogLevelCrit */
            'W', /* kLogLevelWarn */
            'N', /* kLogLevelNote */
            'I', /* kLogLevelInfo */
            'D', /* kLogLevelDebg */
        };

        logString.Append("[%c] ", kLevelChars[aLogLevel]);
    }
#endif

    logString.Append("%.*s%s: ", kMaxLogModuleNameLength, aModuleName,
                     &kModuleNamePadding[StringLength(aModuleName, kMaxLogModuleNameLength)]);

    logString.AppendVarArgs(aFormat, aArgs);

    logString.Append("%s", TINY_CONFIG_LOG_SUFFIX);
    tinyPlatLog(aLogLevel, TINY_LOG_REGION_CORE, "%s", logString.AsCString());

    ExitNow();

exit:
    return;
}

#if TINY_SHOULD_LOG_AT(TINY_LOG_LEVEL_WARN)
void Logger::LogOnError(const char *aModuleName, Error aError, const char *aText)
{
    if (aError != kErrorNone)
    {
        LogAtLevel<kLogLevelWarn>(aModuleName, "Failed to %s: %s", aText, ErrorToString(aError));
    }
}
#endif

#if TINY_CONFIG_LOG_PKT_DUMP

template <LogLevel kLogLevel>
void Logger::DumpAtLevel(const char *aModuleName, const char *aText, const void *aData, uint16_t aDataLength)
{
    DumpInModule(aModuleName, kLogLevel, aText, aData, aDataLength);
}

// Explicit instantiations
template void Logger::DumpAtLevel<kLogLevelNone>(const char *aModuleName,
                                                 const char *aText,
                                                 const void *aData,
                                                 uint16_t    aDataLength);
template void Logger::DumpAtLevel<kLogLevelCrit>(const char *aModuleName,
                                                 const char *aText,
                                                 const void *aData,
                                                 uint16_t    aDataLength);
template void Logger::DumpAtLevel<kLogLevelWarn>(const char *aModuleName,
                                                 const char *aText,
                                                 const void *aData,
                                                 uint16_t    aDataLength);
template void Logger::DumpAtLevel<kLogLevelNote>(const char *aModuleName,
                                                 const char *aText,
                                                 const void *aData,
                                                 uint16_t    aDataLength);
template void Logger::DumpAtLevel<kLogLevelInfo>(const char *aModuleName,
                                                 const char *aText,
                                                 const void *aData,
                                                 uint16_t    aDataLength);
template void Logger::DumpAtLevel<kLogLevelDebg>(const char *aModuleName,
                                                 const char *aText,
                                                 const void *aData,
                                                 uint16_t    aDataLength);

void Logger::DumpInModule(const char *aModuleName,
                          LogLevel    aLogLevel,
                          const char *aText,
                          const void *aData,
                          uint16_t    aDataLength)
{
    HexDumpInfo info;

    VerifyOrExit(tinyLoggingGetLevel() >= aLogLevel);

    info.mDataBytes  = reinterpret_cast<const uint8_t *>(aData);
    info.mDataLength = aDataLength;
    info.mTitle      = aText;
    info.mIterator   = 0;

    while (GenerateNextHexDumpLine(info) == kErrorNone)
    {
        LogInModule(aModuleName, aLogLevel, "%s", info.mLine);
    }

exit:
    return;
}

#endif // TINY_CONFIG_LOG_PKT_DUMP

#endif // TINY_SHOULD_LOG

Error GenerateNextHexDumpLine(HexDumpInfo &aInfo)
{
    constexpr uint16_t kIterTableStartLine = 0;
    constexpr uint16_t kIterFirstDataLine  = NumericLimits<uint16_t>::kMax - 2;
    constexpr uint16_t kIterTableEndLine   = NumericLimits<uint16_t>::kMax - 1;
    constexpr uint16_t kIterFinished       = NumericLimits<uint16_t>::kMax;
    constexpr uint16_t kWidth              = 72;
    constexpr uint16_t kTitleSuffixLen     = sizeof("[ len=000]") - 1;
    constexpr uint16_t kDumpBytesPerLine   = 16;

    Error        error = kErrorNone;
    StringWriter writer(aInfo.mLine, sizeof(aInfo.mLine));

    switch (aInfo.mIterator)
    {
    case kIterTableStartLine:
    {
        uint16_t txtLen = StringLength(aInfo.mTitle, kWidth - kTitleSuffixLen) + kTitleSuffixLen;

        writer.AppendCharMultipleTimes('=', static_cast<uint16_t>((kWidth - txtLen) / 2));
        writer.Append("[%s len=%03u]", aInfo.mTitle, aInfo.mDataLength);
        writer.AppendCharMultipleTimes('=', static_cast<uint16_t>(kWidth - txtLen - (kWidth - txtLen) / 2));
        aInfo.mIterator = kIterFirstDataLine;
        break;
    }

    case kIterTableEndLine:
        writer.AppendCharMultipleTimes('-', kWidth);
        aInfo.mIterator = kIterFinished;
        break;

    case kIterFinished:
        error = kErrorNotFound;
        break;

    case kIterFirstDataLine:
        aInfo.mIterator = 0;
        TINY_FALL_THROUGH;

    default:
    {
        uint16_t startIndex = aInfo.mIterator;
        uint16_t endIndex   = aInfo.mIterator + kDumpBytesPerLine;

        writer.Append("|");

        for (uint16_t i = startIndex; i < endIndex; i++)
        {
            (i < aInfo.mDataLength) ? writer.Append(" %02X", aInfo.mDataBytes[i]) : writer.Append("   ");

            if ((i % 8) == 7)
            {
                writer.Append(" |");
            }
        }

        writer.Append(" ");

        for (uint16_t i = startIndex; i < endIndex; i++)
        {
            char c = ' ';

            if (i < aInfo.mDataLength)
            {
                uint8_t byte = aInfo.mDataBytes[i];

                c = ((byte < 127) && isprint(static_cast<char>(byte))) ? static_cast<char>(byte) : '.';
            }

            writer.Append("%c", c);
        }

        writer.Append(" |");

        aInfo.mIterator = endIndex;

        if (aInfo.mIterator >= aInfo.mDataLength)
        {
            aInfo.mIterator = kIterTableEndLine;
        }

        break;
    }
    }

    return error;
}

} // namespace tiny
