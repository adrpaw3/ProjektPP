#include <iostream> // biblioteka wejscia wyjscia
#include <fstream> // do zarówno czytania jak i pisania do i z plików
#include <string> // biblioteka obslugujaca lancuchy znakow
#include <sstream> // zapewnia obsluge strumieni ciagow znakow
#include <conio.h> // obsluga wejscia wyjscia z konsoli/terminala
using namespace std;

fstream file;
int cost = 0;
string price;
string order[20];
int number = 0;
int counterOfDishes = 1;
string line;

void fileOpen()
{
    file.open("Menu.txt");
    if (file.is_open())
    {
        cout << "Please place an order:" << endl;

        while (getline(file, line))
        {
            cout << line << "\n";
        }
        file.close();
    }
}

void choiceOfDishesFromTheMenu()
{
    int numberOfServings = 0;
    int dishNumber = 0;
    string firstElementOfLine;

    cout << "Please select a dish number: ";
    cin >> dishNumber;
    cout << endl;

    if (dishNumber > 0 && dishNumber < 21)
    {
        cout << "Please enter the number of servings: ";
        cin >> numberOfServings;
        cout << endl;
        file.open("Menu.txt");

        while (true)
        {
            getline(file, line);
            firstElementOfLine = line[0];

            if (firstElementOfLine == to_string(dishNumber))
            {
                break;
            }
        }

        price = (line[line.find('$') - 2]);
        price = price + (line[line.find('$') - 1]);
        cost = cost + (stoi(price) * numberOfServings);

        if (price[0] == ' ')
        {
            price.erase(0, 1);
            price.append(" ");
        }

        //  if (price[1] == ' ' && numberOfServings == 10)
        //  {
        //      line.erase((line.find('$') - 2), (line.find('$') - 3));
        //  }

        line.insert(line.find('$') - 7, to_string(numberOfServings));
        line.insert(line.find('$') - 7, "x");
        line.replace(line.find('x') + 1, 2, price);
        line.replace(line.find('$') - 2, 2, to_string(stoi(price) * numberOfServings));

        line.replace(0, 1, to_string(counterOfDishes));
        order[number] = line;
        counterOfDishes++;
        number++;
        file.close();
    }
    else
    {
        cout << "we don't have such an dishes on our menu\n";
    }
}

int removeTheDish()
{
    int deleteAnItem = 0;
    int numbering = 1;
    string MenuItem;
    int deleteDish = 0;
    int arrayNumberZero = 0;

    cout << endl;

    cout << "select the dish that you want to delete: ";
    cin >> deleteDish;

    MenuItem = order[deleteDish - 1];

    if (deleteDish <= number)
    {
        deleteDish--;

        if (deleteDish == 0)
        {
            arrayNumberZero++;
        }

        while (deleteAnItem <= (deleteDish + arrayNumberZero))
        {
            order[deleteDish + deleteAnItem] = order[deleteDish + deleteAnItem + 1];
            deleteAnItem++;
        }
        order[number] = " ";
        number--;
        arrayNumberZero = 0;

        while (numbering <= number)
        {
            order[numbering - 1].replace(0, 1, to_string(numbering));
            numbering++;
        }
        counterOfDishes--;

        price = (MenuItem[MenuItem.find('$') - 2]);
        price = price + (MenuItem[MenuItem.find('$') - 1]);
        cost = cost - (stoi(price));

        return 1;
    }

    else
    {
        cout << "No such item" << endl;
    }
    return 0;
}

void displayOrder()
{
    string pricePosition = "current account:                                     " + to_string(cost) + "$";
    /*
    for (int c = 0; c < number;)
    {
        if (pricePosition.find('$') == order[c].find('$'))
        {
            c++;
        }
        else
        {
            order[c].erase(int(order[c].find('$')) - 2, pricePosition.find('$') - 2);
            order[c].erase(order[c].find('$') - 1, pricePosition.find('$') - 1);
            order[c].erase(order[c].find('$'), pricePosition.find('$'));
        }
    }
    pricePosition.find('$');
*/
    cout << "Actual order:" << endl;
    for (int displayOrder = 0; displayOrder < number;)
    {
        if (order[displayOrder].length() > 2)
        {
            cout << order[displayOrder] << endl;
        }

        displayOrder++;
    }
    cout << "-----------------------------------------------------" << endl;
    cout << "current account:                                     " << cost << "$" << endl;
}
