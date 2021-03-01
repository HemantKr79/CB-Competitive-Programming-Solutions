#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int arr[] = {1,10,11,9,100};
	int n = sizeof(arr)/sizeof(int);

	int key;
	cin>>key;
	bool present = binary_search(arr,arr+n,key); //It returns boolean value
	(present)?cout<<"Present":cout<<"Absent";
	return 0;
}