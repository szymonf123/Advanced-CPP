#include <iostream>

template<int N>
double dot_product(double u[], double v[]){
    double result = 0;
    for (int i = 0; i < N; i++){
        result += (u[i] * v[i]);
    }
    return result;
}

int main(){
    double a[5] = {1, 2, 3, 4, 5};
    double b[5] = {5, 4, 3, 2, 1};
    std::cout << dot_product<5>(a, b) << std::endl;
    return 0;
}