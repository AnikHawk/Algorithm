
#include<bits/stdc++.h>
using namespace std;

vector <int> g[1000002];
queue <int> q;
vector <int> g2[1000002];
stack<int> stk;
int deep[1000002];
int color[1000002];
int color2[1000002];
int d[1000002];
int f[1000002];
int group[1000002];
int t =0;
int nodes;
int edges;
int comp = 1;
int max_depth = 0;

struct Graph
{

    void input()
    {
        for(int i=0; i<1000002; i++){ g[i].clear(); g2[i].clear(); }
        memset(color,-1,sizeof(color));
        memset(color2,-1,sizeof(color2));
        scanf("%d",&nodes);
        for(int i=0; i<nodes-1; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v); g2[u].push_back(v);
            g[v].push_back(u); g2[v].push_back(u);
        }

    }


     void BFS(int source)
    {
        q.push(source);
        color[source] = 0;

        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            for(int i = 0 ; i<g[current].size(); i ++)
            {
                int v = g[current][i];
                if(color[v]==-1)
                {
                    stk.push(v);
                    color[v] = 0;
                    q.push(v);
                }
            }
            color[current] = 1;
        }
    }
    
     void DFS(int source, int depth)
    {
		
        color2[source] = 0;
        for(int i=0; i<g2[source].size(); i++)
        {
            int v = g2[source][i];
            if(color2[v] == -1)
            {
                
                DFS(v,depth + 1);
            }
        }
        color2[source] = 1;
        max_depth= max(max_depth,depth);
    }


};



int main()
{

    Graph g;
    g.input();

    g.BFS(0);
    //cout<<"Top: "<<stk.top()<<endl;
    g.DFS(stk.top(),0);
    printf("%d\n",max_depth);


}
