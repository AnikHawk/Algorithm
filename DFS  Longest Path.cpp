
#include<bits/stdc++.h>
using namespace std;

vector <int> g[1000002];
int deep[1000002];
int color[1000002];
int d[1000002];
int f[1000002];
int group[1000002];
int t =0;
int nodes;
int edges;
int comp = 1;
//int depth = 0;
int max_depth = 0;

struct Graph
{

    void input()
    {
        for(int i=0; i<1000002; i++) g[i].clear();
       // memset(d,-1,sizeof(d));
        //memset(f,-1,sizeof(f));
        memset(color,-1,sizeof(color));
        //memset(group,-1,sizeof(group));


        //scanf("%d %d",&nodes,&edges);
        scanf("%d",&nodes);
        for(int i=0; i<nodes-1; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

    }


    void DFS(int source, int  depth)
    {
        //depth++;
       // cout<<source<<" ";
        //d[source]= ++t;
        color[source] = 0;
       // group[source] = comp;

        for(int i=0; i<g[source].size(); i++)
        {
            int v = g[source][i];
            if(color[v] == -1)
            {
                DFS(v, depth+1);
            }
        }

        //f[source]= ++t;
        color[source] = 1;
        if(deep[source]<depth) deep[source] = depth;
        if(depth>max_depth) max_depth=depth;
       // cout<<"End:"<<source<<"Depth:"<<depth<<" ";
    }




};



int main()
{

    Graph g;
    g.input();

    for(int i=0; i<nodes; i++)
    {
       // memset(d,-1,sizeof(d));
        //memset(f,-1,sizeof(f));
        memset(color,-1,sizeof(color));
        g.DFS(i,0);
        //cout<<endl;
       // printf("Depth: %d\n",depth);
        //depth=0;
    }

    printf("%d\n",max_depth);


}
