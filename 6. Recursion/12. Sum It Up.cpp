#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

void solve(int *arr,int i,int *out,int j,int n,int target,set<vector<int> > &ans) {
	if(i==n) {
		int sum = 0;
		vector<int> v;
		for(int k=0;k<j;k++) {
			sum += out[k];
			v.push_back(out[k]);
		}
		if(sum==target) {
			sort(v.begin(),v.end());
			ans.insert(v);
		}
		return;
	}
	solve(arr,i+1,out,j,n,target,ans);
	out[j] = arr[i];
	solve(arr,i+1,out,j+1,n,target,ans);
}

int main() {
	int n;
	cin>>n;
	int *arr = new int[n];
	int *out = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	int target;
	cin>>target;
	set<vector<int> > ans;
	solve(arr,0,out,0,n,target,ans);
	for(auto a : ans) {
		for(auto item : a) {
			cout<<item<<" ";
		}
		cout<<endl;
	}
	return 0;
}