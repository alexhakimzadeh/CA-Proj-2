//  Hakimzadeh_assignment4.cpp
//  Coding Project 4
//  Created by Alex Hakimzadeh on 11/30/21.
//########//########//########//########//########//########//########//########
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

struct Ship{
    string shipName;
    string designerFName;
    string designerLName;
    float mass;
    float thrust;
    float acceleration;
    float changeInVelocity;
    float maxAltitude;
};

void Design();
void Read(Ship &ship);
void Test(Ship &ship);
void Simulation();

//  Global variables
string shipName;
// sMass = ship mass // et = engine thrust
float sMass, et;

int main() {
    Ship ship;
    char userMenu;
    do {
    // MENU:    //double endl for formatting
        cout << "Bobcat Aerospace Craft Designer Plus" << endl << endl;
        cout << "D-\t" << "Design a new ship" << endl;
        cout << "T-\t" << "Test a new ship" << endl;
        cout << "S-\t" << "Simulate a flight" << endl;
        cout << "Q-\t" << "Quit the program" << endl << endl;
        cout << "Please select an option: " << endl;
        cin >> userMenu;
        switch(userMenu){
            // Ship Design
            case 'd':
            case 'D':
            {
                Design();
                break;
        }
            //Ship Test
            case 'T':
            case 't':
            {
                Read(ship);
                Test(ship);
                break;
            }
            //Simulate Flight
            case 's':
            case 'S':
            {
                Simulation();
                break;
            }
            // Quit program
            case 'Q':
            case 'q':
            {
                cout << "Thank you for using Craft Designer Plus" << endl;
                return 0;
            }
            default: cout << "ERROR! INVALID INPUT!" << endl << endl;
        }
        
    }while (true);
    
    
    return 0;
}
//  Design a ship:
//  Write one file after taking user input
//  Parameters: None
//  Returns: Nothing
//  Side effects: Writes one file to disk
void Design(){
    // Most code in case D taken from Alex
    // Hakimzadeh's Coding Project 1
    Ship ship;
    float g0 = 9.8;    //gravitational constant
    //ln(2) equation to determine "dv"
    float ln = 0.69314718056;
    
    // user inputs:
    cout << "What is your first and last name? ";
    cin >> ship.designerFName;
    cin >> ship.designerLName;
    cout << "What is the name of your ship? ";
    cin >> ship.shipName;
    cout << "What is your ship's mass? ";
    cin >> ship.mass;
    cout << "What is your ship's engine thrust? ";
    cin >> ship.thrust;
    cout << endl;
    cout << "File written for " << ship.shipName << endl << endl;
    //using dv to acquire max alt. value
    float dv = (100000 / ship.thrust) * g0 * ln;
    
// Console Outputs to file:
// next line taken from code snippet by Gentry Atkinson:
    ofstream file(ship.shipName + ".txt");
    file << "##########" << ship.shipName << "##########" << endl;
    file << endl;
    
// Output Equations:
    file << left << setw(20) << "Ship Mass:" << fixed
        << setprecision(1) << ship.mass << " kg" << endl;
    file << left << setw(20) << "Acceleration:" << fixed
        << setprecision(1) << ship.thrust/ship.mass << " m/s2" << endl;
    file << left << setw(20) << "Delta V:" << fixed
        << setprecision(1) << dv << " m/s" << endl;
    file << left << setw(20) << "Max Altitude:" << fixed
        << setprecision(1) << 100 + (dv - 200)/10
        << " km" << endl;
    
// required timestamp & authorship:
    file << endl;
    file << left << setw(20) << "File saved at:"
        << time(NULL) << endl;
    file << left << setw(20) << "Designed by:"
        << ship.designerFName << " " << ship.designerLName << endl;
    file.close();
}

//  Read a file:
//  Reads a desugned ships' file
//  Parameters: None
//  Returns: Nothing
//  Side effects: Reads file to the "Ship" struct or prints error
void Read(Ship &ship){
    cout << "Enter the spacecraft you want to test: ";
    cin >> ship.shipName;
    ifstream fin (ship.shipName + ".txt");
    // Next line taken from cpp reference website
    if (!fin.is_open()){
        cout << "Error! File does not exist!"
            << endl << endl;
    }
    
    // READ FROM FILE:
    string junk;
    fin >> junk >> junk >> junk >> ship.mass >> junk;
    fin >> junk >> ship.acceleration >> junk;
    fin >> junk >> junk >> ship.changeInVelocity >> junk;
    fin >> junk >> junk >> ship.maxAltitude >> junk;
    fin >> junk>> junk >> junk >> junk >> junk
        >> junk >> ship.designerFName >> ship.designerLName;
}

//  Test a ship:
//  Tests a designed ship
//  Parameters: "Ship" struct
//  Returns: Nothing
//  Side effects: Console displays pass or fail
void Test(Ship &ship){
    //TESTS:
    if (ship.designerFName == "Thomas" && ship.designerLName == "Harris"){
        cout << ship.shipName << " fails test 1" << endl << endl;
    }
    else if (ship.mass >= 1000){
        cout << ship.shipName << " fails test 2" << endl << endl;
    }
    else if (ship.acceleration < 1 || ship.acceleration > 10){
        cout << ship.shipName << " fails test 3" << endl << endl;
    }
    else if (ship.changeInVelocity < 800){
        cout << ship.shipName << " fails test 4" << endl << endl;
    }
    else if (ship.mass < 100 && ship.maxAltitude <= 150){
        cout << ship.shipName << " fails test 5."
            << endl << endl;
    }
    else if (ship.mass > 100 && ship.maxAltitude <= 200){
        cout << ship.shipName << " fails test 5."
            << endl << endl;
    }
    else {
        cout << ship.shipName << " has passed all tests."
            << endl << endl;
    }
}

//  Simulate a flight:
//  Simulates a ships flight
//  Parameters: None
//  Returns: Nothing
//  Side effects: Console displays list of speed and altitude
void Simulation() {
    // get user input
    cout << "Enter the acceleration of the spacecraft: ";
    float acceleration;
    cin >> acceleration;
    cout << "Enter how many seconds this simulation will run: ";
    float secs;
    cin >> secs;
    cout << endl;
    float speed = acceleration * secs;
    float altitude = pow(speed, 2.0)/2.0;
    //interface:
    cout << "At " << 0 << " seconds:\t" << 0 << "m/s\t" << 0 << "m" << endl;
    for (float i = 1.0; i <= secs; i++){
        speed = i * acceleration;
        altitude = 0.5 * acceleration * pow(i, 2.0);
        cout << "At " << fixed << setprecision(1) << i << " seconds:\t"
            << setprecision(1) << speed << "m/s\t";
        //  To convert m to km
        if (altitude >= 1000){
            altitude = altitude * 0.001;
            cout << setprecision(1) << altitude << "km" << endl;
        }
        else cout << setprecision(1) << altitude << "m" << endl;
    }
    cout << endl;
}
