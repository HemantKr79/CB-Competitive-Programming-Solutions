#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int n;
	cin>>n;
	double ans = (0.09)*n;
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}