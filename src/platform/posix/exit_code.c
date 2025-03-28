// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file implements exit code utilities.
 */

#include <tiny/platform/exit_code.h>

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

const char *tinyExitCodeToString(uint8_t aExitCode)
{
    const char *retval = NULL;

    switch (aExitCode)
    {
    case TY_EXIT_SUCCESS:
        retval = "Success";
        break;

    case TY_EXIT_FAILURE:
        retval = "Failure";
        break;

    case TY_EXIT_INVALID_ARGUMENTS:
        retval = "InvalidArgument";
        break;

    case TY_EXIT_RADIO_SPINEL_INCOMPATIBLE:
        retval = "RadioSpinelIncompatible";
        break;

    case TY_EXIT_RADIO_SPINEL_RESET:
        retval = "RadioSpinelReset";
        break;

    case TY_EXIT_RADIO_SPINEL_NO_RESPONSE:
        retval = "RadioSpinelNoResponse";
        break;

    case TY_EXIT_ERROR_ERRNO:
#ifdef errno
        retval = strerror(errno);
#else
        retval = "ErrorNo";
#endif
        break;

    case TY_EXIT_INVALID_STATE:
        retval = "InvalidState";
        break;

    case TY_EXIT_RCP_RESET_REQUIRED:
        retval = "RcpResetRequired";
        break;

    default:
        assert(false);
        retval = "UnknownExitCode";
        break;
    }

    return retval;
}
