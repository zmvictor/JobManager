#pragma once

#include <unordered_set>
#include "WorkerContainerInterface.h"
#include "mutex_lock.h"

namespace JM
{
    class JMWorkerContainer : public WorkerContainerInterface
    {
    public:
        JMWorkerContainer();
        ~JMWorkerContainer() {};

        virtual Uint64 GetNumberOfAllowedWorkers() override;
        virtual void SetNumberOfAllowedWorkers(const Uint64& worker_cnt) override;

        // Caller requires to have worker_cnt workers started
        virtual bool MaintainWorkers(const Uint64& allowed_worker_cnt) override;

    private:
        std::mutex  mutex_;
        Uint64      allowed_worker_cnt_;   // GUARDED_BY mutex_
        
    };
}

