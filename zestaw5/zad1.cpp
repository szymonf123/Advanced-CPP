#include <iostream>
#include <queue>
using namespace std;

template<typename T> class Is_class {
    typedef char one;
    typedef struct {char c[2];} two;
    template<typename U> static one test(int U::* ); 
    template<typename U> static two test(...);

public:
    enum {yes = (sizeof(test<T>(0))==sizeof(one) )};
};

class X {
    string name;
    float n;
};

int main() {
    cout << Is_class<int>::yes << endl;
    cout << Is_class<X>::yes << endl;
    cout << Is_class<queue<long>>::yes << endl;
    return 0;
}