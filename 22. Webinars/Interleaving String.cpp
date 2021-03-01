#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

#define mod 1000000007

bool isInterleav(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int> > &dp) {
	if (s1.length() + s2.length() != s3.length() ) {
		return false;
	}
	if (i == s1.length()) {
		return s2.substr(j) == s3.substr(k);
	}
	if (j == s2.length()) {
		return s1.substr(i) == s3.substr(k);
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	dp[i][j] = ( (s1[i] == s3[k] && isInterleav(s1, s2, s3, i + 1, j, k + 1, dp)) || (s2[j] == s3[k] && isInterleav(s1, s2, s3, i, j + 1, k + 1, dp)) );
	return dp[i][j];
}

bool isInterleave(string s1, string s2, string s3) {
	vector<vector<int> > dp(s1.length(), vector<int>(s2.length(), -1));
	return isInterleav(s1, s2, s3, 0, 0, 0, dp);
}

void solve() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	cout << isInterleave(s1, s2, s3);
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