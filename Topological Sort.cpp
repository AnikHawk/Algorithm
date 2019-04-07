#include<bits/stdc++.h>
using namespace std;

vector <int> g[100002];
queue<int> q;
queue <int> zero;
int parent[1000002];
int dist[1000002];
int color[1000002];
int indegree[1000002];
int outdegree[1000002];
int nodes;
int edges;


struct Graph
{
    void input()
    {
        memset(indegree,0,sizeof(indegree));
        scanf("%d %d",&nodes,&edges);
        for(int i=0; i<edges; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            ++indegree[v];
        }

    }

    void top_sort()
    {
        memset(dist,-1,sizeof(dist));
        memset(parent,-1,sizeof(parent));
        for(int i =0; i< nodes; i++)
        {
            if(!indegree[i]) zero.push(i);
        }

        while(!zero.empty())
        {
            int current = zero.front();
            cout<<current<<endl;
            zero.pop();
            for(int j=0; j<g[current].size(); j++)
            {
                int v = g[current][j];
                indegree[v]--;
                if(indegree[v]==0) zero.push(v);
            }
        }

    }
};

int main()
{

    Graph g;
    g.input();
    g.top_sort();



}
