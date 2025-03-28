// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <ty/log.hpp>
#include <ty/common/as_core_type.hpp>
#include <ty/common/non_copyable.hpp>

typedef struct tinyInstance
{
} tinyInstance;

namespace ty {

/**
 * Represents a Tiny instance.
 *
 * Contains all the components used by Tiny
 */
class Instance : public tinyInstance, private NonCopyable
{
public:
    /**
     * Initializes the single Tiny instance.
     *
     * Initializes Tiny and prepares it for subsequent Tiny API calls. This function must be
     * called before any other calls to Tiny.
     *
     * @returns A reference to the single Tiny instance.
     */
    static Instance &InitSingle(void);
    /**
     * Returns a reference to the single OpenThread instance.
     *
     * @returns A reference to the single OpenThread instance.
     */
    static Instance &Get(void);
    /**
     * Indicates whether or not the instance is valid/initialized and not yet finalized.
     *
     * @returns TRUE if the instance is valid/initialized, FALSE otherwise.
     */
    bool IsInitialized(void) const { return mIsInitialized; }

    /**
     * Returns the active log level.
     *
     * @returns The log level.
     */
    static LogLevel GetLogLevel(void)
#if TY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
    {
        return sLogLevel;
    }
#else
    {
        return static_cast<LogLevel>(TY_CONFIG_LOG_LEVEL);
    }
#endif

#if TY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
    /**
     * Sets the log level.
     *
     * @param[in] aLogLevel  A log level.
     */
    static void SetLogLevel(LogLevel aLogLevel);
#endif

    /**
     * Finalizes the OpenThread instance.
     *
     * Should be called when OpenThread instance is no longer in use.
     */
    void Finalize(void);
    /**
     * Returns a reference to a given `Type` object belonging to the OpenThread instance.
     *
     * For example, `Get<MeshForwarder>()` returns a reference to the `MeshForwarder` object of the instance.
     *
     * Note that any `Type` for which the `Get<Type>` is defined MUST be uniquely accessible from the OpenThread
     * `Instance` through the member variable property hierarchy.
     *
     * Specializations of the `Get<Type>()` method are defined in this file after the `Instance` class definition.
     *
     * @returns A reference to the `Type` object of the instance.
     */
    template <typename Type> inline Type &Get(void);

private:
    Instance(void);
    void AfterInit(void);
#if TY_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
    static LogLevel sLogLevel;
#endif
    bool mIsInitialized;
};

DefineCoreType(tinyInstance, Instance);

template <> inline Instance &Instance::Get(void)
{
    return *this;
}
} // namespace ty

#endif // INSTANCE_H_
