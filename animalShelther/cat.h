#ifndef CAT_H
#define CAT_H

#include<iostream>
#include "Animal.h"
class Cat :
public Animal
{
public:
Cat();
~Cat();
int MyCatNumber;
static int numCats;
string speak();
};

#endif
