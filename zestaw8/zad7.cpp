#include <iostream>
#include <vector>
using namespace std;

class Const_vector;

template<typename T>
struct V_expr_traits {
    typedef T const & op_type;
};
template<>
struct V_expr_traits<Const_vector> {
    typedef Const_vector op_type;
};

class Vector : public vector<double> {
public:
    Vector() : vector<double>(){};
    Vector(int n) : vector<double>(n){};
    Vector(int n, double x) : vector<double>(n, x){};
    Vector(const Vector& v) : vector<double>(static_cast<vector<double>>(v)){};
    Vector(const vector<double>& v) : vector<double>(v) {};
    Vector& operator=(const Vector& rhs) {
        vector<double>::operator=(static_cast<vector<double>>(rhs));
        return (*this);
    }
    template<typename V> Vector& operator=(const V& rhs) {
        for(size_t i = 0 ; i < vector<double>::size(); ++i) 
            (*this)[i] = rhs[i];
        return *this;
    }
};

class Const_vector {
    double _c;
public:
    Const_vector(double c):_c(c) {};
    double operator[](int i) const {return _c;}
};

template<typename LHS,typename RHS> class AddVectors {
    typename V_expr_traits<LHS>::op_type _lhs;
    typename V_expr_traits<RHS>::op_type _rhs;
public:
    AddVectors(const LHS &lhs, const RHS &rhs) : _lhs(lhs), _rhs(rhs){};
    double operator[](int i) const {return _lhs[i] + _rhs[i];}
};

template<typename LHS,typename RHS>
inline AddVectors<LHS,RHS> operator+(const LHS &lhs,const RHS &rhs) {
    return AddVectors<LHS,RHS>(lhs, rhs);
}

template<typename LHS>
inline AddVectors<LHS,Const_vector> operator+(const LHS &lhs,double rhs) {
    return AddVectors<LHS,Const_vector>(lhs,Const_vector(rhs) );
}

template<typename LHS,typename RHS> class MulVectors {
    typename V_expr_traits<LHS>::op_type _lhs;
    typename V_expr_traits<RHS>::op_type _rhs;
public:
    MulVectors(const LHS &lhs, const RHS &rhs) : _lhs(lhs), _rhs(rhs){};
    double operator[](int i) const {return _lhs[i] * _rhs[i];}
};

template<typename LHS,typename RHS>
inline MulVectors<LHS, RHS> operator*(const LHS &lhs, const RHS &rhs) {
    return MulVectors<LHS, RHS>(lhs, rhs);
}

template<typename LHS>
inline MulVectors<LHS, Const_vector> operator*(const LHS& lhs, double rhs) {
    return MulVectors<LHS, Const_vector>(lhs, Const_vector(rhs) );
}

template<typename RHS>
inline MulVectors<Const_vector, RHS> operator*(double lhs, const RHS& rhs) {
    return MulVectors<Const_vector, RHS>(Const_vector(lhs), rhs);
}

main(){
    Vector v1(100, 1);
    Vector v2(100, 2);
    Vector res(100);
    res = 1.2 * v1 + v1 * v2 + v2 * 0.5;

    for (short i = 0; i < 10; i++){
        cout << res[i] << endl;
    }
}