
#include<bits/stdc++.h>
using namespace std;

vector <int> g[100002];
queue<int> q;
int parent[1000002];
int dist[1000002];
int color[1000002];
int nodes;
int edges;

struct Graph
{
    void input()
    {
        scanf("%d %d",&nodes,&edges);
        for(int i=0; i<edges; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
        }

        for(int i=0;i<nodes;i++)
        {
            sort(g[i].begin(),g[i].end());
        }

    }

    void BFS(int source)
    {
        memset(dist,-1,sizeof(dist));
        memset(parent,-1,sizeof(parent));
        parent[source] = -1;
        q.push(source);
        dist[source] = 0;

        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            for(int i = 0 ; i<g[current].size(); i ++)
            {
                int v = g[current][i];
                if(dist[v]==-1)
                {
                    dist[v] = dist[current] + 1;
                    parent[v] = current;
                    q.push(v);
                }
            }
        }

        for(int i = 0 ; i< nodes; i++)
        {
            //cout<<i<<" : "<<dist[i]<<endl;
            printf("%d:",i);
            if(parent[i]==-1 && i)
            {
                printf(" Not Reachable\n");
            }
            else
            {
                stack<int> s;
                int j = i;
                while(j!=-1)
                {
                    s.push(j);
                    j=parent[j];
                }
                while(!s.empty())
                {
                    printf(" %d",s.top());
                    s.pop();
                }
                printf("\n");
            }
        }
    }

};


int main()
{
    Graph g;
    g.input();
    g.BFS(0);


    return 0;
}
