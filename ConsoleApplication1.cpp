#include "Header.h"

int main()
{
    welcome();
    atexit(exiting);
    hereOrDelivery = choiceHereDelivery();
    tableNumberElseDelivery();
    return 0;
}