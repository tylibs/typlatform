// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#ifndef TY_NUMERIC_LIMITS_HPP_
#define TY_NUMERIC_LIMITS_HPP_

#include <stdint.h>

namespace tiny {

static constexpr uint8_t kBitsPerByte = 8; ///< Number of bits in a byte.

/**
 * Returns the bit-size (number of bits) of a given type or variable.
 *
 * @param[in] aItem   The item (type or variable or expression) to get the bit-size of.
 *
 * @returns Number of bits of @p aItem.
 */
#define BitSizeOf(aItem) (sizeof(aItem) * kBitsPerByte)

/**
 * Determines number of byes to represent a given number of bits.
 *
 * @param[in] aBitSize    The bit-size (number of bits).
 *
 * @returns Number of bytes to represent @p aBitSize.
 */
#define BytesForBitSize(aBitSize) static_cast<uint8_t>(((aBitSize) + (kBitsPerByte - 1)) / kBitsPerByte)

/**
 * Provides a way to query properties of arithmetic types.
 *
 * There are no members if `Type` is not a supported arithmetic type.
 */
template <typename Type> struct NumericLimits
{
};

// Specialization for different integral types.

template <> struct NumericLimits<int8_t>
{
    static constexpr int8_t kMin = INT8_MIN;
    static constexpr int8_t kMax = INT8_MAX;
};

template <> struct NumericLimits<int16_t>
{
    static constexpr int16_t kMin = INT16_MIN;
    static constexpr int16_t kMax = INT16_MAX;
};

template <> struct NumericLimits<int32_t>
{
    static constexpr int32_t kMin = INT32_MIN;
    static constexpr int32_t kMax = INT32_MAX;
};

template <> struct NumericLimits<int64_t>
{
    static constexpr int64_t kMin = INT64_MIN;
    static constexpr int64_t kMax = INT64_MAX;
};

template <> struct NumericLimits<uint8_t>
{
    static constexpr uint8_t kMin = 0;
    static constexpr uint8_t kMax = UINT8_MAX;
};

template <> struct NumericLimits<uint16_t>
{
    static constexpr uint16_t kMin = 0;
    static constexpr uint16_t kMax = UINT16_MAX;
};

template <> struct NumericLimits<uint32_t>
{
    static constexpr uint32_t kMin = 0;
    static constexpr uint32_t kMax = UINT32_MAX;
};

template <> struct NumericLimits<uint64_t>
{
    static constexpr uint64_t kMin = 0;
    static constexpr uint64_t kMax = UINT64_MAX;
};

} // namespace tiny

#endif // TY_NUMERIC_LIMITS_HPP_
