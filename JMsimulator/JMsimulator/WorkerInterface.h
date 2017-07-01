#pragma once
#include "stdafx.h"

class WorkerContainerInterface;

class WorkerInterface
{
public:
    enum WorkerStatus
    {
        Initialized,
        Dispatching,
        Running,
        Abandoned,
        Done
    };
    virtual ~WorkerInterface() {}

    // Start/stop worker instance
    virtual void Start() = 0;
    virtual void Stop() = 0;

    /* Getters w/o setters: attributes are ONLY intialized in ctor */

    // Global unique id
    virtual const Uint64& GetWorkerGUID() const = 0;
    // A worker instance must be running on the container
    // Currently we do not consider migration b/w containers
    virtual const WorkerContainerInterface* GetWorkerContainer() const = 0;
    virtual WorkerContainerInterface* GetWorkerContainer() = 0;

    /* getters/setters */

    virtual const WorkerStatus& GetWorkerStatus() = 0;
    virtual void SetWorkerStatus(const WorkerStatus& worker_status) = 0;

    // operators should be overrided
    virtual bool operator==(const WorkerInterface& other) = 0;
};
