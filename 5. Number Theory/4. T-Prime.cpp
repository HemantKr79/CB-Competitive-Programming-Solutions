#include<iostream>
#include<unordered_set>
#include<bitset>
using namespace std;

#define ll long long
unordered_set<ll> s;
bitset<1000005> b;

void seive() {
	b.set();
	b[0] = b[1] = 0;
	s.insert(2*2);
	for(int i=4;i<=1000000;i+=2) {
		b[i] = 0;
	}
	for(ll i=3;i<=1000000;i+=2) {
		if(b[i]==1) {
			s.insert(i*i);
			for(ll j=i*i;j<=1000000;j+=i) {
				b[j] = 0;
			}
		}
	}
}

int main() {
	seive();
	int n;
	cin>>n;
	ll num;
	for(int i=0;i<n;i++) {
		cin>>num;
		if(s.find(num)!=s.end()) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}