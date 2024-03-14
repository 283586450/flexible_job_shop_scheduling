#pragma once

#include "objective.hpp"
#include "pm.hpp"
#include "types.hpp"

namespace scheduling {

class PMObjective : public Objective
{
public:
    explicit PMObjective(const std::shared_ptr<PM>& pm_ptr)
        : pm_ptr_(pm_ptr){};

    ObjectiveValue operator()() override;

private:

    std::shared_ptr<PM> pm_ptr_;
    int                 priority_ = 0;
};

}   // namespace scheduling