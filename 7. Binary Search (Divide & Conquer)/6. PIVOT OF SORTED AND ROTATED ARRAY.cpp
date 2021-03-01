#include<iostream>
using namespace std;

int find_pivot(int *a,int s,int e) {
	int ans = s;
	while(s<=e) {
		int m = (s+e)/2;
		if(a[s]<=a[m]) {
			if(a[m+1]<a[m]) {
				ans = max(ans,m);
			}
			s = m+1;
		}
		else {
			e = m-1;
		}
	}
	return ans;
}

int main() {
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int pivot = find_pivot(a,0,n-1);
	cout<<pivot;
	return 0;
}
