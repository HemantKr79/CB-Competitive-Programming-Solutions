#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

int gcd(int a,int b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}

vector<vector<int> > multiply(vector<vector<int> > &m1,vector<vector<int> > &m2) {
    vector<vector<int> > res(3,vector<int>(3));
    for(int i=1;i<=2;i++) {
        for(int j=1;j<=2;j++) {
            res[i][j] = 0;
            for(int x=1;x<=2;x++) {
                res[i][j] = (res[i][j] + (m1[i][x]*m2[x][j])%MOD)%MOD;
            }
        }
    }
    return res;
}

vector<vector<int> > power(vector<vector<int> > &transformation,int p) {
    vector<vector<int> > res(3,vector<int>(3));
    res[1][1] = 1;
    res[1][2] = 0;
    res[2][1] = 0;
    res[2][2] = 1;
    vector<vector<int> > tmp = transformation;
    while(p>0) {
        if(p&1) {
            res = multiply(res,tmp);
        }
        p = p>>1;
        tmp = multiply(tmp,tmp);
    }
    return res;
}

int fibo(int n) {
    if(n==1 || n==2) {
        return 1;
    }
    vector<vector<int> > transformation(3,vector<int>(3));
    transformation[1][1] = 0;
    transformation[1][2] = 1;
    transformation[2][1] = 1;
    transformation[2][2] = 1;
    vector<int> F1(3);
    F1[1] = 1;
    F1[2] = 1;
    transformation = power(transformation,n-1);
    int ans = 0;
    for(int i=1;i<=2;i++) {
        ans = (ans + transformation[1][i]*F1[i])%MOD;
    }
    return ans;
}

void build_tree(int *a,int *tree,int s,int e,int index) {
    if(s==e) {
        tree[index] = a[s];
        return;
    }
    int m = (s+e)/2;
    build_tree(a,tree,s,m,2*index);
    build_tree(a,tree,m+1,e,2*index+1);
    tree[index] = gcd(tree[2*index],tree[2*index+1]);
}

int query(int *tree,int ss,int se,int qs,int qe,int index) {
    if(qe<ss || qs>se) {
        return 0;
    }
    if(qs<=ss && se<=qe) {
        return tree[index];
    }
    int m = (ss+se)/2;
    int leftAns = query(tree,ss,m,qs,qe,2*index);
    int rightAns = query(tree,m+1,se,qs,qe,2*index+1);
    return gcd(leftAns,rightAns);
}

int main() {
	int n,q;
	cin>>n>>q;
	int *a = new int[n];
	for(int i=0;i<n;i++) {
	    cin>>a[i];
	    a[i] = fibo(a[i]);
	}
	int *tree = new int[4*n+1];
	build_tree(a,tree,0,n-1,1);
	while(q--) {
	    int qs,qe;
	    cin>>qs>>qe;
	    cout<<query(tree,0,n-1,qs-1,qe-1,1)<<endl;
	}
	return 0;
}
