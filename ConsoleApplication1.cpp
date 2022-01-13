#include "Header.h"
#include "choiceOfDishesFromTheMenu.h"

int main()
{
    welcome();
    whatName();
    atexit(exiting);
    hereOrDelivery = choiceHereDelivery();
    tableNumberElseDelivery();
    choiceOfDishesFromTheMenu();
    summary();
    return 0;
}