#include<bits/stdc++.h>
using namespace std;

int minLoss(int  n, int t, int arrival[], int units[], int priority[])
{
    int min = 0;
    for(int i=0; i<n; i++) min+=units[i]*priority[i];
    vector<pair<int,int> > tasksArr;

    for(int i=0; i<n; i++) tasksArr.push_back(make_pair(arrival[i],i)); //push arrival and index
    sort(tasksArr.begin(),tasksArr.end());

    priority_queue<pair<int,int> > pq;

    for(int i=1; i<=t; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(tasksArr[j].first == i)
            {
                arrival[tasksArr[j].second] = 0;
                pq.push(make_pair(priority[tasksArr[j].second], tasksArr[j].second)); //push priority and index
            }
        }
        if(!pq.empty())
        {
            pair<int,int> tmp =pq.top();
            pq.pop();
            units[tmp.second]--;
            min-=tmp.first;
            if(units[tmp.second]>0) pq.push(tmp);
        }
    }

    return min;
}




int main()
{

    int n, t;
    int arrival[100];
    int units[100];
    int priority[100];
    cin>>n>>t;
    for(int i=0; i<n; i++) cin>>arrival[i]>>units[i]>>priority[i];

    cout<<minLoss(n,t, arrival, units, priority);


    return 0;
}
