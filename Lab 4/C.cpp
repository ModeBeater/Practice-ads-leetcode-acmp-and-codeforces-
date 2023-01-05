#include <iostream>
using namespace std;
int ok = 0;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};
class BST{
    Node * root;
    Node* push(Node * cur, int val){
        if (cur == NULL) {
            return new Node(val);
        }
        if (val < cur -> val){
            cur -> left = push(cur -> left, val);
        } 
        if (val > cur -> val){
            cur -> right = push(cur -> right, val);
        }
        return cur;
    }

public:
    BST(){
        root = NULL;
    }

    void push(int val){
        root = push(root, val);
    }
    void check(){
        Node* cur = root;
        int ans;
        if(cur -> right){
            while(cur -> right != NULL){
                ans = cur -> val;
                cur = cur -> right;
            }
            ok = 1;
        }
        if(cur -> left){
            cur = cur -> left;
            ans = cur -> val;
        }
        if(cur -> right){
            while(cur -> right != NULL){
                cur = cur -> right;
                ans = cur -> val;
            }
        }
        cout << ans << endl;
    }
};

int main() {
    BST tree;
    int x;
    cin >> x; 
    while(x != 0){
        tree.push(x);
        cin >> x;
    }
    tree.check();
    return 0;
}