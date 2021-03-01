#include<iostream>
using namespace std;

int DONE,ans = 0;

void nQueen(int rowMask,int ld,int rd) {
	if(rowMask==DONE) {
		ans++;
		return;
	}
	int safe = (DONE)&(~(rowMask | ld | rd));
	while(safe) {
		int p = (safe)&(-safe);
		safe = safe - p;
		nQueen((rowMask|p),(ld|p)<<1,(rd|p)>>1);
	}
}

int main() {
	int n;
	cin>>n;
	DONE = (1<<n)-1;
	nQueen(0,0,0);
	cout<<ans;
	return 0;
}