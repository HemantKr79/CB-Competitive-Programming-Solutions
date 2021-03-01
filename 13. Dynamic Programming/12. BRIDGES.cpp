#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> &a,pair<int,int> &b) {
    if(a.first==b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<pair<int,int> > v(n);
		for(int i=0;i<n;i++) {
			cin>>v[i].first;
		}
		for(int i=0;i<n;i++) {
			cin>>v[i].second;
		}
		sort(v.begin(),v.end(),compare);
		vector<int> dp(n+1,1e9);
		dp[0] = -1e9;
		for(int i=0;i<n;i++) {
			int pos = upper_bound(dp.begin(),dp.end(),v[i].second) - dp.begin();
			if(dp[pos] > v[i].second && dp[pos-1] <= v[i].second) {
				dp[pos] = v[i].second;
			}
		}
		int len = 0;
		for(int i=0;i<=n;i++) {
			if(dp[i]!=1e9) {
				len = i;
			}
		}
		cout<<len<<"\n";
	}
	return 0;
}