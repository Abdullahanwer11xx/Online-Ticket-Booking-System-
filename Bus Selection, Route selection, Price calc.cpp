#include<iostream>
#include<string>
using namespace std;

struct Distance
{
    static int Lahore;
    static int Islamabad;
    static int Mardan;
    static int Peshawar;
};
int Distance::Lahore = 434;
int Distance::Islamabad = 102;
int Distance::Mardan = 80;
int Distance::Peshawar = 125;

int Price_Calculation(int route_selection, Distance distances) {
    switch (route_selection)
    {
    case 1:
        return distances.Lahore;
    case 2:
        return distances.Islamabad;
    case 3:
        return distances.Mardan;
    case 4:
        return distances.Peshawar;
    default:
        return 0;
    }
}

class SelectionBus {
public:
    void Bus_Selection();
};

class Mainn :public SelectionBus {
public:
    void enter();
};

void SelectionBus::Bus_Selection() {
    int route_selection;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "                               WELCOME TO THE BUS TERMINAL                             " << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl << endl;

    cout << "OPTION       ---DESTINATION---          --- DURATION---           FARE" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "  1.           GIKI to Lahore             6:21 hrs           " << Price_Calculation(1, Distance()) << " Rs" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "  2.           GIKI to Islamabad          2:00 hrs           " << Price_Calculation(2, Distance()) << " Rs" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "  3.           GIKI to Mardan             1:30 hrs           " << Price_Calculation(3, Distance()) << " Rs" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "  4.           GIKI to Peshawar           2:30 hrs           " << Price_Calculation(4, Distance()) << " Rs" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl << endl;
    cout << "OPTION: ";
    cin >> route_selection; cout << endl;

    switch (route_selection)
    {
    case 1:
        cout << "| GIKI TO LAHORE " << endl << "|" << endl;
        cout << "| PRICE: " << Price_Calculation(1, Distance()) << " Rs" << endl << "|" << endl;
        cout << "| DURATION: 6 Hours 20 Minutes" << endl << "|";
        break;
    case 2:
        cout << "| GIKI TO ISLAMABAD" << endl << "|" << endl;
        cout << "| PRICE: " << Price_Calculation(2, Distance()) << " Rs" << endl << "|" << endl;
        cout << "| DURATION: 1 Hour 20 Minutes" << endl << "|";
        break;
    case 3:
        cout << "| GIKI TO MARDAN" << endl << "|" << endl;
        cout << "| PRICE: " << Price_Calculation(3, Distance()) << " Rs" << endl << "|" << endl;
        cout << "| DURATION: 1 Hour" << endl << "|";
        break;
    case 4:
        cout << "| GIKI TO PESHAWAR " << endl << "|" << endl;
        cout << "| PRICE: " << Price_Calculation(4, Distance()) << " Rs" << endl << "|" << endl;
        cout << "| DURATION: 2 Hours and 15 Minutes" << endl << "|";
        break;
    default:
        cout << "|-----------------------------------Invalid Selection---------------------------------|" << endl << endl;
        cout << "|------------------------------Please Select a Valid Option---------------------------|" << endl << endl;
        Bus_Selection();
    }
    cout << endl;
    cout << "| Please arrive on time." << endl;
    cout << "|_______________________________" << endl << endl;
}

void Mainn::enter() {
    SelectionBus a;
    int choice;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "                                Welcome to GIKI Transport                              " << endl;
    cout << "                                    Management System                                  " << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "_______________________________________________________________________________________" << endl;
    cout << "|                                          |                                          |" << endl;
    cout << "|                1. LOGIN                  |              2. SIGN-UP                  |" << endl;
    cout << "|__________________________________________|__________________________________________|" << endl;
    cout << "|                                          |                                          |" << endl;
    cout << "|                3.Bus slection               |              4. COMPLAINT                |" << endl;
    cout << "|__________________________________________|__________________________________________|" << endl << endl;
    cout << "OPTION: ";
    cin >> choice; cout << endl;

    switch (choice)
    {
    case 1:
        cout << " Login();" << endl;
        break;
    case 2:
        cout << "Sign_Up()" << endl;
        break;
    case 3:
        a.Bus_Selection();
        break;
    case 4:
        break;
    default:
        cout << endl;
        cout << "|-----------------------------------Invalid Selection---------------------------------|" << endl << endl;
        cout << "|------------------------------Please Select a Valid Option---------------------------|" << endl << endl;
        enter();
    }
}

int main() {
    Mainn b;
    b.enter();
    return 0;
}

