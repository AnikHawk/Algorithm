#include<bits/stdc++.h>
using namespace std;

vector <int> g[1000002];
vector<int> tree[1000002];
stack <int> art;
int color[1000002];
int d[1000002];
int f[1000002];
int parent [1000002];
int group[1000002];
int low[1000002];
int t =0;
int nodes;
int edges;
int comp = 1;
int bridges=0;

struct Graph
{

    void input()
    {
        for(int i=0; i<1000002; i++) g[i].clear();
        for(int i=0; i<1000002; i++) tree[i].clear();
        memset(d,-1,sizeof(d));
        memset(f,-1,sizeof(f));
        memset(color,-1,sizeof(color));
        memset(group,-1,sizeof(group));
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
                    cout<<source<<" "<<v<<endl;
                }
                low[source] = min(low[source],low[v]);
            }
            else if(parent[source]!=v) low[source] = min(low[source], d[v]);
            // if (parent[source] == -1 && tree[source].size() > 1) art.push(source);
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
            comp++;
        }
    }
    if(!bridges) cout<<"No Bridge"<<endl;

}
