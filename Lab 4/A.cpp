#include <iostream>
using namespace std;

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
        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }
    void inOrder(Node * cur ){
        if (cur != NULL){
            inOrder(cur -> left);
            if(cur -> left != NULL && cur -> right != NULL){
                cout << cur -> val << endl;
            }
            // cout << cur -> val << endl;
            inOrder(cur -> right);
        }
    }
    int height(Node* cur){
        if(cur == NULL){
            return 0;
        }
        return max(height(cur -> left), height(cur -> right)) + 1;
    }

public:
    BST(){
        root = NULL;
    }

    void push(int val){
        root = push(root, val);
    }

    void inOrder(){
        inOrder(root);
    }
    int height(){
        return height(root);
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
    // tree.inOrder();
    cout << tree.height();
    return 0;
}