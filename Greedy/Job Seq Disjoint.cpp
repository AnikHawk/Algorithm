#include<bits/stdc++.h>
using namespace std;
int  parent[100];

struct Job
{
    string id;
    int deadline;
    int profit;
    bool operator < (const Job& x) const
    {
        return profit>x.profit;
    }

};

int findParent(int x)
{
    if(parent[x]==x) return x;
    else return parent[x] = findParent(parent[x]);
}

void maxProfit(int n, Job jobs[])
{
    int TimeSlot[100];
    memset(TimeSlot, -1, sizeof(TimeSlot));
    int maxDeadline = 0;
    for(int i =0; i<n; i++) maxDeadline = max(maxDeadline,jobs[i].deadline);
    for(int i =0; i<=maxDeadline; i++) parent[i] = i;

    sort(jobs,jobs+n);
    for(int i =0; i<n; i++)
    {
        int maxAvailableTime = findParent(jobs[i].deadline);
        if(maxAvailableTime)
        {
            TimeSlot[maxAvailableTime] = i;
            // cout<<jobs[i].id<<" "<<maxAvailableTime<<endl;
            parent[maxAvailableTime] = maxAvailableTime-1;
        }

    }


    for(int i =0; i<=maxDeadline; i++)
    {
        if(TimeSlot[i]!=-1) cout<<jobs[TimeSlot[i]].id<<" : "<<i<<endl;
    }

}

int main()
{
    int n;
    cin>>n;
    Job ara[n];
    for(int i =0; i<n; i++)
    {
        cin>>ara[i].id;
        cin>>ara[i].deadline;
        cin>>ara[i].profit;
    }

    maxProfit(n, ara);


    return 0;
}
