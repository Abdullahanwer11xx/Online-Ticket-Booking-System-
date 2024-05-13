#include<iostream>
#include<cstdlib>
#include<ctime>
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
int main(){
	BusTiming b;
	b.Bus_Timing();
}
