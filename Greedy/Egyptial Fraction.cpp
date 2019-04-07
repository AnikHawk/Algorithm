#include <bits/stdc++.h>
using namespace std;

void printEgyptian(int nominator, int denominator)
{
    if (nominator == 0 || denominator == 0)
        return;

    if (denominator%nominator == 0)
    {
        cout << "1/" << denominator/nominator<<endl;
        return;
    }


    if (nominator%denominator == 0)
    {
        cout << nominator/denominator<<endl;
        return;
    }


    if (nominator > denominator)
    {
        cout << nominator/denominator << " + ";
        printEgyptian(nominator%denominator, denominator);
        return;
    }

    int ceil = (denominator/nominator) + 1;
    cout << "1/" << ceil << " + ";


    printEgyptian(nominator*ceil-denominator, denominator*ceil);
 }

int main()
{
    int nominator = 12, denominator = 13;
    cout<< nominator << "/" << denominator << " = ";
    printEgyptian(nominator, denominator);
    return 0;
}
