#include <iostream>

class Animal {
    public:
        virtual void say_something() = 0;
};

class Dog : public Animal {
    public:
        void say_something(){
            std::cout << "I'm a dog\n";
        }
};

class Cat : public Animal {
    public:
        void say_something(){
            std::cout << "I'm a cat\n";
        }
};

class Fish : public Animal {
    public:
        void say_something(){
            std::cout << "I'm a fish\n";
        }
};

void dynamic_poly(Animal* animals[], int n){
    for (int i = 0; i < n; i++){
        animals[i]->say_something();
    }
}

template<typename T>
void static_poly(T animals, int n){
    for (int i = 0; i < n; i++){
        animals[i].say_something();
    }
}

int main(){
    Animal* animals[4];
    animals[0] = new Cat();
    animals[1] = new Dog();
    animals[2] = new Dog();
    animals[3] = new Fish();
    dynamic_poly(animals, 4);
    delete animals[0];
    delete animals[1];
    delete animals[2];
    delete animals[3];

    std::cout << "-----------------\n";

    Fish fishes[2] = {Fish(), Fish()};
    static_poly(fishes, 2);
    return 0;
}