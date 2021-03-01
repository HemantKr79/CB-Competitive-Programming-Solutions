#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

#define mod 1000000007

int powr(int a, int b) {
	int res = 1;
	int tmp = a;
	while (b > 0) {
		if (b & 1) {
			res *= tmp;
			res %= mod;
		}
		tmp *= tmp;
		tmp %= mod;
		b = b >> 1;
	}
	return res;
}

int numberOfArithmeticSlices(vector<int>& A) {
	int n = A.size();
	int dp = 0;
	int res = 0;
	for (int i = 2; i < n; i++) {
		if ( (A[i] - A[i - 1]) == (A[i - 1] - A[i - 2]) ) {
			dp = 1 + dp;
			res += dp;
		}
		else {
			dp = 0;
		}
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << numberOfArithmeticSlices(v);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}