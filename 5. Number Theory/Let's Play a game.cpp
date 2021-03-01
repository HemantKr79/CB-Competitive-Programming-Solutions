#include<iostream>
using namespace std;

#define ll long long
#define N 501
int a[N];
int cnt[N];

void init() {
	for(int i=0;i<N;i++) {
		a[i] = 1;
		cnt[i] = 0;
	}
}

void seive() {
	a[0] = 0;
	a[1] = 1;
	for(int i=2;i<N;i+=2) {
		a[i] = 2;
	}
	for(int i=3;i<N;i+=2) {
		if(a[i]==1) {
			for(int j=i*i;j<N;j+=i) {
				a[j] = i;
			}
		}
	}
}

int main() {
	init();
	seive();
	int n;
	cin>>n;
	for(int i=2;i<=n;i++) {
		int tmp = i;
		while(a[tmp]!=1) {
			tmp /= a[tmp];
			cnt[a[tmp]]++;
		}
	}
	int nInC = 0;
	for(int i=0;i<N;i++) {
		if(cnt[i]!=0) {
			nInC++;
		}
	}
	cout<<(1<<(nInC-1));
	return 0;
}