#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2) {
	if(p1.first+p1.second==p2.first+p2.second) {
		return p1.first-p1.second>p2.first-p2.second;
	}
	return p1.first+p1.second<p2.first+p2.second;
}

int main() {
	int n;
	cin>>n;
	pair<int,int> *circles = new pair<int,int>[n];
	for(int i=0;i<n;i++) {
		cin>>circles[i].first;
		cin>>circles[i].second;
	}
	sort(circles,circles+n,compare);
	int ans = 0;
	int last_circle = INT_MIN;
	for(int i=0;i<n;i++) {
		if(circles[i].first-circles[i].second>=last_circle) {
			last_circle = circles[i].first + circles[i].second;
		}
		else {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}