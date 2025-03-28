// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file includes definitions for locator class for Tiny objects.
 */

#ifndef LOCATOR_HPP_
#define LOCATOR_HPP_

#include "ty/ty-core-config.h"

#include <ty/platform/toolchain.h>

#include <stdint.h>

namespace ty {

class Instance;

#if !TY_CONFIG_MULTIPLE_INSTANCE_ENABLE
extern uint64_t gInstanceRaw[];
#endif

/**
 * @addtogroup core-locator
 *
 * @brief
 *   This module includes definitions for Tiny instance locator.
 *
 * @{
 */

/**
 * Implements `Get<Type>()` method for different `Type` objects belonging to the Tiny
 * instance.
 *
 * Users of this class MUST follow CRTP-style inheritance, i.e., the class `Class` itself should publicly inherit
 * from `GetProvider<Class>`.
 *
 * @tparam InstanceGetProvider   The template sub-lass used in CRTP style inheritance.
 *                               `InstanceGetProvider` MUST provide a method with the following signature:
 *                               `Instance &GetInstance(void) const`
 */
template <class InstanceGetProvider> class GetProvider
{
public:
    /**
     * Returns a reference to a given `Type` object belonging to the Tiny instance.
     *
     * For example, `Get<MeshForwarder>()` returns a reference to the `MeshForwarder` object of the instance.
     *
     * Note that any `Type` for which the `Get<Type>` is defined MUST be uniquely accessible from the Tiny
     * `Instance` through the member variable property hierarchy.
     *
     * @returns A reference to the `Type` object of the instance.
     */
    template <typename Type> inline Type &Get(void) const; // Implemented in `locator_getters.hpp`.

protected:
    GetProvider(void) = default;
};

/**
 * Implements a locator for an Tiny Instance object.
 *
 * The `InstanceLocator` is used as base class of almost all other Tiny classes. It provides a way for an object
 * to get to its owning/parent Tiny `Instance` and also any other `Type` within the `Instance` member variable
 * property hierarchy (using `Get<Type>()` method).
 *
 * If multiple-instance feature is supported, the owning/parent Tiny `Instance` is tracked as a reference. In the
 * single-instance case, this class becomes an empty base class.
 */
class InstanceLocator : public GetProvider<InstanceLocator>
{
    friend class InstanceLocatorInit;

public:
    /**
     * Returns a reference to the parent Tiny Instance.
     *
     * @returns A reference to the parent otInstance.
     */
#if TY_CONFIG_MULTIPLE_INSTANCE_ENABLE
    Instance &GetInstance(void) const { return *mInstance; }
#else
    Instance &GetInstance(void) const { return *reinterpret_cast<Instance *>(&gInstanceRaw); }
#endif

protected:
    /**
     * Initializes the object.
     *
     * @param[in]  aInstance  A reference to the Tiny Instance.
     */
    explicit InstanceLocator(Instance &aInstance)
#if TY_CONFIG_MULTIPLE_INSTANCE_ENABLE
        : mInstance(&aInstance)
#endif
    {
        TY_UNUSED_VARIABLE(aInstance);
    }

private:
    InstanceLocator(void) = default;

#if TY_CONFIG_MULTIPLE_INSTANCE_ENABLE
    Instance *mInstance;
#endif
};

/**
 * Implements a locator for an Tiny Instance object.
 *
 * The `InstanceLocatorInit` is similar to `InstanceLocator` but provides a default constructor (instead of a
 * parameterized one) and allows an inheriting class to initialize the object (set the Tiny Instance) post
 * constructor call using the `Init()` method. This class is intended for types that require a default constructor and
 * cannot use a parameterized one. (e.g., `Neighbor`/`Child`/`Router` classes which are used as a C array element type
 * in`ChildTable`/`RouterTable`).
 *
 * The inheriting class from `InstanceLocatorInit` should ensure that object is properly initialized after the object
 * is created and more importantly that it is re-initialized when/if it is cleared or reset.
 */
class InstanceLocatorInit : public InstanceLocator
{
protected:
    /**
     * This is the default constructor for the `InstanceLocatorInit` object.
     */
    InstanceLocatorInit(void)
        : InstanceLocator()
    {
    }

    /**
     * This method (re)initializes the object and sets the Tiny Instance.
     *
     * @param[in] aInstance  A reference to the Tiny Instance.
     */
    void Init(Instance &aInstance)
    {
#if TY_CONFIG_MULTIPLE_INSTANCE_ENABLE
        mInstance = &aInstance;
#endif
        TY_UNUSED_VARIABLE(aInstance);
    }
};

/**
 * @}
 */

} // namespace ty

#endif // LOCATOR_HPP_
