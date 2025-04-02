// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#ifndef PLATFORM_EXIT_CODE_H_
#define PLATFORM_EXIT_CODE_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <ty/logging.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
 * Represents exit codes used when OpenThread exits.
 */
enum
{
    /**
     * Success.
     */
    TY_EXIT_SUCCESS = 0,

    /**
     * Generic failure.
     */
    TY_EXIT_FAILURE = 1,

    /**
     * Invalid arguments.
     */
    TY_EXIT_INVALID_ARGUMENTS = 2,

    /**
     * Incompatible radio spinel.
     */
    TY_EXIT_RADIO_SPINEL_INCOMPATIBLE = 3,

    /**
     * Unexpected radio spinel reset.
     */
    TY_EXIT_RADIO_SPINEL_RESET = 4,

    /**
     * System call or library function error.
     */
    TY_EXIT_ERROR_ERRNO = 5,

    /**
     * No response from radio spinel.
     */
    TY_EXIT_RADIO_SPINEL_NO_RESPONSE = 6,

    /**
     * Invalid state.
     */
    TY_EXIT_INVALID_STATE = 7,

    /**
     * RCP chip reset is not able to be done by OT
     */
    TY_EXIT_RCP_RESET_REQUIRED = 8,
};

/**
 * Converts an exit code into a string.
 *
 * @param[in]  aExitCode  An exit code.
 *
 * @returns  A string representation of an exit code.
 */
const char *tinyExitCodeToString(uint8_t aExitCode);

/**
 * Checks for the specified condition, which is expected to commonly be true,
 * and both records exit status and terminates the program if the condition is false.
 *
 * @param[in]   aCondition  The condition to verify
 * @param[in]   aExitCode   The exit code.
 */
#define VerifyOrDie(aCondition, aExitCode)                                                     \
    do                                                                                         \
    {                                                                                          \
        if (!(aCondition))                                                                     \
        {                                                                                      \
            const char *start = strrchr(__FILE__, '/');                                        \
            TY_UNUSED_VARIABLE(start);                                                         \
            tyLogCrit("%s() at %s:%d: %s", __func__, (start ? start + 1 : __FILE__), __LINE__, \
                      tinyExitCodeToString(aExitCode));                                        \
            exit(aExitCode);                                                                   \
        }                                                                                      \
    } while (false)

/**
 * Checks for the specified error code, which is expected to commonly be successful,
 * and both records exit status and terminates the program if the error code is unsuccessful.
 *
 * @param[in]  aError  An error code to be evaluated against TY_ERROR_NONE.
 */
#define SuccessOrDie(aError)             \
    VerifyOrDie(aError == TY_ERROR_NONE, \
                (aError == TY_ERROR_INVALID_ARGS ? TY_EXIT_INVALID_ARGUMENTS : TY_EXIT_FAILURE))

/**
 * Unconditionally both records exit status and terminates the program.
 *
 * @param[in]   aExitCode   The exit code.
 */
#define DieNow(aExitCode) VerifyOrDie(false, aExitCode)

/**
 * Unconditionally both records exit status and exit message and terminates the program.
 *
 * @param[in]   aMessage    The exit message.
 * @param[in]   aExitCode   The exit code.
 */
#define DieNowWithMessage(aMessage, aExitCode)                                             \
    do                                                                                     \
    {                                                                                      \
        tyLogCrit("exit(%d): %s line %d, %s, %s", aExitCode, __func__, __LINE__, aMessage, \
                  tinyExitCodeToString(aExitCode));                                        \
        exit(aExitCode);                                                                   \
    } while (false)

#ifdef __cplusplus
}
#endif

#endif // PLATFORM_EXIT_CODE_H_
