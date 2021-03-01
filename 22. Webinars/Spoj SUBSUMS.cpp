#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

#define mod 1000000007

int two_nCn(int n) {
	int num = 1;
	int deno = 1;
	for (int i = 1; i <= n; i++) {
		num *= (n + i);
		deno *= i;
		int g = __gcd(num, deno);
		num /= g;
		deno /= g;
		num %= mod;
		deno %= mod;
	}
	return num;
}

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

void sums(vector<int> &v, vector<int> &s) {
	int n = v.size();
	for (int i = 0; i < (1 << n); i++) {
		int j = 0;
		int tmp = i;
		int sum = 0;
		while (tmp > 0) {
			if (tmp & 1) {
				sum += v[j];
			}
			tmp = tmp >> 1;
			j++;
		}
		s.push_back(sum);
	}
}

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	int n1 = n / 2;
	int n2 = n - n1;
	vector<int> v1(n1);
	vector<int> v2(n2);
	for (int i = 0; i < n1; i++) {
		cin >> v1[i];
	}
	for (int i = 0; i < n2; i++) {
		cin >> v2[i];
	}
	vector<int> s1;
	s1.reserve((1 << n1));
	vector<int> s2;
	s2.reserve((1 << n2));
	sums(v1, s1);
	sums(v2, s2);
	sort(s2.begin(), s2.end());
	int ans = 0;
	for (int i = 0; i < s1.size(); i++) {
		int lo = lower_bound(s2.begin(), s2.end(), a - s1[i]) - s2.begin();
		int up = upper_bound(s2.begin(), s2.end(), b - s1[i]) - s2.begin();
		ans += up - lo;
	}
	cout << ans;
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