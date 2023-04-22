#include <iostream>
#include <cstring>
using  namespace std;

template<typename T>  struct sum_traits;

template<>  struct sum_traits<char> {
    typedef int sum_type; 
};
template<>  struct sum_traits<int> {
    typedef long int sum_type; 
};
template<>  struct sum_traits<float> {
    typedef double sum_type; 
};
template<>  struct sum_traits<double> {
    typedef double sum_type; 
};

template<typename Traits, typename T> 
typename Traits::sum_type sum(T *start,T *stop) { 
    typedef typename Traits::sum_type sum_type;
    sum_type result = sum_type(); 
    while(start != stop ) { 
        result += *start;
        start++; 
    } 
    return result; 
}

template<typename T> 
typename sum_traits<T>::sum_type sum(T *start,T *stop) { 
    return sum<sum_traits<T>, T>(start,stop);
}

struct char_sum {
    typedef char sum_type;
};

int main(){
    char name[] = "@@@";
    cout << sum(name, &name[strlen(name)]) << endl;
    cout << sum<char>(name, &name[strlen(name)]) << endl;
    cout << sum<char_sum>(name, &name[strlen(name)]) << endl;
}