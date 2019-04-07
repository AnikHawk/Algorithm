#include<bits/stdc++.h>
using namespace std;


void bestFit(int length,int m,int n){
    int minRem = length;
    int tmpRem = length;
    int numM = 0, numN = 0;
    int tmpM = 0, tmpN = 0;
    while(length>=n){
        tmpM = length/m;
        tmpRem = length%m;

        if(tmpRem<=minRem)
        {
            minRem = tmpRem;
            numM = tmpM;
            numN = tmpN;
        }
        length -= n;
        tmpN++;
    }
    cout<<numM<<" "<<numN<<" "<<minRem<<endl;


}


int main()
{
    int length, m , n;
    cin>>length>>m>>n;
   bestFit(length,m,n);

    return 0;
}
