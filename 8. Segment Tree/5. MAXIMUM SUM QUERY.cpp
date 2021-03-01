#include <iostream>
#include <climits>
using namespace std;

#define ll long long

class Sequence {
    public:
    ll totalSum,prefixSum,SuffixSum,maxSum;
};

void build_tree(Sequence *tree,ll *a,ll s,ll e,ll index) {
    if(s>e) {
        return;
    }
    if(s==e) {
        tree[index].maxSum = a[s];
        tree[index].prefixSum = a[s];
        tree[index].SuffixSum = a[s];
        tree[index].totalSum = a[s];
        return;
    }
    ll m = (s+e)/2;
    build_tree(tree,a,s,m,2*index);
    build_tree(tree,a,m+1,e,2*index+1);
    tree[index].maxSum = max(max(tree[2*index].maxSum,tree[2*index+1].maxSum),tree[2*index].SuffixSum+tree[2*index+1].prefixSum);
    tree[index].prefixSum = max(tree[2*index].totalSum+tree[2*index+1].prefixSum,tree[2*index].prefixSum);
    tree[index].SuffixSum = max(tree[2*index].SuffixSum+tree[2*index+1].totalSum,tree[2*index+1].SuffixSum);
    tree[index].totalSum = tree[2*index].totalSum+tree[2*index+1].totalSum;
    return;
}

Sequence query(Sequence *tree,ll ss,ll se,ll qs,ll qe,ll index) {
    if(qs>se || qe<ss) {
        Sequence tmp;
        tmp.prefixSum = INT_MIN;
        tmp.SuffixSum = INT_MIN;
        tmp.maxSum = INT_MIN;
        tmp.totalSum = INT_MIN;
        return tmp;
    }
    if(qs<=ss && qe>=se) {
        return tree[index];
    }
    ll m = (ss+se)/2;
    Sequence leftAns = query(tree,ss,m,qs,qe,2*index);
    Sequence rightAns = query(tree,m+1,se,qs,qe,2*index+1);
    Sequence tmp;
    tmp.maxSum = max(max(leftAns.maxSum,rightAns.maxSum),leftAns.SuffixSum+rightAns.prefixSum);
    tmp.prefixSum = max(leftAns.totalSum+rightAns.prefixSum,leftAns.prefixSum);
    tmp.SuffixSum = max(rightAns.totalSum+leftAns.SuffixSum,rightAns.SuffixSum);
    tmp.totalSum = leftAns.totalSum+rightAns.totalSum;
    return tmp;
}

int main() {
    ll n;
    cin>>n;
    ll *a = new ll[n];
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    Sequence *tree = new Sequence[4*n+1];
    build_tree(tree,a,0,n-1,1);
    ll q;
    cin>>q;
    while(q--) {
        ll l,r;
        cin>>l>>r;
        cout<<query(tree,0,n-1,l-1,r-1,1).maxSum<<endl;
    }
    return 0;
}
