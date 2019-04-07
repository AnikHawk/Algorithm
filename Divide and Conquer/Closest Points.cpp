#include<bits/stdc++.h>
using namespace std;

struct Point
{
    int x,y;
};


double dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

bool sortByX(const Point& a, const Point& b)
{
    return a.x<b.x;
}

bool sortByY(const Point& a, const Point& b)
{
    return a.y<b.y;
}

double min(double x, double y)
{
    return x<y?x:y;
}
double bruteForce(Point P[], int n)
{
    double min = 999999;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

double StripClosest(Point p[], int n, double d)
{
    sort(p,p+n,sortByY);
    double minDist = d;
    for(int i =0; i<n; i++)
    {
        int j = i+1;
        while(j<n && p[j].y-p[i].y<minDist)
        {
            if(dist(p[j],p[i])<minDist) minDist = dist(p[i],p[j]);
            j++;
        }



    }
    return minDist;

}

double ClosestPairDist(Point P[], int n)
{
    if(n==3)
    {
        double dist01 = dist(P[0],P[1]);
        double dist12 = dist(P[1],P[2]);
        double dist02 = dist(P[0],P[2]);
        return min(dist01,min(dist02,dist12));
    }


    sort(P,P+n,sortByX);
    int mid = n/2;
    double minLeft = ClosestPairDist(P,mid);
    double minRight = ClosestPairDist(P+mid, n-mid);
    double minDist = min(minLeft,minRight);
    Point strip[n];
    int strpi = 0;
    for(int i =0; i<n; i++)
    {
        if(abs(P[i].x - P[mid].x)<minDist)
            strip[strpi++] = P[i];
    }

    double minStrip = StripClosest(strip,strpi,minDist);
    return min(minDist,minStrip);
}


int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout<<ClosestPairDist(P,n)<<endl;

    return 0;
}
