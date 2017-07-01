
#include <memory>
#include <vector>

#include "gtest\gtest.h"
#include "gmock\gmock.h"

#include "JMWorker.h"
#include "JMWorker.cpp"

namespace JM
{

    class JMWorkerTest : public ::testing::Test
    {
    protected:
        std::unique_ptr<JMWorker> worker_1;
        std::unique_ptr<JMWorker> worker_2;
    };

    TEST_F(JMWorkerTest, WorkerCompare) {
        const Uint64 guid_1 = 10;
        const Uint64 guid_2 = 20;
        worker_1.reset(new JMWorker(guid_1, nullptr));
        worker_2.reset(new JMWorker(guid_2, nullptr));

        EXPECT_TRUE(worker_1 != worker_2);
        EXPECT_EQ(guid_1, worker_1->GetWorkerGUID());
        EXPECT_EQ(guid_2, worker_2->GetWorkerGUID());
        EXPECT_EQ(WorkerInterface::Initialized, worker_1->GetWorkerStatus());
        EXPECT_EQ(WorkerInterface::Initialized, worker_2->GetWorkerStatus());
    }

}

