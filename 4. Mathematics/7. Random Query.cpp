#include<iostream>
#include<unordered_map>
#include<iomanip>
using namespace std;

int main() {
	int n;
	cin>>n;
	int *arr = new int[n+1];
	unordered_map<int,int> last_occ;
	int *s = new int[n+1];
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
		last_occ[arr[i]] = 0;
	}
	s[1] = 1;
	last_occ[arr[1]] = 1;
	long long sum = s[1];
	for(int i=2;i<=n;i++) {
		s[i] = s[i-1] + (i-last_occ[arr[i]]);
		last_occ[arr[i]] = i;
		sum += s[i];
	}
	double ans = (2*(sum-n)+n)/(1.0*n*n);
	cout<<fixed<<setprecision(6)<<ans;
	delete [] arr;
	delete [] s;
	return 0;
}