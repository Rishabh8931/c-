#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

/*
    STL STRING TYPES
    ================
    std::string owns a mutable sequence of characters.
    std::string_view is a non-owning view; the referenced string must remain
    alive and unmoved for the view's lifetime.

    Useful operations:
    - size/empty: inspect
    - append/operator+: concatenate
    - find/substr: search and extract
    - compare: lexical comparison
    - getline: read a complete line

    std::stringstream parses or builds formatted text in memory.
*/

void print_view(std::string_view text) {
    std::cout << "view: " << text << '\n';
}

int main() {
    std::string language = "C++";
    language += " Standard Library";
    print_view(language);

    const auto position = language.find("Library");
    std::cout << "substring: " << language.substr(position) << '\n';

    std::stringstream numbers("10 20 30");
    int value = 0;
    int total = 0;
    while (numbers >> value) {
        total += value;
    }
    std::cout << "parsed total: " << total << '\n';
}
