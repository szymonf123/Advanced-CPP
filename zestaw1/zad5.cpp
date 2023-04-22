#include <deque>

template<typename T, template<typename X > class Sequence=std::deque > 
class Stack {
    Sequence<T> _rep;
public:
    typedef T value_type;
    void push(T e) {
        _rep.push_back(e);
    };
    T pop() {
        T top=_rep.top();
        _rep.pop_back();
        return top;
    }
    bool is_empty() const {
        return _rep.empty();
    }
};

template <typename S>
typename S::value_type sum(S stack){
    typename S::value_type total = 0;
    while (!s.is_empty()){
        total += s.pop();
    }
    return total;
}