
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

double ClosestPairDist(Point Px[], Point Py[], int n)
{
    if(n==3)
    {
        double dist01 = dist(Px[0],Px[1]);
        double dist12 = dist(Px[1],Px[2]);
        double dist02 = dist(Px[0],Px[2]);
        return min(dist01,min(dist02,dist12));
    }
    int mid = n/2;
    Point midPoint = Px[mid];

    Point pyLeft[mid];
    Point pyRight[n-mid];

    int li = 0, ri = 0;


     for (int i = 0; i < n; i++)
    {
      if (Py[i].x <= midPoint.x) pyLeft[li++] = Py[i];
      else pyRight[ri++] = Py[i];
    }

    double minLeft = ClosestPairDist(Px,pyLeft,mid);
    double minRight = ClosestPairDist(Px+mid, pyRight, n-mid);
    double minDist = min(minLeft,minRight);

    Point strip[n];
    int strpi = 0;
    for(int i =0; i<n; i++)
    {
        if(abs(Py[i].x - midPoint.x)<minDist)
            strip[strpi++] = Py[i];
    }

    double minStrip = StripClosest(strip,strpi,minDist);
    return min(minDist,minStrip);
}

double closest(Point p[], int n){
    Point px[n];
    Point py[n];
    for(int i =0;i<n;i++){
        px[i] = p[i];
        py[i] = p[i];
    }
    sort(px,px+n,sortByX);
    sort(py,py+n,sortByY);

    return ClosestPairDist(px,py,n);

}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout<<closest(P,n)<<endl;

    return 0;
}
