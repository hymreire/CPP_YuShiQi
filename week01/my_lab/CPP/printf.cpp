#include <iostream>
using namespace std;

int main()
{
    int a = 1234;
    float f = 123.456;
    char ch = 'a';
    printf("%8d,%2d\n",a,a);
    printf("%f,%8f,%8.1f,%.2f,%2e\n",f,f,f,f,f);
    printf("%3c\n",ch);

    return 0;
}