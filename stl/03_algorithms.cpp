#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

/*
    STL ALGORITHMS
    ==============
    Algorithms operate on iterator ranges [first, last), where last is not
    included. This separation lets one algorithm work with many containers.

    Important groups:
    - searching: find, find_if, binary_search
    - ordering: sort, stable_sort, partial_sort
    - modifying: copy, fill, transform, reverse, remove
    - queries: all_of, any_of, none_of, count
    - numeric: accumulate, iota, inner_product

    Complexity examples:
    - find: O(n)
    - sort: O(n log n)
    - binary_search: O(log n) on sorted random-access data
    - accumulate: O(n)
*/

int main() {
    std::vector<int> values{5, 1, 4, 2, 3};
    std::sort(values.begin(), values.end());

    bool has_even = std::any_of(values.begin(), values.end(), [](int value) {
        return value % 2 == 0;
    });
    int sum = std::accumulate(values.begin(), values.end(), 0);
    auto found = std::find(values.begin(), values.end(), 4);

    std::vector<int> doubled(values.size());
    std::transform(values.begin(), values.end(), doubled.begin(),
                   [](int value) { return value * 2; });

    std::cout << "sorted: ";
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << "\nsum: " << sum
              << "\nhas even: " << std::boolalpha << has_even
              << "\nfound 4: " << (found != values.end()) << '\n';
}
