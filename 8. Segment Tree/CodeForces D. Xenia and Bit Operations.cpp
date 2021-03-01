#include <iostream>
#include <cmath>
using namespace std;

void build_tree(int *a,int *tree,int s,int e,int index) {
    if(s==e) {
        tree[index] = a[s];
        return;
    }
    int m = (s+e)/2;
    build_tree(a,tree,s,m,2*index);
    build_tree(a,tree,m+1,e,2*index+1);
    int range = (e-s+1);
    int flag = log2(range);
    if(flag&1) {
        tree[index] = tree[2*index]|tree[2*index+1];
    }
    else {
        tree[index] = tree[2*index]^tree[2*index+1];
    }
}

void point_update(int *tree,int ss,int se,int pos,int i,int index) {
    if(pos<ss || pos>se) {
        return;
    }
    if(ss==se) {
        tree[index] = i;
        return;
    }
    int m = (ss+se)/2;
    point_update(tree,ss,m,pos,i,2*index);
    point_update(tree,m+1,se,pos,i,2*index+1);
    int range = (se-ss+1);
    int flag = log2(range);
    if(flag&1) {
        tree[index] = tree[2*index]|tree[2*index+1];
    }
    else {
        tree[index] = tree[2*index]^tree[2*index+1];
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    n = 1<<n;
    int *a = new int[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int *tree = new int[4*n+1];
    build_tree(a,tree,0,n-1,1);
    while(m--) {
        int p,b;
        cin>>p>>b;
        point_update(tree,0,n-1,p-1,b,1);
        cout<<tree[1]<<endl;
    }
    return 0;
}
