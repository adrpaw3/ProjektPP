#pragma once
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
    cout << "\x1B[2J\x1B[H";
}
void exiting()
{
    cout << "\x1B[2J\x1B[H";
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

inline void choiceOfDishesFromTheMenu()
{
    fstream file;
    //string dirName = "C:\\Users\\adamw\\source\\repos\\Projekt_Podstawy_Programowania\\Projekt_Podstawy_Programowania\\";
    //string fileName = dirName + "Menu.txt";
    int dishNumber = 0;
    int numberOfServings = 0;
    float coast = 0;
    string prise;
    int endOrder = 1;
    string order[20];
    string firstElementOfLine;
    int number = 0;
    int counterOfDishes = 1;
    file.open("Menu.txt");
    string line;

    if (file.is_open())
    {
        cout << "Please place an order:" << endl;

        while (getline(file, line))
        {
            cout << line << "\n";
        }
        file.close();

        while (endOrder == 1)
        {
            cout << "Please select a dish number: ";
            cin >> dishNumber;
            cout << endl;

            if (dishNumber > 0 && dishNumber < 21)
            {
                cout << "Please enter the number of servings: ";
                cin >> numberOfServings;
                cout << endl;
                file.open(fileName);

                while (true)
                {
                    getline(file, line);
                    firstElementOfLine = line[0];

                    if (firstElementOfLine == to_string(dishNumber))
                    {
                        break;
                    }
                }

                prise = (line[line.find('$') - 2]);
                prise = prise + (line[line.find('$') - 1]);
                coast = coast + (stoi(prise) * numberOfServings);

                if (prise[0] == ' ')
                {
                    prise.erase(0, 1);
                    prise.append(" ");
                }

                line.insert(line.find('$') - 7, to_string(numberOfServings));
                line.insert(line.find('$') - 7, "x");
                line.replace(line.find('x') + 1, 2, prise);
                line.replace(line.find('$') - 2, 2, to_string(stoi(prise) * numberOfServings));

                line.replace(0, 1, to_string(counterOfDishes));
                order[number] = line;
                counterOfDishes++;
                number++;
                file.close();
            }
            else
            {
                cout << "we don't have such an dishes on our menu\n";
            }
            cout << "What you want to do:" << endl;
            cout << "1 - if you want to continue placing the order" << endl;
            cout << "2 - if you want to remove something from your order" << endl;
            cout << "3- that's all the bill, please" << endl;
            cout << "Select an option: ";
            cin >> endOrder;
        }
    }

    if (endOrder == 3)
    {
        cout << "Actual order:" << endl;
        for (int displayOrder = 0; displayOrder < number;)
        {
            cout << order[displayOrder] << endl;
            displayOrder++;
        }
        cout << "-----------------------------------------------------" << endl;
        cout << "current account:\t\t\t\t  " << coast << "$" << endl;
    }
}