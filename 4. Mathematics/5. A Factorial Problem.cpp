#include<iostream>
#include<climits>
using namespace std;

#define ll long long

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,k;
		int ans = INT_MAX;
		cin>>n>>k;
		int occ = 1;
		for(int i=2;i*i<=k;i++) {
			if(k%i==0) {
				occ = 0;
				while(k%i==0) {
					occ++;
					k = k/i;
				}
				int p = i;
				int cnt = 0;
				int tmp = n/p;
				while(tmp>0) {
					cnt += tmp;
					tmp = tmp/p;
				}
				ans = min(ans,cnt/occ);
			}
		}
		if(k>1) {
			int p = k;
			int tmp = n/p;
			int cnt = 0;
			while(tmp>0) {
				cnt += tmp;
				tmp = tmp/p;
			}
			ans = min(ans,cnt);
		}
		if(ans==INT_MAX) {
			ans = 0;
		}
		cout<<ans<<endl;
	}
	return 0;
}