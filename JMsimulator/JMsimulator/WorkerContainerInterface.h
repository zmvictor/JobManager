#pragma once

#include "stdafx.h"

class WorkerContainerInterface
{
public:
    ~WorkerContainerInterface() {};

    // Getter/setter of container capacity by the number of allowed workers
    // Implementation should keep thread safe
    virtual Uint64 GetNumberOfAllowedWorkers() = 0;
    virtual void SetNumberOfAllowedWorkers(const Uint64& worker_cnt) = 0;

    // Caller requires to have worker_cnt workers started
    virtual bool MaintainWorkers(const Uint64& worker_cnt) = 0;
};