#include <iostream>
#include <cstring>
using namespace std;

/* 1 */ template <typename T>
T maks(T a, T b){
    return (a > b) ? a : b;
}

/* 2 */ template <typename T>
T* maks(T* a, T* b){
    return ((*a) > (*b)) ? a : b;
}

/* 3 */ template <typename T>
T maks(T* data, size_t n){
    T result = data[0];
    for (int i = 1; i < n; i++){
        if (data[i] > result){
            result = data[i];
        }
    }
    return result;
}

/* 4 */ template<>
char* maks(char* a, char* b){
    return strcmp(a, b) ? a : b;
}

/* 5 */ template<>
const char* maks(const char* a, const char* b){
    return strcmp(a, b) ? a : b;
}

//szablon pomocniczy do 6
/*template<typename T>
T maks(T a, const T b){
    return a > b ? a : b;
}*/

/* 6  template<>
char* maks(char* a, const char* b){
    return strcmp(a, b) ? a : b;
}*/

int main(){
    const int x = 2;
    const int y = 3;
    int tab[y] = {10, 120, 4};
    const char c1 = 'E';
    const char c2 = '%';
    cout << "1. Max(2, 3) = " << maks(x, y) << endl;
    cout << "2. Max(2, 3) = " << *(maks(&x, &y)) << endl;
    cout << "3. Max(10, 120, 4) = " << maks(tab, y) << endl;
    cout << "4. Max(E, %) = " << maks(c1, c2) << endl;
    cout << "5. Max(E, %) = " << maks(&c1, &c2) << endl;
    return 0;
}