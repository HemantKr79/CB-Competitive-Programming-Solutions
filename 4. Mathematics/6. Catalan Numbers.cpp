#include<iostream>
#include<algorithm>
using namespace std;

void printCatalan(int n) {
	int N = 2*n;
	int R = n;
	long long num = 1;
	long long deno = 1;
	if(R!=0) {
		while(R>0) {
			num *= N;
			deno *= R;
			long long gcd = __gcd(num,deno);
			num = num/gcd;
			deno = deno/gcd;
			N--;
			R--;
		}
	}
	else {
		num = 1;
	}
	long long catalan = num/(1+n);
	cout<<catalan;
}

int main() {
	int n;
	cin>>n;
	printCatalan(n);
	cout<<endl;
	return 0;
}