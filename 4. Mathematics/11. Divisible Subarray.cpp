#include<iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a;
		long long sum = 0;
		int *freq = new int[n]();
		freq[0] = 1;
		for(int i=0;i<n;i++) {
			cin>>a;
			sum += a;
			sum %= n;
			sum = (sum+n)%n;
			freq[sum]++;
		}
		long long ans = 0;
		for(int i=0;i<n;i++) {
			long long m = freq[i];
			ans += (m)*(m-1)/2;
		}
		delete [] freq;
		cout<<ans<<endl;
	}
	return 0;
}