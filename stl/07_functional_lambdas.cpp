#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

/*
    FUNCTIONAL UTILITIES
    =====================
    - Lambda: an inline callable object, often used with algorithms.
    - std::function: type-erased wrapper that can store compatible callables.
    - std::bind: adapts argument order/values; lambdas are often clearer.
    - std::ref: passes an object by reference when a copy would otherwise occur.

    Lambdas can capture values [x] or references [&x]. Be careful that a
    reference capture must not outlive the referenced object.
*/

int main() {
    int multiplier = 3;
    auto multiply = [multiplier](int value) { return value * multiplier; };

    std::function<int(int)> operation = multiply;
    std::cout << "operation(4): " << operation(4) << '\n';

    std::vector<int> values{1, 2, 3, 4};
    int sum = std::accumulate(values.begin(), values.end(), 0,
                              [](int total, int value) {
                                  return total + value;
                              });
    std::cout << "sum: " << sum << '\n';
}
