#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>
#include <string>
using namespace std;
void powitanie()
{
    cout << "\nWitaj w restauracji Let's IT przy ulicy Wizualnej 62!\n";
    cout << "Wcisnij dowolny klawisz, aby kontynowac";
    cin.ignore(1, '\n');
    cout << "\x1B[2J\x1B[H";
}
int choiceHereTakeaway()
{
    int ifHere;
    cout << "Wpisz \"1\" jesli danie ma byc na miejscu.\n";
    cout << "Wpisz \"2\" jesli danie ma byc na dowoz.\n";
    cin >> ifHere;
    if (ifHere == 1 || ifHere == 2)
    {
        return ifHere;
    }
    else
    {
        cout << "\nNie wybrano poprawnej opcji!\n";
        choiceHereTakeaway();
    }
}

int table()
{
    cout << "\nPodaj numer stolika od 1 do 14.\n";
    int tableNumber;
    cin >> tableNumber;
    if (tableNumber >= 1 && tableNumber <= 14)
    {
        return tableNumber;
    }
    else
    {
        cout << "\nNieprawidlowy numer stolika.\n";
        table();
    }
}