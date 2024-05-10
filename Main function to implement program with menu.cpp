#include<iostream>
#include<string>
using namespace std;



class Abc{
public:
void Main() {
    
        cout << "|*************************************************************************************|" << endl;
        cout << "|                                  Welcome to GIKI Online                             |" << endl;
        cout << "|                                   Ticket Booking System                             |" << endl;
        cout << "|*************************************************************************************|" << endl;
        cout << "|*************************************************************************************|" << endl;
        cout << "|                                          |                                          |" << endl;
        cout << "|                1. LOGIN                  |              2. SIGN-UP                  |" << endl;
        cout << "|*************************************************************************************|" << endl;
        cout << "|                                          |                                          |" << endl;
        cout << "|                3. REFUND                 |              4. COMPLAINT                |" << endl;
        cout << "|*************************************************************************************|" << endl << endl;
        cout << "OPTION: ";
        int choice;
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                //Login();                            MADE AND ADDED IN FINAL CODE
                break;
            case 2:
                //Sign_Up();                   MADE AND ADDED IN FINAL CODE
                break;
            case 3:
                //Refund();                MADE AND ADDED IN FINAL CODE
                break;
            case 4:
               // Complaint();       MADE AND ADDED IN FINAL CODE
                break;
            default:
                system("CLS");
                cout << endl;
                cout << "|-----------------------------------Invalid Selection---------------------------------|" << endl << endl;
                cout << "|------------------------------Please Select a Valid Option---------------------------|" << endl << endl;
                Main();
        }

       // Bus_Selection();    MADE AND ADDED IN FINAL CODE
        
        
    }};
    int main(){
    	
    	Abc c;
    	
    	c.Main();
    	
    	
    	
	}
