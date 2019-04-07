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
    int node, path_cost;
    element() {}
    element(int _node, int _path_cost)
    {
        node = _node;
        path_cost = _path_cost;
    }
    bool operator <(const element &a) const
    {
        return (path_cost > a.path_cost);
    }


};


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

    }
    void Dijkstra (int source)
    {
        d[source] = 0;
        parent[source] = -1;
        priority_queue <element> q;
        q.push(element(source, 0));
        while (!q.empty())
        {
            element nxt = q.top();
            q.pop();
            int u = nxt.node;
            for (int i=0; i<g[u].size(); i++)
            {
                element tmp;
                tmp = element(g[u][i], cost[u][i]);
                if (d[g[u][i]] > d[u] + cost[u][i])  //if(d[tmp.node] > d[u] + cost[tmp.path_cost])
                {
                    d[g[u][i]] = d[u] + cost[u][i];
                    parent[g[u][i]] = u;
                    q.push(element(tmp.node, d[tmp.node]));
                }
            }
        }

        for(int i=0; i<nodes; i++)
        {
            cout<<i<<" : "<<d[i]<<" path: ";
            int j = i;
            stack<int> s;
            while(j!=-1)
            {
                s.push(j);
                j = parent[j];
            }
            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
            cout<<endl;
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
    int i = nodes - 1;
    return 0;
}
