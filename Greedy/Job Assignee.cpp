#include<bits/stdc++.h>
using namespace std;

bool isPossible(int n,int jobs[], int k, int time){
    int totalAssigned = 1;
    int tmp = time;
    for(int i =0;i<n;i++){
        if(jobs[i]>tmp){
            totalAssigned++;
            tmp = time - jobs[i];
        }
        else tmp-=jobs[i];
    }
    return (totalAssigned<=k);
}


int assignJobs(int n, int jobs[], int k)
{
    int lo = 0, hi = 0, maxTime = 0;
    for(int i =0; i<n; i++)
    {
        maxTime = max(maxTime,jobs[i]);
        hi+=jobs[i];
    }
    int result = hi;
    while(lo<=hi){
        int mid = (lo+hi)/2;

     if( mid>=maxTime && isPossible(n, jobs, k, mid)){
            result = min(result,mid);
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return result;
}


int main()
{
    int n = 6;
    int  jobs[] = {10, 7, 8, 12, 6, 8};
    int k = 4;
    cout<<assignJobs(n, jobs, k);

}
