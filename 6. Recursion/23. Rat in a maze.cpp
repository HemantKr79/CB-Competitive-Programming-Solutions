#include<iostream>
using namespace std;

int n,m;

bool rat_in_a_maze_helper(char maze[1000][1000],int solution[1000][1000],int i,int j) {
	if(i==n-1 && j==m-1) {
		solution[i][j] = 1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cout<<solution[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	if(i>n-1 || j>m-1) {
		return false;
	}
	if(maze[i][j] == 'X') {
		return false;
	}
	solution[i][j] = 1;
	bool smallAns1 = rat_in_a_maze_helper(maze,solution,i,j+1);
	if(smallAns1) {
		return true;
	}
	bool smallAns2 = rat_in_a_maze_helper(maze,solution,i+1,j);
	if(smallAns2) {
		return true;
	}
	solution[i][j] = 0;
	return false;
}

void rat_in_a_maze(char maze[1000][1000],int solution[1000][1000],int i,int j) {
	bool ans = rat_in_a_maze_helper(maze,solution,i,j);
	if(ans==false) {
		cout<<-1;
	}
}

int main() {
	cin>>n>>m;
	char maze[1000][1000];
	int solution[1000][1000];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>maze[i][j];
			solution[i][j] = 0;
		}
	}
	rat_in_a_maze(maze,solution,0,0);
	return 0;
}