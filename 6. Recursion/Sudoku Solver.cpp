#include <iostream>
#include <cmath>
using namespace std;

bool canPlace(int mat[][9],int i,int j,int n,int number) {
    for(int x=0;x<n;x++) {
        if(mat[x][j]==number || mat[i][x]==number) {
            return false;
        }
    }
    int sq_n = sqrt(n);
    int start_row = (i/sq_n)*sq_n;
    int start_col = (j/sq_n)*sq_n;
    for(int r=start_row;r<start_row+sq_n;r++) {
        for(int c=start_col;c<start_col+sq_n;c++) {
            if(mat[r][c]==number) {
                return false;
            }
        }
    }
    return true;
}

bool solveSoduko(int mat[][9],int i,int j,int n) {
    if(i==n) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(j==n) {
        return solveSoduko(mat,i+1,0,n);
    }
    if(mat[i][j]!=0) {
        return solveSoduko(mat,i,j+1,n);
    }
    for(int number=1;number<=n;number++) {
        if(canPlace(mat,i,j,n,number)) {
            mat[i][j] = number;
            bool canSolve = solveSoduko(mat,i,j+1,n);
            if(canSolve) {
                return true;
            }
        }
    }
    mat[i][j] = 0;
    return false;
}

int main() {
    int mat[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    int n = 9;
    bool canBeSolved = solveSoduko(mat,0,0,n);
    if(!canBeSolved) {
        cout<<-1;
    }
    return 0;
}
