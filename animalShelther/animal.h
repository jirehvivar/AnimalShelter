#ifndef ANIMAL_H
#define ANIMAL_H


#include <iostream>
#include<string>
using namespace std;
class Animal
    {
        public: Animal();
        ~Animal();
        string speak();
        string type_ ;
        string name_;
        string age_;
        string weight_;
        string breed_;
        string color_;
        string health_;
        string sound_;
    };

#endif
