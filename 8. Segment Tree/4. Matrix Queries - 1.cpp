#include<iostream>
using namespace std;

int r;

class matrix {
	public:
	int a,b,c,d;
};

matrix multiply(matrix m1,matrix m2) {
	matrix res;
	res.a = ((m1.a*m2.a)%r + (m1.b*m2.c)%r)%r;
	res.b = ((m1.a*m2.b)%r + (m1.b*m2.d)%r)%r;
	res.c = ((m1.c*m2.a)%r + (m1.d*m2.c)%r)%r;
	res.d = ((m1.c*m2.b)%r + (m1.d*m2.d)%r)%r;
	return res;
}

void build_tree(matrix *tree,matrix *input,int s,int e,int index) {
	if(s==e) {
		tree[index] = input[s];
		return;
	}
	int m = (s+e)/2;
	build_tree(tree,input,s,m,2*index);
	build_tree(tree,input,m+1,e,2*index+1);
	tree[index] = multiply(tree[2*index],tree[2*index+1]);
}

matrix make_query(matrix *tree,int ss,int se,int l,int r,int index) {
	if(r<ss || l>se) {
		matrix m;
		m.a = m.d = 1;
		m.b = m.c = 0;
		return m;
	}
	if(l<=ss && r>=se) {
		return tree[index];
	}
	int m = (ss+se)/2;
	matrix leftAns = make_query(tree,ss,m,l,r,2*index);
	matrix rightAns = make_query(tree,m+1,se,l,r,2*index+1);
	return multiply(leftAns,rightAns);
}

int main() {
	int n,q;
	cin>>r>>n>>q;
	matrix *input = new matrix[n];
	for(int i=0;i<n;i++) {
		cin>>input[i].a;
		cin>>input[i].b;
		cin>>input[i].c;
		cin>>input[i].d;
	}
	matrix *tree = new matrix[4*n+1];
	build_tree(tree,input,0,n-1,1);
	while(q--) {
		int l,r;
		cin>>l>>r;
		matrix ans = make_query(tree,0,n-1,l-1,r-1,1);
		cout<<ans.a<<" "<<ans.b<<endl;
		cout<<ans.c<<" "<<ans.d<<endl;
		cout<<endl;
	}
	return 0;
}