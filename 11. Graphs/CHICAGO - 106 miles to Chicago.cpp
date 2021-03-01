#include<iostream>
#include<vector>
#include<cfloat>
#include<iomanip>
using namespace std;

#define int long long

void lets_do_it() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

int32_t main() {
	lets_do_it();
	while(true) {
		int n,m;
		cin>>n;
		if(n==0) {
			break;
		}
		cin>>m;
		vector<vector<double> > g(n+1,vector<double>(n+1,0.0));
		for(int i=0;i<m;i++) {
			int x,y,w;
			cin>>x>>y>>w;
			double weight = w/(100.0);
			g[x][y] = weight;
			g[y][x] = weight;
		}
		for(int k=1;k<=n;k++) {
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					g[i][j] = max(g[i][j],g[i][k]*g[k][j]);
				}
			}
		}
		cout<<fixed<<setprecision(6)<<g[1][n]*100<<" percent"<<endl;
	}
	return 0;
}