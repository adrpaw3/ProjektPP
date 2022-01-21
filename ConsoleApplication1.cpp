#include "Header.h"
#include "Order.h"
#include <conio.h>
#include "checkIfTheVariableIsANumber.h"
using namespace std;

int main()
{
    //welcome();
    // whatName();
    // atexit(exiting);
    // hereOrDelivery = choiceHereDelivery();
    // tableNumberElseDelivery(); // numer stolika bądź dostawa
    //**************************************************************************************

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
        saveOrderInFile();
        cin >> endOrder;
    }
    // summary(); // podsumowuje zamowienie, podaje wybrany numer stolika lub adres zamowienia
    return 0;
}