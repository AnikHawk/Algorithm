#include<bits/stdc++.h>
using namespace std;

vector<int> g[105];

int gray[105], white[105], black[105];

int flag = 1;

void dfs(int node)
{

        gray[node] = 1;
        white[node] = 1;

        for(int i=0; i<g[node].size(); i++)
        {
            int v = g[node][i];

            if(gray[v]==1)  flag = 0;

            if(black[v]==1) continue;

            if(white[v]==0) dfs(v);
        }

        gray[node] = 0;
        black[node] = 1;
}

int main()
{

        int n, m, u, v;

        scanf("%d %d", &n, &m);

        while(m--)
        {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);

        }


        dfs(1);

        puts(flag?"no cycle":"cycle");


}

