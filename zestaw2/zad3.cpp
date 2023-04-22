#include <iostream>
#include <vector>
#include <list>

template <class InputIterator, class T>
T accumulate(InputIterator first, InputIterator last, T init) {
T total=init;
for(; first != last; ++first) 
   total += *first;
return total;
}

int main(){
    std::vector<std::string> names({"Ala", "Ola", "Ula", "Ela"});
    std::vector<std::string>::iterator i1 = names.begin() + 1;
    std::vector<std::string>::iterator i2 = names.end() - 1;
    std::cout << accumulate<std::vector<std::string>::iterator, std::string>(i1, i2, "Names = ") << std::endl;

    std::list<int> numbers({3, 4, 2, 78, 1});
    std::list<int>::iterator i3 = numbers.begin();
    std::list<int>::iterator i4 = numbers.end();
    std::cout << accumulate(i3, i4, 0);
    return 0;
}