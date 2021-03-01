#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
    char data;
    unordered_map<char,Node*> children;
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
    bool find(char *w) {
        Node *tmp = root;
        for(int i=0;w[i]!='\0';i++) {
            if(tmp->children.count(w[i])) {
                tmp = tmp->children[w[i]];
            }
            else {
                return false;
            }
        }
        return tmp->terminal;
    }
};

int main() {
    Trie t;
    char words[][10] = {"not","apple","norway"};
    char w[10];
    for(int i=0;i<3;i++) {
        t.insert(words[i]);
    }
    cin>>w;
    cout<<t.find(w);
    return 0;
}
