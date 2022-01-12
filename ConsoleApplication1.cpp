#include "Header.h"

int main()
{
    welcome();
    atexit(exiting);
    choiceOfDishesFromTheMenu();
    hereOrDelivery = choiceHereDelivery();
    tableNumberElseDelivery();
    return 0;
}
