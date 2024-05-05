
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
class Complaint{
public:
void refund()
{
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
       
    }

    cout << "Reason of Cancelation: ";
    cin >> reason;

    int gen = rand() % 2;

    if (gen == 1)
    {
        system("CLS");
        cout << endl;
        cout << "|---Your refund is being processed.You will get your refund in 2 to 3 business days---|" << endl << endl;
        
    }
    else
    {
        system("CLS");
        cout << endl;
        cout << "|-------Your refund request has been rejected because your reason was not valid-------|" << endl << endl;
    
    }


}
void complaint()
{
    system("CLS");

    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "|                                   COMPLAINT SECTION                                 |" << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    string cause;
    cout << "Please Enter Your Complaint: " << endl;
    cin >> cause;
    system("CLS");
    cout << endl;
    cout << "|--------Your complaint is being processed,our representative will call you soon------|" << endl << endl;
     
}};


int main (){
	Complaint c;
	c.refund();
	c.complaint();
	
	
	
	
}
