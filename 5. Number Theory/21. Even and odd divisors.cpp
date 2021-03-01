#include<iostream>
#include<unordered_map>
using namespace std;

#define N 100001
#define ll long long
int *factorize = new int[N]();

void seive() {
	factorize[0] = 0;
	factorize[1] = 1;
	for(int i=2;i<N;i+=2) {
		factorize[i] = 2;
	}
	for(ll i=3;i<N;i+=2) {
		if(factorize[i]==0) {
			factorize[i] = i;
			for(ll j=i*i;j<N;j+=i) {
				factorize[j] = i;
			}
		}
	}
}

ll power(ll a,ll n) {
	ll ans = 1;
	ll tmp = a;
	while(n>0) {
		if(n&1) {
			ans *= tmp;
		}
		tmp *= tmp;
		n = n>>1;
	}
	return ans;
}

ll gp(ll r,ll n) {
	ll ans = (power(r,n+1)-1)/(r-1);
	return ans;
}

ll solve(int n) {
	unordered_map<int,int> m;
	while(factorize[n]!=1) {
		m[factorize[n]]++;
		n /= factorize[n];
	}
	ll even_sum = 0;
	ll odd_sum = 1ll;
	if(m.count(2)) {
		ll sum_of_2 = gp(2,m[2]);
		even_sum = sum_of_2-1;	
	}
	ll sum_of_rest_terms = 1;
	for(auto item : m) {
		if(item.first == 2) {
			continue;
		}
		sum_of_rest_terms *= gp(item.first,item.second);
	}
	ll ans = (even_sum-odd_sum)*sum_of_rest_terms;
	return ans;
}

int main() {
	seive();
	int q;
	cin>>q;
	while(q--) {
		int n;
		cin>>n;
		cout<<solve(n)<<endl;
	}
	return 0;
}