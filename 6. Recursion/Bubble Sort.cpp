#include <iostream>
using namespace std;

void bubble_sort(int a[],int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-1;j++) {
            if(a[j]>a[j+1]) {
                swap(a[j],a[j+1]);
            }
        }
    }
}

void bubble_sort_recursive(int a[],int j,int n) {
    if(n==1) {
        return;
    }
    if(j==n-1) {
        bubble_sort_recursive(a,0,n-1);
        return;
    }
    if(a[j]>a[j+1]) {
        swap(a[j],a[j+1]);
    }
    bubble_sort_recursive(a,j+1,n);
}

int main() {
    int a[] = {5,4,3,1,2};
    int n = sizeof(a)/sizeof(int);
    bubble_sort_recursive(a,0,n);
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
