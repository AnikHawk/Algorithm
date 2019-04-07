#include<bits/stdc++.h>
using namespace std;

vector <int> g[1000002];
vector<int> tree[1000002];
stack <int> art;
int color[1000002];
int d[1000002];
int f[1000002];
int parent [1000002];
int low[1000002];
int t =0;
int nodes;
int edges;
int bridges=0;
struct edge
{
    int x;
    int y;
    edge(int X, int Y)
    {
        if(X<Y)
        {
            x = X;
            y = Y;
        }

        if(X>Y)
        {
            x = Y;
            y = X;
        }


    }
    void print()
    {
        cout<<x<<" "<<y<<endl;
    }
    bool operator <(const edge &e) const
    {
        if(x < e.x || (x==e.x && y<e.y)) return true;
        return false;
    }

    bool operator >(const edge &e) const
    {
        if(x > e.x || (x==e.x && y>e.y)) return true;
        return false;
    }

    bool operator ==(const edge &e) const
    {
        if(x == e.x && y == e.y) return true;
        return false;
        }
};
vector <edge> edge_set;
struct Graph
{
    void input()
    {
        for(int i=0; i<1000002; i++) g[i].clear();
        for(int i=0; i<1000002; i++) tree[i].clear();
        memset(d,-1,sizeof(d));
        memset(f,-1,sizeof(f));
        memset(color,-1,sizeof(color));
        memset(low,-1,sizeof(low));
        memset(parent,-1,sizeof(parent));


        scanf("%d %d",&nodes,&edges);
        for(int i=0; i<edges; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

    }


    void DFS(int source)
    {

        d[source]= ++t;
        color[source] = 0;
        low[source] = d[source];

        for(int i=0; i<g[source].size(); i++)
        {
            int v = g[source][i];
            if(color[v] == -1)
            {
                parent[v] = source;
                tree[source].push_back(v);
                DFS(v);
                if(d[source]<low[v])
                {
                    ++bridges;
                    edge_set.push_back(edge(source,v));
                }
                low[source] = min(low[source],low[v]);
            }
            else if(parent[source]!=v) low[source] = min(low[source], d[v]);
        }

        f[source]= ++t;
        color[source] = 1;
    }



};



int main()
{
    Graph g;
    g.input();

    for(int i=0; i<nodes; i++)
    {
        if(color[i]==-1)
        {
            g.DFS(i);
        }
    }
    //if(!bridges) cout<<"No Bridge"<<endl;
    sort(edge_set.begin(),edge_set.end());
    for(int i =0;i<edge_set.size();i++){
        edge e = edge_set[i];
        e.print();
    }
}
