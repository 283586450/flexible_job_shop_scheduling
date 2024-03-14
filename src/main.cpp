#include <iostream>

#include <fmt/core.h>

#include "example.hpp"
#include "solution.hpp"

int main()
{
    // std::cout << "a + b = " << add(3, 2) << '\n';
    std::cout << "Hello, World!" << '\n';

    scheduling::Solution solution;
    scheduling::Example  example(2);

    example.add_precedent_constraint(3);
    // example.add_subsequent_constraint(0);
    example.add_subsequent_constraint(6);

    auto constraints = example.get_precedence_constraints();
    for (auto& constraint : constraints) {
        fmt::print(
            "constraint: {} -> {}\n", constraint.first, constraint.second);
    }

    auto results = example.checkPrecedenceConstraints(solution);

    if (results.empty()) {
        fmt::print("No constraints violated\n");
    }
    else {
        for (auto& result : results) {
            fmt::print("result: {}: {} -> {}\n",
                       result.first,
                       result.second.first,
                       result.second.second);
        }
    }

    // example.print_precedence_constraints();



    // arithmetic::hello();
    return EXIT_SUCCESS;
}
