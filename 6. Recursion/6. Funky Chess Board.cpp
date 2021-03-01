#include<iostream>
using namespace std;

int ans = 0;

void solve(int **board,int i,int j,int n,int cnt) {
	if(i<0 || j<0) {
		return;
	}
	if(i>=n || j>=n) {
		return;
	}
	if(board[i][j]==0) {
		return;
	}
	else {
		ans = max(cnt+1,ans);
		board[i][j] = 0;
		solve(board,i-2,j-1,n,cnt+1);
		solve(board,i-2,j+1,n,cnt+1);
		solve(board,i-1,j-2,n,cnt+1);
		solve(board,i-1,j+2,n,cnt+1);
		solve(board,i+1,j-2,n,cnt+1);
		solve(board,i+1,j+2,n,cnt+1);
		solve(board,i+2,j-1,n,cnt+1);
		solve(board,i+2,j+1,n,cnt+1);
		board[i][j] = 1;
	}
}

int main() {
	int n;
	cin>>n;
	int **board = new int*[n];
	int cnt1 = 0;
	for(int i=0;i<n;i++) {
		board[i] = new int[n];
		for(int j=0;j<n;j++) {
			cin>>board[i][j];
			if(board[i][j]==1) {
				cnt1++;
			}
		}
	}
	solve(board,0,0,n,0);
	cout<<cnt1-ans;
	for(int i=0;i<n;i++) {
		delete [] board[i];
	}
	delete [] board;
	return 0;
}