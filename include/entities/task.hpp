#pragma once

#include "types.hpp"

namespace scheduling {

class Task
{
public:
    Task()                       = delete;
    Task(const Task&)            = delete;
    Task(Task&&)                 = delete;
    Task& operator=(const Task&) = delete;
    Task& operator=(Task&&)      = delete;
    virtual ~Task()              = default;

    bool operator<(const Task& other) const
    {
        return start_time_ < other.start_time_;
    }

protected:
    TaskType  task_type_;
    MachineID machine_id_;
    TimeStamp start_time_;
    TimeStamp end_time_;
};

}   // namespace scheduling