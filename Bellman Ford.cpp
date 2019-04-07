#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000002];
vector<int> cost[1000002];
int parent[1000002];
int d[1000002];
int nodes;
int edges;
bool neg_cycle = false;



struct Graph
{

    void input()
    {
        scanf("%d %d", &nodes,&edges);
        memset(d,1000002,sizeof(d));
        for(int i =0; i< edges; i++)
        {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            g[u].push_back(v);
            cost[u].push_back(c);
        }

    }

    void BellmanFord(int source)
    {
        d[source] = 0;
        for(int i = 0; i<nodes-1; i++)
        {
            for(int u = 0; u<nodes; u++)
            {
                for(int x = 0; x<g[u].size(); x++)
                {
                    // cout<<u<<"->"<<g[u][x]<<endl;
                    int v = g[u][x];
                    int cost_u_v = cost[u][x];
                    d[v] = min(d[v], d[u]+cost_u_v);
                }
            }
        }

        for(int u = 0; u<nodes; u++)
        {
            for(int x = 0; x<g[u].size(); x++)
            {
                int v = g[u][x];
                int cost_u_v = cost[u][x];
                //d[v] = min(d[v], d[u]+cost);
                if(d[v] > d[u] + cost_u_v) neg_cycle = true;
            }
        }
        if(neg_cycle) cout<<"Negative Cycle Detected"<<endl;
        else
        {
            for(int i = 0; i<nodes; i++)
            {
                cout<<i<<" : "<<d[i]<<endl;
            }
        }

    }
};

int  main()
{
    Graph g;
    g.input();
    g.BellmanFord(0);


    return 0;

}
