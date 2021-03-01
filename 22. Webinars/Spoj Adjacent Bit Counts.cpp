#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

#define mod 1000000007

int dp[105][105][2];

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

int dp_solve(int n, int k , int first) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		if (k == 0) {
			return 1;
		}
		return 0;
	}
	if (dp[n][k][first] != -1) {
		return dp[n][k][first];
	}
	int retval = 0;
	if (first == 1) {
		retval = dp_solve(n - 1, k - 1, 1) + dp_solve(n - 1, k, 0);
	}
	else {
		retval = dp_solve(n - 1, k, 1) + dp_solve(n - 1, k, 0);
	}
	dp[n][k][first] = retval;
	return retval;
}

void solve() {
	int t;
	cin >> t;
	while (t--) {
		int testcase, n, k;
		cin >> testcase >> n >> k;
		memset(dp, -1, sizeof(dp));
		int x = dp_solve(n, k, 1) + dp_solve(n, k, 0);
		cout << testcase << " " << x << "\n";
	}
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