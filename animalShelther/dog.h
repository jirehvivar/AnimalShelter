#ifndef DOG_H
#define DOG_H

#include<iostream>
#include"Animal.h"
using namespace std;

class Dog :
public Animal
{
public:
    Dog();
    ~Dog();
    int MyDogNumber;
    static int numDogs;

 string speak();

};

#endif
