#include<iostream>
using namespace std;

#define MOD 98765431

int main() {
	int n,t;
	cin>>n>>t;
	long long sum = 0;
	int *cows = new int[n];
	for(int i=0;i<n;i++) {
		cin>>cows[i];
		sum += cows[i];
	}
	while(t--) {
		long long tmp = 0;
		for(int i=0;i<n;i++) {
			cows[i] = ((sum-cows[i])%MOD+MOD)%MOD;
			tmp += cows[i];
		}
		sum = tmp;
	}
	for(int i=0;i<n;i++) {
		cout<<cows[i]<<endl;
	}
	return 0;
}