#include<iostream>
using namespace std;

long long power(long long ans,long long p,long long mod) {
	if(p==1) {
		return ans;
	}
	if(p&1) {
		return (ans*power(ans,p-1,mod))%mod;
	}
	long long tmp = power(ans,p/2,mod)%mod;
	return (tmp*tmp)%mod;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		long long a,n,p;
		cin>>a;
		cin>>n;
		cin>>p;
		long long ans = a%p;
		for(int i=2;i<=n;i++) {
			ans = power(ans,i,p)%p;
		}
		cout<<ans<<endl;
	}
	return 0;
}