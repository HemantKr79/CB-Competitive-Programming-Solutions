#include<iostream>
#include<string>
#include<set>
using namespace std;

void permute(char *input,int i,set<string> &s) {
	if(input[i]=='\0') {
		string str(input);
		s.insert(str);
		return;
	}
	for(int j=i;input[j]!='\0';j++) {
		swap(input[i],input[j]);
		permute(input,i+1,s);
		swap(input[i],input[j]);
	}
}

int main() {
	char input[9];
	cin>>input;
	set<string> s;
	permute(input,0,s);
	for(auto str : s) {
		cout<<str<<endl;
	}
	return 0;
}