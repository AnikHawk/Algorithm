#include<bits/stdc++.h>
using namespace std;

vector<int> g[105];
bool vis[105];

int indegree[105];
vector<int> topsort;

void dfs(int u)
{
    vis[u] = 1;

    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(!vis[v]) dfs(v);
    }

    topsort.push_back(u);
}

int main()
{

        int n, m, u, v;

        scanf("%d %d", &n, &m);

        while(m--)
        {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            indegree[v]++;
        }

        for(int i=1; i<=n; i++)
        {
            if(indegree[i]==0)  dfs(i);
        }

        reverse(topsort.begin(), topsort.end());

        for(int i=0; i<topsort.size(); i++)
        {
            cout<<topsort[i]<<" ";
        }





}
