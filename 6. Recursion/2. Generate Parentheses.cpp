#include<iostream>
using namespace std;

void generate_brackets(char *output,int n,int i,int open,int close) {
	if(2*n==i) {
		output[i] = '\0';
		cout<<output<<endl;
		return;
	}
	if(close < open) {
		output[i] = ')';
		generate_brackets(output,n,i+1,open,close+1);
	}
	if(open < n) {
		output[i] = '(';
		generate_brackets(output,n,i+1,open+1,close);
	}
}

int main() {
	int n;
	cin>>n;
	char output[23];
	generate_brackets(output,n,0,0,0);
	return 0;
}