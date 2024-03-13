#pragma once

#include "task.hpp"
#include "types.hpp"
#include <vector>

namespace scheduling {

class Step : public Task
{

protected:
    JobID                    job_id_;
    StepID                   step_id_;
    std::vector<AvblMachine> avbl_machine_list_;
};

}   // namespace scheduling