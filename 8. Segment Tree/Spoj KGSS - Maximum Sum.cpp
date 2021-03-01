#include <iostream>
#include <climits>
using namespace std;
 
#define ll long long
 
void build_tree(pair<ll,ll> *tree,ll *a,ll s,ll e,ll index) {
    if(s==e) {
        tree[index] = make_pair(a[s],0);
        return;
    }
    ll m = (s+e)/2;
    build_tree(tree,a,s,m,2*index);
    build_tree(tree,a,m+1,e,2*index+1);
    tree[index].first = max(tree[2*index].first,tree[2*index+1].first);
    tree[index].second = max(min(tree[2*index].first,tree[2*index+1].first),max(tree[2*index].second,tree[2*index+1].second));
}
 
pair<ll,ll> make_query(pair<ll,ll> *tree,ll ss,ll se,ll qs,ll qe,ll index) {
    if(qe<ss || se<qs) {
        return make_pair(0,0);
    }
    if(ss>=qs && qe>=se) {
        return tree[index];
    }
    ll m = (ss+se)/2;
    pair<ll,ll> leftAns = make_query(tree,ss,m,qs,qe,2*index);
    pair<ll,ll> rightAns = make_query(tree,m+1,se,qs,qe,2*index+1);
    pair<ll,ll> ans;
    ans.first = max(leftAns.first,rightAns.first);
    ans.second =  max(min(leftAns.first,rightAns.first),max(leftAns.second,rightAns.second));
    return ans;
}
 
void point_update(pair<ll,ll> *tree,ll ss,ll se,ll pos,ll update,ll index) {
    if(pos<ss || se<pos) {
        return;
    }
    if(ss==se) {
        tree[index].first = update;
        return;
    }
    ll m = (ss+se)/2;
    point_update(tree,ss,m,pos,update,2*index);
    point_update(tree,m+1,se,pos,update,2*index+1);
    tree[index].first = max(tree[2*index].first,tree[2*index+1].first);
    tree[index].second = max(min(tree[2*index].first,tree[2*index+1].first),max(tree[2*index].second,tree[2*index+1].second));
}
 
int main() {
    ll n;
    cin>>n;
    ll *a = new ll[n];
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    pair<ll,ll> *tree = new pair<ll,ll>[4*n+1];
    build_tree(tree,a,0,n-1,1);
    ll q;
    cin>>q;
    while(q--) {
        char c;
        cin>>c;
        if(c=='Q') {
            ll qs,qe;
            cin>>qs>>qe;
            pair<ll,ll> ans = make_query(tree,0,n-1,qs-1,qe-1,1);
            ll answer = ans.first + ans.second;
            cout<<answer<<endl;
        }
        else {
            ll pos,update;
            cin>>pos>>update;
            point_update(tree,0,n-1,pos-1,update,1);
        }
    }
    return 0;
}
 