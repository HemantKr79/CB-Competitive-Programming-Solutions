#include<iostream>
using namespace std;

class node {
	public:
	int data;
	node *next;
	node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

int main() {
	int n;
	cin>>n;
	int mx = n;
	int *input = new int[n+1];
	for(int i=1;i<=n;i++) {
		cin>>input[i];
	}
	node **vertices = new node*[n+1];
	for(int i=1;i<=n;i++) {
		vertices[i] = NULL;
	}
	int *output = new int[n+1];
	for(int i=1;i<=n;i++) {
		int nd = i;
		int next_node = input[i];
		if(next_node==-1) {
			output[nd] = mx--;
			continue;
		}
		if(vertices[next_node]==NULL) {
			vertices[nd] = new node(i);
			vertices[nd]->next = new node(next_node);
		}
		else {
			node *tmp = vertices[next_node];
			vertices[next_node] = NULL;
			vertices[nd] = new node(i);
			vertices[nd]->next = tmp;
		}
	}
	int st = 1;
	for(int i=1;i<=n;i++) {
		if(vertices[i]==NULL) {
			continue;
		}
		node *tmp = vertices[i];
		while(tmp->next!=NULL) {
			output[tmp->data] = st++;
			tmp = tmp->next;
		}
	}
	for(int i=1;i<=n;i++) {
		cout<<output[i]<<" ";
	}
	return 0;
}