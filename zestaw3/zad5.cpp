#include <iostream>
#include <set>
#include <functional>
using namespace std;

int main(){
    set<int, greater<>> s1;
    s1.insert(1);
    s1.insert(4);
    s1.insert(3);
    s1.insert(1);
    for (set<int, greater<>>::iterator i = s1.begin(); i != s1.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}