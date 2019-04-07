#include<bits/stdc++.h>
using namespace std;



/*
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
*/

bool checkJobs(int n, int start[], int end[]){
    vector< pair<int, int > > job;
    for(int i=0;i<n;i++){
        job.push_back(make_pair(start[i],end[i]));
    }
    sort(job.begin(), job.end());

    int finished1 = job[0].second, finished2 = job[1].second;

    for(int i =2;i<n;i++){
        if(job[i].first > finished1){
            finished1 = finished2;
            finished2 = job[i].second;
        }
        else if(job[i].first > finished2){
            finished2 = job[i].second;
        }
        else return false;
    }

    return true;
}


int main(){
    int n;
    int start[100];
    int end[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>start[i];
        cin>>end[i];
    }

    cout<<checkJobs(n, start, end);

    return 0;
}
