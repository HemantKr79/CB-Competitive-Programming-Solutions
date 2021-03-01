#include<iostream>
using namespace std;

int help_rahul(int *a,int s,int e,int key) {
	while(s<=e) {
		int m = (s+e)/2;
		if(a[m]==key) {
			return m;
		}
		else if(a[s]<=a[m]) {
		    if(a[s]<=key && key<=a[m]) {
				e = m-1;
			}
			else {
				s = m+1;
			}
		}
		else {
			if(a[e]>=key && key>=a[m]) {
				s = m+1;
			}
			else {
				e = m-1;
			}
		}
	}
	return -1;
}

int main() {
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int key;
	cin>>key;
	int index = help_rahul(a,0,n-1,key);
	cout<<index;
	return 0;
}
