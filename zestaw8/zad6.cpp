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

class First{
public:
    double operator()(double x){
        return x;
    }
    double operator()(double x, double){
        return x;
    }
};

class Second {
public:
    double operator()(double, double y){
        return y;
    }
};

class Constant{
    double _c;
public:
    Constant(double c) :_c(c){};
    double operator()(double x) {
        return _c;
    }
    double operator()(double, double){
        return _c;
    }
};

template<typename LHS, typename RHS>
class AddExpr {
    LHS _lhs;
    RHS _rhs;
public:
    AddExpr(const LHS &l, const RHS &r) :_lhs(l),_rhs(r) {};
    double operator()(double x){
        return _lhs(x) + _rhs(x, x);
    }
    double operator()(double x, double y){
        return _lhs(x, y) + _rhs(x, y);
    }
}; 

template<typename LHS, typename RHS> 
AddExpr<LHS,RHS> operator+(const LHS &l, const RHS &r) {
    return AddExpr<LHS, RHS>(l, r);
};   


template<typename LHS> 
AddExpr<LHS, Constant> operator+(const LHS &l, double r) {
    return AddExpr<LHS, Constant>(l, Constant(r));
};   

template<typename RHS> 
AddExpr<Constant, RHS> operator+(double l, const RHS &r) {
    return AddExpr<Constant, RHS>(Constant(l), r);
};

template<typename LHS,typename RHS>
class DivExpr {
    LHS _lhs;
    RHS _rhs;
public:
    DivExpr(const LHS &l, const RHS &r) :_lhs(l), _rhs(r) {};
    double operator()(double x) {
        return _lhs(x) / _rhs(x);
    }
    double operator()(double x,double y) {
        return _lhs(x, y)+_rhs(x, y);
    }
}; 

template<typename LHS, typename RHS> 
DivExpr<LHS, RHS> operator/(const LHS &l, const RHS &r) {
    return DivExpr<LHS, RHS>(l, r);
};

template<typename LHS> 
DivExpr<LHS,Constant> operator/(const LHS &l, double r) {
    return DivExpr<LHS, Constant>(l, Constant(r));
};   

template<typename RHS> 
DivExpr<Constant, RHS> operator/(double l, const RHS &r) {
    return DivExpr<Constant, RHS>(Constant(l), r);
};   

template<typename Arg>
class SinExpr{ 
    Arg _arg;
public:
    SinExpr(const Arg& arg) :_arg(arg) {};
    double operator()(double x){
        return sin(_arg(x));
    }
};

template<typename Arg>
SinExpr<Arg> sin(const Arg& a) {
    return SinExpr<Arg>(a);
}

main(){
    First x;
    Second y;
    std::cout << ::integrate(x + y, 0.0, 1.0, 0.001) << std::endl;
}