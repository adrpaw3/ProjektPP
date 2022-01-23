#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Header.h"
#include "Order.h"
#include "checkIfTheVariableIsANumber.h"
using namespace std;

int main()
{
    welcome();
    whatName();
    atexit(exiting);
    hereOrDelivery = choiceHereDelivery();
    tableNumberElseDelivery(); // numer stolika bądź dostawa

    int endOrder = 1;
    int successfulRemove = 1;
    string checkTheNumber;
    string FinishPlaceOrder;

    fileOpen();

    while (endOrder != 5)
    {

        switch (endOrder)
        {
        case 1:
            choiceOfDishesFromTheMenu();
            displayOrder(endOrder);
            break;

        case 2:
            displayOrder(endOrder);
            successfulRemove = removeTheDish();
            if (successfulRemove == 1)
            {
                if (!order[0].empty())
                {
                    displayOrder(endOrder);
                }
                else
                {
                    cout << "There are no items in your order" << endl;
                }
            }
            break;

        case 3:
            system("cls");
            fileOpen();
            break;

        case 4:
            if (endOrder == 4 && !order[0].empty())
            {
                displayOrder(endOrder);

                cout << "Are you sure that you want to finish place order?" << endl;
                cout << "Write \'yes\' if you want to finish place order or something else if you want to continue: ";
                cin >> FinishPlaceOrder;

                if (FinishPlaceOrder == "yes")
                {

                    summary(); // podsumowuje zamowienie, podaje wybrany numer stolika lub adres zamowienia

                    ofstream myfile;

                    string fileName = customerName + "'s order.txt";
                    ifstream ifile;
                    int i = 1;
                    ifile.open(fileName);
                    while (ifile) // sprawdza czy plik o takiej istnieje - jesli istnieje, zmienia nazwe pliku, zeby nie nadpisac poprzedniego
                    {
                        ifile.open(fileName);
                        i++;
                        stringstream ss;
                        ss << customerName << i;
                        ss >> fileName;
                        fileName = fileName + "'s order.txt";
                    }
                    myfile.open(fileName);
                    myfile << "Customer name: " << customerName << "\n";
                    if (hereOrDelivery == 1) // jeśli użytkownik wpisał 1
                    {
                        myfile << "Table number: " << hereNumber << "\n";
                    }
                    else
                    {
                        myfile << "Address: " << addressStreet << " " << addressStreetNumber << "/" << addressFlatNumber << "\n";
                        myfile << "Delivery time: " << ddeliveryTime << "\n";
                    }
                    myfile << order[number] << "\n";
                    for (int displayOrder = 0; displayOrder < number;)
                    {
                        if (order[displayOrder].length() > 2)
                        {
                            myfile << order[displayOrder] << endl;
                        }

                        displayOrder++;
                    }
                    myfile << order[number] << "\n";
                    myfile << order[number + 1];
                    endOrder = 5;
                }
                else
                {
                    cout << "continue placing an order" << endl;
                }
            }
            else
            {
                cout << "You can't place an order if you don't choose anything";
            }
        case 5:
            break;
        }
        if (endOrder != 5)
        {
            cout << "What you want to do:" << endl;
            cout << "1 - if you want to continue placing the order" << endl;
            cout << "2 - if you want to remove something from your order" << endl;
            cout << "3 - show me menu again" << endl;
            cout << "4 - that's all the bill, please" << endl;
            cout << "5 - exit the application" << endl;
            cout << "Select an option: ";

            cin >> checkTheNumber;
            endOrder = stoi(checkIfTheVariableIsANumber1(checkTheNumber));
            checkTheNumber.clear();
        }
    }

    return 0;
}

void saveToFile()
{
}