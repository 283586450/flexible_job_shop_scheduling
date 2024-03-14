#pragma once

#include <algorithm>
#include <format>
#include <functional>
#include <iostream>
#include <map>
#include <ranges>
#include <utility>
#include <vector>


#include "solution.hpp"

namespace scheduling {





class Example
{
    using step_pair       = std::pair<int, int>;
    using validate_return = std::pair<bool, step_pair>;
    using constraint_func = std::function<validate_return(const Solution&)>;

private:
    int step_id_ = 0;
    // std::vector<constraint_func>         constraints_;
    std::map<step_pair, constraint_func> precedence_constraints_;


public:
    explicit Example(int step_id)
        : step_id_(step_id){};


public:
    void add_precedent_constraint(int stepID2)
    {
        constraint_func constraint = [this, stepID2](const Solution& solution) {
            // 获取 start_time1 和 start_time2
            int start_time1 = solution.getStartTime(step_id_);
            int start_time2 = solution.getStartTime(stepID2);

            // 检查 start_time1 是否小于 start_time2
            // return start_time1 < start_time2;
            if (start_time1 < start_time2) {
                return std::make_pair(true, std::make_pair(step_id_, stepID2));
            }
            else {
                return std::make_pair(false, std::make_pair(step_id_, stepID2));
            }
        };
        precedence_constraints_[std::make_pair(step_id_, stepID2)] = constraint;
    }

    void add_subsequent_constraint(int stepID2)
    {
        constraint_func constraint = [this, stepID2](const Solution& solution) {
            // 获取 start_time1 和 start_time2
            int start_time1 = solution.getStartTime(step_id_);
            int start_time2 = solution.getStartTime(stepID2);

            // 检查 start_time1 是否小于 start_time2
            // return start_time1 > start_time2;
            if (start_time1 > start_time2) {
                return std::make_pair(true, std::make_pair(stepID2, step_id_));
            }
            else {
                return std::make_pair(false, std::make_pair(stepID2, step_id_));
            }
        };
        precedence_constraints_[std::make_pair(stepID2, step_id_)] = constraint;
    }

    std::vector<std::pair<int, int>> get_precedence_constraints()
    {
        // std::vector<step_pair> result;
        // for (const auto& [steps, _] : precedence_constraints_) {
        //     result.push_back(steps);
        // }
        // return result;

        std::vector<step_pair> result(precedence_constraints_.size());
        std::ranges::transform(
            precedence_constraints_,
            result.begin(),
            [](const auto& map_element) { return map_element.first; });
        return result;
    }

    [[nodiscard]] std::vector<validate_return> checkPrecedenceConstraints(
        const Solution& solution) const
    {
        // std::vector<validate_return> results;
        // std::ranges::for_each(precedence_constraints_,
        //                       [&](const auto& constraint) {
        //                           auto result = constraint.second(solution);
        //                           if (!result.first) {
        //                               //   fmt::print("({}, {})\n",
        //                               //              result.second.first,
        //                               //              result.second.second);
        //                               results.push_back(result);
        //                           }
        //                       });
        // return results;

        std::vector<validate_return> results;
        auto constraints = precedence_constraints_ | std::ranges::views::values;
        std::ranges::for_each(constraints, [&](const auto& constraint) {
            auto result = constraint(solution);
            if (!result.first) {
                results.push_back(result);
            }
        });
        return results;
    }

    void print_precedence_constraints()
    {
        for (const auto& [steps, _] : precedence_constraints_) {
            std::cout << std::format("({}, {})\n", steps.first, steps.second);
        }
    }
};



}   // namespace scheduling
