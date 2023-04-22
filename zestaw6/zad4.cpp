#include <iostream>

class No_checking_policy;
template <typename U, size_t M>
class Static_table_allocator;

template<typename T = int, size_t N = 100, typename Checking_policy = No_checking_policy, template<typename U, size_t M>  class Allocator_policy = Static_table_allocator> 
class Stack : private Checking_policy, public Allocator_policy<T, N> {
    typedef typename Allocator_policy<T, N>::rep_type rep_type;
    size_t _top;

public:
    Stack(size_t n = N) :_top(0) {
        Stack::init(n);
    };

    void push(const T &val) {
        Stack::expand_if_needed(_top);
        Checking_policy::check_push(_top, this->size());
        Stack::_rep[_top++] = val;
    }

    void pop() {
        Checking_policy::check_pop(_top);
        --_top;
        Stack::shrink_if_needed(_top);
    }
  
    const T& top() const {
        Checking_policy::check_top(_top);
        return Stack::_rep[_top - 1];
    }
  
    bool is_empty() {
        return !_top;
    } 

    ~Stack() {
        Stack::dealocate();
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

template<typename T, size_t N = 0>
class Static_table_allocator {
    typedef T rep_type[N];
    rep_type _rep;
    void init(size_t) {};
    void expand_if_needed(size_t) {};
    void shrink_if_needed(size_t) {};
    void dealocate(){};

    static size_t size() {
        return N;
    };
};

template<typename T,size_t N>
struct Dynamic_table_allocator {
    typedef T * rep_type;
    rep_type _rep;
    size_t _size;
    void init(size_t n) {
        _size = n;
        _rep = new T[_size];
    };
    void expand_if_needed(size_t) {};
    void shrink_if_needed(size_t) {};
    void dealocate() {
        delete [] _rep;
    };

    size_t size() const {
        return _size;
    };

public:
  void resize(size_t n) {
      T* tmp = new T[n];
      std::copy(_rep, &_rep[(_size<n)?_size:n], tmp);
      delete [] _rep;
      _rep = tmp;
      _size = n;
  }
};

int main(){
    Stack<char, 4, Abort_on_error_policy, Dynamic_table_allocator> stack(4);
    stack.push('g');
    stack.push('5');
    std::cout << "Wstawiono 2 element\n";
    stack.push(')');
    std::cout << "Wstawiono 3 element\n";
    stack.push('Q');
}