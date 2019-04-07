
#include<bits/stdc++.h>
using namespace std;

vector <int> g[100002];
vector <int> cost[1000002];
queue<int> q;
queue <int> zero;
int parent[1000002];
int dist[100][100];
int color[1000002];
int indegree[1000002];
int outdegree[1000002];
int nodes;
int edges;


struct Graph
{
    void input()
    {
        memset(indegree,0,sizeof(indegree));
        scanf("%d %d",&nodes,&edges);
        for(int i=0; i<edges; i++)
        {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            g[u].push_back(v);
            cost[u].push_back(c);
            ++indegree[v];
        }

    }

    void warshall()
    {
        for(int i =0; i<nodes; i++)
            for(int j=0; j<nodes; j++) dist[i][j] = 100;
        for(int i =0; i<nodes; i++) dist[i][i] = 0;

        for(int i =0; i<nodes; i++)
        {
            for(int j =0; j<g[i].size(); j++) dist[i][g[i][j]] = cost[i][j];
        }
        for(int k = 0; k<nodes; k++)
        {
            for(int i = 0; i<nodes; i++)
            {
                for(int j = 0; j<nodes; j++)
                {
                    if( dist[i][j] > dist[i][k] + dist[k][j] )
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
            //printMatrix();
            //cout<<endl;
        }

    }


    void printMatrix()
    {
        for(int i =0; i<nodes; i++)
        {
            for(int j =0; j<nodes; j++) cout<<dist[i][j]<<" ";
            cout<<endl;
        }
    }
};

int main()
{

    Graph g;
    g.input();
    g.warshall();
    g.printMatrix();



}
