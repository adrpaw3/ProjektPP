#include <iostream>
#include <fstream> // klasa, która pozwala na odczytywanie lub zapisywanie danych z pliku
#include <string>  //biblioteka obslugujaca lancuchy znakow
#include <sstream> //zapewnia obsluge strumieni ciagow znakow
#include <conio.h> //obsluga wejscia wyjscia z konsoli/terminala
#include "checkIfTheVariableIsANumber.h"

using namespace std;

fstream file;
int cost = 0;
string price;     // cena za porcję wyciągana z menu
string order[20]; // tablica, w której przechowywane jest zamówinie
int number = 0;
int counterOfDishes = 1;
string line; // string, który przechowuje odpowiednią linię zamówinia

// Funkcja otwiera menu i wyświtela je w konsoli
void fileOpen()
{
    file.open("Menu.txt");
    if (file.is_open())
    {
        cout << "Please place an order:" << endl;

        while (getline(file, line))
        {
            cout << line << "\n";
        }
        file.close();
    }
}
// funkcja obsługująca zamówienie
void choiceOfDishesFromTheMenu()
{

    int numberOfServings = 0;
    int dishNumber = 0;
    string firstElementOfLine;
    string portionsPrice;
    int shift = 7;
    int formatingCounter = 0;
    string charOfPortionsPrice;
    string checkTheNumber;
    bool checkIfTheDishHasBeenSelected = false;
    bool dishNumberCorrect = false;
    bool numberOfServingsCorrect = false;

    while (checkIfTheDishHasBeenSelected == false)
    {
        if (dishNumberCorrect == false)
        {
            cout << "Please select a dish number: ";
            cin >> checkTheNumber;
            cout << endl;

            dishNumber = stoi(checkIfTheVariableIsANumber1(checkTheNumber));
            checkTheNumber.clear();
        }

        if (dishNumber > 0 && dishNumber < 21 && number < 10)
        {
            dishNumberCorrect = true;

            cout << "Please enter the number of servings: ";
            cin >> checkTheNumber;
            numberOfServings = stoi(checkIfTheVariableIsANumber1(checkTheNumber));
            checkTheNumber.clear();
            cout << endl;

            if (numberOfServings <= 10 && numberOfServings > 0)
            {
                numberOfServingsCorrect = true;

                if (dishNumberCorrect == true && numberOfServingsCorrect == true)
                {
                    file.open("Menu.txt");

                    while (!file.eof())
                    {
                        getline(file, line);

                        if (to_string(dishNumber).length() == 1)
                        {
                            firstElementOfLine = line[0];
                        }
                        else
                        {
                            firstElementOfLine = line[0];
                            firstElementOfLine = firstElementOfLine + line[1];
                        }

                        if (firstElementOfLine == to_string(dishNumber))
                        {

                            break;
                        }
                    }
                    file.close();

                    // numeracja
                    if (to_string(dishNumber).length() == 1)
                    {
                        if (counterOfDishes < 10)
                        {
                            line.replace(0, 1, to_string(counterOfDishes));
                        }
                        else
                        {
                            line.replace(0, 2, to_string(counterOfDishes));
                        }
                    }
                    else
                    {
                        if (counterOfDishes < 10)
                        {
                            line.replace(0, 1, to_string(counterOfDishes));
                            line.erase(1, 1);
                            line.insert(line.find('$') - 5, " ");
                        }
                        else
                        {
                            line.replace(0, 2, to_string(counterOfDishes));
                        }
                    }

                    price = (line[line.find('$') - 2]);
                    price = price + (line[line.find('$') - 1]);
                    cost = cost + (stoi(price) * numberOfServings);

                    if (isdigit(price[0]))
                    {
                        price.append("$");
                    }
                    else if (price[0] == ' ')
                    {
                        price.erase(0, 1);
                        price.replace(1, 1, "$");
                    }

                    line.insert(line.length() - 7, to_string(numberOfServings));
                    line.insert(line.length() - 7, "x");
                    line.insert(line.length() - 7, price);

                    portionsPrice = to_string(stoi(price) * numberOfServings);
                    line.replace(line.rfind('$') - 3, 4, " ");

                    // Formatowanie wyświetlania ceny końcowej

                    portionsPrice.append("$");
                    formatingCounter = portionsPrice.length();

                    while (shift > 0)
                    {
                        line.append(" ");
                        shift--;
                    }
                    shift = 10;
                    while (portionsPrice != "")
                    {
                        if (numberOfServings < 10)
                        {
                            charOfPortionsPrice = portionsPrice[formatingCounter - 1];
                            portionsPrice.erase(formatingCounter, 1);
                            line.replace(line.rfind("x") + shift, 1, charOfPortionsPrice);
                            formatingCounter--;
                            shift--;
                        }
                        else if (numberOfServings >= 10)
                        {
                            charOfPortionsPrice = portionsPrice[formatingCounter - 1];
                            portionsPrice.erase(formatingCounter, 1);
                            line.replace(line.rfind("x") - 1 + shift, 1, charOfPortionsPrice);
                            formatingCounter--;
                            shift--;
                        }
                    }

                    order[number] = line;
                    counterOfDishes++;
                    number++;
                }
                checkIfTheDishHasBeenSelected = true;
            }
            else
            {
                cout << "You can order a maximum of 10 servings of one dish" << endl;
            }
        }
        else
        {
            if (number == 10)
            {
                cout << "You can order a maximum of 10 dishes\n";
                break;
            }
            else
            {
                cout << "We don't have such an dishes on our menu\n";
            }
        }
    }
}

// Funkcja pozwalająca na usunięcie pozycji z zamówinia klienta
int removeTheDish()
{
    int deleteAnItem = 0;
    int numbering = 1;
    string MenuItem;
    int deleteDish = 0;
    string checkTheNumber;

    cout << endl;

    cout << order[number];

    cout << "select the dish that you want to delete: ";
    cin >> checkTheNumber;

    deleteDish = stoi(checkIfTheVariableIsANumber1(checkTheNumber));
    checkTheNumber.clear();

    MenuItem = order[deleteDish - 1];

    if (deleteDish <= number)
    {
        deleteDish--;

        while (deleteAnItem < (number - deleteDish))
        {
            order[deleteDish + deleteAnItem] = order[deleteDish + deleteAnItem + 1];
            deleteAnItem++;
        }
        order[number].clear();
        number--;

        while (numbering <= number)
        {
            if (numbering < 10)
            {
                order[numbering - 1].replace(0, 1, to_string(numbering));
                numbering++;
            }
            else
            {
                order[numbering - 1].replace(0, 1, to_string(numbering));
                order[numbering - 1].erase(1, 1);
                numbering++;
            }
        }

        numbering = 0;
        counterOfDishes--;

        price = (MenuItem[MenuItem.rfind('$') - 2]);
        price = price + (MenuItem[MenuItem.rfind('$') - 1]);
        cost = cost - (stoi(price));

        return 1;
    }

    else
    {
        cout << "No such item" << endl;
    }
    return 0;
}
// funkcja wyświetlająca aktualne zamówienie
int displayOrder(int choice)
{
    string pricePosition;
    int displayCounter = 0;
    string lineSummary;
    string summary;
    if (number > 0)
    {
        cout << "Actual order:" << endl;
        for (int displayOrder = 0; displayOrder < number;)
        {
            if (order[displayOrder].length() > 2)
            {
                cout << order[displayOrder] << endl;
            }

            displayOrder++;
        }

        while (order[number - 1].rfind('$') + 1 > displayCounter)
        {
            lineSummary.append("-");
            displayCounter++;
        }
        displayCounter = 0;

        while (order[0].rfind('$') - 19 > displayCounter)
        {
            pricePosition.append(" ");
            displayCounter++;
        }
        displayCounter = 0;

        cout << lineSummary << endl;

        cout << "Current account:" << pricePosition << cost << "$" << endl;

        if (choice == 4)
        {
            summary = "Current account:" + pricePosition + to_string(cost) + "$";
            order[number] = lineSummary;
            order[number + 1] = summary;
        }
    }
    else
    {
        cout << "There is no dish in your order";
    }

    return 0;
}
