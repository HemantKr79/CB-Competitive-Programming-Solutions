#include<iostream>
#include<map>
#include<vector>
using namespace std;

#define MOD 1000000007
#define ll long long
int divisor[10000001] = {0};
vector<ll> primes;

void seive() {
	for(int i=2;i<10000001;i+=2) {
		divisor[i] = 2;
	}
	primes.push_back(2);
	for(ll i=3;i<10000001;i+=2) {
		if(divisor[i]==0) {
			primes.push_back(i);
			divisor[i] = i;
			for(ll j=i*i;j<10000001;j+=i) {
				divisor[j] = i;
			}
		}
	}
}

int main() {
	seive();
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		map<int,int> factors;
		while(n--) {
			int a;
			cin>>a;
			while(a!=1) {
				factors[divisor[a]]++;
				a = a/divisor[a];
			}
		}
		ll ans = 1;
		for(auto p : factors) {
			ans = (ans*(p.second+1))%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}