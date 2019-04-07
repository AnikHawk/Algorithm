#include<bits/stdc++.h>
using namespace std;

vector <int> g[1000002];
vector<int> tree[1000002];
stack <int> art;
int color[1000002];
int d[1000002];
int f[1000002];
int parent [1000002];
int group[1000002];
int low[1000002];
int t =0;
int nodes;
int edges;
int comp = 1;

struct edge
{
    int u,v;
    edge(int U, int V)
    {
        u = U ;
        v = V;
    }

    void print()
    {
        printf("%d - %d\n",u,v);
    }

    bool operator ==(const edge& e) const
    {
        if(u == e.u && v == e.v) return true;
        return false;
    }
    bool operator !=(const edge& e) const
    {
        if(u != e.u || v != e.v) return true;
        return false;
    }
};

vector <edge> stk;

void print_stack(stack<edge> stk)
{
    while(!stk.empty())
    {
        edge e = stk.top();
        e.print();
    }
}

struct Graph
{
    void input()
    {
        for(int i=0; i<1000002; i++) g[i].clear();
        for(int i=0; i<1000002; i++) tree[i].clear();
        memset(d,-1,sizeof(d));
        memset(f,-1,sizeof(f));
        memset(color,-1,sizeof(color));
        memset(group,-1,sizeof(group));
        memset(low,-1,sizeof(low));
        memset(parent,-1,sizeof(parent));


        scanf("%d %d",&nodes,&edges);
        for(int i=0; i<edges; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

    }


    void DFS(int source)
    {

        d[source]= ++t;
        color[source] = 0;
        low[source] = d[source];

        for(int i=0; i<g[source].size(); i++)
        {
            int v = g[source][i];
            if(color[v] == -1)
            {
                parent[v] = source;
                stk.push_back(edge(source,v));
                tree[source].push_back(v);
                DFS(v);
                low[source] = min(low[source],low[v]);
                if(d[source]<=low[v] && parent[source]!=-1)
                {
                    art.push(source);
                    edge e = edge(source,v);
                    edge bck = stk.back();
                    cout<<"Group:"<<endl;
                    while(stk.back()!=e)
                    {
                        edge last = stk.back();
                        last.print();
                        stk.pop_back();
                    }
                    edge last = stk.back();
                    last.print();
                    stk.pop_back();
                }

            }
            else if(parent[source]!=v)
            {
                if(low[source] > d[v])
                {
                    low[source] = d[v];
                    stk.push_back(edge(source,v));
                }
            }
            if (parent[source] == -1 && tree[source].size() > 1)
            {
                edge e = edge(source,v);
                while(stk.back()!=e)
                {
                    edge last = stk.back();
                    last.print();
                    stk.pop_back();
                }
                edge last = stk.back();
                last.print();
                stk.pop_back();
                art.push(source);
            }
        }

        f[source]= ++t;
        color[source] = 1;
    }



};
/*
12 14
0 1
1 2
1 3
2 3
2 4
3 4
1 5
0 6
5 6
5 7
5 8
7 8
8 9
10 11
*/

int main()
{

    Graph g;
    g.input();

    for(int i=0; i<nodes; i++)
    {
        if(color[i]==-1)
        {
            g.DFS(i);
            comp++;
            cout<<"Group"<<endl;
            while(!stk.empty())
            {
                edge e = stk.back();
                e.print();
                stk.pop_back();
            }

        }

        //if(!art.size()) cout<<"No Articulation Point"<<endl;
//    while(!art.empty())
//    {
//        int i = art.top();
//        art.pop();
//        cout<<i<<endl;
//    }

    }
}
