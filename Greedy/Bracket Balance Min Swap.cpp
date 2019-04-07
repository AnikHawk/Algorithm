#include<bits/stdc++.h>
using namespace std;


int minSwap(string s)
{
    int result = 0;
    vector<int> leftPos;
    for(int i=0; i<s.length(); i++)
        if(s[i]=='[') leftPos.push_back(i);
    int nextLeft=0;
    int tracker = 0;
    for(int i =0; i<s.length(); i++)
    {
        if(s[i] == '[')
        {
            tracker++;
            nextLeft++;
        }
        else if(s[i]==']')
        {
            tracker--;
        }

        if(tracker<0)
        {
            result+= leftPos[nextLeft] - i;
            swap(s[leftPos[nextLeft++]],s[i]);
            tracker = 1;
        }
    }


    return result;
}


int main()
{
    string s =  "[][]]][[";
    cout<<minSwap(s);

    return 0;
}
