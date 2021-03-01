#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
	vector<int> left(heights.size());
	vector<int> right(heights.size());
	stack<int> s;
	for (int i = 0; i < heights.size(); i++) {
		while (!s.empty() && heights[i] <= heights[s.top()]) {
			s.pop();
		}
		if (s.empty()) {
			left[i] = -1;
		}
		else {
			left[i] = s.top();
		}
		s.push(i);
	}
	while (!s.empty()) {
		s.pop();
	}
	for (int i = heights.size() - 1; i >= 0; i--) {
		while (!s.empty() && heights[i] <= heights[s.top()]) {
			s.pop();
		}
		if (s.empty()) {
			right[i] = heights.size();
		}
		else {
			right[i] = s.top();
		}
		s.push(i);
	}
	int ans = 0;
	for (int i = 0; i < heights.size(); i++) {
		ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
	}
	return ans;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.size() == 0) {
		return 0;
	}
	vector<int> heights(matrix[0].size());
	int ans = 0;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == '0') {
				heights[j] = 0;
			}
			else {
				heights[j] += 1;
			}
		}
		ans = max(ans, largestRectangleArea(heights));
	}
	return ans;
}

int main() {
	int r,c;
	cin>>r>>c;
	vector<vector<char> > matrix(r,vector<char>(c));
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			cin>>matrix[i][j];
		}
	}
	cout<<maximalRectangle(matrix);
	return 0;
}