# C++ Constructors, Destructor, and Copy Constructor

These special member functions control how an object is created, copied, and
destroyed.

## 1. Constructor

A constructor is a member function that has the same name as the class and has
no return type. It runs automatically when an object is created and is
normally used to initialize the object's data members.

### Default constructor

A default constructor takes no arguments:

```cpp
#include <string>

using namespace std;

class Chai
{
public:
    string name;
    int servings;

    Chai()
    {
        name = "Default Chai";
        servings = 1;
    }
};

int main()
{
    Chai tea; // Chai() runs automatically
}
```

Use a default constructor when an object should have sensible default values,
for example when creating an empty container, a configuration object, or a
form model.

Prefer a member-initializer list for initialization:

```cpp
Chai() : name("Default Chai"), servings(1) {}
```

The initializer list is required for `const` members, reference members, and
members whose types do not have a default constructor. It also initializes
members directly instead of first default-initializing them and then assigning
new values.

### Parameterized constructor

A parameterized constructor accepts values from the caller:

```cpp
#include <string>

using namespace std;

class Chai
{
public:
    string name;
    int servings;

    Chai(const string& chaiName, int numberOfServings)
        : name(chaiName), servings(numberOfServings)
    {
    }
};

int main()
{
    Chai masalaChai("Masala Chai", 2);
}
```

Use one when an object must start in a specific, valid state. Constructors can
be overloaded, so a class can provide both default and parameterized forms.

## 2. Destructor

A destructor has the class name preceded by `~`, takes no arguments, and has no
return type. It runs automatically when an object reaches the end of its
lifetime.

```cpp
#include <iostream>

using namespace std;

class Chai
{
public:
    Chai()
    {
        cout << "Chai created\n";
    }

    ~Chai()
    {
        cout << "Chai destroyed\n";
    }
};

int main()
{
    {
        Chai tea;
    } // ~Chai() runs here
}
```

Typical destructor use cases include releasing resources acquired by the
object:

- closing a file;
- releasing a lock;
- closing a socket or database connection;
- releasing memory obtained with `new`.

Do not manually call a destructor for an ordinary automatic object. C++ calls
it automatically. A destructor should usually be `noexcept` (the default
unless a member destructor can throw), because throwing during stack
unwinding can terminate the program.

## 3. Copy constructor

A copy constructor creates a new object from an existing object of the same
class. Its common form is:

```cpp
ClassName(const ClassName& other);
```

It is called in situations such as:

```cpp
Chai first("Masala Chai", 2);
Chai second = first; // copy constructor
Chai third(first);   // copy constructor
```

If no copy constructor is declared, the compiler generates one that copies
each member. This is correct for value-like members such as `string`,
`vector`, and numeric types. It is not automatically safe for a raw owning
pointer, because two objects can then point to the same resource.

### Copying an object that owns dynamic memory

```cpp
#include <cstring>
#include <iostream>

using namespace std;

class Recipe
{
private:
    char* name;

public:
    Recipe(const char* recipeName)
        : name(new char[strlen(recipeName) + 1])
    {
        strcpy(name, recipeName);
    }

    // Deep copy: allocate separate storage for the new object.
    Recipe(const Recipe& other)
        : name(new char[strlen(other.name) + 1])
    {
        strcpy(name, other.name);
    }

    ~Recipe()
    {
        delete[] name;
    }

    void rename(const char* newName)
    {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    void display() const
    {
        cout << name << '\n';
    }
};

int main()
{
    Recipe original("Masala Chai");
    Recipe copy = original; // Recipe(const Recipe&) runs

    copy.rename("Ginger Chai");

    original.display(); // Masala Chai
    copy.display();     // Ginger Chai
}
```

The copy owns a different character array, so changing or destroying one
object does not affect the other. This is called a **deep copy**.

Without an explicit copy constructor, the generated copy would copy only the
pointer value (a **shallow copy**). Both objects would then try to delete the
same array, causing undefined behavior, often a double-free error.

## 4. Rule of Three

If a class manually manages a resource and needs any one of these functions,
it often needs all three:

1. destructor;
2. copy constructor;
3. copy-assignment operator.

The copy constructor handles creation of a new object:

```cpp
Recipe copy = original;
```

Copy assignment handles two objects that already exist:

```cpp
Recipe another("Plain Chai");
another = original;
```

For modern C++, prefer an RAII type such as `string`, `vector`, or
`unique_ptr` instead of manually managing a raw pointer. Then the compiler
generated special member functions are usually safe.

## 5. Practical summary

| Member function | Called when | Main purpose |
| --- | --- | --- |
| Constructor | An object is created | Establish a valid initial state |
| Default constructor | An object is created without arguments | Supply default values |
| Parameterized constructor | An object is created with arguments | Initialize from caller-provided values |
| Copy constructor | A new object is initialized from another object | Copy the source object's state/resource ownership |
| Destructor | An object leaves its lifetime | Release resources and perform cleanup |

### Important notes

- Destruction happens in the reverse order of construction.
- Local objects are destroyed automatically at the end of their scope.
- Dynamically allocated objects are destroyed when `delete` is used.
- A destructor is not called when `std::exit` ends the program.
- Compiler optimizations such as copy elision can remove some copy-constructor
  calls, even when the code appears to create a temporary copy.
