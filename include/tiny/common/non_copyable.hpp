// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file includes a common base class for disabling copying.
 */

#ifndef NON_COPYABLE_HPP_
#define NON_COPYABLE_HPP_

namespace tiny {

/**
 * Makes any class that derives from it non-copyable. It is intended to be used as a private base class.
 */
class NonCopyable
{
public:
    NonCopyable(const NonCopyable &)            = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;

protected:
    NonCopyable(void) = default;
};

} // namespace tiny

#endif // NON_COPYABLE_HPP_
