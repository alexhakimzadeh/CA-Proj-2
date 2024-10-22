//  Alex Hakimzadeh
//  9/2/21

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){
    
// dFirst/dLast = Designer first/last name // sName = ship name
    string dFirst, dLast, sName;
// sMass = ship mass // et = engine thrust
    float sMass, et;
// user inputs:
    cout << "What is your first and last name? ";
    cin >> dFirst;
    cin >> dLast;
    cout << "What is the name of your ship? ";
    cin >> sName;
    cout << "What is your ship's mass? ";
    cin >> sMass;
    cout << "What is your ship's engine thrust? ";
    cin >> et;
    cout << endl;
    cout << "File written for " << sName << endl << endl;
    
// Console Outputs to file:
   // next line taken from code snippet by Gentry Atkinson:
    ofstream file(sName + ".txt");
    file << "##########" << sName << "##########" << endl;
    file << endl;
// Output Equations:
    file << left << setw(20) << "Ship Mass:" << fixed << setprecision(1)
            << sMass << " kg" << endl;
    file << left << setw(20) << "Acceleration:" << fixed << setprecision(1)
            << et/sMass << " m/s2" << endl;
    float g0 = 9.8;                 //gravitational constant
    float ln = 0.69314718056;       //ln(2) equation to determine "dv"
    float dv = (100000 / et) * g0 * ln;     //using dv to acquire max alt. value
    file << left << setw(20) << "Delta V:" << fixed << setprecision(1)
            << dv << " m/s" << endl;
    file << left << setw(20) << "Max Altitude:" << fixed << setprecision(1)
            << 100 + (dv - 200)/10 << " km" << endl;
// required timestamp & authorship:
    file << endl;
    file << left << setw(20) << "File saved at:" << time(NULL) << endl;
    file << left << setw(20) << "Designed by:"
            << dFirst << " " << dLast << endl;
    file.close();
    return 0;
}
