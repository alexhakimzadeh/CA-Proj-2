
//  Coding Project 2
//  Created by Alex Hakimzadeh on 9/27/21.

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    char userMenu;
    string shipName;
    // sMass = ship mass // et = engine thrust
    float sMass, et;
    
    do {

    // MENU:    //double endl for formatting
        cout << "Bobcat Aerospace Craft Designer Plus" << endl << endl;
        cout << "D-\t" << "Design a new ship" << endl;
        cout << "T-\t" << "Test a new ship" << endl;
        cout << "Q-\t" << "Quit the program" << endl << endl;
        cout << "Please select an option: " << endl;
        cin >> userMenu;
        switch(userMenu){
            // Ship Design
            case 'd':
            case 'D':
            {
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
                break;
        }
            case 'T':
            case 't':
            {
                cin >> shipName;
                ifstream fin (shipName + ".txt");
                // Next line taken from cpp reference website
                if (!fin.is_open()){
                    cout << "Error! File does not exist!"
                        << endl << endl;
                    break;
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
                break;
            }
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
