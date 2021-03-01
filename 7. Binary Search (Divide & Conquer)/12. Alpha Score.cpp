#include<iostream>
#include<set>
using namespace std;

#define MOD 1000000007

int main() {
	int n;
	cin>>n;
	set<int> seen_stairs;
	long long ans = 0;
	int stair_number;
	for(int i=0;i<n;i++) {
		cin>>stair_number;
		for(auto item : seen_stairs) {
			if(item < stair_number) {
				ans = (ans + item)%MOD;
			}
			else {
				break;
			}
		}
		seen_stairs.insert(stair_number);
	}
	cout<<ans;
	return 0;
}