#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> v;

int to_code(char *input,int i) {
	int ans = 0;
	ans = input[i] - '0';
	ans *= 10;
	ans += input[i+1] - '0';
	return ans;
}

void codes_of_the_string(char *input,char *output,int i,int j) {
	if(input[i]=='\0') {
		output[j] = '\0';
		string s(output);
		v.push_back(s);
		return;
	}
	output[j] = input[i] - '1' + 'a';
	codes_of_the_string(input,output,i+1,j+1);
	if(input[i+1]!='\0') {
		int code = to_code(input,i);
		if(code<=26) {
			output[j] = code + 'a' - 1;
			codes_of_the_string(input,output,i+2,j+1);
		}
	}
}

int main() {
	char input[10000];
	cin>>input;
	char output[10000];
	codes_of_the_string(input,output,0,0);
	cout<<"[";
	for(int i=0;i<v.size()-1;i++) {
	    cout<<v[i]<<", ";
	}
	cout<<v[v.size()-1]<<"]";
	return 0;
}