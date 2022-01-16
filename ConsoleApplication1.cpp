#include "Header.h"
#include "Order.h"

int main()
{
    welcome();
    whatName();
    atexit(exiting);
    hereOrDelivery = choiceHereDelivery();
    tableNumberElseDelivery(); // numer stolika bądź dostawa
    choiceOfDishesFromTheMenu(); // wybór dań z menu
    summary(); // podsumowuje zamowienie, podaje wybrany numer stolika lub adres zamowienia
    return 0;
}