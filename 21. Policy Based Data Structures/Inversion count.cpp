#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

int main() {
	PBDS st;
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
	    cin>>arr[i];
	}
	int inversion_cnt = 0;
	for(int i=0;i<n;i++) {
	    inversion_cnt += (st.size() - (st.order_of_key(arr[i])));
	    st.insert(arr[i]);
	}
	cout<<inversion_cnt;
	delete [] arr;
	return 0;
}
