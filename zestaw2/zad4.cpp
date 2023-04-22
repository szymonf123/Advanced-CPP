#include <iostream>
#include <vector>
#include <functional>

template<typename T> class SequenceGen {
    private:
        T _start; 
        T _step;
    public:
        SequenceGen(T start = T(),T step = 1 ):
        _start(start),_step(step){};
        T operator()() {
            T tmp=_start;
            _start+=_step;
            return tmp;
        }
};

int main(){
    const size_t n = 20 ;
    std::vector<int> v(n);
    generate_n(v.begin(),n,SequenceGen<int>(1,2));
    std::vector<int>::iterator it = find_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, 4));
    if (it != v.end())
        std::cout << *it << std::endl;
    else
        std::cout << "Nie znaleziono\n";
    return 0;
}