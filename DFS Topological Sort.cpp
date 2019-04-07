
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
stack<int> stk;

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


    void DFS(int source)
    {

        d[source]= ++t;
        color[source] = 0;
        group[source] = comp;

        for(int i=0; i<g[source].size(); i++)
        {
            int v = g[source][i];
            if(color[v] == -1) DFS(v);
        }

        f[source]= ++t;
        color[source] = 1;
        stk.push(source);
    }

    void TopSort(int source)
    {
        //DFS(source);
        while(!stk.empty())
        {
            int i = stk.top();
            stk.pop();
            printf("%d ",i);
        }
        cout<<endl;
    }



};



int main()
{

    Graph g;
    g.input();
   // g.TopSort(0);

    for(int i=0; i<nodes; i++)
    {
        if(color[i]==-1)
        {
            g.DFS(i);
            comp++;
        }
    }
    g.TopSort(0);
//    for(int i=0; i<nodes; i++)
//    {
//        printf("%d: %d %d %d\n",i,group[i],d[i],f[i]);
//
//    }
//


}
