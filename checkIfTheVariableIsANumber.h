
#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
using namespace std;

#ifndef checkIfTheVariableIsANumber
#define checkIfTheVariableIsANumber

string checkIfTheVariableIsANumber1(string numberToCheck)
{
    char singleCharacter;
    int characterShift = 0;

    while (characterShift < numberToCheck.length())
    {
        singleCharacter = numberToCheck[characterShift];
        if (isdigit(singleCharacter))
        {
            characterShift++;
        }
        else if (singleCharacter == ' ' || numberToCheck.empty())
        {
            numberToCheck.clear();
            cout << "The value entered is not a number" << endl;
            cout << "Please enter a number: ";
            cin >> numberToCheck;
            cout << endl;
            characterShift = 0;
        }

        else
        {
            numberToCheck.clear();
            cout << "The value entered is not a number" << endl;
            cout << "Please enter a number: ";
            cin >> numberToCheck;
            cout << endl;
            characterShift = 0;
        }
    }
    return numberToCheck;
}

#endif