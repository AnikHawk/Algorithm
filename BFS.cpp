#include<bits/stdc++.h>
using namespace std;

vector <int> g[100002];
queue<int> q;
int parent[1000002];
int dist[1000002];
int color[1000002];
int nodes;
int edges;

struct Graph
{
    void input()
    {
        scanf("%d %d",&nodes,&edges);
        for(int i=0; i<edges; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

    }

    void BFS(int source)
    {
        memset(dist,-1,sizeof(dist));
        memset(parent,-1,sizeof(parent));
        memset(color,-1,sizeof(color));

        q.push(source);
        dist[source] = 0;
        color[source] = 0;

        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            for(int i = 0 ; i<g[current].size(); i ++)
            {
                int v = g[current][i];
                if(color[v]==-1)
                {
                    dist[v] = dist[current] + 1;
                    color[v] = 0;
                    parent[v] = current;
                    q.push(v);
                }
            }
            color[current] = 1;
        }

        for(int i = 0 ; i< nodes; i++)
        {
            cout<<i<<" : "<<dist[i]<<endl;
        }
    }

};


int main()
{
    Graph g;
    g.input();
    g.BFS(0);


    return 0;
}
