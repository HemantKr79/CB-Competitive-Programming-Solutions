#include<iostream>
#include<unordered_map>
using namespace std;

#define N 100001
#define ll long long
int *factorize = new int[N]();
unordered_map<ll,ll> solver;

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

void init() {
	unordered_map<int,int> m;
	for(ll i=1;i<N;i++) {
		ll tmp = i;
		while(factorize[tmp]!=1) {
			m[factorize[tmp]]++;
			tmp /= factorize[tmp];
		}
		ll sum_of_divisors = 1;
		for(auto item : m) {
			sum_of_divisors *= gp(item.first,item.second);
		}
		solver[sum_of_divisors] = i;
		m.clear();
	}	
}

int main() {
	seive();
	init();
	ll num;
	while(true) {
		cin>>num;
		if(num==0) {
			break;
		}
		if(solver.count(num)) {
			cout<<solver[num]<<endl;
		}
		else {
			cout<<-1<<endl;
		}
	}
	return 0;
}