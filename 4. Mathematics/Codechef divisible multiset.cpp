#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	int test;
	cin>>test;
	int num;
	while(test--) {
	   int n;
	   cin>>n;
	   map<int,set<int> > m;
	   int sum = 0;
	   for(int i=0;i<n;i++) {
	       cin>>num;
	       sum += num;
	       sum %= n;
	       sum = (sum + n)%n;
	       m[sum].insert(i);
	   }
	   if(!m[0].empty()) {
	       int subsetsize = (*m[0].begin());
	       cout<<subsetsize+1<<endl;
	       for(int i=0;i<=subsetsize;i++) {
	           cout<<i+1<<" ";
	       }
	       cout<<endl;
	       continue;
	   }
	   for(int i=1;i<n;i++) {
	       if(m[i].size()>1) {
	           int it1 = (*m[i].begin());
	           int it2 = (*(++m[i].begin()));
	           int subsetsize = (it2-it1);
	           cout<<subsetsize<<endl;
	           for(int i=it1+1;i<=it2;i++) {
	               cout<<i+1<<" ";
	           }
	           cout<<endl;
	           break;
	       }
	   }
	}
	return 0;
}