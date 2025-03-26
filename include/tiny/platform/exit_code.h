#ifndef PLATFORM_EXIT_CODE_H_
#define PLATFORM_EXIT_CODE_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <tiny/logging.h>
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
    TINY_EXIT_SUCCESS = 0,

    /**
     * Generic failure.
     */
    TINY_EXIT_FAILURE = 1,

    /**
     * Invalid arguments.
     */
    TINY_EXIT_INVALID_ARGUMENTS = 2,

    /**
     * Incompatible radio spinel.
     */
    TINY_EXIT_RADIO_SPINEL_INCOMPATIBLE = 3,

    /**
     * Unexpected radio spinel reset.
     */
    TINY_EXIT_RADIO_SPINEL_RESET = 4,

    /**
     * System call or library function error.
     */
    TINY_EXIT_ERROR_ERRNO = 5,

    /**
     * No response from radio spinel.
     */
    TINY_EXIT_RADIO_SPINEL_NO_RESPONSE = 6,

    /**
     * Invalid state.
     */
    TINY_EXIT_INVALID_STATE = 7,

    /**
     * RCP chip reset is not able to be done by OT
     */
    TINY_EXIT_RCP_RESET_REQUIRED = 8,
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
#define VerifyOrDie(aCondition, aExitCode)                                                           \
    do                                                                                               \
    {                                                                                                \
        if (!(aCondition))                                                                           \
        {                                                                                            \
            const char *start = strrchr(__FILE__, '/');                                              \
            TINY_UNUSED_VARIABLE(start);                                                             \
            tinyLogCritPlat("%s() at %s:%d: %s", __func__, (start ? start + 1 : __FILE__), __LINE__, \
                            tinyExitCodeToString(aExitCode));                                        \
            exit(aExitCode);                                                                         \
        }                                                                                            \
    } while (false)

/**
 * Checks for the specified error code, which is expected to commonly be successful,
 * and both records exit status and terminates the program if the error code is unsuccessful.
 *
 * @param[in]  aError  An error code to be evaluated against TINY_ERROR_NONE.
 */
#define SuccessOrDie(aError)               \
    VerifyOrDie(aError == TINY_ERROR_NONE, \
                (aError == TINY_ERROR_INVALID_ARGS ? TINY_EXIT_INVALID_ARGUMENTS : TINY_EXIT_FAILURE))

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
#define DieNowWithMessage(aMessage, aExitCode)                                                   \
    do                                                                                           \
    {                                                                                            \
        tinyLogCritPlat("exit(%d): %s line %d, %s, %s", aExitCode, __func__, __LINE__, aMessage, \
                        tinyExitCodeToString(aExitCode));                                        \
        exit(aExitCode);                                                                         \
    } while (false)

#ifdef __cplusplus
}
#endif

#endif // PLATFORM_EXIT_CODE_H_
