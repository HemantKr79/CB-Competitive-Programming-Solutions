#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007
#define ll long long

vector<vector<ll> > multiply(vector<vector<ll> > m1,vector<vector<ll> > m2) {
	vector<vector<ll> > res(4,vector<ll>(4));
	for(int i=1;i<=3;i++) {
		for(int j=1;j<=3;j++) {
			res[i][j] = 0;
			for(int x=1;x<=3;x++) {
				res[i][j] = (res[i][j] + (m1[i][x]*m2[x][j])%MOD)%MOD;
			}
		}
	}
	return res;
}

vector<vector<ll> > power(vector<vector<ll> > transformation,int p) {
	if(p==1) {
		return transformation;
	}
	if(p&1) {
		return multiply(transformation,power(transformation,p-1));
	}
	vector<vector<ll> > answer = power(transformation,p/2);
	return multiply(answer,answer);
}

ll solve(int n) {
	if(n<=0) {
		return 0;
	}
	if(n==1) {
		return 1;
	}
	vector<ll> F1(4);
	F1[1] = 1;
	F1[2] = 0;
	F1[3] = 1;
	vector<vector<ll> > transformation(4,vector<ll>(4));
	for(int i=1;i<=3;i++) {
		for(int j=1;j<=3;j++) {
			if(i==1) {
				transformation[i][j] = 1;
			}
			else if(i==3) {
				if(j==1) {
					transformation[i][j] = 0;
				}
				else {
					transformation[i][j] = 1;
				}
			}
			else {
				if(i+1==j) {
					transformation[i][j] = 1;
				}
				else {
					transformation[i][j] = 0;
				}
			}
		}
	}
	vector<vector<ll> > T = power(transformation,n-1);
	ll ans = 0;
	for(int i=1;i<=3;i++) {
		ans = (ans + (T[1][i]*F1[i])%MOD)%MOD;
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		ll sumUptoN = solve(n-1);
		ll sumUptoM = solve(m);
		cout<<(((sumUptoM-sumUptoN)%MOD)+MOD)%MOD;
		cout<<endl;
	}
	return 0;
}