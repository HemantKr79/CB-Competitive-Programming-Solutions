#include<iostream>
using namespace std;
bool solve(int *arr,int i,int *out,int j,int n) {
	if(i==n) {
		if(j==0) {
			return false;
		}
		int sum = 0;
		for(int k=0;k<j;k++) {
			sum += out[k];
		}
		return sum==0;
	}
	if(solve(arr,i+1,out,j,n)) {
		return true;
	}
	out[j] = arr[i];
	if(solve(arr,i+1,out,j+1,n)) {
		return true;
	}
	return false;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *arr = new int[n];
		int *out = new int[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		bool ans = solve(arr,0,out,0,n);
		if(ans) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	return 0;
}