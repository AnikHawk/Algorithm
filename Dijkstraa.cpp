
#include<bits/stdc++.h>
using namespace std;

vector<int> g[1000002];
vector<int> cost[1000002];
int parent[1000002];
int d[1000002];
int color[1000002];
int nodes;
int edges;

struct element
{
    int node;
    element() {}
    element(int _node)
    {
        node = _node;
    }
    bool operator <(const element &a) const
    {
        return (d[node] > d[a.node]);
    }

    bool operator ==(const element &a) const
    {
        return (d[node] == d[a.node]);
    }


};
priority_queue <element> q;

struct Graph
{

    void input()
    {
        scanf("%d %d", &nodes,&edges);
        memset(parent,-1,sizeof(parent));
        memset(d,1000002,sizeof(d));
        for(int i =0; i< edges; i++)
        {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            g[u].push_back(v);
            cost[u].push_back(c);
        }
        for(int i =0; i<nodes; i++) q.push(element(i));

    }
    void Dijkstra (int source)
    {
        d[source] = 0;
        parent[source] = -1;

        while (!q.empty())
        {
            element nxt = q.top();
            q.pop();
            int u = nxt.node;
            cout<<"Popped: "<<u<<endl;
            for (int i=0; i<g[u].size(); i++)
            {
                int v = g[u][i];
                element tmp;
                tmp = element(v);
                cout<<u<<" - "<<g[u][i]<<"   d[u]: "<<d[u]<<"  cost[u][v]: "<<cost[u][i]<<endl;
                if (d[g[u][i]] > d[u] + cost[u][i])  //if(d[tmp.node] > d[u] + cost[tmp.path_cost])
                {
                    d[g[u][i]] = d[u] + cost[u][i];
                    parent[g[u][i]] = u;
                }
            }
        }

        for(int i=0; i<nodes; i++)
        {
            cout<<i<<" : "<<d[i]<<endl;
        }
    }


};
/*
4 4
0 1 2
0 2 5
1 2 1
2 3 3
*/
int main()
{
    Graph g;
    g.input();
    g.Dijkstra(0);
    return 0;
}
