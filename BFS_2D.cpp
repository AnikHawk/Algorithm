#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dist[100][100];
int color[100][100];

int grid[100][100];
int n,m;

struct node{

    int x;
    int y;
};

queue< node > q;

struct Grid{

    void input()
    {
        cin>>n;
        cin>>m;
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char c;
                cin>>c;
                if(c=='.') grid[i][j]=1;
                else grid[i][j]= 0;
            }
        }
    }

    void BFS_2D(int  sx, int sy){
        memset(dist,-1,sizeof(dist));
        memset(color,-1,sizeof(color));
        node nd; nd.x=sx; nd.y=sy;
        q.push(nd);
        dist[sx][sy]=0;
        color[sx][sy] = 0;

        while(!q.empty())
        {
            node current = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x = current.x + dx[i];
                int y = current.y + dy[i];
                if(x>=0 && x<=n && y>=0 && y<=m && grid[x][y] && color[x][y]==-1)
                {
                    color[x][y]=0;
                    dist[x][y]= dist[current.x][current.y] + 1 ;
                    node n; n.x=x; n.y =y;
                    q.push(n);

                }
            }
            color[current.x][current.y]=1;

        }

    }

};


int main()
{
    Grid g;
    g.input();


    g.BFS_2D(0,0);
    cout<<dist[n-1][m-1];
    return 0;
}
