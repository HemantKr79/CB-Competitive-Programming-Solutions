#include <iostream>
#include <deque>
using namespace std;

void max_of_subarrays(int *arr, int n, int k){
    deque<int> dq(k);
    int i=0;
    for(;i<k;i++) {
        while( (!dq.empty()) && (arr[i] >= arr[dq.back()]) ) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(;i<n;i++) {
        cout<<arr[dq.front()]<<" ";
        while( (!dq.empty()) && (dq.front() <= i-k) ) {
            dq.pop_front();
        }
        while( !dq.empty() && (arr[i] >= arr[dq.back()]) ) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<arr[dq.front()];
}

int main() {
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
	    cin>>arr[i];
	}
	int k;
	cin>>k;
	max_of_subarrays(arr,n,k);
	delete [] arr;
	return 0;
}
