#include<bits/stdc++.h>
using namespace std;

vector<int> g[105];

int color[105];

int flag = 1;

void dfs(int u, int c)
{
    color[u] = c;

    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];

        if(color[v]==-1)
        {
            dfs(v, 1-c);
        }

        else if(color[v]==c)    flag = 0;
    }
}

int main()
{

        int n, m, u, v;

        scanf("%d %d", &n, &m);

        memset(color, -1, sizeof color);

        while(m--)
        {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, 0);


        puts(flag?"Bicolorable":"Not bicolorable");


}

