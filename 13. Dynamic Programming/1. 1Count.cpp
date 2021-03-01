#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++) {
		cin>>v[i];
	}
	int max_len = 0;
	int l = 0;
	int r = -1;
	int zero_count = 0;
	bool karnah = false;
	int x,y;
	while(r+1<n) {
		if(v[r+1]==0) {
			++zero_count;
		}
		++r;
		while(zero_count > k) {
			if(v[l]==0) {
				--zero_count;
			}
			++l;
		}
		if( (r-l+1) > max_len) {
			max_len = r-l+1;
			x = l;
			y = r;
			karnah = true;
		}
	}
	cout<<max_len<<"\n";
	if(karnah) {
		for(int i=x;i<=y;i++) {
			v[i] = 1;
		}
	}
	for(int i=0;i<n;i++) {
		cout<<v[i]<<" ";
	}
	return 0;
}