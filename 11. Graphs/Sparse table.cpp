#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

struct sparse_table {
    int n,m;
    vector<vector<int> > mat;
    vector<int> p2;
    void init(int _n) {
        n = _n;
        m = ceil(log2(n)) + 1;
        mat.resize(n);
        p2.resize(n+1);
        for(int i=0;i<n;i++) {
            mat[i].resize(m);
        }
        for(int i=1;i<=n;i++) {
            p2[i] = p2[i/2] + 1;
        }
    }
    void print() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void build(int *a) {
        for(int i=0;i<n;i++) {
            mat[i][0] = a[i];
        }
        for(int j=1;j<m;j++) {
            for(int i=0;i+(1<<j)<=n;i++) {
                mat[i][j] = min(mat[i][j-1],mat[i+(1<<(j-1))][j-1]);
            }
        }
    }
    int query(int l,int r) {
        int pw = p2[(r-l)];
        return min(mat[l][pw],mat[r - (1<<pw) + 1][pw]);
    }
};

int main() {
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sparse_table s;
    s.init(n);
    s.build(a);
    s.print();
    return 0;
}
