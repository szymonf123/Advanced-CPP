#include<iostream>
#include <array>
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

template<typename T> 
typename sum_traits<T>::sum_type sum(T *start,T *stop) { 
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type result = sum_type(); 
    while(start != stop) { 
        result += *start;
        start++; 
    } 
    return result; 
};

int main(){
    array<int, 5> a1({2, 3, 18, -3, -5});
    cout << "sum<int> = " << sum(a1.begin(), a1.end());

    array<float, 3> a2({1.0/3, 1.0/3, 1.0/3});
    cout << "\nsum<float> = " << sum(a2.begin(), a2.end());

    array<double, 3> a3({3.33, 3.33, 3.333333});
    cout << "\nsum<double> = " << sum(a3.begin(), a3.end());

    char name[] = "@@@";
    cout << "\nsum<char> = " << sum(name, &name[strlen(name)]);
    return 0;
}