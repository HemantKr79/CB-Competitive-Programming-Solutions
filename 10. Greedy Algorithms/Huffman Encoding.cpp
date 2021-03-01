#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node {
    public:
    pair<char,int> data;
    Node *left,*right;
    Node(pair<char,int> data) {
        this->data = data;
        left = right = NULL;
    }
};

class NodeCompare {
    public:
    bool operator()(Node *a,Node *b) {
        return a->data.second > b->data.second;
    }
};

void fill_mapping(Node *curr,char *str,int index,map<char,string> &forward_mapping,map<string,char> &reverse_mapping) {
    if(curr->left==NULL && curr->right==NULL) {
        str[index] = '\0';
        string code(str);
        forward_mapping.insert(make_pair(curr->data.first,code));
        reverse_mapping.insert(make_pair(code,curr->data.first));
        return;
    }
    if(curr->left!=NULL) {
        str[index] = '0';
        fill_mapping(curr->left,str,index+1,forward_mapping,reverse_mapping);
    }
    if(curr->right!=NULL) {
        str[index] = '1';
        fill_mapping(curr->right,str,index+1,forward_mapping,reverse_mapping);
    }
}

int main() {
    string s;
    cin>>s;
    map<char,int> freq;
    for(int i=0;i<s.size();i++) {
        freq[s[i]]++;
    }
    priority_queue<Node*,vector<Node*>,NodeCompare> pq;
    for(auto item : freq) {
        Node *p = new Node(item);
        pq.push(p);
    }
    while(pq.size()>1) {
        Node *item1 = pq.top();
        pq.pop();
        Node *item2 = pq.top();
        pq.pop(); 
        Node *p = new Node(make_pair('\0',item1->data.second+item2->data.second));
        p->left = item1;
        p->right = item2;
        pq.push(p);
    }
    Node *root = pq.top();
    map<char,string> forward_mapping;
    map<string,char> reverse_mapping;
    char *str = new char[10000];
    fill_mapping(root,str,0,forward_mapping,reverse_mapping);
    for(auto item:forward_mapping) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    cout<<endl;
    for(auto item:reverse_mapping) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    cout<<endl;
}
