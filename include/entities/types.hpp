#pragma once

#include <utility>
#include <vector>

namespace scheduling {

using TimeStamp    = int;
using TimeDuration = int;

using MachineID       = int;
using StepID          = int;
using JobID           = int;
using PTime           = int;
using TransferTime    = int;
using ObjectiveValue  = float;
using TaskID          = std::pair<JobID, StepID>;
using AvblMachine     = std::pair<MachineID, PTime>;
using MachineSchedule = std::vector<TaskID>;

enum class PMType
{
    BY_PIECES,
    BY_CALANDER
};

enum class TaskType
{
    PM,
    STEP
};

}   // namespace scheduling