
#include<bits/stdc++.h>
using namespace std;
int total_points = 0;
struct point
{
    int x, y;
    point(int X, int Y)
    {
        x = X;
        y = Y;
    }
    point() {};
    void print()
    {
        cout<<x<<" , "<<y<<endl;
    }
    bool operator ==(const point & p) const
    {
        return (x==p.x && y==p.y);
    }

    bool operator !=(const point & p) const
    {
        return (x!=p.x || y!=p.y);
    }
    bool operator <(const point & p) const
    {
        if(x<p.x) return true;
        else if(x > p.x) return false;
        else if(x == p.x)
        {
            if(y == p.y) return false;
            else if(y< p.y) return true;
            return false;

        }
    }

};
vector<point> points;
struct edge
{
    double w;
    point u,v;
    edge(point U, point V)
    {
        u = U;
        v = V;
        w = sqrt(pow(u.x-v.x,2) + pow(u.y-v.y,2));
        //cout<<w<<endl;
    }
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};
map <point, point> pr;
vector<edge> e;
point find(point r)
{
    return (pr[r] == r) ? r : find(pr[r]);
}
double mst(int n)
{
    sort(e.begin(), e.end());
    for (int i = 0; i < total_points; i++)
        pr[points[i]] = points[i];

    int count = 0;
    double s = 0;
    for (int i = 0; i < (int)e.size(); i++)
    {
        point u = pr[e[i].u];
        point v = pr[e[i].v];
        // cout<<"parent of"<<endl;e[i].u.print();cout<<"is"<<endl;u.print();
        //cout<<"parent of"<<endl;e[i].v.print();cout<<"is"<<endl;v.print();


        if (u != v)
        {
            pr[u] = v;
            count++;
            cout<<"Cost: "<<e[i].w<<endl;
            s += e[i].w;
            if (count == total_points - 1)
                break;
        }
    }
    return s;
}

int main()
{
    // READ("in");
    int n,m;
    cin >> m;
    total_points = m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back(point(x,y));
    }

    for(int i = 0; i<points.size(); i++)
    {
        for(int j = 0; j<points.size(); j++)
        {
            point u = points[i];
            point v = points[j];
            edge line = edge(u,v);
            e.push_back(line);
        }
    }
    cout << mst(m) << endl;
    return 0;
}
