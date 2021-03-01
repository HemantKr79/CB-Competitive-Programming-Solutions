#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define MOD 1000000007

vector<vector<ll> > multiply(vector<vector<ll> > m1,vector<vector<ll> > m2) {
	vector<vector<ll> > res(3,vector<ll>(3));
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

vector<vector<ll> > power(vector<vector<ll> > transformation,int p) {
	if(p==1) {
		return transformation;
	}
	if(p&1) {
		return multiply(transformation,power(transformation,p-1));
	}
	vector<vector<ll> > tmp = power(transformation,p/2);
	tmp = multiply(tmp,tmp);
	return tmp;
}

void fibonacci(int n) {
	if(n<1) {
		cout<<0;
		return;
	}
	if(n==1) {
		cout<<1;
		return;
	}
	vector<vector<ll> > transformation(3,vector<ll>(3));
	transformation[1][1] = 0;
	transformation[1][2] = 1;
	transformation[2][1] = 1;
	transformation[2][2] = 1;
	vector<ll> F1(3);
	F1[1] = 1;
	F1[2] = 1;
	vector<vector<ll> > T = power(transformation,n-1);
	ll ans = 0;
	for(int i=1;i<3;i++) {
		ans = (ans + (T[1][i]*F1[i])%MOD)%MOD;
	}
	cout<<ans;
}

int main () {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		fibonacci(n);
		cout<<endl;
	}
	return 0;
}