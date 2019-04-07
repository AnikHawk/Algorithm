#include<bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int>adj[100];
int dist[100],parent[100],path[100],visited[100];





void bfs(int source,int dis)
{
    memset(parent,-1,sizeof(parent));
    dist[source] = 0;
    parent[source] = -1;
    q.push(source);
    visited[source]++;

    while(!q.empty())
    {
        int p = q.front();
        q.pop();

        for(int i=0;i<adj[p].size();i++)
        {
        int v = adj[p][i];
        if(visited[v]!=0) continue;
        dist[v] = dist[p]+1;
        parent[v] = p;

        q.push(v);
        visited[v]++;

        }
    }
    int t =0;
    int i = dis;
    while(i!=-1)
    {
        path[t]=i;
        i=parent[i];
        t++;
    }

    for(i=t-1;i>=0;i--)
    {

        cout<<path[i]<<"->";

    }
    printf("\n");

}


main()
{
    int m,n,u,v;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    while(1)
    {
        cout<<"bfs: ";
        cin>>u>>v;
        bfs(u,v);
    }
}
