#include <iostream>
#include <cmath>
  
template<typename F>
double integrate(F f, double  min, double max, double ds){
    double integral = 0.0;
    for(double x = min; x < max; x += ds){
        integral += f(x);
    }
    return integral * ds;
};

class Variable{
public:
    double operator()(double x){
        return x;
    }
};


class Constant{
    double _c;
public:
    Constant(double c) :_c(c){};
    double operator()(double x) {
        return _c;
    }
};

main(){
    Variable x;
    std::cout << ::integrate(x, 0.0, 1.0, 0.001) << std::endl;
    std::cout << ::integrate(Constant(5.0), 0.0, 5.0, 0.001) << std::endl;
}