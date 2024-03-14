#pragma once

#include "task.hpp"
#include "types.hpp"

namespace scheduling {

class PM : public Task
{
protected:
    PMType       pm_type_;
    int          pm_index_;
    TimeDuration mttr_;
    TimeDuration mtbf_;
    TimeStamp    init_point_;
};

}   // namespace scheduling