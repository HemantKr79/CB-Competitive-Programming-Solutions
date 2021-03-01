#include <iostream>
using namespace std;

bool isPossible(int *board,int m,int k,int n) {
    int i = 0;
    for(int painter=0;painter<k;painter++) {
        int time = 0;
        while(i<n && time + board[i] <= m ) {
            time += board[i];
            i++;
            if(i==n) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int k,n;
    cin>>k;
    cin>>n;
    int *board = new int[n];
    int e = 0;
    int s = 0;
    for(int i=0;i<n;i++) {
        cin>>board[i];
        e += board[i];
        s = max(s,board[i]);
    }
    int ans = e;
    while(s<=e) {
        int m = (s+e)/2;
        if(isPossible(board,m,k,n)) {
            e = m-1;
            ans = min(ans,m);
        }
        else {
            s = m+1;
        }
    }
    cout<<ans;
    return 0;
}