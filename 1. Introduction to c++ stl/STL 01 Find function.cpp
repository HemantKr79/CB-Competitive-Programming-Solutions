#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int arr[] = {1,10,11,9,100};
	int n = sizeof(arr)/sizeof(int);

	int key;
	cin>>key;
	auto it = find(arr,arr+n,key); //It returns the address by default
	int index = it - arr; //index is equal to n if key is not present
	if(index == n) {
		cout<<key<<" not present";
	}
	else {
		cout<<key<<" present at index "<<index;
	}
	return 0;
}