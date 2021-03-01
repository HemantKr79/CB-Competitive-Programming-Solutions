#include<iostream>
#include<vector>
using namespace std;

int findSumOfDigits(int n) {
	int sum = 0;
	while(n>0) {
		sum += n%10;
		n = n/10;
	}
	return sum;
}

bool isPrime(int n) {
	if(n<=1) {
		return false;
	}
	if(n<=3) {
		return true;
	}
	if(n%2 == 0 || n%3 == 0) {
		return false;
	}
	for(int i=5;i*i<n;i+=6) {
		if(n%i==0 || n%(i+2)==0) {
			return false;
		}
	}
	return true;
}

bool isBoston(int n) {
	int digitSum = findSumOfDigits(n);
	int primeSum = 0;
	for(int prime=2;prime<=n;prime++) {
		if(isPrime(prime)) {
			int primedigitsum = findSumOfDigits(prime);
			while(n%prime == 0) {
				primeSum += primedigitsum;
				n = n/prime;
			}
		}
		if(n<=1) {
			return digitSum==primeSum;
		}
	}
	return digitSum==primeSum;
}

int main() {
	int n;
	cin>>n;
	cout<<isBoston(n);
	return 0;
}