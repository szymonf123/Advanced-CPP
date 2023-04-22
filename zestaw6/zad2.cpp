#include <iostream>

class No_checking_policy;

template<typename T = int, size_t N = 100, typename Checking_policy = No_checking_policy > 
class Stack {
private:	
    T _rep[N];
    size_t _top;
public:
    Stack() : _top(0) {};
    void push(const T &val) {
        Checking_policy::check_push(_top, N);
        _rep[_top++] = val;
    }
    void pop() {
        Checking_policy::check_pop(_top);
        --_top;
    }
    const T& top() const {
        Checking_policy::check_top(_top);
        return _rep[top - 1];
    }
    bool is_empty() {
        return !_top;
    }
};

class No_checking_policy {
    static void check_push(size_t, size_t) {};
    static void check_pop(size_t) {};
    static void check_top(size_t) {};
};

class Abort_on_error_policy {
public:
    static void check_push(size_t top, size_t size) {
        if(top >= size) {
            std::cerr << "Invalid pushing\n";
            abort();
        }
    };
    static void check_pop(size_t top) {
        if (top == 0){
            std::cerr << "Invalid popping\n";
            abort();
        }
    }
    static void check_top(size_t top){
        if (top == 0){
            std::cerr << "Invalid top\n";
            abort();
        }
    }
};

int main(){
    Stack<char, 4, Abort_on_error_policy> stack;
    stack.push('g');
    stack.push('5');
    stack.push(')');
    stack.push('Q');
    std::cout << "Wstawiono 4 elementy\n";
    stack.push('2');
}