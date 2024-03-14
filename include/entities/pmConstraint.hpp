#pragma once

#include <memory>

#include "constraint.hpp"
#include "pm.hpp"
#include "types.hpp"

namespace scheduling {

class PMConstraint : public Constraint
{
public:
    explicit PMConstraint(const std::shared_ptr<PM>& pm_ptr)
        : pm_ptr_(pm_ptr){};

    bool           operator()() const override;
    ObjectiveValue penalty() override;

private:
    std::shared_ptr<PM> pm_ptr_;
};

}   // namespace scheduling