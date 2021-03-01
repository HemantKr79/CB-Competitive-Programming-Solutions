#include <iostream>
using namespace std;

int *a = new int[1000000];
int *tree = new int[1000000];
int *lazy = new int[1000000];


void update_lazy(int ss,int se,int l,int r,int c,int index) {
    if(lazy[index]!=0) {
        tree[index] = lazy[index];
        if(ss!=se) {
            lazy[2*index+1] = lazy[index];
            lazy[2*index+2] = lazy[index];
        }
        lazy[index] = 0;
    }
    if(se<l || r<ss) {
        return;
    }
    if(l<=ss && r>=se) {
        tree[index] = c;
        if(ss!=se) {
            lazy[2*index+1] = c;
            lazy[2*index+2] = c;
        }
        return;
    }
    int m = (ss+se)/2;
    update_lazy(ss,m,l,r,c,2*index+1);
    update_lazy(m+1,se,l,r,c,2*index+2);
    tree[index] = -1;
}

int query(int ss,int se,int p,int index) {
    if(lazy[index]!=0) {
        tree[index] = lazy[index];
        if(ss!=se) {
            lazy[2*index+1] = lazy[index];
            lazy[2*index+2] = lazy[index];
        }
        lazy[index] = 0;
    }
    if(p<ss || p>se) {
        return -1;
    }
    if(ss<=p && p<=se) {
        if(tree[index]!=-1) {
            return tree[index];
        }
    }
    int m = (ss+se)/2;
    int leftAns = query(ss,m,p,2*index+1);
    int rightAns = query(m+1,se,p,2*index+2);
    if(leftAns==-1) {
        return rightAns;
    }
    return leftAns;
}

int main() {
    int n,q,l,r,col;
    cin>>n>>q;
    while(q--) {
        cin>>l>>r>>col;
        --l;
        --r;
        update_lazy(0,n-1,l,r,col,1);
    }
    for(int i=0;i<n;i++) {
        cout<<query(0,n-1,i,1)<<endl;
    }
    return 0;
}
