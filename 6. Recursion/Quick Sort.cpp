#include <iostream>
using namespace std;

int partition(int a[],int s,int e) {
    int i = s-1;
    int pivot = a[e];
    int j = s;
    while(j<=e-1) {
        if(a[j]<=pivot) {
            i = i + 1;
            swap(a[i],a[j]);
        }
        j = j + 1;
    }
    swap(a[i+1],a[e]);
    return i+1;
}

void quick_sort(int a[],int s,int e) {
    if(s>=e) {
        return;
    }
    int p = partition(a,s,e);
    quick_sort(a,s,p-1);
    quick_sort(a,p+1,e);
}

int main() {
    int a[] = {1,5,2,6,3,0};
    int n = sizeof(a)/sizeof(int);
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}