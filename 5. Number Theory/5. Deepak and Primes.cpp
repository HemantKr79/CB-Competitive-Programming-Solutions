#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

#define ll long long
#define N 8000000
bitset<N+1> b;
vector<int> primes;

void seive() {
	b.set();
	for(int i=2;i<=N;i+=2) {
		b[i] = 0;
	}
	primes.push_back(2);
	for(ll i=3;i<=N;i+=2) {
		if(b[i]==1) {
			primes.push_back(i);
			for(ll j=i*i;j<=N;j+=i) {
				b[j] = 0;
			}
		}
	}
	b[0] = b[1] = 0;
	b[2] = 1;
}

int main() {
	primes.reserve(5000000);
	seive();
	int n;
	cin>>n;
	cout<<primes[n-1];
	return 0;
}