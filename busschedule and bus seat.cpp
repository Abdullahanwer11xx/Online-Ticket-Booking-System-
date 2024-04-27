#include <iostream>
#include <string>
#include <cstdlib> // For random number generation

using namespace std;

class BusSchedule {
private:
    string peshawarTimings;
    string islamabadTimings;
    string lahoreTimings;
    string mardanTimings;
    
public:
    BusSchedule() {
        // Initialize bus timings for different cities
        peshawarTimings = "Peshawar: 12:00 AM";
        islamabadTimings = "Islamabad: 9:00 AM ";
        lahoreTimings = "Lahore: 7:00 AM ";
        mardanTimings = "Mardan: 10:00 AM ";
    }
    
    void displayCityOptions() {
        cout << "The buses are ready for these cities " << endl;
        cout << "1. ..........Peshawar.........." << endl;
        cout << "2. ..........Islamabad.........." << endl;
        cout << "3. ..........Lahore.........." << endl;
        cout << "4. ..........Mardan.........." << endl;
    }
    
    void displayAllTimings() {
        cout << ":..........All Bus Timings..........:" << endl;
        cout << peshawarTimings << endl;
        cout << islamabadTimings << endl;
        cout << lahoreTimings << endl;
        cout << mardanTimings << endl;
    }
    
    void displayTimings(int choicee) {
        switch (choicee) {
            case 1:
                cout << "Bus timing for Peshawar..........: " << peshawarTimings << " Be on time thanks!"<< endl;
                break;
            case 2:
                cout << "Bus timing for Islamabad..........: " << islamabadTimings << " Be on time thanks!"<< endl;
                break;
            case 3:
                cout << "Bus timing for Lahore..........: " << lahoreTimings << " Be on time thanks!"<< endl;
                break;
            case 4:
                cout << "Bus timing for Mardan..........: " << mardanTimings << " Be on time thanks!"<< endl;
                break;
            default:
                cout << "Your choice is not valid.......... " << endl;
        }
    }
};

class BusSeat {
private:
    string seatType;
    int seatNumber;

public:
    BusSeat() {
        seatType = "Any"; 
        seatNumber = 0; 
    }

    void select(const string& type) {
        seatType = type;
    }

    void assign() {
        if (seatType == "Window") {
            // Generate a random seat number between 1 and 10 for window seat
            seatNumber = rand() % 10 + 1;
        } else {
            // Generate a random seat number between 11 and 20 for other seats
            seatNumber = rand() % 10 + 11;
        }
    }

    void displaySeatInfo() {
        cout << "Selected seat type: " << seatType << endl;
        cout << "Assigned seat number: " << seatNumber << endl;
    }
};

int main() {
    BusSchedule busSchedule;
    
    busSchedule.displayCityOptions();
    busSchedule.displayAllTimings();
    int choice;
    cout << "What is your choice from 1 to 4: ";
    cin >> choice;
    
    busSchedule.displayTimings(choice);
   
    int numberOfSeats;
    cout << "How many seats do you want to book? ";
    cin >> numberOfSeats;

    // Create an array of BusSeat objects to store seat information
    BusSeat seats[numberOfSeats];

    for (int i = 0; i < numberOfSeats; ++i) {
        BusSeat& seat = seats[i];

        cout << "Select your seat type for seat " << i + 1 << endl;
        cout << "1. Window" << endl;
        cout << "2. Any other" << endl;

        int choice;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        switch (choice) {
            case 1:
                seat.select("Window");
                break;
            case 2:
                seat.select("Any other");
                break;
            default:
                cout << "Invalid choice! Defaulting to Any other seat." << endl;
                seat.select("Any other");
        }

        // Assign a seat number based on the selected seat type
        seat.assign();
    }

    // Display seat information for all booked seats
    cout << "Booked Seats Information:" << endl;
    for (int i = 0; i < numberOfSeats; ++i) {
        cout << "Seat " << i + 1 << ":" << endl;
        seats[i].displaySeatInfo();
        cout << endl;
    }

    return 0;
}

