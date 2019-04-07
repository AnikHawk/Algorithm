#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int dist[100][100];
int color[100][100];
int comp = 0;
int grid[100][100];
int n,m;

struct node
{

    int x;
    int y;
};

queue< node > q;

struct Grid
{

    void input()
    {
        cin>>n;
        cin>>m;
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                char c;
                cin>>c;
                if(c=='.') grid[i][j]=1;
                else grid[i][j]= 0;
                color[i][j]=-1;
            }
        }
    }


    void DFS_2D(int sx, int sy)
    {
        color[sx][sy] = 0;
        for(int i=0; i<4; i++)
        {
            int x = sx + dx[i];
            int y = sy + dy[i];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && color[x][y]==-1)
            {
                DFS_2D(x,y);
            }
        }

   } };


    int main()
    {
        Grid g;
        g.input();
        for(int i = 0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(color[i][j]==-1 && grid[i][j]){
                //++comp;
                    g.DFS_2D(i,j);
                    comp++;
                }
            }
        }
        cout<<comp<<endl;
        return 0;
    }
