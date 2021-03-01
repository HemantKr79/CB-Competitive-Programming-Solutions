#include<iostream>
#include<math.h>
using namespace std;
int main() {
	double ans = 0;
	for(int i=1;i<=6;i++) {
		ans = ans + (6.0)/(7.0-i);
	}
	cout<<ceil(ans);
	return 0;
}