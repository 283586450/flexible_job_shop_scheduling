#pragma once

#include "types.hpp"
namespace scheduling {

class Constraint
{
public:
    Constraint()                                        = default;
    Constraint(const Constraint&)                       = delete;
    Constraint(Constraint&&)                            = delete;
    Constraint&            operator=(const Constraint&) = delete;
    Constraint&            operator=(Constraint&&)      = delete;
    virtual bool           operator()() const           = 0;
    virtual ObjectiveValue penalty()                    = 0;
    virtual ~Constraint(){};
};

}   // namespace scheduling