#include<iostream>
#include<string>                                     
#include<cstdlib>
#include<ctime>
#include<fstream>                                
#include<windows.h>                                   //Library for window switching
using namespace std;

class TicketingSystem {                                       //Class and struct to store variables
public:
    struct Distance {
        int Lahore = 434;
        int Islamabad = 102;
        int Mardan = 80;                                            
        int Peshawar = 125;
    };
};
class BusTiming:public TicketingSystem{                       //Inherited class with TicketingSystem
	public:
		void Bus_Timing() {
       srand(time(0));                                                    //Function for timing of bus

    int Hour = rand() % 24;
    int Minutes = rand() % 59 + 10;

    cout << "| BUS TIMING: " << Hour << ":" << Minutes << endl << "|" << endl;   // Implementation for bus timing
    }
};

class TicketBook : public BusTiming {                       //Inherited class with BusTiming
public:                                                                
	string R_Username, R_Password;
    int choice, route_selection, window_seat;
    
    Distance distances;
    
ofstream Store_Data;                            //Declaring ofstream variable for file handling

    void Main() {
    
        cout << "|*************************************************************************************|" << endl;
        cout << "|                                  Welcome to GIKI Online                             |" << endl;
        cout << "|                                   Ticket Booking System                             |" << endl;
        cout << "|*************************************************************************************|" << endl;  //Menu
        cout << "|*************************************************************************************|" << endl;
        cout << "|                                          |                                          |" << endl;
        cout << "|                1. LOGIN                  |              2. SIGN-UP                  |" << endl;
        cout << "|*************************************************************************************|" << endl;
        cout << "|                                          |                                          |" << endl;
        cout << "|                3. REFUND                 |              4. COMPLAINT                |" << endl;
        cout << "|*************************************************************************************|" << endl << endl;
        cout << "OPTION: ";
        
        cin >> choice;
        cout << endl;

        switch (choice) {                                     //Switch case statement in Main for selection
            case 1:
                Login();
                break;
            case 2:
                Sign_Up();
                break;
            case 3:
                Refund();
                break;
            case 4:
                Complaint();
                break;
            default:
                system("CLS");
                cout << endl;
                cout << "|-----------------------------------Invalid Selection---------------------------------|" << endl << endl;
                cout << "|------------------------------Please Select a Valid Option---------------------------|" << endl << endl;
                Main();
        }

        Bus_Selection();
    }

    void Login() {                                                 //Login function
         system("CLS");                         
    cout << endl;
    cout << "|*************************************************************************************|" << endl;
    cout << "                                         LOGIN                                         " << endl;
    cout << "|*************************************************************************************|" << endl << endl;

    string Username, Password;

    cout << "GIKI REG NO: ";
    cin >> Username; cout << endl;
    cout << "PASSWORD: ";
    cin >> Password; cout << endl;

    ifstream Read_Data("GIKI_transport.txt");                //Reading data at login to verify 
    string Saved_Username, Saved_Password;

    while (Read_Data >> Saved_Username >> Saved_Password)
    {
        if (Username == Saved_Username && Password == Saved_Password)
        {
            system("CLS");
            cout << endl;
            cout << "|----------------------------------LOGIN SUCCESSFUL!----------------------------------|" << endl << endl;
            Read_Data.close();
        }
        else
        {
            Read_Data.close();
            cout << "|------------------------INVALID CREDENTIALS PLEASE SIGN-UP FIRST---------------------|" << endl << endl;
            Main();
        }
    }
 // Implementing for login
    }

    void Sign_Up() {
      system("CLS");                                 //Sign up functiobn 
    cout << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "                                        SIGN-UP                                        " << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;


                             

    cout << "REG NO: ";
    cin >> R_Username; cout << endl;

    int sz = R_Username.length();

    while (sz != 7)                                                          
    {
        cout << "Reg No must be of 7 digits" << endl << endl;
        cout << "REG NO: ";                                                       
        cin >> R_Username; cout << endl;
        sz = R_Username.length();
    }

    do
    {
        cout << "(Must contain a capital letter and be greater than 8 letters)" << endl;
        cout << "Choose Your password : ";
        cin >> R_Password; cout << endl;

        bool hasUpperCase = false;

        for (int i = 0; i < R_Password.length(); ++i)
        {
            if (isupper(R_Password[i]))
            {
                hasUpperCase = true;
                break;
            }
        }

        if (hasUpperCase && R_Password.length() > 8)
        {
            break;
        }

    } while (true);

	 Store_Data.open("GIKI_transport.txt");                                
	  
    Store_Data << R_Username << " " << R_Password << endl;               //Data of signup in the the file showed 
    Store_Data.close();
    system("CLS");
    cout << endl;
    cout << "|---------------------------------Sign-up successful!---------------------------------|" << endl << endl;
    cout << "|------------------------------- Now Login to Continue--------------------------------|" << endl;
    cout << endl;
    Main();  // Implementation for sign-up
    }

    void Refund() {
          system("CLS");

    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "                                        REFUND                                         " << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    int seat_num;
    string reason;

    cout << endl;
    cout << "Your Seat Number: ";
    cin >> seat_num; cout << endl << endl;
    if (seat_num < 1 || seat_num>18)
    {
        system("cls");
        cout << endl;
        cout << "|--------------------------------Invalid Seat Number----------------------------------|" << endl << endl;
        cout << "|----------------------------Please Book a Ticket First-------------------------------|" << endl << endl;
        Main();
    }

    cout << "Reason of Cancellation: ";
    cin >> reason;

    int gen = rand() % 2;

    if (gen == 1)
    {
        system("CLS");
        cout << endl;
        cout << "|---Your refund is being processed.You will get your refund in 2 to 3 business days---|" << endl << endl;
        Main();
    }
    else
    {
        system("CLS");
        cout << endl;
        cout << "|-------Your refund request has been rejected because your reason was not valid-------|" << endl << endl;
        Main();
    }// Implementation for refund
    }

    void Complaint() {
        system("CLS");

    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "                                   COMPLAINT SECTION                                   " << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    string cause;
    cout << "Please Enter Your Complaint: " << endl;
    cin >> cause;
    system("CLS");
    cout << endl;
    cout << "|--------Your complaint is being processed,our representative will call you soon------|" << endl << endl;
    Main(); // Implementation for complaint
    }

    void Bus_Selection() {
        cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "                               WELCOME TO THE BUS TERMINAL                             " << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl << endl;

    cout << "  OPTION       DESTINATIONS               DURATION           FARE" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "  1.           GIKI to Lahore             6:21 hrs           " << Price_Calculation(1, distances) << " Rs" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "  2.           GIKI to Islamabad          1:30 hrs           " << Price_Calculation(2, distances) << " Rs" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "  3.           GIKI to Mardan             1:00 hrs           " << Price_Calculation(3, distances) << " Rs" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "  4.           GIKI to Peshawar           2:00 hrs           " << Price_Calculation(4, distances) << " Rs" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl << endl;
    cout << "OPTION: ";
    cin >> route_selection; cout << endl;

    switch (route_selection)
    {
    case 1:
        Ticket();
        cout << "| GIKI TO LAHORE " << endl << "|" << endl;
        cout << "| PRICE: " << Price_Calculation(1, distances) << " Rs" << endl << "|" << endl;
        cout << "| DURATION: 6 Hours 20 Minutes" << endl << "|";
        break;
    case 2:
        Ticket();
        cout << "| GIKI TO ISLAMABAD" << endl << "|" << endl;
        cout << "| PRICE: " << Price_Calculation(2, distances) << " Rs" << endl << "|" << endl;
        cout << "| DURATION: 1 Hour 20 Minutes" << endl << "|";
        break;
    case 3:
        Ticket();
        cout << "| GIKI TO MARDAN" << endl << "|" << endl;
        cout << "| PRICE: " << Price_Calculation(3, distances) << " Rs" << endl << "|" << endl;
        cout << "| DURATION: 1 Hour" << endl << "|";
        break;
    case 4:
        Ticket();
        cout << "| GIKI TO PESHAWAR " << endl << "|" << endl;
        cout << "| PRICE: " << Price_Calculation(4, distances) << " Rs" << endl << "|" << endl;
        cout << "| DURATION: 2 Hours and 15 Minutes" << endl << "|";
        break;
    default:
        system("CLS");
        cout << endl;
        cout << "|-----------------------------------Invalid Selection---------------------------------|" << endl << endl;
        cout << "|------------------------------Please Select a Valid Option---------------------------|" << endl << endl;
        Bus_Selection();
    }
    cout << endl;
    cout << "| Please arrive on time." << endl;
    cout << "|_" << endl << endl;// Implementation for bus selection
    }

    void Ticket() {
       cout << "Do you prefer a window seat: " << endl << endl;;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl << endl;
    cin >> window_seat;

    system("CLS");                                         //Window shift
    

    cout << "_" << endl << "|" << endl;
    Seat_Assign();
    Bus_Timing(); // Implementation for ticket
    }

    void Seat_Assign() {
       int window_seats[8] = { 1, 3, 5, 7, 11, 13, 15, 17 };

    srand(time(0));

    int Temporary;

    if (window_seat == true)
    {

        do
        {
            Temporary = rand() % 8;

        } while (Temporary % 2 == 0);

        cout << "| SEAT NO: " << window_seats[Temporary] << endl << "|" << endl;;
    }
    else
    {
        Temporary = rand() % 18 + 1;

        cout << "| SEAT NO: " << Temporary << endl << "|" << endl;;
    }

} // Implementation for seat assignment
    

    

    int Price_Calculation(int route_selection, Distance distances) {
        // Implementation for price calculation
     int petrol_price = 280;
    int bus_avg = 6;
    int bus_mileage = petrol_price / bus_avg;
    int profit = 2;
    int bus_fare;

    switch (route_selection)
    {
    case 1:
        bus_fare = profit + bus_mileage * (distances.Lahore);
        return bus_fare / 18;
        break;
    case 2:
        bus_fare = profit + bus_mileage * (distances.Islamabad);
        return bus_fare / 18;
        break;
    case 3:
        bus_fare = profit + bus_mileage * (distances.Mardan);
        return bus_fare / 18;
        break;
    case 4:
        bus_fare = profit + bus_mileage * (distances.Peshawar);
        return bus_fare / 18;
        break;
    default:
        cout << "|------------------------------Invalid destination entered----------------------------|" << endl;
        return 0;
    } }
};
  
int main() {
   TicketBook s;                                   //Main function to make object of class
    s.Main();
    return 0;                  
}

