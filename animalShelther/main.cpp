/*-------------------------------------main function of animal shelter --------------------------------------------------------------*/
/*jirehvivar 04.22.2023               - put showFile as a separate function in order to be able to find commas
                                      - using debugger to output whether or not it is reading my file correctly and slicing it correctly
                                      - added 'get line' to allow it to skip the header line in the file
                                      - deleted divideFile and placed file slicing into main function
                                            - this fixed finding variables !
                                      - moved classes to separate file, deleted gameRun function
                                      - created switch case for each report for debugging
                                      - moved output to .cpp files, changed to for loops
                                      - organized output for better viewing*/
#include <iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>
#include "dog.h"
#include "cat.h"
using namespace std;

bool showFlow = false;
string line;
int Dog::numDogs = 0;
int Cat::numCats = 0;

void showflow(string line)
{
    cout << line << endl;
}

//this functions outputs the file in the debugger
void showFile(string line)
{
    if(showFlow)
        showflow("Entering function showFile");

    ifstream inputFile("animalRegistration.csv");
    string fileLines;
    while(getline(inputFile,fileLines))
            {
                cout << fileLines << endl;
            }
    if(showFlow)
        showflow("Leaving function showFile");
}

int main()
{
    ifstream inputFile("animalRegistration.csv");
    vector<Animal*> animals;
    vector<Dog*> dogs;
    vector<Cat*> cats;
    ofstream report;
    string fileLines, name, type, age, weight, color, sound, health, breed;
    //header
    cout << setw(40) << "Animal Shelter" << endl;
    if(showFlow) showflow( "the name of the file: animalRegistration.csv");//in case name is not recognized

    if (!inputFile)
        {
            cout << "Error in file reading" << endl;
        }
    if(showFlow)//making sure the file is being read correctly
            {showFile(line);}
    //divideFile(line, animals);
    getline(inputFile, fileLines);//ignoring header
    getline(inputFile, fileLines);
    while (inputFile) {
    type = fileLines.substr(0, fileLines.find(','));
    fileLines = fileLines.erase(0, fileLines.find(',') + 1);
    name = fileLines.substr(0, fileLines.find(','));
    fileLines = fileLines.erase(0, fileLines.find(',') + 1);
    age = fileLines.substr(0, fileLines.find(','));
    fileLines = fileLines.erase(0, fileLines.find(',') + 1);
    weight = fileLines.substr(0, fileLines.find(','));

    fileLines = fileLines.erase(0, fileLines.find(',') + 1);
    breed = fileLines.substr(0, fileLines.find(','));
    fileLines = fileLines.erase(0, fileLines.find(',') + 1);
    color = fileLines.substr(0, fileLines.find(','));
    fileLines = fileLines.erase(0, fileLines.find(',') + 1);
    health = fileLines.substr(0, fileLines.find(','));
    sound = fileLines.erase(0, fileLines.find(',') + 1);
    Animal * animal;
    //place cat and dog in sections
    if (type == "cat") {
    animal = new Cat();
    }
    else if (type == "dog") {
    animal = new Dog();
    }
    else
    {
    animal = new Animal();
    }
    animal->age_ = age;
    animal->breed_ = breed;
    animal->color_ = color;
    animal->health_ = health;
    animal->name_ = name;
    animal->sound_ = sound;
    animal->type_ = type;
    animal->weight_ = weight;
    animals.push_back(animal);
    if (type == "cat")
        {
            cats.push_back((Cat *)animal);
        }
    else if (type == "dog")
        {
            dogs.push_back((Dog *)animal);

        }
    getline(inputFile, fileLines);
    }
    if(showFlow)
        {
        showflow("Entering report inputs");
       int reportChoice; //choices help with debuggingg and centraliziing each section
        cout << "Report 1: total number of animals created, number of cats created, number of dogs created " << endl;
        cout << "Report 2: An Animal report. Have each animal in the Animal vector introduce itself" << endl;
        cout << "Report 3: A Cat report: same as above but using all Cat attributes" << endl;
        cout << "Report 4: A Dog report: same as above but using all Dog attributes" << endl;
        cout << "Report 5: View all" << endl;
        cout << "Which report would you like to see? Enter Number: ";
        cin >> reportChoice;
            if(showFlow)
                cout << reportChoice << endl;
        switch(reportChoice)
        {
        case 1:
            cout << "Report 1: " << endl;
            cout << "Total Animals created:" << animals.size() << endl;
            cout << "Total cats created:" << cats.size() << endl;
            cout <<" Total dogs created:" << dogs.size() << endl;
            cout << "Total other animals: " << animals.size()-(cats.size()+dogs.size())  << endl;
            report << "Total Animals created:" << animals.size() << endl
             << "Total cats created: " << cats.size() << endl
             << "Total dogs created: " << dogs.size() << endl
            << "Total other animals: " << animals.size()-(cats.size()+dogs.size()) << endl;
            break;
        case 2:
            cout << "Report 2: Animals" << endl;
            for (int i = 0; i < animals.size();i++)
                {
                    cout << animals[i]->speak() << endl;
                    report << animals[i]->speak() << endl;
                }

            break;
        case 3:
            cout << "Report 3: Cats" << endl;
            for (int i = 0; i < cats.size();i++)
                {
                    cout << cats[i]->speak() << endl;
                    report << cats[i]->speak() << endl;
                }
            break;
        case 4:
            cout << "Report 4: Dogs" << endl;
            for (int i = 0; i < dogs.size();i++)
                {
                    cout << dogs[i]->speak() << endl;
                    report << dogs[i]->speak() << endl;
                }
            break;
        case 5:
            cout << "Total Animals created:" << animals.size() << endl;
            cout << "Total cats created:" << cats.size() << endl;
            cout <<" Total dogs created:" << dogs.size() << endl;
            cout << "Total other animals: " << animals.size()-(cats.size()+dogs.size())  << endl;
            report << "Total Animals created:" << animals.size() << endl
             << "Total cats created: " << cats.size() << endl
             << "Total dogs created: " << dogs.size() << endl
            << "Total other animals: " << animals.size()-(cats.size()+dogs.size()) << endl;
            cout << "Animals" << endl;

            for (int i = 0; i < animals.size();i++)
                {
                    cout << animals[i]->speak() << endl;
                    report << animals[i]->speak() << endl;
                }
            cout << endl << "Cats" << endl;
            for (int i = 0; i < cats.size();i++)
                {
                    cout << cats[i]->speak() << endl;
                    report << cats[i]->speak() << endl;
                }
            cout << endl << "Dogs" << endl;
            for (int i = 0; i < dogs.size();i++)
                {
                    cout << dogs[i]->speak() << endl;
                    report << dogs[i]->speak() << endl;
                }
            break;
        }
    }
//   <--------------this prints output on separate disk file--------->
    report.open("report.txt");
    if (report)
        {
            if(!showFlow)
            {
            cout << setw(20) << "Report 1: " << endl;
            cout << "Total Animals created:" << animals.size() << endl;
            cout << "Total cats created:" << cats.size() << endl;
            cout <<" Total dogs created:" << dogs.size() << endl;
            cout << "Total other animals: " << animals.size()-(cats.size()+dogs.size())  << endl;
            report << "Total Animals created:" << animals.size() << endl
             << "Total cats created: " << cats.size() << endl
             << "Total dogs created: " << dogs.size() << endl
            << "Total other animals: " << animals.size()-(cats.size()+dogs.size()) << endl;
cout << "--------------------------------------------------------------------------------" << endl;
            cout << setw(20) << "Report 2: Animals" << endl;
            for (int i = 0; i < animals.size();i++)
                {
                    cout << animals[i]->speak() << endl;
                    report << animals[i]->speak() << endl;
                }
cout << "--------------------------------------------------------------------------------" << endl;
            cout << endl << setw(20) << "Report 3: Cats" << endl;
            for (int i = 0; i < cats.size();i++)
                {
                    cout << cats[i]->speak() << endl;
                    report << cats[i]->speak() << endl;
                }
cout << "--------------------------------------------------------------------------------" << endl;
            cout << endl << setw(20) << "Report 4: Dogs" << endl;
            for (int i = 0; i < dogs.size();i++)
                {
                    cout << dogs[i]->speak() << endl;
                    report << dogs[i]->speak() << endl;
                }
            }
        report.close();
        }
    inputFile.close();
    return 0;
}
