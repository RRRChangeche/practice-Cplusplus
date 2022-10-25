#include <iostream>

using namespace std;

class Animal {
public:
    virtual void barking();
};

void Animal::barking() {
    cout << "virtual bakring !!" << endl;
}

class Dog : public Animal {
public:
    void barking();
};

void Dog::barking() {
    cout << "woof!!" << endl;
}

class Cat : public Animal {
public:
    void barking();
};

void Cat::barking() {
    cout << "meow!!" << endl;
}

void demoBarking(Animal& a) {
    a.barking();
}

void demoBarking_withoutReference(Animal a) {
    a.barking();
}


int main()
{
    Dog dog;
    Cat cat;

    demoBarking(dog);
    demoBarking(cat);
    demoBarking_withoutReference(cat);
    demoBarking_withoutReference(dog); 

    // pass by reference
    // a_ref is child instance
    // >> woof!!
    Animal* a_ref = &dog;
    a_ref->barking();
    
    // pass by assignment 
    // >> virtual barking!!
    Animal a = cat;
    a.barking();

}

/*
* Note:
* Polymorphism
* 1. create the virtual function of base class
* 2. overwrite the virtual function in child class with different behaviour
* 3. behaviour of calling function depend on what type of instance passed in.
*
* Calling function with base class as parameter
* 1. passing by reference
* 2. if pass by assignment, will copy the instance as parent class.
* 
* Referece:
* https://iter01.com/76832.html
*/