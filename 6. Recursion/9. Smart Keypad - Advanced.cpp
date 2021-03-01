#include<iostream>
#include<string>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

void smart_keypad_advanced(char *input,char *out,int i,int j) {
	if(input[i]=='\0') {
		out[j] = '\0';
		string s(out);
		for(int k=0;k<=10;k++) {
			if(searchIn[k].find(s)!=-1) {
				cout<<searchIn[k]<<endl;
			}
		}
		return;
	}
	int key = input[i] - '0';
	for(int k=0;k<table[key].length();k++) {
		out[j] = table[key][k];
		smart_keypad_advanced(input,out,i+1,j+1);
	}
}

int main() {
	char input[10];
	char out[40];
	cin>>input;
	smart_keypad_advanced(input,out,0,0);
	return 0;
}