#include<iostream>
using namespace std;

bool isEquivalent(string a,string b) {
	if(a.length()==1) {
		return a==b;
	}
	if(a.length()%2!=0) {
		return a==b;
	}
	string a1 = a.substr(0,a.length()/2);
	string b1 = b.substr(0,b.length()/2);
	string a2 = a.substr(a.length()/2,a.length()/2);
	string b2 = b.substr(b.length()/2,b.length()/2);
	if(isEquivalent(a1,b1) && isEquivalent(a2,b2)) {
		return true;
	}
	if(isEquivalent(a1,b2) && isEquivalent(a2,b1)) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		string a,b;
		cin>>a;
		cin>>b;
		if(isEquivalent(a,b)) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}