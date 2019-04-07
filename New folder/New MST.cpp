

#include<bits/stdc++.h>
using namespace std;

vector<int> g[1000002];
vector<int> cost[1000002];
//vector<int> cost[1000002];
int parent[1000002];
int d[1000002];
int color[1000002];
int nodes;
int edges;

int added[1000002] = {0};


struct edge
{
    int u,v,c;
    edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
    void print(){
        printf("%d - %d : %d\n",u,v,c);
    }
    bool operator <(const edge &a) const
    {
        return c>a.c;
    }

    bool operator >(const edge &a) const
    {
        return c<a.c;
    }

    bool operator ==(const edge &a) const
    {
        return c==a.c;
    }

};


vector<int> Vmst;
vector<edge> Emst;
priority_queue<edge> pq;

struct Graph
{
    void input()
    {
        scanf("%d %d", &nodes,&edges);
        memset(d,1000002,sizeof(d));
        for(int i =0; i< edges; i++)
        {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            g[u-1].push_back(v-1);
            g[v-1].push_back(u-1);
            cost[u-1].push_back(c);
            cost[v-1].push_back(c);
        }

    }

    void Prim(int source)
    {
        Vmst.push_back(source);
        added[source] = 1;
        for(int i=0; i<g[source].size(); i++) pq.push(edge(source,g[source][i],cost[source][i]));
        while(!pq.empty())
        {
            edge e = pq.top();
            int u = e.v;
            pq.pop();
            if(!added[u])
            {
                Vmst.push_back(u);
                Emst.push_back(e);
                added[u] = 1;
                for(int i =0; i<g[u].size(); i++)
                {
                    int v = g[u][i];
                    if(!added[v]) pq.push(edge(u,v,cost[u][i]));
                }
            }

        }
        int weight = 0;
       // cout<<"MST Contains following Edges: "<<endl;
        for(int i = 0;i<Emst.size();i++){
            edge e = Emst[i];
            weight+=e.c;
            //e.print();
        }
        cout<<weight<<endl;
    }

};

/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7


*/


int main()
{

    Graph g;
    g.input();
    g.Prim(0);


    return 0;
}
