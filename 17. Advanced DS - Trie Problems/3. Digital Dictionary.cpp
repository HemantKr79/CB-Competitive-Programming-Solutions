#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Node {
	public:
	char data;
	map<char,Node*> children;
	bool terminal;
	Node(char d) {
		data = d;
		terminal = false;
	}
};

class Trie {
	public:
	Node *root;
	Trie() {
		root = new Node('\0');
	}
	void insert(char *w) {
		Node *tmp = root;
		for(int i=0;w[i]!='\0';i++) {
			if(tmp->children.count(w[i])) {
				tmp = tmp->children[w[i]];
			}
			else {
				tmp->children[w[i]] = new Node(w[i]);
				tmp = tmp->children[w[i]];
			}
		}
		tmp->terminal = true;
	}
	void all_nodes(Node *tmp,int i,char *str,vector<string> &v) {
		if(tmp->terminal) {
			str[i] = '\0';
			v.push_back(string(str));
		}
		for(auto item : tmp->children) {
			str[i] = item.first;
			all_nodes(item.second,i+1,str,v);
		}
	}
	void print(char *w) {
		Node *tmp = root;
		bool newNode = false;
		for(int i=0;w[i]!='\0';i++) {
			if(tmp->children.count(w[i])) {
				tmp = tmp->children[w[i]];
			}
			else {
				newNode = true;
				tmp->children[w[i]] = new Node(w[i]);
				tmp = tmp->children[w[i]];
			}
		}
		if(newNode) {
			tmp->terminal = true;
			cout<<"No suggestions"<<endl;
		}
		else {
			vector<string> v;
			char *str = new char[200005];
			all_nodes(tmp,0,str,v);
			for(auto s : v) {
				cout<<w<<s<<endl;
			}
		}
	}
};

int main() {
	Trie t;
	int n;
	cin>>n;
	char *str = new char[200005];
	for(int i=0;i<n;i++) {
		cin>>str;
		t.insert(str);
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++) {
		cin>>str;
		t.print(str);
	}
	return 0;
}