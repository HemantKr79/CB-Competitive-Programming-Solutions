#include <iostream>
using namespace std;

void merge(int a[],int s,int e) {
    int m = (s+e)/2;
    int i = s;
    int j = m+1;
    int k = 0;
    int *tmp = new int[e-s+1];
    while(i<=m && j<=e) {
        if(a[i]<a[j]) {
            tmp[k++] = a[i++];
        }
        else {
            tmp[k++] = a[j++];
        }
    }
    while(i<=m) {
        tmp[k++] = a[i++];
    }
    while(j<=e) {
        tmp[k++] = a[j++];
    }
    k = 0;
    for(int i=s;i<=e;i++) {
        a[i] = tmp[k++];
    }
    delete [] tmp;
}

void merge_sort(int a[],int s,int e) {
    if(s>=e) {
        return;
    }
    int m = (s+e)/2;
    merge_sort(a,s,m);
    merge_sort(a,m+1,e);
    merge(a,s,e);
}

int main() {
    int a[] = {1,5,2,6,3,0};
    int n = sizeof(a)/sizeof(int);
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}
