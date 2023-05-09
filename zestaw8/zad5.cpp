#include <cmath>
#include <iostream>
  
template<typename F> double integrate(F f,double  min,double max,double ds) {
  double integral=.0;
  for(double x=min;x<max;x+=ds) {
    integral+=f(x);
  }
  return integral*ds;
};


template<typename T> class Variable {
public:
  T operator()(T x) {
    return x;
  }
};


template<typename T> class Constant {
  T _c;
public:
  Constant(T c) :_c(c){};
  T operator()(T x) {return _c;}
};

template<typename T,typename R = Variable<T> > class Expr {
  R _rep;
 public:
  Expr() {};
  Expr(R rep):_rep(rep) {};
  T operator()(T x) {return _rep(x);}
  R rep() const {return _rep;};
};

/* dodawanie */

template<typename T, typename LHS,typename RHS > class AddExpr {
  LHS _lhs;
  RHS _rhs;
public:
  AddExpr(const LHS &l,const RHS &r) :_lhs(l),_rhs(r) {};
  T operator()(T x) {
    return _lhs(x)+_rhs(x);
  }
}; 

template<typename T,typename LHS,typename RHS > 
Expr<T,AddExpr<T,LHS,RHS> >  operator+(const Expr<T,LHS> &l,
			const Expr<T,RHS> &r) {
  return Expr<T,AddExpr<T,LHS,RHS> >(AddExpr<T,LHS,RHS>(l.rep(),r.rep()));
};   


template<typename T,typename LHS > 
Expr<T,AddExpr<T,LHS,Constant<T> > >   
operator+(const Expr<T,LHS>  &l,
			T r) {
return Expr<T,AddExpr<T,LHS,Constant<T> > >(AddExpr<T,LHS,Constant<T> >(l.rep(),Constant<T>(r)));
};   


template<typename T,typename LHS > 
Expr<T,AddExpr<T,Constant<T>,LHS > >  operator+(T r,
					  const Expr<T,LHS>  &l) {
  return Expr<T,AddExpr<T,Constant<T>,LHS> >(AddExpr<T,Constant<T>,LHS>(Constant<T>(r),l.rep()));
};   

//odejmowanie

template<typename T, typename LHS,typename RHS > class SubExpr {
  LHS _lhs;
  RHS _rhs;
public:
  SubExpr(const LHS &l,const RHS &r) :_lhs(l),_rhs(r) {};
  T operator()(T x) {
    return _lhs(x)-_rhs(x);
  }
}; 

template<typename T,typename LHS,typename RHS > 
Expr<T,SubExpr<T,LHS,RHS> >  operator-(const Expr<T,LHS> &l,
			const Expr<T,RHS> &r) {
  return Expr<T,SubExpr<T,LHS,RHS> >(SubExpr<T,LHS,RHS>(l.rep(),r.rep()));
};   


template<typename T,typename LHS > 
Expr<T,SubExpr<T,LHS,Constant<T> > >   
operator-(const Expr<T,LHS>  &l,
			T r) {
return Expr<T,SubExpr<T,LHS,Constant<T> > >(SubExpr<T,LHS,Constant<T> >(l.rep(),Constant<T>(r)));
};   


template<typename T,typename LHS > 
Expr<T,SubExpr<T,Constant<T>,LHS > >  operator-(T r,
					  const Expr<T,LHS>  &l) {
  return Expr<T,SubExpr<T,Constant<T>,LHS> >(SubExpr<T,Constant<T>,LHS>(Constant<T>(r),l.rep()));
};

//mnozenie

template<typename T, typename LHS,typename RHS > class MulExpr {
  LHS _lhs;
  RHS _rhs;
public:
  MulExpr(const LHS &l,const RHS &r) :_lhs(l),_rhs(r) {};
  T operator()(T x) {
    return _lhs(x)*_rhs(x);
  }
}; 

template<typename T,typename LHS,typename RHS > 
Expr<T,MulExpr<T,LHS,RHS> >  operator*(const Expr<T,LHS> &l,
			const Expr<T,RHS> &r) {
  return Expr<T,MulExpr<T,LHS,RHS> >(MulExpr<T,LHS,RHS>(l.rep(),r.rep()));
};   


template<typename T,typename LHS > 
Expr<T,MulExpr<T,LHS,Constant<T> > >   
operator*(const Expr<T,LHS>  &l,
			T r) {
return Expr<T,MulExpr<T,LHS,Constant<T> > >(MulExpr<T,LHS,Constant<T> >(l.rep(),Constant<T>(r)));
};   


template<typename T,typename LHS > 
Expr<T,MulExpr<T,Constant<T>,LHS > >  operator*(T r,
					  const Expr<T,LHS>  &l) {
  return Expr<T,MulExpr<T,Constant<T>,LHS> >(MulExpr<T,Constant<T>,LHS>(Constant<T>(r),l.rep()));
};

//dzielenie

template<typename T, typename LHS,typename RHS > class DivExpr {
  LHS _lhs;
  RHS _rhs;
public:
  DivExpr(const LHS &l,const RHS &r) :_lhs(l),_rhs(r) {};
  T operator()(T x) {
    return _lhs(x)/_rhs(x);
  }
}; 

template<typename T,typename LHS,typename RHS > 
Expr<T,DivExpr<T,LHS,RHS> >  operator/(const Expr<T,LHS> &l,
			const Expr<T,RHS> &r) {
  return Expr<T,DivExpr<T,LHS,RHS> >(DivExpr<T,LHS,RHS>(l.rep(),r.rep()));
};   


template<typename T,typename LHS > 
Expr<T,DivExpr<T,LHS,Constant<T> > >   
operator/(const Expr<T,LHS>  &l,
			T r) {
return Expr<T,DivExpr<T,LHS,Constant<T> > >(DivExpr<T,LHS,Constant<T> >(l.rep(),Constant<T>(r)));
};   


template<typename T,typename LHS > 
Expr<T,DivExpr<T,Constant<T>,LHS > >  operator/(T r,
					  const Expr<T,LHS>  &l) {
  return Expr<T,DivExpr<T,Constant<T>,LHS> >(DivExpr<T,Constant<T>,LHS>(Constant<T>(r),l.rep()));
};

template<typename Arg> class SinExpr{ 
  Arg _arg;
public:
  SinExpr(const Arg& arg) :_arg(arg) {};
  double operator()(double x) {return sin(_arg(x));}
};

template<typename Arg> SinExpr<Arg> sin(const Arg&a) {
  return SinExpr<Arg>(a);}

main(){
  long long c = 123;
  Expr<long long> x;
  std::cout << ::integrate(c / x, 1.0, 2.0, 0.001) << std::endl;
}