#pragma once

#include "job.hpp"
#include "jobConstraint.hpp"
#include "jobObjective.hpp"
#include "machine.hpp"
#include "machineConstraint.hpp"
#include "machineObjective.hpp"
#include "pmConstraint.hpp"
#include "pmObjective.hpp"
#include "problemConstraint.hpp"
#include "problemObjective.hpp"
#include "stepConstraint.hpp"
#include "stepObjectiev.hpp"
#include "types.hpp"
#include <memory>
#include <vector>

namespace scheduling {

class Problem
{

protected:
    std::vector<Job>                                job_list_;
    std::vector<Machine>                            machine_list_;
    TimeStamp                                       start_time_;
    TimeStamp                                       end_time_;
    TimeDuration                                    time_horizon_;
    std::vector<std::shared_ptr<PMConstraint>>      pm_constraint_list_;
    std::vector<std::shared_ptr<MachineConstraint>> machine_constraint_list_;
    std::vector<std::shared_ptr<StepConstraint>>    step_constraint_list_;
    std::vector<std::shared_ptr<JobConstraint>>     job_constraint_list_;
    std::vector<std::shared_ptr<ProblemConstraint>> problem_constraint_list_;

    std::vector<std::shared_ptr<PMObjective>>      pm_objective_list_;
    std::vector<std::shared_ptr<MachineObjective>> machine_objective_list_;
    std::vector<std::shared_ptr<StepObjective>>    step_objective_list_;
    std::vector<std::shared_ptr<JobObjective>>     job_objective_list_;
    std::vector<std::shared_ptr<ProblemObjective>> problem_objective_list_;

    ObjectiveValue objective_value_;
};


}   // namespace scheduling