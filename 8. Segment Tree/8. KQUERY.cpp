#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void build_tree(vector<int> *tree,int *a,int s,int e,int index) {
    if(s==e) {
        tree[index].push_back(a[s]);
        return;
    }
    int m = (s+e)/2;
    build_tree(tree,a,s,m,2*index);
    build_tree(tree,a,m+1,e,2*index+1);
    auto it1 = tree[2*index].begin();
    auto it2 = tree[2*index+1].begin();
    while(it1!=tree[2*index].end() && it2!=tree[2*index+1].end()) {
        if((*it1)<(*it2)) {
            tree[index].push_back(*it1);
            it1++;
        }
        else {
            tree[index].push_back(*it2);
            it2++;
        }
    }
    while(it1!=tree[2*index].end()) {
        tree[index].push_back(*it1);
        it1++;
    }
    while(it2!=tree[2*index+1].end()) {
        tree[index].push_back(*it2);
        it2++;
    }
}

int make_query(vector<int> *tree,int ss,int se,int l,int r,int k,int index) {
    if(l>se || r<ss) {
        return 0;
    }
    if(ss>=l && se<=r) {
        return tree[index].size() - ( upper_bound(tree[index].begin(),tree[index].end(),k) - tree[index].begin() );
    }
    int m = (ss+se)/2;
    int leftAns = make_query(tree,ss,m,l,r,k,2*index);
    int rightAns = make_query(tree,m+1,se,l,r,k,2*index+1);
    return leftAns+rightAns;
}

int main() {
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int ans = 0;
    vector<int> *tree = new vector<int>[4*n+1];
    build_tree(tree,a,0,n-1,1);
    int q;
    cin>>q;
    while(q--) {
        int a,b,c;
        cin>>a>>b>>c;
        --a;
        --b;
        ans = make_query(tree,0,n-1,a,b,c,1);
        cout<<ans<<endl;
    }
    return 0;
}
