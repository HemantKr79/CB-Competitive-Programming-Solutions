#include<iostream>
using namespace std;

#define ll long long
#define N 1000000
int tot[N+1];

void seive() {
	for(int i=0;i<=N;i++) {
		tot[i] = i;
	}
	for(int i=2;i<=N;i++) {
		if(tot[i]==i) {
			for(int j=i;j<=N;j+=i) {
				tot[j] *= (i-1);
				tot[j] /= i;
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
		cout<<tot[n]<<endl;
	}
	return 0;
}