#include <iostream>
#include<vector>
#include<set>
using namespace std;

#define N 400005

vector<int> gr[N];
int tin[N];
int tout[N];
vector<set<int> > lazy;
vector<set<int> > tree;
int *a = new int[N];
int timer;

void euler_tour(int curr,int par) {
    tin[curr] = ++timer;
    for(auto nbr : gr[curr]) {
        if(nbr!=par) {
            euler_tour(nbr,curr);
        }
    }
    tout[curr] = timer;
}

void build_tree(int ss,int se,int index) {
    if(ss>se) {
        return;
    }
    if(ss==se) {
        set<int> s;
        s.insert(a[ss]);
        tree[index] = s;
        return;
    }
    int m = (ss+se)/2;
    build_tree(ss,m,2*index);
    build_tree(m+1,se,2*index+1);
    set<int> s = tree[2*index];
    s.insert(tree[2*index+1].begin(),tree[2*index+1].end());
    tree[index] = s;
}

void update(int ss,int se,int c,int l,int r,int index) {
    if(lazy[index].size()!=0) {
        tree[index] = lazy[index];
        if(ss!=se) {
            lazy[2*index] = lazy[index];
            lazy[2*index+1] = lazy[index];
        }
        lazy[index].clear();
    }
    if(l>se || r<ss) {
        return;
    }
    if(l<=ss && se<=r) {
        set<int> s;
        s.insert(c);
        tree[index] = s;
        if(ss!=se) {
            lazy[2*index] = s;
            lazy[2*index+1] = s;
        }
        return;
    }
    int m = (ss+se)/2;
    update(ss,m,c,l,r,2*index);
    update(m+1,se,c,l,r,2*index+1);
    set<int> s = tree[2*index];
    s.insert(tree[2*index+1].begin(),tree[2*index+1].end());
    tree[index] = s;
}

set<int> query(int ss,int se,int l,int r,int index) {
    if(lazy[index].size()>0) {
        tree[index] = lazy[index];
        if(ss!=se) {
            lazy[2*index] = lazy[index];
            lazy[2*index+1] = lazy[index];
        }
        lazy[index].clear();
    }
    if(l>se || r<ss) {
        set<int> s;
        return s;
    }
    if(l<=ss && se<=r) {
        return tree[index];
    }
    int m = (ss+se)/2;
    set<int> leftAns = query(ss,m,l,r,2*index);
    set<int> rightAns = query(m+1,se,l,r,2*index+1);
    leftAns.insert(rightAns.begin(),rightAns.end());
    return leftAns;
}

int main() {
    int n,q;
    cin>>n>>q;
    lazy.reserve(4*n+5);
    tree.reserve(4*n+5);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    int x,y;
    for(int i=0;i<n-1;i++) {
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    timer = 0;
    euler_tour(1,0);
    build_tree(1,n,1);
    while(q--) {
        int type;
        cin>>type;
        if(type==1) {
            int v,c;
            cin>>v>>c;
            int l_range = tin[v];
            int r_range = tout[v];
            update(1,n,c,l_range,r_range,1);
        }
        else {
            int v;
            cin>>v;
            cout<<query(1,n,tin[v],tout[v],1).size()<<endl;
        }
    }
    return 0;
}
