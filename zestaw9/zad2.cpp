#include <iostream>
#include <memory>

class SomeClass {
    short someField;
    void someMethod(){};
};

main(){
    std::cout << sizeof(SomeClass*) << std::endl;
    std::cout << sizeof(std::unique_ptr<SomeClass>) << std::endl;
    std::cout << sizeof(std::shared_ptr<SomeClass>) << std::endl;
    std::cout << sizeof(std::weak_ptr<SomeClass>) << std::endl;
}