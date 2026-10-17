#include <cmath>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

/*
    NUMERIC UTILITIES
    =================
    <numeric> contains range-based numeric operations:
    - accumulate/fold a range into a result
    - reduce, inner_product, adjacent_difference
    - iota fills a range with increasing values
    - gcd/lcm calculate number-theory results

    <random> provides engines and distributions. Construct an engine once
    and use a distribution to produce values in the desired range.
*/

int main() {
    std::vector<int> values(5);
    std::iota(values.begin(), values.end(), 1);

    const int sum = std::accumulate(values.begin(), values.end(), 0);
    std::cout << "iota values sum: " << sum << '\n';
    std::cout << "gcd(84, 30): " << std::gcd(84, 30)
              << ", lcm(4, 6): " << std::lcm(4, 6) << '\n';

    std::mt19937 engine(42); // Fixed seed makes this demonstration repeatable.
    std::uniform_int_distribution<int> distribution(1, 6);
    std::cout << "random die roll: " << distribution(engine) << '\n';
}
