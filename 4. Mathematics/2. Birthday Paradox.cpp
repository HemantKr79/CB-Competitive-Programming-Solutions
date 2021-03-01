#include<iostream>
using namespace std;

int main() {
	float p;
	cin>>p;
	float probOfDiffrent = 1.0f;
	if(p==float(1.0)) {
		cout<<366;
		return 0;
	}
	int n = 0;
	while( (1-probOfDiffrent) < p ) {
		probOfDiffrent *= float(365-n)/365;
		n++;
	}
	cout<<n;
	return 0;
}