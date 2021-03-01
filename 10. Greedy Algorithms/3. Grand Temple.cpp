#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int *x = new int[n];
	int *y = new int[n];
	for(int i=0;i<n;i++) {
		cin>>x[i];
		cin>>y[i];
	}
	sort(x,x+n);
	sort(y,y+n);
	int dx = 0;
	int dy = 0;
	for(int i=1;i<n;i++) {
		dx = max(dx,x[i]-x[i-1]-1);
		dy = max(dy,y[i]-y[i-1]-1);
	}
	cout<<dx*dy;
	return 0;
}