#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef short int i16;
typedef unsigned long long int u64;
typedef unsigned int u32;
typedef unsigned short int u16;
typedef unsigned char u8;

const int N = 128;

struct edge
{
    int to,w;
    edge() {}
    edge(int a, int b)
    {
        to=a;
        w=b;
    }
};

struct el
{
    int vertex,cost;
    el() {}
    el(int a, int b)
    {
        vertex=a;
        cost=b;
    }
    bool operator<(const el &a) const
    {
        return cost>a.cost;
    }
};

priority_queue <el> pq;

vector <edge> v[N];

vector <int> dist[N];

int n,m,q;

void input()
{
    int i,a,b,c;
    for(i=0; i<N; i++)
        v[i].clear();
    for(i=1; i<=m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        a++;
        b++;
        v[a].push_back(edge(b,c));
        v[b].push_back(edge(a,c));
    }
}

void Dijkstra(int starting_node, int ending_node)
{
    int i,current_distance;
    el curr;
    for(i=0; i<N; i++)
        dist[i].clear();
    while(!pq.empty())
        pq.pop();
    pq.push(el(starting_node,0));
    while(!pq.empty())
    {
        curr=pq.top();
        pq.pop();
        if(dist[curr.vertex].size()==0)
            dist[curr.vertex].push_back(curr.cost);
        else if(dist[curr.vertex].back()!=curr.cost)
            dist[curr.vertex].push_back(curr.cost);
        if(dist[curr.vertex].size()>2)
            continue;
        for(i=0; i<v[curr.vertex].size(); i++)
        {
            if(dist[v[curr.vertex][i].to].size()==2)
                continue;
            current_distance=v[curr.vertex][i].w+curr.cost;
            pq.push(el(v[curr.vertex][i].to,current_distance));
        }
    }
    if(dist[ending_node].size()<2)
        printf("?\n");
    else
        printf("%d\n", dist[ending_node][1]);
}

void solve()
{
    int i,a,b;
    scanf("%d", &q);
    for(i=1; i<=q; i++)
    {
        scanf("%d %d", &a, &b);
        a++;
        b++;
        Dijkstra(a,b);
    }
}

int main()
{
    int i;
    for(i=1; scanf("%d %d", &n, &m)!=EOF; i++)
    {
        input();
        printf("Set #%d\n", i);
        solve();
    }
    return 0;
}
