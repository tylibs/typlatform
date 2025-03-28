// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file includes macros for parsing variadic arguments.
 */

#ifndef COMMON_ARG_MACROS_HPP_
#define COMMON_ARG_MACROS_HPP_

/**
 * Returns the first argument in a list of input arguments.
 *
 * @param[in] ...   A list of arguments (MUST contain at least one).
 *
 * @returns The first argument in the given list of input arguments.
 */
#define TY_FIRST_ARG(...) _TY_GET_FIRST_ARG(__VA_ARGS__, JUNK)

/**
 * Returns the second argument in a list of input arguments if any.
 *
 * @note: This macro works when the list contains either one or two arguments.
 *
 * @param[in] ...   A list of arguments (MUST contain either one or two arguments).
 *
 * @returns The second argument if any.
 */
#define TY_SECOND_ARG(...) _TY_GET_SECOND_ARG(_TY_HAS_ONE_ARG_OR_TWO_ARGS(__VA_ARGS__), __VA_ARGS__)

/**
 * Expands to comma separated list of arguments excluding the first one.
 *
 * If there is only one argument, it expands to empty. If there is more than one argument, it expands to an initial
 * comma followed by all the rest of arguments excluding the first one.
 *
 * @note: This macro supports up to 20 arguments.
 *
 * @param[in] ...  A list of arguments (MUST contain at least one).
 *
 * @returns A comma separated list of arguments excluding the first one.
 */
#define TY_REST_ARGS(...) _TY_GET_REST_ARGS(_TY_HAS_ONE_ARG_VS_TWO_OR_MORE(__VA_ARGS__), __VA_ARGS__)

//---------------------------------------------------------------------------------------------------------------------
// Private/local macros - for use in this header only.

#define _TY_GET_FIRST_ARG(aFirst, ...) aFirst

#define _TY_HAS_ONE_ARG_OR_TWO_ARGS(...) _TY_SELECT_3(__VA_ARGS__, TWO_ARGS, ONE_ARG, JUNK)
#define _TY_SELECT_3(a1, a2, a3, ...) a3

#define _TY_GET_SECOND_ARG(aNum, ...) _TY_GET_SECOND_APPEND_NUM_ARGS(aNum, __VA_ARGS__)
#define _TY_GET_SECOND_APPEND_NUM_ARGS(aNum, ...) _TY_GET_SECOND_WITH_##aNum(__VA_ARGS__)

#define _TY_GET_SECOND_WITH_ONE_ARG(aFirst)
#define _TY_GET_SECOND_WITH_TWO_ARGS(aFirst, aSecond) aSecond

#define _TY_GET_REST_ARGS(aNum, ...) _TY_GET_REST_APPEND_NUM_ARGS(aNum, __VA_ARGS__)
#define _TY_GET_REST_APPEND_NUM_ARGS(aNum, ...) _TY_GET_REST_WITH_##aNum(__VA_ARGS__)

#define _TY_GET_REST_WITH_ONE_ARG(aFirst)
#define _TY_GET_REST_WITH_TWO_OR_MORE_ARGS(aFirst, ...) , __VA_ARGS__

#define _TY_HAS_ONE_ARG_VS_TWO_OR_MORE(...)                                                                 \
    _TY_SELECT_20(__VA_ARGS__, TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS,      \
                  TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, \
                  TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, \
                  TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, TWO_OR_MORE_ARGS, ONE_ARG, JUNK)

#define _TY_SELECT_20(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, ...) \
    a20

#endif // COMMON_ARG_MACROS_HPP_
