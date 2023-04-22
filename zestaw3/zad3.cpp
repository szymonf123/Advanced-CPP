#include <iostream>
#include <vector>
using namespace std;

template<typename T, int N>
class Stack {
    public:
    Stack(){
        cout << "T | N\n";
    }
};

template<typename T>
class Stack<T, 666> {
    public:
    Stack(){
        cout << "T | 666\n";
    }
};

template<typename T, int N>
class Stack<T*, N> {
    public:
    Stack(){
        cout << "T* | N\n";
    }
};

template<int N>
class Stack<double, N> {
    public:
    Stack(){
        cout << "double | N\n";
    }
};

template<int N>
class Stack<int*, N> {
    public:
    Stack(){
        cout << "int* | N\n";
    }
};

template<>
class Stack<double, 666> {
    public:
    Stack(){
        cout << "double | 666\n";
    }
};

template<>
class Stack<double*, 44> {
    public:
    Stack(){
        cout << "double* | 44\n";
    }
};

int main(){
    Stack<string, 10> s0;
    Stack<vector<int>, 666> s1;
    Stack<long long*, 18> s2;
    Stack<double, 1000> s3;
    Stack<int*, 22> s4;
    Stack<double, 666> s5;
    Stack<double*, 44> s6;
    //Stack<char*, 666> s7;
    return 0;
}