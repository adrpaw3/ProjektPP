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
    summary(); // podsumowuje zamowienie, podaje wybrany numer stolika lub adres zamowienia
    return 0;
}