#include<iostream>
using namespace std;

int pow(int n,int p) {
	if(p==0) {
		return 1;
	}
	int smallAns = pow(n,p/2);
	if(p&1) {
		return n*smallAns*smallAns;
	}
	return smallAns*smallAns;
}

int main() {
	int n,p;
	cin>>n>>p;
	cout<<pow(n,p);
	return 0;
}