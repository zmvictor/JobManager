#pragma once

namespace JM
{
    class WorkerManagerInterface
    {
    public:
        virtual ~WorkerManagerInterface() {};

        // start/stop the service
        virtual void Start() = 0;
        virtual void Stop() = 0;

    };
}