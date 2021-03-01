#include<iostream>
#include<algorithm>
using namespace std;

void solve(int *arr,int n) {
	do {
		for(int i=0;i<n;i++) {
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	while(next_permutation(arr,arr+n));
}

int main() {
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	sort(arr,arr+n);
	solve(arr,n);
	return 0;
}