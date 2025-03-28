// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

#include "tiny/instance.h"
#include "instance.hpp"
#include "tiny/common/as_core_type.hpp"
#include "tiny/common/code_utils.hpp"
#include "tiny/common/new.hpp"

/********************************************
 * C API
 *******************************************/
tinyInstance *tinyInstanceInitSingle(void)
{
    return &tiny::Instance::InitSingle();
}
tinyInstance *tinyInstanceFinalize(void)
{
    return &tiny::Instance::InitSingle();
}
void tinyInstanceFinalize(tinyInstance *aInstance)
{
    tiny::AsCoreType(aInstance).Finalize();
}

// void tinyInstanceReset(tinyInstance *aInstance)
// {
//     tiny::AsCoreType(aInstance).Reset();
// }

/********************************************
 * C++ Implementation
 *******************************************/
namespace tiny {
// Define the raw storage used for Tiny instance (in single-instance case).
TY_DEFINE_ALIGNED_VAR(gInstanceRaw, sizeof(Instance), uint64_t);

Instance::Instance(void) {}

Instance &Instance::InitSingle(void)
{
    Instance *instance = &Get();

    VerifyOrExit(!instance->mIsInitialized);

    instance = new (&gInstanceRaw) Instance();

    instance->AfterInit();

exit:
    return *instance;
}

Instance &Instance::Get(void)
{
    void *instance = &gInstanceRaw;

    return *static_cast<Instance *>(instance);
}

void Instance::AfterInit(void)
{
    mIsInitialized = true;
}

void Instance::Finalize(void)
{
    VerifyOrExit(mIsInitialized);

    mIsInitialized = false;

    this->~Instance();

exit:
    return;
}
} // namespace tiny
