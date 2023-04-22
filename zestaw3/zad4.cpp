#include <iostream>
#include <vector>
using namespace std;

template<typename T, int N, typename R = T*>
class Stack {
    private:
        int top;
        R data;
    public:
        Stack();
        void push(T e);
        T pop();
        ~Stack();
};

template<typename T, int N>
class Stack<T, N, T*>{
    private:
        int top;
        T* data;
    public:
        Stack(){
            top = -1;
            data = new T[N];
        }
        void push(T e){
            if (top < N - 1){
                top++;
                data[top] = e;
            }
        }
        T pop(){
            if (top >= 0){
                top--;
                return data[top + 1];
            }
            cout << "Nie mam co zwracac\n";
            exit(0);
        }
        ~Stack(){
            delete[] data;
        }
};

template<typename T, int N, template<typename R> class Sequence>
class Stack<T, N, Sequence<T>>{
    private:
        Sequence<T> data;
    public:
        Stack(){}
        void push(T e){
            if (data.size() < N){
                data.push_back(e);
            }
        }
        T pop(){
            if (data.size() > 0){
                return data.at(data.size() - 1);
            }
            cout << "Nie mam co zwracac\n";
            exit(0);
        }
};

int main(){
    Stack<int, 100> s_default;
    for (int i = 0; i < 150; i++)
        s_default.push(i);
    cout << "s_default.pop() = " << s_default.pop() << endl;

    Stack<int, 0, vector<int>> s_container;
    s_container.push(30);
    cout << "s_container.pop() = " << s_container.pop() << endl;

    return 0;
}