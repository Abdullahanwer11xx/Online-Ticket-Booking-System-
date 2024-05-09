#include<iostream>
#include<string>
#include<fstream> 
using namespace std;
class Loginn{
public:
void Login()
{
    system("CLS");
    cout << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "                                         LOGIN                                         " << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl << endl;

    string Username, Password;

    cout << "GIKI REG NO: ";
    cin >> Username; cout << endl;
    cout << "PASSWORD: ";
    cin >> Password; cout << endl;

    ifstream Read_Data("C:\\Users\\Abdullah\\Desktop\\user_data.txt");
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
            
        }
    }

}};
class Signup:public Loginn{
public:
void Sign_Up()
{
    system("CLS");
    cout << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "                                        SIGN-UP                                        " << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;


    string R_Username, R_Password;

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

    ofstream Store_Data("C:\\Users\\Abdullah\\Desktop\\user_data.txt");
    Store_Data << R_Username << " " << R_Password << endl;
    Store_Data.close();
    system("CLS");
    cout << endl;
    cout << "|---------------------------------Sign-up successful!---------------------------------|" << endl << endl;
    cout << "|------------------------------- Now Login to Continue--------------------------------|" << endl;
    cout << endl;
    
}};
int main(){
	
	Signup  s;
	s.Login();
	s.Sign_Up();
}
