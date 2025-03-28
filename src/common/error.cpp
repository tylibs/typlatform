
// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#include "ty/common/error.hpp"
#include "ty/common/array.hpp"

namespace tiny {

const char *ErrorToString(Error aError)
{
    static const char *const kErrorStrings[kNumErrors] = {
        "OK",                      // (0)  kErrorNone
        "SubscriberCountExceeded", // (1)  kErrorSubscriberCountExceeded
        "NotFound",                // (2)  kErrorNotFound
        "NoBufs",                  // (3)  kErrorNoBufs
        "InvalidArgs",             // (4)  kErrorInvalidArgs
        "Parse",                   // (5)  kErrorParse
        "Failed",                  // (6)  kErrorFailed
    };

    return aError < GetArrayLength(kErrorStrings) ? kErrorStrings[aError] : "UnknownErrorType";
}

} // namespace tiny
