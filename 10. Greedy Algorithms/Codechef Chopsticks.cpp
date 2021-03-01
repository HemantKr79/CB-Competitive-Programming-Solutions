#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,d;
	cin>>n>>d;
	int *chopsticks = new int[n];
	for(int i=0;i<n;i++) {
	    cin>>chopsticks[i];
	}
	sort(chopsticks,chopsticks+n);
	int i = 0;
	int ans = 0;
	while(i<n-1) {
	    int diff = chopsticks[i+1] - chopsticks[i];
	    if(diff<=d) {
	        ans++;
	        i += 2;
	    }
	    else {
	        i += 1;
	    }
	}
	cout<<ans;
	return 0;
}
