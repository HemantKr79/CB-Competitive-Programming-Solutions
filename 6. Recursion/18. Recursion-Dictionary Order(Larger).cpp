#include<iostream>
#include<set>
using namespace std;

void solve(char *input,int i,set<string> &ans) {
	if(input[i]=='\0') {
		string str(input);
		ans.insert(input);
		return;
	}
	for(int x=i;input[x]!='\0';x++) {
		swap(input[i],input[x]);
		solve(input,i+1,ans);
		swap(input[i],input[x]);
	}
}

int main() {
	char input[11];
	cin>>input;
	set<string> ans;
	solve(input,0,ans);
	string input_str(input);
	for(auto s : ans) {
		if(s>input_str) {
			cout<<s<<endl;
		}
	}
	return 0;
}