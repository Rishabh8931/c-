#include <array>
#include <iostream>
#include <memory>
#include <string>

/*
    TRIE (PREFIX TREE)
    ==================
    A trie stores strings one character per tree level. Each path from the
    root represents a prefix; a terminal flag marks a complete stored word.

    For a word of length L:
    - insert/search: O(L)
    - memory: O(total characters), with an alphabet-dependent pointer cost

    Tries are useful for autocomplete, dictionaries, and prefix searching.
    This version supports lowercase English letters only.
*/

struct TrieNode {
    std::array<std::unique_ptr<TrieNode>, 26> children{};
    bool is_word = false;
};

class Trie {
public:
    void insert(const std::string& word) {
        TrieNode* current = root.get();
        for (char letter : word) {
            const int index = letter - 'a';
            if (!current->children[index]) {
                current->children[index] = std::make_unique<TrieNode>();
            }
            current = current->children[index].get();
        }
        current->is_word = true;
    }

    bool contains(const std::string& word) const {
        const TrieNode* current = root.get();
        for (char letter : word) {
            const int index = letter - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index].get();
        }
        return current->is_word;
    }

private:
    std::unique_ptr<TrieNode> root = std::make_unique<TrieNode>();
};

int main() {
    Trie dictionary;
    dictionary.insert("cat");
    dictionary.insert("car");

    std::cout << std::boolalpha
              << "contains cat: " << dictionary.contains("cat") << '\n'
              << "contains can: " << dictionary.contains("can") << '\n';
}
