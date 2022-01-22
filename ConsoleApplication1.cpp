#include "Header.h"
#include "Order.h"
#include <conio.h>
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

    fileOpen();

    while (endOrder != 4)
    {

        switch (endOrder)
        {
        case 1:
            choiceOfDishesFromTheMenu();
            displayOrderOrsaveInFile(endOrder);
            break;

        case 2:
            displayOrderOrsaveInFile(endOrder);
            successfulRemove = removeTheDish();
            if (successfulRemove == 1)
            {
                if (!order[0].empty())
                {
                    displayOrderOrsaveInFile(endOrder);
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
        }
        cout << "What you want to do:" << endl;
        cout << "1 - if you want to continue placing the order" << endl;
        cout << "2 - if you want to remove something from your order" << endl;
        cout << "3 - show me menu again" << endl;
        cout << "4 - that's all the bill, please" << endl;
        cout << "Select an option: ";

        cin >> checkTheNumber;
        endOrder = stoi(checkIfTheVariableIsANumber1(checkTheNumber));
        checkTheNumber.clear();
    }
    if (endOrder == 4)
    {
        displayOrderOrsaveInFile(endOrder);
  //      saveOrderInFile();
        cin >> endOrder;
    }
    summary(); // podsumowuje zamowienie, podaje wybrany numer stolika lub adres zamowienia
    ofstream myfile;
    string fileName = customerName + "'s order.txt";
    ifstream ifile;
    int i = 1; 
    ifile.open(fileName);
    while (ifile)// sprawdza czy plik o takiej istnieje - jesli istnieje, zmienia nazwe pliku, zeby nie nadpisac poprzedniego
    {
        ifile.open(fileName);
        i++;
        stringstream ss;
        ss << customerName << i;
        ss >> fileName;
        fileName = fileName + "'s order.txt";
    }
    myfile.open (fileName);
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
    myfile << order[number+1];
    return 0;
}
