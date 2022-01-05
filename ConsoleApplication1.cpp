#include "Header.h"

int main()
{
    welcome();
    atexit(exiting);

    struct tm newTime;
    time_t now = time(0);
    localtime_s(&newTime, &now);
//    cout << newTime.tm_hour << ":" << newTime.tm_min;


    hereOrDelivery = choiceHereDelivery();
 
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
    return 0;
}