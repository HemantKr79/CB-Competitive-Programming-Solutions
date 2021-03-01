#include<iostream>
using namespace std;

int cross_inversion_count(int *a,int s,int e) {
	int m = (s+e)/2;
	int *tmp = new int[e-s+1];
	int i = s;
	int j = m+1;
	int k = 0;
	int cross_inversion = 0;
	while(i<=m && j<=e) {
		if(a[i]>a[j]) {		
			tmp[k++] = a[j++];
			cross_inversion += (m-i+1);
		}
		else {
			tmp[k++] = a[i++];
		}
	}
	while(i<=m) {
		tmp[k++] = a[i++];
	}
	while(j<=e) {
		tmp[k++] = a[j++];
	}
	k = 0;
	i = s;
	while(i<=e) {
		a[i++] = tmp[k++];
	}
	delete [] tmp;
	return cross_inversion;
}

int inversion_count(int *a,int s,int e) {
	if(s>=e) {
		return 0;
	}
	int m = (s+e)/2;
	int x = inversion_count(a,s,m);
	int y = inversion_count(a,m+1,e);
	int cross_inversion = cross_inversion_count(a,s,e);
	return x+y+cross_inversion;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *a = new int[n];
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}
		cout<<inversion_count(a,0,n-1)<<endl;
	}
	return 0;
}