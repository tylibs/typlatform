// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file defines the errors used by Tiny core.
 */

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include "ty/ty-core-config.h"

#include <ty/error.h>

#include <stdint.h>

namespace tiny {

/**
 * Represents error codes used by Tiny core modules.
 */
typedef tinyError Error;

/*
 * The `TY_ERROR_*` enumeration values are re-defined using `kError` style format.
 * See `ty/error.h` for more details about each error.
 */
constexpr Error kErrorNone                    = TY_ERROR_NONE;
constexpr Error kErrorSubscriberCountExceeded = TY_ERROR_SUBSCRIBER_COUNT_EXCEEDED;
constexpr Error kErrorNotFound                = TY_ERROR_NOT_FOUND;
constexpr Error kErrorNoBufs                  = TY_ERROR_NO_BUFS;
constexpr Error kErrorInvalidArgs             = TY_ERROR_INVALID_ARGS;
constexpr Error kErrorParse                   = TY_ERROR_PARSE;
constexpr Error kErrorFailed                  = TY_ERROR_FAILED;
constexpr Error kErrorGeneric                 = TY_ERROR_GENERIC;

constexpr uint8_t kNumErrors = TY_NUM_ERRORS;

/**
 * Converts an `Error` into a string.
 *
 * @param[in]  aError     An error.
 *
 * @returns  A string representation of @p aError.
 */
const char *ErrorToString(Error aError);

} // namespace tiny

#endif // ERROR_HPP_
