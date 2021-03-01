#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > multiply(vector<vector<int> > m1,vector<vector<int> > m2) {
    vector<vector<int> > ans(4,vector<int>(4));
    for(int i=1;i<4;i++) {
        for(int j=1;j<4;j++) {
            for(int x=1;x<4;x++) {
                ans[i][j] += m1[i][x] * m2[x][j];
            }
        }
    }
    return ans;
}

vector<vector<int> > power(vector<vector<int> > transformation,int n) {
    if(n==1) {
        return transformation;
    }
    if(n&1) {
        return multiply(power(transformation,n-1),transformation);
    }
    vector<vector<int> > res = power(transformation,n/2);
    return multiply(res,res);
}

int solve(int n) {
    vector<int> b(4);
    vector<int> c(4);
    c[0] = 0;
    for(int i=1;i<=3;i++) {
        c[i] = 1;
    }
    b[0] = 0;
    b[1] = 1;
    b[2] = 2;
    b[3] = 3;
    vector<int> F1(4);
    F1[1] = 1;
    F1[2] = 2;
    F1[3] = 3;
    vector<vector<int> > transformation(4,vector<int>(4));
    for(int i=1;i<4;i++) {
        for(int j=1;j<4;j++) {
            if(i<3) {
                if(i+1==j) {
                    transformation[i][j] = 1;
                }
                else {
                    transformation[i][j] = 0;
                }
            }
            else {
                transformation[i][j] = 1;
            }
        }
    }
    cout<<"Transformation Matrix: "<<endl;
    for(int i=1;i<4;i++) {
        for(int j=1;j<4;j++) {
            cout<<transformation[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<vector<int> > T = power(transformation,n-1);
    int ans = 0;
    for(int i=1;i<4;i++) {
        ans += T[1][i]*F1[i];
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<solve(n);
        cout<<endl;
    }
    return 0;
}
