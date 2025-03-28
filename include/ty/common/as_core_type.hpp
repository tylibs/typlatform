// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file includes helper functions to convert between public OT C structs and corresponding core C++ classes.
 */

#ifndef AS_CORE_TYPE_HPP_
#define AS_CORE_TYPE_HPP_

#include "ty/ty-core-config.h"

#include "ty/common/debug.hpp"

namespace tiny {

/**
 * Relates a given public OT type to its corresponding core C++ class/type.
 *
 * @tparam FromType  The public OT type.
 *
 * Specializations of this template struct are provided for different `FromType` which include a member type definition
 * named `Type` to provide the corresponding core class/type related to `FromType.
 *
 * For example, `CoreType<otIp6Address>::Type` is defined as `Ip6::Address`.
 */
template <typename FromType> struct CoreType;

/**
 * Converts a pointer to public OT type (C struct) to the corresponding core C++ type reference.
 *
 * @tparam Type   The public OT type to convert.
 *
 * @param[in] aObject   A pointer to the object to convert.
 *
 * @returns A reference of the corresponding C++ type matching @p aObject.
 */
template <typename Type> typename CoreType<Type>::Type &AsCoreType(Type *aObject)
{
    AssertPointerIsNotNull(aObject);

    return *static_cast<typename CoreType<Type>::Type *>(aObject);
}

/**
 * Converts a const pointer to public OT type (C struct) to the corresponding core C++ type reference.
 *
 * @tparam Type   The public OT type to convert.
 *
 * @param[in] aObject   A const pointer to the object to convert.
 *
 * @returns A const reference of the corresponding C++ type matching @p aObject.
 */
template <typename Type> const typename CoreType<Type>::Type &AsCoreType(const Type *aObject)
{
    AssertPointerIsNotNull(aObject);

    return *static_cast<const typename CoreType<Type>::Type *>(aObject);
}

/**
 * Converts a pointer to public OT type (C struct) to the corresponding core C++ type pointer.
 *
 * @tparam Type   The public OT type to convert.
 *
 * @param[in] aObject   A pointer to the object to convert.
 *
 * @returns A pointer of the corresponding C++ type matching @p aObject.
 */
template <typename Type> typename CoreType<Type>::Type *AsCoreTypePtr(Type *aObject)
{
    return static_cast<typename CoreType<Type>::Type *>(aObject);
}

/**
 * Converts a const pointer to public OT type (C struct) to the corresponding core C++ type pointer.
 *
 * @tparam Type   The public OT type to convert.
 *
 * @param[in] aObject   A pointer to the object to convert.
 *
 * @returns A const pointer of the corresponding C++ type matching @p aObject.
 */
template <typename Type> const typename CoreType<Type>::Type *AsCoreTypePtr(const Type *aObject)
{
    return static_cast<const typename CoreType<Type>::Type *>(aObject);
}

/**
 * Maps two enumeration types.
 *
 * @tparam FromEnumType  The enum type.
 *
 * Specializations of this template struct are provided which include a member type definition named `Type` to provide
 * the related `enum` type mapped with `FromEnumType`.
 *
 * For example, `MappedEnum<otMacFilterAddressMode>::Type` is defined as `Mac::Filter::Mode`.
 */
template <typename FromEnumType> struct MappedEnum;

/**
 * Convert an enumeration type value to a related enumeration type value.
 *
 * @param[in] aValue   The enumeration value to convert
 *
 * @returns The matching enumeration value.
 */
template <typename EnumType> const typename MappedEnum<EnumType>::Type MapEnum(EnumType aValue)
{
    return static_cast<typename MappedEnum<EnumType>::Type>(aValue);
}

// Helper macro to define specialization of `CoreType` struct relating `BaseType` with `SubType`.
#define DefineCoreType(BaseType, SubType) \
    template <> struct CoreType<BaseType> \
    {                                     \
        using Type = SubType;             \
    }

// Helper macro to map two related enumeration types.
#define DefineMapEnum(FirstEnumType, SecondEnumType) \
    template <> struct MappedEnum<FirstEnumType>     \
    {                                                \
        using Type = SecondEnumType;                 \
    };                                               \
                                                     \
    template <> struct MappedEnum<SecondEnumType>    \
    {                                                \
        using Type = FirstEnumType;                  \
    }

} // namespace tiny

#endif // AS_CORE_TYPE_HPP_
