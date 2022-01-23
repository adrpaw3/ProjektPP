
#include <iostream> // biblioteka wejscia wyjscia
#include <string> // biblioteka obslugujaca lancuchy znakow
#include <sstream> // zapewnia obsluge strumieni ciagow znakow
#include <conio.h> // obsluga wejscia wyjscia z konsoli/terminala
using namespace std; // zastosowanie przestrzeni nazw

#ifndef checkIfTheVariableIsANumber
#define checkIfTheVariableIsANumber

// Funkcja sprawdzajaca poprawnosc wprowadzanych danych. To znaczy czy wartosc podana prze uzytkownika jest liczba.
// W przypadku podania blednej wartosci funkcja wskazuje i wymusza wprowadzenie prawidlowej wartosci. 

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