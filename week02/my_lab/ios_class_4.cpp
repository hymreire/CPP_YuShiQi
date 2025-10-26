#include<iostream>
using namespace std;

int main()
{
    bool flag = false;
    double a = 2.3876;
    double b = 0.46e2;

    cout << boolalpha << flag << endl; // 输出：false
    cout << fixed << a << endl; // 输出：2.387600
    cout << b << endl; // 输出：46.000000
    cout << noboolalpha << flag << endl; // 输出：0

    cout.unsetf(ios::fixed);
    cout << a << endl; // 输出：2.3876
    cout << b << endl; // 输出：46

    return 0;
}