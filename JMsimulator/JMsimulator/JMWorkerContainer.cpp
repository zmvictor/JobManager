#include "stdafx.h"
#include "JMWorkerContainer.h"

namespace JM
{
    JMWorkerContainer::JMWorkerContainer() 
        : allowed_worker_cnt_(0) {}
 
    Uint64 JMWorkerContainer::GetNumberOfAllowedWorkers()
    {
        MutexLock l(&mutex_);
        return allowed_worker_cnt_;
    }

    void JMWorkerContainer::SetNumberOfAllowedWorkers(const Uint64 & allowed_worker_cnt)
    {
        MutexLock l(&mutex_);
        allowed_worker_cnt_ = allowed_worker_cnt;
    }

    bool JMWorkerContainer::MaintainWorkers(const Uint64 & worker_cnt)
    {
        return false;
    }

}
