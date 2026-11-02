#pragma once

#include <Types.h>

#include <framework/seadCalculateTask.h>

// vtable Address: 0x60C2A0C0
class AppCalculateTask : public sead::CalculateTask {
public:
    // Address: deleted
    AppCalculateTask(const sead::TaskConstructArg& arg);

    // Address: 0x60818330
    AppCalculateTask(const sead::TaskConstructArg& arg, const char* task_name);

    // Address: 0x608EBCB0
    ~AppCalculateTask() override = default;

    // Address: 0x60818350
    void prepare() override;

    void beforePrepare_();

    void afterPrepare_();

    void prepareImpl_();

    void prepareDestory();
};
SIZE_ASSERT(AppCalculateTask, 0xC0);
