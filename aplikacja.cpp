#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;



int choiceHereTakeaway()
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
        cout << "\nNie wybrano poprawnej opcji!";
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

int main()
{
    struct tm newTime;
    time_t now = time(0);
    localtime_s(&newTime, &now);
    cout << newTime.tm_hour << ":" << newTime.tm_min;


    cout << "\nWitaj w restauracji Let's IT przy ulicy Wizualnej 62!\n";
    cout << "Wcisnij dowolny klawisz, aby kontynowac";
    cin.ignore(1, '\n');

    int hereOrTakeaway = choiceHereTakeaway();
    int hereNumber;
    string adress;

    if (hereOrTakeaway == 1)
    {
        hereNumber = table();
        cout << "\nWybrales stolik numer: " << hereNumber;
    }
    else
    {
        cout << "\nPodaj adres.\n";
        cin >> adress;
        cout << "\nZamowienie bedzie dostarczone na adres: " << adress;
        cout << "\nPodaj godzine dostarczenia zamowienia.";
        cout << "\nAktualna godzina: ";
        struct tm newTime;
        time_t now = time(0);
        localtime_s(&newTime, &now);
        cout << newTime.tm_hour << ":" << newTime.tm_min;

    }



    return 0;
}