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

int longestPalindromeSubseq(string s) {
	int n = s.length();
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[0][n - 1];
}

void solve() {
	string str;
	cin >> str;
	cout << longestPalindromeSubseq(str);
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