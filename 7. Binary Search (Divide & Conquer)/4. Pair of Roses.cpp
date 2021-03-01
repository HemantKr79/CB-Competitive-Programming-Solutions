#include<iostream>
#include<set>
using namespace std;

class set_compare {
	public:
	bool operator()(pair<int,int> p1,pair<int,int> p2) {
		return (p1.second - p1.first)<(p2.second - p2.first);
	}
};

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *roses = new int[n];
		for(int i=0;i<n;i++) {
			cin>>roses[i];
		}
		int money;
		cin>>money;
		set<pair<int,int>,set_compare> ans;
		for(int i=0;i<n-1;i++) {
			for(int j=i+1;j<n;j++) {
				if(roses[i]+roses[j]==money) {
					ans.insert(make_pair(min(roses[i],roses[j]),max(roses[i],roses[j])));
				}
			}
		}
		cout<<"Deepak should buy roses whose prices are "<<(*ans.begin()).first<<" and "<<(*ans.begin()).second<<"."<<endl;
	}
	return 0;
}