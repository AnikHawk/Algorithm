
#include<bits/stdc++.h>
using namespace std;

vector <int> g[1000002];
int color[1000002];
int d[1000002];
int f[1000002];
int group[1000002];
int t =0;
int nodes;
int edges;
int comp = 1;
bool cycle = false;

struct Graph
{

    void input()
    {
        for(int i=0; i<1000002; i++) g[i].clear();
        memset(d,-1,sizeof(d));
        memset(f,-1,sizeof(f));
        memset(color,-1,sizeof(color));
        memset(group,-1,sizeof(group));


        scanf("%d %d",&nodes,&edges);
        for(int i=0; i<edges; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            //g[v].push_back(u);
        }

    }


    void IsCycle(int source)
    {

        d[source]= ++t;
        color[source] = 0;
        group[source] = comp;

        for(int i=0; i<g[source].size(); i++)
        {
            int v = g[source][i];
            if(color[v]==0)
            {
                cycle = true;
                return;
            }
            if(color[v] == -1) IsCycle(v);
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
            g.IsCycle(i);
            comp++;
        }
    }
    for(int i=0; i<nodes; i++)
    {
        printf("%d: %d %d %d\n",i,group[i],d[i],f[i]);
    }


    if(cycle) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;



}
