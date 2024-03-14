#pragma once

#include "constraint.hpp"
#include "machine.hpp"
#include "types.hpp"
#include <memory>

namespace scheduling {

class MachineConstraint : public Constraint
{
public:
    explicit MachineConstraint(const std::shared_ptr<Machine>& machine_ptr)
        : machine_ptr_(machine_ptr){};

    bool           operator()() const override;
    ObjectiveValue penalty() override;

protected:
    std::shared_ptr<Machine> machine_ptr_;
};

class NooverLapConstraint : public MachineConstraint
{
public:
    explicit NooverLapConstraint(const std::shared_ptr<Machine>& machine_ptr)
        : MachineConstraint(machine_ptr){};

    bool           operator()() const final;
    ObjectiveValue penalty() final;
};
}   // namespace scheduling
