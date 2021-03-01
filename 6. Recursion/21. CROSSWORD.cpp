#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

int maxlen = 0;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void crossword_solver(set<string> &dict,vector<string> &crossword,vector<vector<bool> > &visited,set<string> &ans,string &tmp,int i,int j,int m) {
	if(i<0 || j<0 || i>=m || j>=m) {
		return;
	}
	if(visited[i][j]) {
		return;
	}
	if(tmp.length() > maxlen) {
		return;
	}
	visited[i][j] = true;
	tmp.push_back(crossword[i][j]);
	auto it = dict.find(tmp);
	if(it!=dict.end()) {
		ans.insert(tmp);
		dict.erase(it);
	}
	int new_i,new_j;
	for(int x=0;x<8;x++) {
		new_i = i + dx[x];
		new_j = j + dy[x];
		crossword_solver(dict,crossword,visited,ans,tmp,new_i,new_j,m);
	}
	tmp.pop_back();
	visited[i][j] = false;
}

int main() {
	int n,m;
	cin>>n;
	set<string> dict;
	string s;
	for(int i=0;i<n;i++) {
		cin>>s;
		if(s.length() > maxlen) {
			maxlen = s.length();
		}
		dict.insert(s);
	}
	cin>>m;
	vector<string> crossword(m);
	for(int i=0;i<m;i++) {
		cin>>crossword[i];
	}
	set<string> ans;
	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++) {
			string tmp;
			vector<vector<bool> > visited(m,vector<bool>(m,false));
			crossword_solver(dict,crossword,visited,ans,tmp,i,j,m);
		}
	}
	for(auto item : ans) {
		cout<<item<<" ";
	}
	return 0;
}