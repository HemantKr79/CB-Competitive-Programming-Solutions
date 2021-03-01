#include<iostream>
#include<stack>
using namespace std;

int main() {
	string str;
	cin>>str;
	stack<int> is;
	stack<char> cs;
	is.push(-1);
	int max_len = 0;
	for(int i=0;i<str.size();i++) {
		if(str[i]=='(') {
			cs.push('(');
			is.push(i);
		}
		else {
			if(!cs.empty()) {
				cs.pop();
				is.pop();
				max_len = max(max_len,i-is.top());
			}
			else {
				is.push(i);
			}
		}
	}
	cout<<max_len;
	return 0;
}