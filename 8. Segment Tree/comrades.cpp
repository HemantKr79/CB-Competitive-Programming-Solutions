#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void wake_up(vector<int> &tree,vector<int> &lazy,int ss,int se,int l,int r,int index) {
	if(lazy[index]!=-1) {
		if(ss!=se) {
			lazy[2*index] = lazy[2*index+1] = lazy[index];
		}
		if(lazy[index]==1) {
			tree[index] = (se-ss+1);
		}
		else {
			tree[index] = 0;
		}
		lazy[index] = -1;
	}
	if(r<ss || l>se) {
		return;
	}
	if(ss>=l && se<=r) {
		tree[index] = (se-ss)+1;
		if(ss!=se) {
			lazy[2*index] = lazy[2*index+1] = 1;
		}
		return;
	}
	int m = (ss+se)/2;
	wake_up(tree,lazy,ss,m,l,r,2*index);
	wake_up(tree,lazy,m+1,se,l,r,2*index+1);
	tree[index] = tree[2*index] + tree[2*index+1];
}

void sleep(vector<int> &tree,vector<int> &lazy,int ss,int se,int l,int r,int index) {
	if(lazy[index]!=-1) {
		if(ss!=se) {
			lazy[2*index] = lazy[2*index+1] = lazy[index];
		}
		if(lazy[index]==1) {
			tree[index] = (se-ss+1);
		}
		else {
			tree[index] = 0;
		}
		lazy[index] = -1;
	}
	if(r<ss || l>se) {
		return;
	}
	if(ss>=l && se<=r) {
		tree[index] = 0;
		if(ss!=se) {
			tree[2*index] = tree[2*index+1] = 0;
		}
		return;
	}
	int m = (ss+se)/2;
	sleep(tree,lazy,ss,m,l,r,2*index);
	sleep(tree,lazy,m+1,se,l,r,2*index+1);
	tree[index] = tree[2*index] + tree[2*index+1];
}

int query(vector<int> &tree,vector<int> &lazy,int ss,int se,int l,int r,int index) {
	if(lazy[index]!=-1) {
		if(ss!=se) {
			lazy[2*index] = lazy[2*index+1] = lazy[index];
		}
		if(lazy[index]==1) {
			tree[index] = (se-ss+1);
		}
		else {
			tree[index] = 0;
		}
		lazy[index] = -1;
	}
	if(r<ss || se<l) {
		return 0;
	}
	if(ss>=l && se<=r) {
		return tree[index];
	}
	int m = (ss+se)/2;
	int leftAns = query(tree,lazy,ss,m,l,r,2*index);
	int rightAns = query(tree,lazy,m+1,se,l,r,2*index+1);
	return leftAns+rightAns;
}

int main() {
	int n,tmp;
	cin>>n;
	vector<int> gr[n];
	int st;
	for(int i=0;i<n;i++) {
		cin>>tmp;
		if(tmp==0) {
			st = i;
		}
		gr[tmp].push_back(i);
		gr[i].push_back(tmp);
	}
	queue<int> q;
	q.push(st);
	vector<bool> visited(n,false);
	visited[st] = true;
	vector<int> idx_to_p(n);
	vector<int> p_to_index(n);
	vector<int> tree(4*n+2,1);
	vector<int> lazy(4*n+2,-1);
	int i = 0;
	while(!q.empty()) {
		int fv = q.front();
		idx_to_p[i] = fv;
		p_to_index[fv] = i++;
		q.pop();
		for(auto nbr : gr[fv]) {
			if(!visited[nbr]) {
				visited[nbr] = true;
				q.push(nbr);
			}
		}
	}
	int queries;
	cin>>queries;
	while(queries--) {
		int qType,id;
		cin>>qType>>id;
		if(qType==1) {
			int index = p_to_index[id];
			wake_up(tree,lazy,0,n-1,index,n-1,1);
		}
		else if(qType==2) {
			int index = p_to_index[id];
			sleep(tree,lazy,0,n-1,index,n-1,1);
		}
		else {
			int index = p_to_index[id];
			cout<<query(tree,lazy,0,n-1,index,n-1,1)<<"\n";
		}
	}
	return 0;
}