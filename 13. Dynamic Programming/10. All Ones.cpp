#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestSquareSide(vector<int>& heights) {
	vector<int> left(heights.size());
	vector<int> right(heights.size());
	stack<int> s;
	for(int i=0;i<heights.size();i++) {
		while(!s.empty() && heights[i] <= heights[s.top()]) {
			s.pop();
		}
		if(s.empty()) {
			left[i] = -1;
		}
		else {
			left[i] = s.top();
		}
		s.push(i);
	}
	while(!s.empty()) {
		s.pop();
	}
	for(int i=heights.size()-1;i>=0;i--) {
		while(!s.empty() && heights[i] <= heights[s.top()]) {
			s.pop();
		}
		if(s.empty()) {
			right[i] = heights.size();
		}
		else {
			right[i] = s.top();
		}
		s.push(i);
	}
	int ans = 0;
	for(int i=0;i<heights.size();i++) {
		if( (right[i]-left[i]-1) == heights[i] ) {
			ans = max(ans,heights[i]);
		}
	}
	return ans;
}

int maximalSide(vector<vector<char> > &matrix) {
	vector<int> heights(matrix[0].size(),0);
	int ans = 0;
	for(int i=0;i<matrix.size();i++) {
		for(int j=0;j<matrix[i].size();j++) {
			if(matrix[i][j]=='0') {
				heights[j] = 0;
			}
			else {
				heights[j] += 1;
			}
		}
		ans = max(ans,largestSquareSide(heights));
	}
	return ans;
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<vector<char> > matrix(n,vector<char>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>matrix[i][j];
		}
	}
	cout<<maximalSide(matrix);
	return 0;
}