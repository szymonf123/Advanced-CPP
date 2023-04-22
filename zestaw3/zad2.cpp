#include <iostream>
using namespace std;

template<typename T, typename U>
T convert(U u){
    return static_cast<T>(u);
}

template<typename U>
int convert(U u){
    return static_cast<int>(u);
}

template<typename U>
double convert(U u){
    return static_cast<double>(u);
}

int main(){
    cout << convert<int>(2.22) << endl << convert<double>(7) / convert<double>(2) << endl;
    return 0;
}