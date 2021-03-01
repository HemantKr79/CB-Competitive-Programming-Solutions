#include<iostream>
#include<vector>
using namespace std;

int ans = 0;

bool isSafePosition(vector<vector<int> > &board,int i,int j,int n) {
	if(i<0 || j<0) {
		return true;
	}
	if(i>=n || j>=n) {
		return true;
	}
	return board[i][j]==0;
}

bool isSafe(vector<vector<int> > &board,int i,int j,int n) {
	if(!isSafePosition(board,i-2,j-1,n)) {
	    return false;
	}
	if(!isSafePosition(board,i-2,j+1,n)) {
	    return false;
	}
	if(!isSafePosition(board,i+2,j+1,n)) {
	    return false;
	}
	if(!isSafePosition(board,i+2,j-1,n)) {
	    return false;
	}
	if(!isSafePosition(board,i+1,j-2,n)) {
	    return false;
	}
	if(!isSafePosition(board,i+1,j+2,n)) {
	    return false;
	}
	if(!isSafePosition(board,i-1,j+2,n)) {
	    return false;
	}
	if(!isSafePosition(board,i-1,j-2,n)) {
	    return false;
	}
	return true;
}

void solution(vector<vector<int> > &board,int i,int j,int n,int knight) {
    if(knight==0) {
        ans++;
        return;
    }
	if(i==n) {
		return;
	}
	if(j==n) {
	    solution(board,i+1,0,n,knight);
	    return;
	}
	if(isSafe(board,i,j,n)) {
		board[i][j] = 1;
		solution(board,i,j+1,n,knight-1);
		board[i][j] = 0;
	}
	solution(board,i,j+1,n,knight);
}

void print_solution(vector<vector<int> > &board,int i,int j,int n,int knight) {
    if(knight==0) {
        for(int r=0;r<n;r++) {
            for(int c=0;c<n;c++) {
                if(board[r][c]==1) {
                    cout<<"{"<<r<<"-"<<c<<"} ";
                }
            }
        }
		cout<<" ";
        return;
    }
    if(i==n) {
        return;
    }
    if(j==n) {
        print_solution(board,i+1,0,n,knight);
        return;
    }
    if(isSafe(board,i,j,n)) {
        board[i][j] = 1;
        print_solution(board,i,j+1,n,knight-1);
        board[i][j] = 0;
    }
    print_solution(board,i,j+1,n,knight);
}

int main() {
	int n;
	cin>>n;
	vector<vector<int> > board(n,vector<int>(n,0));
	print_solution(board,0,0,n,n);
	solution(board,0,0,n,n);
	cout<<endl<<ans;
	return 0;
}