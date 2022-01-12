#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
using namespace std;

int hereNumber;
int deliveryHour;
int deliveryMin;
char colon;
string addressStreet;
int addressStreetNumber;
int addressFlatNumber;
string ddeliveryTime;
int hereOrDelivery;
unsigned char inputChar;

void welcome()
{
    cout << "\nWitaj w restauracji Let's IT przy ulicy Wizualnej 62!\n";
    cout << "Wcisnij enter, aby kontynowac";
    cin.ignore(1, '\n');
}
void exiting()
{
    cin.ignore(1, '\n');
    cout << "\n\nDziekujemy za skorzystanie z programu!\n\n";
    system("pause");
}
int choiceHereDelivery()
{
    int ifHere;
    cout << "\nWpisz \"1\" jesli danie ma byc na miejscu.\n";
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
    return 0;
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
    return 0;
}
string street()
{
    cout << "\nPodaj adres.\n"
         << "Ulica:";
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
    cout << "\nWybierz godzine dostarczenia zamowienia.\n";
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
    return NULL;
}
void tableNumberElseDelivery()
{
    if (hereOrDelivery == 1)
    {
        hereNumber = table();
        cout << "\nWybrales stolik numer: " << hereNumber;
    }
    else
    {
        addressStreet = street();
        addressStreetNumber = streetNumber();
        addressFlatNumber = flatNumber();
        cout << "\nZamowienie bedzie dostarczone na adres: " << addressStreet << " " << addressStreetNumber << " " << addressFlatNumber;
        ddeliveryTime = deliveryT();
        cout << "\nZamowienie bedzie dostarczone na godzine: " << ddeliveryTime;
    }
}