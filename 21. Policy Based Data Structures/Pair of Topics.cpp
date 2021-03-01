#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

void solve() {
	int n;
	cin>>n;
	vector<int> a(n),b(n),c(n);
	for(int i=0;i<n;i++) {
	    cin>>a[i];
	}
	for(int i=0;i<n;i++) {
	    cin>>b[i];
	    c[i] = a[i] - b[i];
	}
	int ans = 0;
	PBDS st;
	for(int i=0;i<n;i++) {
	    ans += (st.size() - st.order_of_key(make_pair(-c[i],1e6)));
	    st.insert(make_pair(c[i],i));
	}
	cout<<ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	solve();
	return 0;
}