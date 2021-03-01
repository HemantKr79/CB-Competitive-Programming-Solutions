#include<iostream>
#include<cstring>
using namespace std;

char table[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

int to_int(char c) {
	return (int)(c-'0');
}

void smart_keypad(char *input,char *output,int index,int j,int l) {
	if(index==l) {
		output[j] = '\0';
		cout<<output<<endl;
		return;
	}
	int key = to_int(input[index]);
	int stringLen = strlen(table[key]);
	for(int i=0;i<stringLen;i++) {
		output[j] = table[key][i];
		smart_keypad(input,output,index+1,j+1,l);
	}
}

int main() {
	char input[11];
	cin>>input;
	char output[100];
	smart_keypad(input,output,0,0,strlen(input));
	return 0;
}