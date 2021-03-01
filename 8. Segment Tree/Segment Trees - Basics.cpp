#include <iostream>
#include <climits>
using namespace std;

int *lazy = new int[10000]();

void buildTree(int *a,int ss,int se,int *tree,int index) {
    if(ss==se) {
        tree[index] = a[ss];
        return;
    }
    int m = (ss+se)/2;
    buildTree(a,ss,m,tree,2*index);
    buildTree(a,m+1,se,tree,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
}

int make_query(int *tree,int ss,int se,int qs,int qe,int index) {
    if(qe<ss || qs>se) {
        return INT_MAX;
    }
    if(qs<=ss && qe>=se) {
        return tree[index];
    }
    int m = (ss+se)/2;
    int leftAns = make_query(tree,ss,m,qs,qe,2*index);
    int rightAns = make_query(tree,m+1,se,qs,qe,2*index+1);
    return min(leftAns,rightAns);
}

void point_update(int *tree,int ss,int se,int i,int increment,int index) {
    if(i<ss || i>se) {
        return;
    }
    if(ss==se) {
        tree[index] += increment;
        return;
    }
    int m = (ss+se)/2;
    point_update(tree,ss,m,i,increment,2*index);
    point_update(tree,m+1,se,i,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
}

void range_update(int *tree,int ss,int se,int l,int r,int increment,int index) {
    if(r<ss || l>se) {
        return;
    }
    if(ss==se) {
        tree[index] += increment;
        return;
    }
    int m = (ss+se)/2;
    range_update(tree,ss,m,l,r,increment,2*index);
    range_update(tree,m+1,se,l,r,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
}

void range_update_lazy(int *tree,int ss,int se,int l,int r,int increment,int index) {
    if(lazy[index]!=0) {
        tree[index] += lazy[index];
        if(ss!=se) {
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(ss>r || se<l) {
        return;
    }
    if(ss>=l && se<=r) {
        tree[index] += increment;
        if(ss!=se) {
            lazy[2*index] += increment;
            lazy[2*index+1] += increment;
        }
        return;
    }
    int m = (ss+se)/2;
    range_update_lazy(tree,ss,m,l,r,increment,2*index);
    range_update_lazy(tree,m+1,se,l,r,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
}

int make_query_lazy(int *tree,int ss,int se,int l,int r,int index) {
    if(lazy[index]!=0) {
        tree[index] += lazy[index];
        if(ss!=se) {
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(r<ss || l>se) {
        return INT_MAX;
    }
    if(ss>=l && se<=r) {
        return tree[index];
    }
    int m = (ss+se)/2;
    int leftAns = make_query_lazy(tree,ss,m,l,r,2*index);
    int rightAns = make_query_lazy(tree,m+1,se,l,r,2*index+1);
    return min(leftAns,rightAns);
}

int main() {
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    };
    int *tree = new int[4*n+1];
    buildTree(a,0,n-1,tree,1);
    point_update(tree,0,n-1,3,10,1);
    range_update(tree,0,n-1,2,4,10,1);
    range_update_lazy(tree,0,n-1,1,4,2,1);
    int q;
    cin>>q;
    while(q--) {
        int l,r;
        cin>>l>>r;
        cout<<make_query_lazy(tree,0,n-1,l,r,1)<<endl;
    }
    return 0;
}
