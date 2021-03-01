#include<iostream>
#include<string>
using namespace std;

#define ll long long

int gcd(int a,int b) {
	if(b==0) {
		return a;
	}
	return gcd(b,a%b);
}

void find_gcd(string m,int n) {
	ll ans = 0;
	for(int i=0;i<m.length();i++) {
		ans = (ans*10 + (m[i]-'0'))%n;
	}
	ans = (ans + n)%n;
	cout<<gcd(n,ans);
}

int main() {
	string m;
	int n;
	cin>>n;
	cin>>m;
	if(n!=0) {
		find_gcd(m,n);
	}
	else {
		cout<<m;
	}
	return 0;
}