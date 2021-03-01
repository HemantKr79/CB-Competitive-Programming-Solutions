#include <iostream>
#include <set>
#include <vector>
using namespace std;

class point {
    public:
    int x,y;
    point() {
    }
    point(int x,int y) {
        this->x = x;
        this->y = y;
    }
};

class compare {
    public:
    bool operator()(const point &a,const point &b) {
        if(a.x==b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
};

int solve(vector<point> &v) {
    set<point,compare> s;
    for(auto p : v) {
        s.insert(p);
    }
    int ans = 0;
    for(auto it = s.begin();it!=prev(s.end());it++) {
        for(auto jt = next(it);jt!=s.end();jt++) {
            point p1 = *it;
            point p2 = *jt;
            if(p1.x==p2.x || p1.y==p2.y) {
                continue;
            }
            point p3(p1.x,p2.y);
            point p4(p2.x,p1.y);
            if(s.find(p3)!=s.end() && s.find(p4)!=s.end()) {
                ++ans;
            }
        }
    }
    return ans/2;
}

int main() {
    int n;
    cin>>n;
    vector<point> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i].x>>v[i].y;
    }
    cout<<solve(v);
}
