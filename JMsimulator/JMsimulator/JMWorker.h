#pragma once
#include "WorkerInterface.h"
#include "mutex_lock.h"

namespace JM
{
    // Thread safe
    class JMWorker : public WorkerInterface
    {
    public:
        explicit JMWorker(const Uint64& worker_guid, 
                          WorkerContainerInterface* worker_container);
        virtual ~JMWorker() {};

        virtual void Start() override;
        virtual void Stop() override;

        virtual const Uint64& GetWorkerGUID() const override { return worker_guid_; }

        virtual const WorkerContainerInterface* GetWorkerContainer() const
            override { return worker_container_; }
        virtual WorkerContainerInterface* GetWorkerContainer() 
            override { return worker_container_; }
        
        virtual const WorkerStatus& GetWorkerStatus() override;
        virtual void SetWorkerStatus(const WorkerStatus& worker_status) override;

        virtual bool operator==(const WorkerInterface& other) 
            override { return this->worker_guid_ == other.GetWorkerGUID(); }
        
    private:
        Uint64                      worker_guid_;
        // not owned
        WorkerContainerInterface*   worker_container_;
        std::mutex                  mutex_;
        WorkerStatus                worker_status_;     // GUARDED_BY mutex_;
    };

}   // end of namespace JM
