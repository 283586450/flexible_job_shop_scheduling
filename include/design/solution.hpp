#pragma once

#include <map>
#include <queue>

#include "infeasibleConstraint.hpp"

namespace scheduling {

class Solution
{
public:
    // [[nodiscard]] virtual int getStartTime(int stepID) const = 0;

    // Solution(const Solution&)            = default;
    // Solution(Solution&&)                 = delete;
    // Solution& operator=(const Solution&) = default;
    // Solution& operator=(Solution&&)      = delete;
    // virtual ~Solution()                  = default;
    Solution()
    {
        for (int i = 0; i < 10; i++) {
            start_times_[i] = i * i;
        }
    };

    [[nodiscard]] int getStartTime(int stepID) const
    {
        return start_times_.at(stepID);
    };

    bool repair_solution();

private:
    std::map<int, int>                        start_times_;
    std::vector<InfeasibleConstraint>         infeasible_constraints_;
    std::priority_queue<InfeasibleConstraint> infeasible_constraints_queue_;
};

}   // namespace scheduling
