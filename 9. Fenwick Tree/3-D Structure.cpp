#include<iostream>
#include<vector>
using namespace std;

void update1d(vector<vector<vector<int> > > &BIT,int x,int y,int z,int val,int n) {
	while(z<=n) {
		BIT[x][y][z] += val;
		z += z&(-z);
	}
}

void update2d(vector<vector<vector<int> > > &BIT,int x,int y,int z,int val,int n) {
	while(y<=n) {
		update1d(BIT,x,y,z,val,n);
		y += y&(-y);
	}
}

void update3d(vector<vector<vector<int> > > &BIT,int x,int y,int z,int val,int n) {
	while(x<=n) {
		update2d(BIT,x,y,z,val,n);
		x += x&(-x);
	}
}

int query1d(vector<vector<vector<int> > > &BIT,int x,int y,int z) {
	int ans1d = 0;
	while(z>0) {
		ans1d += BIT[x][y][z];
		z -= z&(-z);
	}
	return ans1d;
}

int query2d(vector<vector<vector<int> > > &BIT,int x,int y,int z) {
	int ans2d = 0;
	while(y>0) {
		ans2d += query1d(BIT,x,y,z);
		y -= y&(-y);
	}
	return ans2d;
}

int query3d(vector<vector<vector<int> > > &BIT,int x,int y,int z) {
	int ans3d = 0;
	while(x>0) {
		ans3d += query2d(BIT,x,y,z);
		x -= x&(-x);
	}
	return ans3d;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		vector<vector<vector<int> > > BIT(n+1,vector<vector<int> >(n+1,vector<int>(n+1,0)));
		while(m--) {
			string qType;
			cin>>qType;
			if(qType=="UPDATE") {
				int x,y,z,val;
				cin>>x>>y>>z>>val;
				update3d(BIT,x,y,z,val,n);
			}
			else {
				int x1,y1,z1,x2,y2,z2;
				cin>>x1>>y1>>z1>>x2>>y2>>z2;
				int largeAns = query3d(BIT,x2,y2,z2);
				int smallAns = query3d(BIT,x1-1,y1-1,z1-1);
				cout<<largeAns-smallAns<<endl;
			}
		}
	}
	return 0;
}