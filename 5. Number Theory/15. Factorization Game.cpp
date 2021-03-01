#include<iostream>
#include<vector>
using namespace std;

#define N 1000001
#define ll long long
vector<ll> cnt(N,0);

bool winner(ll arr[],int n) {
	for(int i=0;i<N;i++) {
		cnt[i] = 0;
	}
	for(int i=0;i<n;i++) {
		if(arr[i]==1) {
			continue;
		}
		for(ll j=2;j*j<=arr[i];j++) {
			while(arr[i]%j==0) {
				cnt[j]++;
				arr[i] /= j;
			}
		}
		if(arr[i]!=1) {
			cnt[arr[i]]++;
		}
	}
	ll x = 0;
	for(int i=1;i<N;i++) {
		x = x^cnt[i];
	}
	return (x!=0);
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		ll *arr = new ll[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		if(winner(arr,n)) {
			cout<<"Mancunian"<<endl;
		}
		else {
			cout<<"Liverbird"<<endl;
		}
	}
	return 0;
}