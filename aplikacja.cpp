#include "Header.h"

int main()
{
    powitanie();
    struct tm newTime;
    time_t now = time(0);
    localtime_s(&newTime, &now);
//    cout << newTime.tm_hour << ":" << newTime.tm_min;


    int hereOrTakeaway = choiceHereTakeaway();
    int hereNumber;
    int takeAwayHour;
    int takeAwayMin;
    char colon;
    string street;
    int streetNumber;
    int flatNumber;

    if (hereOrTakeaway == 1)
    {
        hereNumber = table();
        cout << "\nWybrales stolik numer: " << hereNumber;
    }
    else
    {
        cout << "\nPodaj adres.\n"<<"Ulica:";
        while (!(cin >> street))
        {
            cout << "\nPodaj prawidlowa ulice:";
            cin.clear();
            cin.ignore(123, '\n');
        }
        cout << "\nNumer ulicy:";
        while (!(cin >> streetNumber))
        {
            cout << "\nPodaj prawidlowy numer ulicy:";
            cin.clear();
            cin.ignore(123, '\n');
        }
        cout << "\nNumer mieszkania:";
        while (!(cin >> flatNumber))
        {
            cout << "\nPodaj prawidlowy numer mieszkania:";
            cin.clear();
            cin.ignore(123, '\n');
        }
        cout << "\nZamowienie bedzie dostarczone na adres: "<<street<< " " << streetNumber << "/" << flatNumber;
        cout << "\nWybierz godzine dostarczenia zamowienia sposrod podanych ponizej.\n";

        cin >> takeAwayHour >> colon >> takeAwayMin;
        cout << takeAwayHour << ":" << takeAwayMin;

        struct tm newTime;
        time_t now = time(0);
        localtime_s(&newTime, &now);
    }
    return 0;
}