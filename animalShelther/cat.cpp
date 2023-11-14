#include<iostream>
#include"cat.h"
using namespace std;
Cat::Cat()
{
MyCatNumber = numCats;
 numCats++;
}
Cat::~Cat() {
}
string Cat::speak() {

  std::string output;
  output += "Hi! My name is " + name_ + "\n";
  output += "I am " + age_ + " years old \n";
  output += "I weigh " + weight_ + " pounds.\n";
  output += "I'm a " + breed_ + "\n";
  output += " My color is " + color_ + "\n";
  output += "My health is labeled as: " + health_ + ".\n";
  output += "Here's the sound I make: " + sound_ + ".\n";
  return output;
}
