#include<iostream>
using namespace std;

#define ll long long

int main() {
	int n;
	cin>>n;
	ll x = 0;
	ll *arr = new ll[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		x = x^arr[i];
	}
	ll ans = x;
	ll new_arr_xor = 0;
	for(int i=0;i<n;i++) {
		new_arr_xor = x^arr[i];
		ans = max(ans,new_arr_xor);
	}
	cout<<ans;
	return 0;
}