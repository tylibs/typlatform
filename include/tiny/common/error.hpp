/**
 * @file
 *   This file defines the errors used by Tiny core.
 */

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include "tiny/tiny-core-config.h"

#include <tiny/error.h>

#include <stdint.h>

namespace tiny {

/**
 * Represents error codes used by Tiny core modules.
 */
typedef tinyError Error;

/*
 * The `TINY_ERROR_*` enumeration values are re-defined using `kError` style format.
 * See `tiny/error.h` for more details about each error.
 */
constexpr Error kErrorNone                    = TINY_ERROR_NONE;
constexpr Error kErrorSubscriberCountExceeded = TINY_ERROR_SUBSCRIBER_COUNT_EXCEEDED;
constexpr Error kErrorNotFound                = TINY_ERROR_NOT_FOUND;
constexpr Error kErrorNoBufs                  = TINY_ERROR_NO_BUFS;
constexpr Error kErrorInvalidArgs             = TINY_ERROR_INVALID_ARGS;
constexpr Error kErrorParse                   = TINY_ERROR_PARSE;
constexpr Error kErrorFailed                  = TINY_ERROR_FAILED;
constexpr Error kErrorGeneric                 = TINY_ERROR_GENERIC;

constexpr uint8_t kNumErrors = TINY_NUM_ERRORS;

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
