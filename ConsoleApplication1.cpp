#include "Header.h"
#include "choiceOfDishesFromTheMenu.h"

int main()
{
    welcome();
    atexit(exiting);
    choiceOfDishesFromTheMenu();
    hereOrDelivery = choiceHereDelivery();
    tableNumberElseDelivery();
    return 0;
}