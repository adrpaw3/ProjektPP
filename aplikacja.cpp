#include <iostream>
using namespace std;

int ChoiceHereTakeaway()
{
    int ifHere;
    cout << "\nWpisz \"1\" jesli danie ma byc na miejscu.\n";
    cout << "Wpisz \"2\" jesli danie ma byc na dowoz.\n";
    cin >> ifHere;
    if (ifHere == 1 || ifHere == 2)
    {
        return ifHere;
    }
    else
    {
        cout << "\nNie wybrano poprawnej opcji!";
        ChoiceHereTakeaway();
    }
}

int Table()
{
    cout << "\nPodaj numer stolika od 1 do 14.\n";
    int tableNumber;
    cin >> tableNumber;
    if (tableNumber >= 1 && tableNumber <= 14) 
    {
        return tableNumber;
    }
    else
    {
        cout << "\nNieprawidlowy numer stolika.\n";
        Table();
    }
}

int main()
{
    cout << "Witaj w restauracji Let's IT przy ulicy Wizualnej 62!\n";
    cout << "Wcisnij dowolny klawisz, aby kontynowac";
    cin.ignore(1, '\n');
    int hereOrTakeaway = ChoiceHereTakeaway();
    int hereNumber;
    string adress;
    if (hereOrTakeaway == 1)
    {
        hereNumber = Table();
        cout << "\nWybrales stolik numer: " << hereNumber;
    }
    else
    {
        cout << "\nPodaj adres.\n";
        cin >> adress;
        cout << "\nZamowienie bedzie dostarczone na adres: " << adress;
    }




}