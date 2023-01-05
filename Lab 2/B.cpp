#include <iostream>

using namespace std;

struct Node{
    string val;
    int cnt;
    Node* next;
    Node(string v){
        val = v;
        next = NULL;
        cnt = 1;
    }
};
class LinkedList{
public:
    Node * head;
    LinkedList(){
        head = NULL;
    }
    void push(string val){
        Node * NewNode = new Node(val);
        if (head == NULL){
            head = NewNode;
        }
        else{
            Node * cur = head;
            while(cur != NULL){
                if(cur -> val == val){
                    cur -> cnt++;
                    break;
                }
                if(cur -> next == NULL){
                    cur -> next = NewNode;
                    break;
                }
                cur = cur->next;
            }
        }
    }
    void sort(){
        Node *i = head;
        Node *j = head -> next;
        while(i -> next != NULL){
            while(j != NULL){
                if (i -> cnt < j -> cnt){
                    swap(i -> val, j -> val);
                    swap(i -> cnt, j -> cnt);
                }
                if(i -> cnt == j -> cnt){
                    if (i -> val > j -> val){
                        swap(i -> val, j -> val);
                        swap(i -> cnt, j -> cnt);
                    }
                }
                j = j -> next;
            }
            i = i -> next;
            j = i;
        }
    }
    void print(){
        Node * cur = head;
        while(cur != NULL){
            cout << cur->val << " " << cur-> cnt << endl;
            cur = cur->next;
        }
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    LinkedList list;
    string s;
    while(cin >> s){
        list.push(s);
    }
    list.sort();
    list.print();
}