#include<bits/stdc++.h>
using namespace std;

vector <int> g[1000002];
vector <int> trans_g[1000002];
stack <int> stk;
int color[1000002];
int color2[1000002];
int d[1000002];
int f[1000002];
vector <int> component[1000002];
int t =0;
int nodes;
int edges;
int comp = 1;

struct Graph
{

    void input()
    {
        for(int i=0; i<1000002; i++) g[i].clear();
        memset(d,-1,sizeof(d));
        memset(f,-1,sizeof(f));
        memset(color,-1,sizeof(color));
         memset(color2,-1,sizeof(color2));
        //memset(component,-1,sizeof(component));


        scanf("%d %d",&nodes,&edges);
        for(int i=0; i<edges; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            trans_g[v].push_back(u);
        }

    }


    void DFS(int source)
    {

        d[source]= ++t;
        color[source] = 0;

        for(int i=0; i<g[source].size(); i++)
        {
            int v = g[source][i];
            if(color[v] == -1) DFS(v);
        }

        f[source]= ++t;
        color[source] = 1;
        stk.push(source);
    }


    void DFS2(int source, int comp)
    {
		component[comp].push_back(source);
        color2[source] = 0;

        for(int i=0; i<trans_g[source].size(); i++)
        {
            int v = trans_g[source][i];
            if(color2[v] == -1) DFS2(v,comp);
        }
        color2[source] = 1;

	}

	void SCC()
	{
		 for(int i=0; i<nodes; i++)
    {
        if(color[i]==-1)
        {
            DFS(i);
        }
    }
    while(!stk.empty())
    {
		int u = stk.top();
		stk.pop();
		if(color2[u]==-1)
		{
			comp++;
			DFS2(u,comp);
		}
	}

	}




};





int main()
{

    Graph g;
    g.input();
    g.SCC();



    printf("Total Components: %d\n",comp-1);
    for(int i=1; i<=comp; i++)
    {
       for(int j=0;j<component[i].size();j++)
       {
		   printf("%d ",component[i][j]);
	   }
	   cout<<endl;

    }



}
