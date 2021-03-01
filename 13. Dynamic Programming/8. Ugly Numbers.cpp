#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define int long long

int32_t main() {
	int t;
	cin>>t;
	vector<pair<int,int> > testcases(t);
	for(int i=0;i<t;i++) {
		cin>>testcases[i].first;
		testcases[i].second = i;
	}
	sort(testcases.begin(),testcases.end());
	vector<int> ans(t);
	set<int> ugly_numbers;
	set<int> possible_numbers;
	possible_numbers.insert(1);
	for(int i=0;i<t;i++) {
		while(ugly_numbers.size() != testcases[i].first) {
			int curr_ugly_number = *possible_numbers.begin();
			possible_numbers.erase(curr_ugly_number);
			ugly_numbers.insert(curr_ugly_number);
			possible_numbers.insert(2*curr_ugly_number);
			possible_numbers.insert(3*curr_ugly_number);
			possible_numbers.insert(5*curr_ugly_number);
		}
		ans[testcases[i].second] = *prev(ugly_numbers.end());
	}
	for(int i=0;i<t;i++) {
		cout<<ans[i]<<"\n";
	}
	return 0;
}