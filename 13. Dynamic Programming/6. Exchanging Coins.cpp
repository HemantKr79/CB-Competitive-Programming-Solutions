#include<iostream>
#include<unordered_map>
using namespace std;

#define int long long

int solve(int n,unordered_map<int,int> &m) {
	if(n<12) {
		return n;
	}
	if(m.count(n)) {
		return m[n];
	}
	return m[n] = max(n,solve(n/2,m) + solve(n/3,m) + solve(n/4,m));
}

int32_t main() {
	int n;
	cin>>n;
	unordered_map<int,int> m;
	cout<<solve(n,m);
	return 0;
}