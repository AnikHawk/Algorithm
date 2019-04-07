
#include<bits/stdc++.h>
using namespace std;

const int mx = 200005;

int par[mx];

struct edge
{
    int u, v, w;

    edge(int u, int v, int w): u(u), v(v), w(w) {}

    bool operator<(const edge &p)const
    {
        return w<p.w;
    }
};

vector<edge> E;

void makeset(int n)
{
    par[n] = n;
}

int find_par(int n)
{
    if (par[n]==n) return n;
    par[n]=find_par(par[n]);
    return par[n];
}

void Merge(int x, int y)
{
    int u = find_par(x);
    int v = find_par(y);

    if(u==v)    return;
    par[u] = v;
}

int main()
{


    int n, m, x, y, z, i;

    while(scanf("%d %d", &n, &m)!=EOF)
    {

        if(n==0 && m==0 )   break;

        E.clear();

        int sum = 0, res = 0;

        for(i=0; i<mx; i++)    makeset(i);

        for(i=0; i<m; i++)
        {
            scanf("%d %d %d", &x, &y, &z);

            E.push_back(edge(x, y, z));

            res+=z;
        }

        sort(E.begin(), E.end());

        for(i=0; i<E.size(); i++)
        {
            x = E[i].u;
            y = E[i].v;
            z = E[i].w;

            if(find_par(x)==find_par(y))
            {
                res -=z;
            }

            else
            {
                Merge(x, y);

                /*
                	graph[x].push_back(y);
                	graph[y].push_back(x);
                	cost[x].pb(z)
                	cost[y].pb(z)

                */

            }
        }

        cout<<res<<endl;
    }
}
