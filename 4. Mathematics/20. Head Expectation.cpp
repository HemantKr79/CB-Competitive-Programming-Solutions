#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	long long ans = 0;
	ans = (1<<(n+1)) - 2;
	cout<<ans;
	return 0;
}