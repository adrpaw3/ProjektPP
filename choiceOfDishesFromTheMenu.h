#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
using namespace std;

inline int choiceOfDishesFromTheMenu()
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
                file.open("Menu.txt");

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
    return 0;
}