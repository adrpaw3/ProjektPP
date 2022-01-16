#include "Header.h"
#include "Order.h"

int main()
{
    welcome();
    whatName();
    atexit(exiting);
    hereOrDelivery = choiceHereDelivery();
    tableNumberElseDelivery(); // numer stolika bądź dostawa
    //**************************************************************************************
    int endOrder = 1;
    int successfulRemove = 1;
    fileOpen();
    while (endOrder != 3)
    {

        switch (endOrder)
        {
        case 1:
            choiceOfDishesFromTheMenu();
            break;

        case 2:
            displayOrder();
            successfulRemove = removeTheDish();
            if (successfulRemove == 1)
            {
                displayOrder();
            }
            break;
        }
        cout << "What you want to do:" << endl;
        cout << "1 - if you want to continue placing the order" << endl;
        cout << "2 - if you want to remove something from your order" << endl;
        cout << "3 - that's all the bill, please" << endl;
        cout << "Select an option: ";
        cin >> endOrder;
    }
    if (endOrder == 3)
    {
        displayOrder();
    }
    summary(); // podsumowuje zamowienie, podaje wybrany numer stolika lub adres zamowienia
    saveToFile();
    return 0;
}