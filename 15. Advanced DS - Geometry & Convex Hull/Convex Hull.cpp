


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    bool operator < (Point &P) {
        if(P.x==x) {
            return y < P.y;
        }
        return x < P.x;
    }
    bool operator == (Point &P) {
        return (P.x==x && P.y==y);
    }
};

bool cw(Point a,Point b,Point c) {
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) < 0;
}

bool cww(Point a,Point b,Point c) {
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) < 0;
}

bool collinear(Point a,Point b,Point c) {
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) == 0;
}

void convex_hull(vector<Point> &p) {
    if(p.size() <= 2) {
        return;
    }
    int n = p.size();
    sort(p.begin(),p.end());
    vector<Point> up;
    vector<Point> down;
    Point p1 = p[0];
    Point p2 = p[n-1];
    up.push_back(p[0]);
    down.push_back(p[0]);
    for(int i=0;i<n;i++) {
        if(i==n-1 || !cww(p1,p[i],p2)) {
            while(up.size() >= 2 && cww(up[up.size()-2],up[up.size()-1],p[i])) {
                up.pop_back();
            }
            up.push_back(p[i]);
        }
        if(i==n-1 || !cw(p1,p[i],p2)) {
            while(down.size() >= 2 && cw(down[down.size()-2],down[down.size()-1],p[i])) {
                down.pop_back();
            }
            down.push_back(p[i]);
        }
    }
    p.clear();
    for(auto pnt : up) {
        p.push_back(pnt);
    }
    for(auto pnt : down) {
        p.push_back(pnt);
    }
    p.resize(unique(p.begin(),p.end()) - p.begin());
}

int main() {
    int n;
    cin>>n;
    vector<Point> p(n);
    for(int i=0;i<n;i++) {
        cin>>p[i].x>>p[i].y;
    }
    convex_hull(p);
    for(auto pnt : p) {
        cout<<pnt.x<<" "<<pnt.y<<endl;
    }
}
