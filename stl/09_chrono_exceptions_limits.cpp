#include <chrono>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <thread>

/*
    OTHER IMPORTANT STL COMPONENTS
    ===============================
    - chrono represents durations, time points, and clocks.
    - limits provides type properties such as min/max.
    - exceptions provide standard error classes.
    - thread (from the standard library) supports basic concurrency.

    Use exceptions for exceptional failures and catch by const reference.
    Prefer a specific exception type such as out_of_range over catch(...).
*/

int main() {
    const auto start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    const auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);

    std::cout << "elapsed microseconds: " << elapsed.count() << '\n';
    std::cout << "largest int: " << std::numeric_limits<int>::max() << '\n';

    try {
        throw std::out_of_range("example range error");
    } catch (const std::out_of_range& error) {
        std::cout << "caught: " << error.what() << '\n';
    }
}
