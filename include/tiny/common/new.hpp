// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file defines the new operator used by OpenThread.
 */

#ifndef COMMON_NEW_HPP_
#define COMMON_NEW_HPP_

#include <stddef.h>

#include "tiny/platform/toolchain.h"

inline void *operator new(size_t, void *p) throw()
{
    return p;
}

#endif // OT_INCLUDE_COMMON_NEW_HPP_
