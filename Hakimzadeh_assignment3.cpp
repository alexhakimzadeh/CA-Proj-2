
//  Coding Project 3
//  Created by Alex Hakimzadeh on 11/01/2021.
//########//########//########//########//########//########//########//########
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

void Simulation();
void Design();
void Test();

//  Global variables
string shipName;
// sMass = ship mass // et = engine thrust
float sMass, et;

int main() {
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
                Test();
                break;
            }
            //Simulate
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
    // dFirst/dLast = Designer first/last name
    // sName = ship name
    string dFirst, dLast;
    
    float g0 = 9.8;    //gravitational constant
    //ln(2) equation to determine "dv"
    float ln = 0.69314718056;
    
    // user inputs:
    cout << "What is your first and last name? ";
    cin >> dFirst;
    cin >> dLast;
    cout << "What is the name of your ship? ";
    cin >> shipName;
    cout << "What is your ship's mass? ";
    cin >> sMass;
    cout << "What is your ship's engine thrust? ";
    cin >> et;
    cout << endl;
    cout << "File written for " << shipName << endl << endl;
    //using dv to acquire max alt. value
    float dv = (100000 / et) * g0 * ln;
    
// Console Outputs to file:
// next line taken from code snippet by Gentry Atkinson:
    ofstream file(shipName + ".txt");
    file << "##########" << shipName << "##########" << endl;
    file << endl;
    
// Output Equations:
    file << left << setw(20) << "Ship Mass:" << fixed
        << setprecision(1) << sMass << " kg" << endl;
    file << left << setw(20) << "Acceleration:" << fixed
        << setprecision(1) << et/sMass << " m/s2" << endl;
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
        << dFirst << " " << dLast << endl;
    file.close();
}

//  Test a ship:
//  Tests a designed ship
//  Parameters: None
//  Returns: Nothing
//  Side effects: Console displays pass or fail
void Test(){
    cout << "Enter the spacecraft you want to test: ";
    cin >> shipName;
    ifstream fin (shipName + ".txt");
    // Next line taken from cpp reference website
    if (!fin.is_open()){
        cout << "Error! File does not exist!"
            << endl << endl;
        
    }
    
    // READ FROM FILE:
    string junk, dName1, dName2;
    float accl, vChange, maxAlt;
    fin >> junk >> junk >> junk >> sMass >> junk;
    fin >> junk >> accl >> junk;
    fin >> junk >> junk >> vChange >> junk;
    fin >> junk >> junk >> maxAlt >> junk;
    fin >> junk>> junk >> junk >> junk >> junk
        >> junk >> dName1 >> dName2;
    
    //TESTS:
    if (dName1 == "Thomas" && dName2 == "Harris"){
        cout << shipName << " fails test 1" << endl << endl;
    }
    else if (sMass > 1000){
        cout << shipName << " fails test 2" << endl << endl;
    }
    else if (accl < 1 || accl > 10){
        cout << shipName << " fails test 3" << endl << endl;
    }
    else if (vChange < 800){
        cout << shipName << " fails test 4" << endl << endl;
    }
    else if (sMass > 100){
        if (maxAlt >= 150 || maxAlt >= 200){
            cout << shipName << " fails test 5"
                << endl << endl;
        }
        else{
            cout << shipName << " has passed all tests."
                << endl << endl;
        }
    }
    else {
        cout << shipName << " has passed all tests."
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
