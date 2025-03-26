#ifndef COMMON_CODE_UTILS_H_
#define COMMON_CODE_UTILS_H_

#include "common/arg_macros.hpp"

// Allocate the structure using "raw" storage.
#define TINY_DEFINE_ALIGNED_VAR(name, size, align_type) \
    align_type name[(((size) + (sizeof(align_type) - 1)) / sizeof(align_type))]

/**
 * Checks for the specified status, which is expected to commonly be successful, and branches to the local
 * label 'exit' if the status is unsuccessful.
 *
 * @param[in]  aStatus     A scalar status to be evaluated against zero (0).
 */
#define SuccessOrExit(aStatus) \
    do                         \
    {                          \
        if ((aStatus) != 0)    \
        {                      \
            goto exit;         \
        }                      \
    } while (false)

/**
 * Checks for the specified condition, which is expected to commonly be true, and both executes @a ... and
 * branches to the local label 'exit' if the condition is false.
 *
 * @param[in]  aCondition  A Boolean expression to be evaluated.
 * @param[in]  aAction     An optional expression or block to execute when the assertion fails.
 */
#define VerifyOrExit(...)                   \
    do                                      \
    {                                       \
        if (!(TINY_FIRST_ARG(__VA_ARGS__))) \
        {                                   \
            TINY_SECOND_ARG(__VA_ARGS__);   \
            goto exit;                      \
        }                                   \
    } while (false)

#endif // COMMON_CODE_UTILS_H_
