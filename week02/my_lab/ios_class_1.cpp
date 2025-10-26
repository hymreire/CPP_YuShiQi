#include<iostream>
using namespace std;

int main()
{
    cout << 56.8 << endl;

    cout.width(12); // 设置宽度
    cout.fill('+'); // 设置填充
    cout << 456.77 << endl;

    cout.precision(2); // 控制位数
    cout << 123.356 << endl;

    cout.precision(5);
    cout << 3897.678485 << endl;

    return 0;
}