#include <iostream>
#include <memory>

main() {
    std::shared_ptr<int> sptr;

    sptr.reset(new int);
    *sptr = 10;

    std::weak_ptr<int> weak1 = sptr;

    sptr.reset(new int);
    *sptr = 5;

    std::weak_ptr<int> weak2 = sptr;

    if (auto tmp = weak1.lock())
        std::cout << "weak1 value is " << *tmp << '\n';
    else
        std::cout << "weak1 expired\n";
    
    if (auto tmp = weak2.lock())
        std::cout << "weak2 value is " << *tmp << '\n';
    else
        std::cout << "weak2 expired\n";
}