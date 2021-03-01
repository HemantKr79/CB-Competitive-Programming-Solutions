#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

int main() {
	int n,num;
	cin>>n;
	unordered_map<int,list<int>::iterator> m;
	list<int> l;
	for(int i=0;i<n;i++) {
		cin>>num;
		if(m.find(num)==m.end()) {
			l.push_back(num);
			m[num] = --(l.end());
		}
		else {
			l.erase(m[num]);
			l.push_back(num);
			m[num] = --(l.end());
		}
	}
	for(auto item : l) {
		cout<<item<<endl;
	}
	return 0;
}