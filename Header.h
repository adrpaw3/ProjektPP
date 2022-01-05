#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

int hereNumber;
int deliveryHour;
int deliveryMin;
char colon;
string addressStreet;
int addressStreetNumber;
int addressFlatNumber;
string ddeliveryTime;

void powitanie()
{
    cout << "\nWitaj w restauracji Let's IT przy ulicy Wizualnej 62!\n";
    cout << "Wcisnij dowolny klawisz, aby kontynowac";
    cin.ignore(1, '\n');
    cout << "\x1B[2J\x1B[H";
}
int choiceHereDelivery()
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
        choiceHereDelivery();
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
string street()
{
    cout << "\nPodaj adres.\n" << "Ulica:";
    string streetS;
    cin.clear();
    cin.ignore(123, '\n');
    getline(cin, streetS);
    return streetS;
}
int streetNumber()
{
    int streetNum;
    cout << "\nNumer ulicy:";
    while (!(cin >> streetNum))
    {
        cout << "\nPodaj prawidlowy numer ulicy:";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return streetNum;
}
int flatNumber()
{
    int flatNum;
    cout << "\nNumer mieszkania:";
    while (!(cin >> flatNum))
    {
        cout << "\nPodaj prawidlowy numer mieszkania:";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return flatNum;
}
string deliveryT()
{
    int delH;
    int delM;
    string delTime;
    cout << "\nWybierz godzine dostarczenia zamowienia sposrod podanych ponizej.\n";
    cin >> delH >> colon >> delM;
    if (delH >= 0 && delH <= 23 && delM >= 0 && delM <= 59)
    {
        stringstream ss;
        ss << delH;
        ss << colon;
        ss << delM;
        ss >> delTime;
        return delTime;
    }
    else
    {
        cout << "\nNieprawidlowy format godziny.\n";
            deliveryT();
    }
}