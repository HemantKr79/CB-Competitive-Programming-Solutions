#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

#define mod 1000000007

int calculate_cost(vector<int> &captain, vector<int> &assistant, int i, int n_captain, int n_assistant, int n, vector<vector<int> > &dp) {
	if (i == n) {
		return 0;
	}
	if (dp[n_captain][n_assistant] != -1) {
		return dp[n_captain][n_assistant];
	}
	if (n_captain == n_assistant) {
		return dp[n_captain][n_assistant] = assistant[i] + calculate_cost(captain, assistant, i + 1, n_captain, n_assistant + 1, n, dp);
	}
	if (n_assistant == n / 2) {
		return dp[n_captain][n_assistant] = captain[i] + calculate_cost(captain, assistant, i + 1, n_captain + 1, n_assistant, n, dp);
	}
	return dp[n_captain][n_assistant] = min(assistant[i] + calculate_cost(captain, assistant, i + 1, n_captain, n_assistant + 1, n, dp), captain[i] + calculate_cost(captain, assistant, i + 1, n_captain + 1, n_assistant, n, dp));
}

void solve() {
	int n;
	cin >> n;
	vector<int> captain(n), assistant(n);
	for (int i = 0; i < n; i++) {
		cin >> captain[i] >> assistant[i];
	}
	vector<vector<int> > dp((n / 2) + 1, vector<int>((n / 2) + 1, -1));
	cout << calculate_cost(captain, assistant, 0, 0, 0, n, dp);
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