#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << 56.8 << setw(12) << setfill('#') << 456.77 << endl; // 56.800000##456.770000

    cout << left;
    cout << setw(12) << setprecision(2) << 123.356 << endl; // 123.36######
    cout << setw(12) << setprecision(5) << 3897.6784385 << endl; // 3897.67844##

    cout << right;
    cout << setw(12) << setfill(' ') << 123.356 << endl; //    123.35600
    cout << setw(12) << setfill(' ') << 3897.6784385 << endl; //   3897.67844

    cout.unsetf(ios_base::fixed);
    cout << 56.8 << setw(12) << setfill('$') << 456.77 << endl; // 56.8$$$$$$456.77

    return 0;
}