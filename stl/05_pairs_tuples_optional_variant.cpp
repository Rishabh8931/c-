#include <iostream>
#include <optional>
#include <tuple>
#include <variant>

/*
    PAIR, TUPLE, OPTIONAL, AND VARIANT
    ==================================
    - pair stores exactly two values, possibly of different types.
    - tuple stores a fixed number of values of different types.
    - optional<T> represents either a T or no value.
    - variant<T...> represents one value from a fixed set of types.

    These types make absence and alternatives explicit instead of using
    magic values or unsafe void pointers.
*/

std::optional<int> find_score(bool found) {
    if (found) {
        return 95;
    }
    return std::nullopt;
}

int main() {
    std::pair<std::string, int> student{"Ada", 95};
    auto [name, score] = student;

    auto location = std::make_tuple("London", 51.5, -0.1);
    std::cout << name << ": " << score
              << ", city: " << std::get<0>(location) << '\n';

    if (auto result = find_score(true)) {
        std::cout << "optional score: " << *result << '\n';
    }

    std::variant<int, std::string> answer = "success";
    std::visit([](const auto& item) { std::cout << "variant: " << item << '\n'; },
               answer);
}
