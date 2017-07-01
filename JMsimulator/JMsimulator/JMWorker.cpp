#include "stdafx.h"
#include "JMWorker.h"

namespace JM
{
    JMWorker::JMWorker(const Uint64& worker_guid, WorkerContainerInterface * worker_container)
        : worker_guid_(worker_guid),
          worker_container_(worker_container),
          worker_status_(Initialized) {}

    void JMWorker::Start()
    {
        // TODO
    }

    void JMWorker::Stop()
    {
        // TODO
    }

    const WorkerInterface::WorkerStatus& JMWorker::GetWorkerStatus()
    {
        MutexLock l(&mutex_);
        return worker_status_;
    }

    void JMWorker::SetWorkerStatus(const WorkerInterface::WorkerStatus& worker_status)
    {
        MutexLock l(&mutex_);
        worker_status_ = worker_status;
    }

}
