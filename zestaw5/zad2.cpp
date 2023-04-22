#include <iostream>
#include <queue>
using namespace std;

template<typename T> class Has_value_type {
    typedef char one;
    typedef struct {char c[2];} two;
    template<typename U> static one test(typename U::value_type); 
    template<typename U> static two test(...);

public:
    enum {yes = (sizeof(test<T>(0))==sizeof(one) )};
};

class X {
    string name;
    float n;
};

template <typename T>
class Something {
    public:
        typedef T value_type;
};

class Something2 {
    public:
        typedef short value_type;
};

int main() {
    cout << Has_value_type<int>::yes << endl;
    cout << Has_value_type<X>::yes << endl;
    cout << Has_value_type<queue<long>>::yes << endl;
    cout << Has_value_type<Something<string>>::yes << endl;
    cout << Has_value_type<Something2>::yes << endl;
    return 0;
}