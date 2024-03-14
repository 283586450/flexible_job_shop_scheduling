#pragma once

#include "types.hpp"

namespace scheduling {

class Objective
{
public:
    virtual ObjectiveValue operator()() = 0;
};

}   // namespace scheduling