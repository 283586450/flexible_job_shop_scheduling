#pragma once

#include <functional>
#include <string>



namespace scheduling {
class Solution;


struct InfeasibleConstraint
{
    int                           priority = 0;
    std::string                   message;
    std::function<bool(Solution)> repair_func;

    bool operator<(const InfeasibleConstraint& other) const
    {
        return priority > other.priority;
        // 因为priority_queue是一个最大堆，所以需要反向，优先级最低的，放在最上面
    }
};


}   // namespace scheduling