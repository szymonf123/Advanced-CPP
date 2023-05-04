#include <iostream>

template<size_t N>
double inner(double *x, double *y){
    return inner<N - 1>(x, y) + x[N - 1] * y[N - 1];
}

template<>
double inner<0>(double* x, double* y){
    return 0.0;
}

int main(){
    double a[4] = {1.0, 2.0, 3.0, 4.0};
    double b[4] = {2.0, 1.0, 4.0, 3.0};
    std::cout << inner<4>(a, b) << std::endl;
}