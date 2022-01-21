#include <iostream> // biblioteka wejscia wyjscia
#include <fstream> // do zarówno czytania jak i pisania do i z plików
#include <string> // biblioteka obslugujaca lancuchy znakow 
#include <sstream> // zapewnia obsluge strumieni ciagow znakow
#include <conio.h> // obsluga wejscia wyjscia z konsoli/terminala
using namespace std; // zastosowanie przestrzeni nazw

int hereNumber; // wybrany numer stolika
int deliveryHour; // godzina dostarczenia zamowienia
int deliveryMin; // minuta dostarczenia zamowienia
char colon;
string addressStreet; // ulica
int addressStreetNumber; // numer ulicy 
int addressFlatNumber; // numer mieszkania
string ddeliveryTime; // czas dostawy
int hereOrDelivery; // na miejscu lub na dowóz 
unsigned char inputChar;
string customerName; // imie klienta

void welcome()
{
    cout << "\nWelcome to the Let's IT restaurant\n"; // wyświetl "Witamy w restauracji 'Let's IT'"
    system("pause");
}
// procedura wykonujaca pewne operacje przy zamknieciu programu
void exiting()
{
    cin.ignore(1, '\n');
    cout << "\n\nThank you for using our program!\n\n"; // wyświetl "Dziękujemy za korzystanie z naszego programu!"
    system("pause");
}
// wybor na miejscu lub dostawa
int choiceHereDelivery()
{
    int ifHere;
    cout << "\nType \"1\" if you want to order on site.\n"; // wyświetl "Napisz 1 jeśli chcesz zamówić na miejscu."
    cout << "Type \"2\" if you want a delivery.\n"; // wyświetl "Napisz 2 jeśli chcesz dostawę."
    cin >> ifHere; // pobierz to co zostało wpisane 
    if (ifHere == 1 || ifHere == 2) // jeśli 1 lub 2 
    {
        return ifHere; // zwróć tą liczbę
    }
    else // w przeciwnym wypadku
    {
        cout << "\nThe correct option was not selected!\n"; // wyświetl "Nie wybrano prawidłowej opcji!"
        choiceHereDelivery();
    }
    return 0;
}
// wybor numeru stolika
int table()
{
    cout << "\nEnter the table numer from 1 to 14!\n"; // wyświetl "Wpisz numer stolika od 1 do 14!"
    int tableNumber; // zmienna int numer stolika
    cin >> tableNumber; // pobierz numer stolika który został podany przez użytkownika
    if (tableNumber >= 1 && tableNumber <= 14) // jeśli nr stolika jest równy większy 1 i mniejszy równy 14
    {
        return tableNumber; // zwróć tą liczbę
    }
    else // w przeciwnym wypadku
    {
        cout << "\nInvalid table number!\n"; // wypisz "Nieprawidłowy numer stolika!"
        table();
    }
    return 0;
}
//pobieranie informacji adresu od użytkownika
string street()
{
    cout << "\nEnter address!\n" // wyświetl "Wpisz adres"
         << "Street:";
    string streetS;
    cin.clear();
    cin.ignore(123, '\n');
    getline(cin, streetS);
    return streetS; // zwróć co użytkownik podał
}
// pobranie informacji o numerze ulicy od użytkownika
int streetNumber()
{
    int streetNum;
    cout << "\nStreet number:"; // wyświetl "Numer ulicy: "
    while (!(cin >> streetNum))
    {
        cout << "\nEnter a valid street number:"; // wyświetl "Wpisz poprawny numer ulicy: "
        cin.clear();
        cin.ignore(123, '\n');
    }
    return streetNum; // zwróć co użytkownik podał
}
// pobranie informacji o numerze mieszkania od użytkownika
int flatNumber()
{
    int flatNum;
    cout << "\nFlat number:"; // wyświetl "Numer mieszkania:"
    while (!(cin >> flatNum))
    {
        cout << "\nEnter a valid flat number:"; // wyświetl "Wpisz poprawny numer mieszkania:"
        cin.clear();
        cin.ignore(123, '\n');
    }
    return flatNum; // zwróć co użytkownik podał
}
// pobranie informacji o terminie dostawy od użytkownika
string deliveryT()
{
    int delH;
    int delM;
    string delTime;
    cout << "\nSelect the time of order delivery\n"; // wyświetl "Wybierz termin dostawy zamówienia"
    cin >> delH >> colon >> delM; // pobranie od użutkownika godiny dostawy 
    if (delH >= 0 && delH <= 23 && delM >= 0 && delM <= 59) // wertyfikacja poprawności wprowadzonej godziny 
    {
        stringstream ss;
        ss << delH;
        ss << colon;
        ss << delM;
        ss >> delTime;
        return delTime; // zwrócenie sformołowanej godziny: hh:mm
    }
    else 
    {
        cout << "\nInvalid time format\n"; // wypisz "Nieprawidłowy format czasu"
        deliveryT();
    }
    return NULL;
}
// jesli wybrano na miejscu - podaje numer stolika, jesli na wynos - pyta o adres i czas dostawy
void tableNumberElseDelivery()


{
    if (hereOrDelivery == 1) // jeśli użytkownik wybrał 1
    {
        hereNumber = table(); // wybrany numer stolika
        cout << "\nYour table number: " << hereNumber << "\n"; // wyświetl "Twój numer stolika: " wyświetla liczbę jaką podał użytkownik  
    }
    else  
    {
        addressStreet = street(); // adres ulicy
        addressStreetNumber = streetNumber(); // numer ulicy
        addressFlatNumber = flatNumber(); // numer mieszkania
        cout << "\nThe order will be delivered to the following address: " << addressStreet << " " << addressStreetNumber << " " << addressFlatNumber << "\n"; // wyświetl "Zamówienie zostanie dostarczone na adres: " adres który podał użytkownik
        ddeliveryTime = deliveryT();
        cout << "\nThe order will be delivered at " << ddeliveryTime << "\n"; // wyświetl  "Zamówienie zostanie dostarczone na " wybrany czas przez użytkownika
    }
}
// procedura pyta o imie, nastepnie przypisuje podana przez uzytkownika linie tekstu pod zmienna
void whatName()
{
    cout << "What is your name?\n"; // wyświetl "Jak masz na imię?"
    getline(cin,customerName); // pobierz co podał użytkownik
}
// podumowanie
void summary()
{
    if (hereOrDelivery == 1) // jeśli użytkownik wpisał 1
    {
    cout << "\nYour table number: " << hereNumber << "\n"; // wyświetl "Twój numer stolika: wyświetl numer stolika który wybrał użytkownik"
    }
    else 
    {
    cout << "\nThe order will be delivered to the following address: " << addressStreet << " " << addressStreetNumber << "/" << addressFlatNumber << "\n"; // wyświetl "Zamówienie zostanie dostarczone na poniższy adres: wyświetla nazwę uliczy, nr ulicy i nr mieszkania"
    cout << "\nThe order will be delivered at " << ddeliveryTime << "\n"; // wyświetl "Zamówienie zostanie dostarczone na" wybrany czas
    }
}
// zapisanie zamowienia do pliku
void saveToFile()
{
    ofstream myfile;
    string fileName = customerName + "'s order.txt";
    ifstream ifile;
    int i = 1; 
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
        myfile << "Delivery time: " << ddeliveryTime;
    }
}
