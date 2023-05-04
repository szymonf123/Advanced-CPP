#include <iostream>

template<size_t N, typename T>
class Dot {
public:
    static T dot(T *x, T *y){
        return Dot<N - 1, T>::dot(x, y) + x[N - 1] * y[N - 1];
    }
};


template<typename T>
class Dot<0, T>{
public:
    static T dot(T* x, T* y){
        return 0.0;
    };

};

int main(){
    double a[3] = {-3.0, -4.5, 9.78};
    double b[3] = {7.12, -10.35, 2.0};
    std::cout << Dot<3, double>::dot(a, b) << std::endl;

    int c[4] = {1, 2, 3, 4};
    int d[4] = {4, 3, 2, 1};
    std::cout << Dot<4, int>::dot(c, d) << std::endl;
}