#include <iostream>
using namespace std;

class Node {
    public:
    Node *left; // for 0
    Node *right; // for 1
    Node() {
        left = NULL;
        right = NULL;
    }
};

class Trie {
    public:
    Node *root;
    Trie() {
        root = new Node;
    }
    void insert(int num) {
        Node *tmp = root;
        for(int i=31;i>=0;i--) {
            int bit = (num>>i)&1;
            if(bit) {
                if(tmp->right==NULL) {
                    tmp->right = new Node;
                }
                tmp = tmp->right;
            }
            else {
                if(tmp->left==NULL) {
                    tmp->left = new Node;
                }
                tmp = tmp->left;
            }
        }
    }
    int max_xor_helper(int value) {
        Node *tmp = root;
        int ans = 0;
        for(int i=31;i>=0;i--) {
            int bit = (value>>i)&1;
            if(bit) {
                if(tmp->left!=NULL) {
                    ans += (1<<i);
                    tmp = tmp->left;
                }
                else {
                    tmp = tmp->right;
                }
            }
            else {
                if(tmp->right!=NULL) {
                    tmp = tmp->right;
                    ans += (1<<i);
                }
                else {
                    tmp = tmp->left;
                }
            }
        }
        return ans;
    }
    int max_xor(int *arr,int n) {
        int max_xor_value = 0;
        for(int i=0;i<n;i++) {
            insert(arr[i]);
            int cur_xor = max_xor_helper(arr[i]);
            max_xor_value = max(cur_xor,max_xor_value);
        }
        return max_xor_value;
    }
};

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    Trie t;
    cout<<t.max_xor(arr,n);
    delete [] arr;
    return 0;
}
