



#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
    char data;
    int freq;
    unordered_map<char,Node*> children;
    bool terminal;
    Node(char d) {
        data = d;
        freq = 0;
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
            tmp->freq += 1;
        }
        tmp->terminal = true;
    }
    char* prefix(char *w) {
        char *ans = new char[100];
        int k = 0;
        Node *tmp = root;
        for(int i=0;w[i]!='\0';i++) {
            if(tmp->children[w[i]]->freq > 1) {
                ans[k++] = w[i];
            }
            else {
                ans[k++] = w[i];
                break;
            }
            tmp = tmp->children[w[i]];
        }
        ans[k] = '\0';
        return ans;
    }
};

int main() {
    int n;
    cin>>n;
    char word[10][100];
    Trie t;
    for(int i=0;i<n;i++) {
        cin>>word[i];
        t.insert(word[i]);
    }
    for(int i=0;i<n;i++) {
        cout<<t.prefix(word[i])<<endl;
    }
}
