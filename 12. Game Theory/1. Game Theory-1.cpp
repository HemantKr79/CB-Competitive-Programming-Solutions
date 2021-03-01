#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

unordered_map<int,int> dp;

int calculate_mex(unordered_set<int> &s) {
	int mex = 0;
	while(s.find(mex)!=s.end()) {
		++mex;
	}
	return mex;
}

int calculate_grundy(int n) {
	if(n==0 || n==1) {
		return 0;
	}
	if(dp.count(n)) {
		return dp[n];
	}
	unordered_set<int> s;
	for(int i=1;i<=(n/2);i++) {
		if(n%i==0) {
			s.insert(calculate_grundy(i));
		}
	}
	return dp[n] = calculate_mex(s);
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		if(n%2==0) {
			cout<<2;
		}
		else {
			int grundy_m = calculate_grundy(m);
			if(grundy_m==0) {
				cout<<2;
			}
			else {
				cout<<1;
			}
		}
		cout<<"\n";
	}
	return 0;
}