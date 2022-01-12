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
    cout << "\nWelcome to the Let's IT restaurant\n";
    system("pause");
}
void exiting()
{
    cin.ignore(1, '\n');
    cout << "\n\nThank you for using our program!\n\n";
    system("pause");
}
int choiceHereDelivery()
{
    int ifHere;
    cout << "\nType \"1\" if you want to order on site.\n";
    cout << "Type \"2\" if you want a delivery.\n";
    cin >> ifHere;
    if (ifHere == 1 || ifHere == 2)
    {
        return ifHere;
    }
    else
    {
        cout << "\nThe correct option was not selected!\n";
        choiceHereDelivery();
    }
    return 0;
}
int table()
{
    cout << "\nEnter the table numer from 1 to 14!\n";
    int tableNumber;
    cin >> tableNumber;
    if (tableNumber >= 1 && tableNumber <= 14)
    {
        return tableNumber;
    }
    else
    {
        cout << "\nInvalid table number!\n";
        table();
    }
    return 0;
}
string street()
{
    cout << "\nEnter address!\n"
         << "Street:";
    string streetS;
    cin.clear();
    cin.ignore(123, '\n');
    getline(cin, streetS);
    return streetS;
}
int streetNumber()
{
    int streetNum;
    cout << "\nStreet number:";
    while (!(cin >> streetNum))
    {
        cout << "\nEnter a valid street number:";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return streetNum;
}
int flatNumber()
{
    int flatNum;
    cout << "\nFlat number:";
    while (!(cin >> flatNum))
    {
        cout << "\nEnter a valid flat number:";
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
    cout << "\nSelect the time of order delivery\n";
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
        cout << "\nInvalid time format\n";
        deliveryT();
    }
    return NULL;
}
void tableNumberElseDelivery()
{
    if (hereOrDelivery == 1)
    {
        hereNumber = table();
        cout << "\nYour table number: " << hereNumber;
    }
    else
    {
        addressStreet = street();
        addressStreetNumber = streetNumber();
        addressFlatNumber = flatNumber();
        cout << "\nThe order will be delivered to the following address: " << addressStreet << " " << addressStreetNumber << " " << addressFlatNumber;
        ddeliveryTime = deliveryT();
        cout << "\nThe order will be delivered at " << ddeliveryTime;
    }
}