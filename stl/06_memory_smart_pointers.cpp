#include <iostream>
#include <memory>

/*
    MEMORY UTILITIES
    ================
    Smart pointers express ownership and automatically release resources.

    - unique_ptr: one owner; movable but not copyable
    - shared_ptr: reference-counted shared ownership
    - weak_ptr: non-owning observer of a shared_ptr object; prevents cycles
    - make_unique/make_shared: preferred construction helpers

    unique_ptr is the default choice. Use shared_ptr only when ownership is
    genuinely shared. A raw pointer can observe an object without owning it.
*/

struct Resource {
    explicit Resource(int id) : id(id) {
        std::cout << "resource " << id << " created\n";
    }
    ~Resource() {
        std::cout << "resource " << id << " destroyed\n";
    }
    int id;
};

int main() {
    auto unique = std::make_unique<Resource>(1);
    std::cout << "unique id: " << unique->id << '\n';

    auto shared_a = std::make_shared<Resource>(2);
    auto shared_b = shared_a;
    std::cout << "shared owners: " << shared_a.use_count() << '\n';

    std::weak_ptr<Resource> observer = shared_a;
    if (auto locked = observer.lock()) {
        std::cout << "observed id: " << locked->id << '\n';
    }
}
