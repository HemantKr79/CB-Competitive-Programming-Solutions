#include<iostream>
using namespace std;

// We are provided with 2N+1 numbers
// All numbers occour twice expect an unique number
// We have to find the unique number

int main() {
	int n;
	int no;
	cin>>n;
	int ans = 0;
	for(int i=0;i<n;i++) {
		cin>>no;
		ans = ans^no;
	}
	cout<<ans;
	return 0;
}