#include <iostream>
#include <memory>

using namespace std;

/*
    C++ NOTES: POINTERS, REFERENCES, AND DYNAMIC MEMORY

    1. A pointer stores the memory address of another object.
       - &value  -> address of value ("address-of" operator)
       - *pointer -> value at that address ("dereference" operator)

    2. A reference is another name (alias) for an existing object.
       - It must be initialized when it is declared.
       - It cannot be changed to refer to a different object later.

    3. Local variables normally live on the stack and are cleaned up
       automatically. Dynamic objects live on the heap and need a lifetime
       managed explicitly, preferably with smart pointers.
*/

void changeWithPointer(int* number) {
    // A pointer can be null, so check it before dereferencing it.
    if (number != nullptr) {
        *number = 20;
    }
}

void changeWithReference(int& number) {
    // A reference must refer to a valid object, so no null check is needed.
    number = 30;
}

int main() {
    cout << "=== 1. Pointers ===\n";

    int score = 10;
    int* scorePointer = &score;

    cout << "score: " << score << '\n';
    cout << "address of score: " << scorePointer << '\n';
    cout << "value through pointer: " << *scorePointer << '\n';

    // Changing *scorePointer changes the original score.
    *scorePointer = 15;
    cout << "score after *scorePointer = 15: " << score << "\n\n";

    int* emptyPointer = nullptr;
    cout << "emptyPointer is null: "
         << boolalpha << (emptyPointer == nullptr) << "\n\n";

    cout << "=== 2. References ===\n";

    int age = 18;
    int& ageAlias = age;

    cout << "age: " << age << '\n';
    cout << "ageAlias: " << ageAlias << '\n';

    // A reference is an alias, not a separate copy.
    ageAlias = 19;
    cout << "age after changing ageAlias: " << age << "\n\n";

    cout << "=== 3. Passing pointers and references to functions ===\n";

    int pointerValue = 5;
    changeWithPointer(&pointerValue);
    cout << "value changed through pointer: " << pointerValue << '\n';

    int referenceValue = 5;
    changeWithReference(referenceValue);
    cout << "value changed through reference: " << referenceValue << "\n\n";

    cout << "=== 4. Dynamic memory with new and delete ===\n";

    // new allocates an int on the heap and returns its address.
    int* dynamicNumber = new int(42);
    cout << "dynamic number: " << *dynamicNumber << '\n';

    // Every object created with new must be released with delete.
    delete dynamicNumber;
    dynamicNumber = nullptr; // Avoid keeping a dangling pointer.

    // Dynamic arrays use new[] and must be released with delete[].
    int size = 3;
    int* dynamicArray = new int[size]{10, 20, 30};

    cout << "dynamic array: ";
    for (int index = 0; index < size; ++index) {
        cout << dynamicArray[index] << ' ';
    }
    cout << '\n';

    delete[] dynamicArray;
    dynamicArray = nullptr;

    cout << "\n=== 5. Preferred approach: smart pointers ===\n";

    // unique_ptr automatically deletes the object when it leaves this scope.
    auto smartNumber = make_unique<int>(99);
    cout << "unique_ptr value: " << *smartNumber << '\n';

    // A smart pointer can also manage a dynamic array.
    auto smartArray = make_unique<int[]>(3);
    smartArray[0] = 1;
    smartArray[1] = 2;
    smartArray[2] = 3;

    cout << "unique_ptr array: ";
    for (int index = 0; index < 3; ++index) {
        cout << smartArray[index] << ' ';
    }
    cout << "\n\n";

    cout << "Remember:\n"
         << "- Use a pointer when you need an address or optional (nullable) value.\n"
         << "- Use a reference when an object must exist and should be modified directly.\n"
         << "- Prefer containers and smart pointers over manual new/delete.\n"
         << "- Never dereference nullptr or a pointer after its memory was released.\n";

    return 0;
}
