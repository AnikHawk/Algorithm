#include<bits/stdc++.h>
using namespace std;


main()

{
    string name[100];
    int roll[100],marks[100],i,j,n;
    freopen("input.txt","r",stdin);

    while(scanf("%d", &n)!=EOF)
    {
       for(i=0;i<n;i++)
       {
           cin>>name[i];
           scanf("%d %d",&roll[i], &marks[i]);
       }
    }
    for(i=0;i<n;i++)
       {
           cout<<name[i]<<" ";
           printf("%d %d\n",roll[i], marks[i]);
       }
}
