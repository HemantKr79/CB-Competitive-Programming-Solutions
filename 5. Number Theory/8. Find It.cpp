#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int *cnt = new int[100001]();
	int *sum = new int[100001]();
	int input;
	for(int i=0;i<n;i++) {
		cin>>input;
		cnt[input]++;
	}
	for(int i=1;i<=100000;i++) {
		for(int j=i;j<=100000;j+=i) {
			sum[i] += cnt[j];
		}
	}
	int q;
	cin>>q;
	while(q--) {
		int num;
		cin>>num;
		cout<<sum[num];
		cout<<endl;
	}
	delete [] cnt;
	delete [] sum;
	return 0;
}