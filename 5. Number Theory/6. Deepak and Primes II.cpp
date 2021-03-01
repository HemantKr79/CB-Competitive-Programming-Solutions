#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

#define ll long long
#define N 10000001
bitset<N> b;
vector<ll> primes;

void seive() {
	b.set();
	b[0] = b[1] = 0;
	primes.push_back(2);
	for(int i=4;i<N;i+=2) {
		b[i] = 0;
	}
	for(ll i=3;i<N;i+=2) {
		if(b[i]==1) {
			primes.push_back(i);
			for(ll j=i*i;j<N;j+=i) {
				b[j] = 0;
			}
		}
	}
}

int main() {
	seive();
	int t;
	cin>>t;
	while(t--) {
		int m,n;
		cin>>m>>n;
		int nums[n-m+1];
		for(int i=0;i<n-m+1;i++) {
			nums[i] = 1;
		}
		for(auto p : primes) {
			if(p*p > n) {
				break;
			}
			ll start = (m/p)*p;
			if(p>=m && p<=n) {
				start = 2*p;
			}
			if(start<m) {
				start += p;
			}
			while(start<=n) {
				nums[start-m] = 0;
				start += p;
			}
		}
		for(int i=0;i<n-m+1;i++) {
			if(nums[i]==1 && (m+i)!=1) {
				cout<<m+i<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}