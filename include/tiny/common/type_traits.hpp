#ifndef TINY_TYPE_TRAITS_HPP_
#define TINY_TYPE_TRAITS_HPP_

namespace tiny {
namespace TypeTraits {

/**
 * Represents a true value (contains a `true` static `kValue` member variable).
 */
struct TrueValue
{
    constexpr static bool kValue = true; ///< true value.
};

/**
 * Represents a false value (contains a `false` static `kValue` member variable).
 */
struct FalseValue
{
    constexpr static bool kValue = false; ///< false value.
};

/**
 * Indicates whether or not a given template `Type` is a pointer type.
 *
 * The `constexpr` expression `IsPointer<Type>::kValue` would be `true` when the `Type` is a pointer, otherwise it
 * would be `false`.
 *
 * @tparam Type    A type to check if is a pointer.
 */
template <typename Type> struct IsPointer : public FalseValue
{
};

// Partial template specializations of the `IsPointer<Type>`

template <typename Type> struct IsPointer<Type *> : public TrueValue
{
};

template <typename Type> struct IsPointer<const Type *> : public TrueValue
{
};

template <typename Type> struct IsPointer<volatile Type *> : public TrueValue
{
};

template <typename Type> struct IsPointer<const volatile Type *> : TrueValue
{
};

/**
 * Indicates whether or not a given template `FirstType is the same as `SecondType`.
 *
 * The `constexpr` expression `IsSame<FirstType, SecondType>::kValue` would be `true` when the two types are the same,
 * otherwise it would be `false`.
 *
 * @tparam FirstType     The first type.
 * @tparam SecondType    The second type.
 */
template <typename FirstType, typename SecondType> struct IsSame : public FalseValue
{
};

template <typename Type> struct IsSame<Type, Type> : public TrueValue
{
};

/**
 * Selects between two given types based on a boolean condition at compile time.
 *
 * It provides member type named `Type` which is defined as `TypeOnTrue` if `kCondition` is `true` at compile time, or
 * as `TypeOnFalse` if `kCondition` is `false`.
 *
 * @tparam kCondition   The boolean condition which is used to select between the two types.
 * @tparam TypeOnTrue   The type to select when `kCondition` is `true`.
 * @tparam TypeOnFalse  The type to select when `kCondition` is `false`.
 */
template <bool kCondition, typename TypeOnTrue, typename TypeOnFalse> struct Conditional
{
    typedef TypeOnFalse Type; ///< The selected type based on `kCondition`.
};

template <typename TypeOnTrue, typename TypeOnFalse> struct Conditional<true, TypeOnTrue, TypeOnFalse>
{
    typedef TypeOnTrue Type;
};

/**
 * Determines the return type of a given function pointer type.
 *
 * It provides member type named `Type` which gives the return type of `HandlerType` function pointer.
 *
 * For example, `ReturnTypeOf<Error (*)(void *aContext)>::Type` would be `Error`.
 *
 * @tparam HandlerType   The function pointer type.
 */
template <typename HandlerType> struct ReturnTypeOf;

template <typename RetType, typename... Args> struct ReturnTypeOf<RetType (*)(Args...)>
{
    typedef RetType Type; ///< The return type.
};

/**
 * Determines the type of the first argument of a given function pointer type.
 *
 * It provides member type named `Type` which gives the first argument type of `HandlerType` function pointer.
 *
 * For example, `ReturnTypeOf<Error (*)(void *aContext)>::Type` would be `void *`.
 *
 * @tparam HandlerType   The function pointer type.
 */
template <typename HandlerType> struct FirstArgTypeOf;

template <typename RetType, typename FirstArgType, typename... Args>
struct FirstArgTypeOf<RetType (*)(FirstArgType, Args...)>
{
    typedef FirstArgType Type; ///< The first argument type.
};

} // namespace TypeTraits
} // namespace tiny

#endif // TINY_TYPE_TRAITS_HPP_
