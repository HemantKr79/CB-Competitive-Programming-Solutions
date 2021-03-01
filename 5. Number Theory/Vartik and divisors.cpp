#include<iostream>
#include<unordered_map>
using namespace std;

#define N 100001
#define ll long long

ll *ans = new ll[N]();
int *factorize = new int[N]();
unordered_map<int,ll> m;

ll power(int a,int p) {
	ll ans = 1;
	ll tmp = 1;
	while(p>0) {
		if(p&1) {
			ans *= tmp;
		}
		tmp *= a;
		p = p>>1;
	}
	return ans;
}

ll gp(int base,int n) {
	ll ans = (power(base,n-1)-1)/(base-1);
	return ans;
}

void seive() {
	factorize[0] = 0;
	factorize[1] = 1;
	for(int i=2;i<N;i++) {
		factorize[i] = 2;
	}
	m.insert(make_pair(2,0));
	for(ll i=3;i<N;i+=2) {
		if(factorize[i]==0) {
			factorize[i] = i;
			m.insert(make_pair(i,0));
			for(ll j=i*i;j<N;j+=i) {
				factorize[j] = i;
			}
		}
	}
}

void init() {
	for(int i=1;i<N;i++) {
		int temp = i;
		while(factorize[temp]!=1) {
			m[factorize[temp]]++;
			temp /= factorize[temp];
		}
		ll divisors = 0;
		for(auto item : m) {
			if(item.second!=0) {
				divisors *= gp(item.first,item.second);
			}
			item.second = 0;
		}
		ans[i] = divisors;
	}
}

int main() {
	seive();
	init();
	int num;
	while(true) {
		cin>>num;
		if(num==0) {
			break;
		}
		int a = ans[num];
		if(ans[num]==0) {
			cout<<-1<<endl;
		}
		else {
			cout<<ans[num]<<endl;
		}
	}
	cout<<power(2,5)<<endl;
	for(int i=0;i<10;i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}