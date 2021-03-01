#include<iostream>
using namespace std;

bool isOdd(int n) {
	return (n | 1);
}

bool getBit(int n,int i) {
	return ((n & (1<<i)) > 0);
}

int setBit(int n,int i) {
	int mask = 1<<i;
	int ans = (n | mask);
	return ans;
}

int clearBit(int n,int i) {
	int mask = ~(1<<i);
	int ans = (n & mask);
	return ans;
}

void updateBit(int &n,int i,int v) {
	int mask = ~(1<<i);
    int cleared_n = n & mask;
	n = cleared_n | (v<<i);
}

int main() {
	int n;
	int i;
	cin>>n>>i;
	cout<<"isOdd: "<<isOdd(n)<<endl;
	cout<<"getBit: "<<getBit(n,i)<<endl;
	cout<<"setBit: "<<setBit(n,i)<<endl;
	updateBit(n,2,0);
	updateBit(n,3,1);
	cout<<"updateBit: "<<n<<endl;
	return 0;
}