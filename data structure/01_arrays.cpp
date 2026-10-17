#include <iostream>
#include <array>
#include <vector>

/*
    ARRAYS
    ======
    An array stores elements of the same type in contiguous memory.

    - Fixed array: size is known at compile time.
    - std::array: fixed-size array with a safer, useful interface.
    - std::vector: resizable contiguous array; usually the best choice
      when the size is not known in advance.

    Complexity:
    - Read/write by index: O(1)
    - Search in an unsorted array: O(n)
    - Insert/remove in the middle: O(n), because elements move
    - Add at the end of vector: O(1) amortized
*/

int main() {
    std::array<int, 5> fixed{10, 20, 30, 40, 50};
    std::cout << "fixed[2] = " << fixed[2] << '\n';

    std::vector<int> numbers{1, 2, 3};
    numbers.push_back(4); // May allocate a larger block and copy elements.
    numbers.insert(numbers.begin() + 1, 99);
    numbers.erase(numbers.begin() + 2);

    std::cout << "vector: ";
    for (int number : numbers) {
        std::cout << number << ' ';
    }
    std::cout << "\nsize = " << numbers.size()
              << ", capacity = " << numbers.capacity() << '\n';
}
