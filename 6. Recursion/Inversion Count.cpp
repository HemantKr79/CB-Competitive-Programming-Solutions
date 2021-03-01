#include <iostream>
using namespace std;

int merge(int a[],int s,int e) {
    int m = (s+e)/2;
    int i = s;
    int j = m+1;
    int k = 0;
    int *tmp = new int[e-s+1];
    int cross_inversion = 0;
    while(i<=m && j<=e) {
        if(a[i]<a[j]) {
            tmp[k++] = a[i++];
        }
        else {
            cross_inversion += (m-i+1);
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
    return cross_inversion;
}

int inversion_count(int a[],int s,int e) {
    if(s>=e) {
        return 0;
    }
    int m = (s+e)/2;
    int x = inversion_count(a,s,m);
    int y = inversion_count(a,m+1,e);
    int z = merge(a,s,e);
    return x+y+z;
}

int main() {
    int a[] = {1,5,2,6,3,0};
    int n = sizeof(a)/sizeof(int);
    int inversion_cnt = inversion_count(a,0,n-1);
    cout<<inversion_cnt;
    return 0;
}