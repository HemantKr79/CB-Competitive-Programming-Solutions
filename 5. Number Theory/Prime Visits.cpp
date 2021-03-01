#include <iostream>
using namespace std;

#define ll long long

void prime_seive(int *p) {
    for(int i=3;i<=1000000;i+=2) {
        p[i] = 1;
    }
    for(ll i=3;i<=1000000;i+=2) {
        if(p[i]==1) {
            for(ll j=i*i;j<=1000000;j+=i) {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[0] = p[1] = 0;
}

int main() {
	int *prime = new int[1000006]();
	prime_seive(prime);
	int *cumulativeSum = new int[1000006]();
	cumulativeSum[0] = 0;
	for(int i=1;i<1000005;i++) {
	    cumulativeSum[i] = cumulativeSum[i-1] + prime[i];
	}
	int t;
	cin>>t;
	while(t--) {
	    int a,b;
	    cin>>a>>b;
	    cout<<cumulativeSum[b] - cumulativeSum[a-1];
	    cout<<endl;
	}
	delete [] prime;
	delete [] cumulativeSum;
	return 0;
}
