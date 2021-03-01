#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int *mike = new int[n];
	for(int i=0;i<n;i++) {
		cin>>mike[i];
	}
	if(n>=130) {
		delete [] mike;
		cout<<"YES";
		return 0;
	}
	for(int i=0;i<n-3;i++) {
		for(int j=i+1;j<n-2;j++) {
			for(int k=j+1;j<n-1;j++) {
				for(int l=k+1;l<n;l++) {
					int res = mike[i]^mike[j]^mike[k]^mike[l];
					if(res==0) {
						cout<<"YES";
						delete [] mike;
						return 0;
					}
				}
			}
		}
	}
	delete [] mike;
	cout<<"NO";
	return 0;
}