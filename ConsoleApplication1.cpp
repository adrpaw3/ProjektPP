#include "Header.h"

int main()
{
    powitanie();
    struct tm newTime;
    time_t now = time(0);
    localtime_s(&newTime, &now);
//    cout << newTime.tm_hour << ":" << newTime.tm_min;


    int hereOrTakeaway = choiceHereTakeaway();
    


    if (hereOrTakeaway == 1)
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
        cout << "\nWybierz godzine dostarczenia zamowienia sposrod podanych ponizej.\n";

        cin >> takeAwayHour >> colon >> takeAwayMin;
        cout << takeAwayHour << ":" << takeAwayMin;

        struct tm newTime;
        time_t now = time(0);
        localtime_s(&newTime, &now);
    }
    return 0;
}