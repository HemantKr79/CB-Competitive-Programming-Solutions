#include <iostream>
#include <unordered_map>
using namespace std;

int solve(int *x,int *y,int n) {
    unordered_map<int,int> x_map;
    unordered_map<int,int> y_map;
    for(int i=0;i<n;i++) {
        x_map[x[i]]++;
        y_map[y[i]]++;
    }
    int ans = 0;
    for(auto item : x_map) {
        int cnt = y_map[item.first];
        ans += (item.second-1)*(cnt-1);
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    int *x = new int[n];
    int *y = new int[n];
    for(int i=0;i<n;i++) {
        cin>>x[i]>>y[i];
    }
    cout<<solve(x,y,n);
    delete [] x;
    delete [] y;
    return 0;
}
