#include "tiny/instance.h"
#include "instance.hpp"
#include "tiny/common/code_utils.hpp"
#include "tiny/common/new.hpp"

/********************************************
 * C API
 *******************************************/

tinyInstance *tinyInstanceInitSingle(void)
{
    return &tiny::Instance::InitSingle();
}

/********************************************
 * C++ Implementation
 *******************************************/
namespace tiny {
// Define the raw storage used for Tiny instance (in single-instance case).
TINY_DEFINE_ALIGNED_VAR(gInstanceRaw, sizeof(Instance), uint64_t);

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
