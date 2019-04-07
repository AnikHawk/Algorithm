#include<bits/stdc++.h>
using namespace std;

int generateLen(string& a, string& b)
{
    int lena = a.length();
    int lenb = b.length();

    if(lena>lenb)
    {
        for(int i =1; i<=lena-lenb; i++) b = '0' + b;
        return lena;
    }
    else
    {
        for(int i =1; i<=lenb-lena; i++) a = '0' + a;
    }
    return lenb;

}


string addBits( string first, string second )
{
    string result;
    int length = generateLen(first, second);
    int carry = 0;


    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
        int sum = (firstBit ^ secondBit ^ carry)+'0';
        result = (char)sum + result;
        carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
    }
    if (carry)  result = '1' + result;
    return result;
}


int multiplySingle(string a, string b)
{
    return (a[0]-'0') * (b[0] - '0');
}

int multiply(string a, string b)
{
    int n = generateLen(a,b);
    if(n==0) return 0;
    if(n==1) return multiplySingle(a,b);

    int left = n/2; //floor(n/2)
    int right = n - left; //ceil

    string a1 = a.substr(0,left);
    string a2 = a.substr(left, n-left);
    string b1 = b.substr(0,left);
    string b2 = b.substr(left, n-left);

    int p1 = multiply(a1,b1);
    int p2 = multiply(a2,b2);
    int p3 = multiply(addBits(a1,a2),addBits(b1,b2)) - p1 - p2;

    return p1*pow(2,right*2) + p2 + p3*pow(2,right);

}


int main()
{
    cout<<multiply("111","110")<<endl;


    return 0;
}
