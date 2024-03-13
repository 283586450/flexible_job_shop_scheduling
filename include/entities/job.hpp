#pragma once

#include "step.hpp"
#include "types.hpp"

namespace scheduling {

class Job
{
protected:
    JobID             job_id_;
    std::vector<Step> step_list_;
};

}   // namespace scheduling