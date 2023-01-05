#include <iostream>
#include <sstream>
using namespace std;

int ok = 1;

struct Node{
    unsigned long val;
    Node* next;
    Node* prev;
    Node(unsigned long v){
        this->val = v;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LinkedList{
public:
    Node* head = NULL;
    Node* tail = NULL;
    void push(unsigned long val){
        Node * NewNode = new Node(val);
        if (head == NULL){
            head = tail = NewNode;
        }
        else{
            tail -> next = NewNode;
            NewNode -> prev = tail;
            tail = NewNode;
        }
    }
    void sort(){
        if(head == NULL){
            return;
        }
        Node *i = head;
        Node *j = head -> next;
        while(i -> next != NULL){
            while(j != NULL){
                if (i -> val > j -> val){
                    swap(i -> val, j -> val);
                }
                j = j -> next;
            }
            i = i -> next;
            j = i;
        }
    }
    void Remove(unsigned long val){
        Node* cur = head;
        while(cur != NULL){
            if(cur -> val == val){
                if (cur -> prev){
                    if(cur -> next){
                        cur -> prev -> next = cur -> next;
                        cur -> next -> prev = cur -> prev;
                    }
                    else{
                        tail = cur -> prev;
                        tail -> next = NULL;
                    }
                    break;
                }
                else{
                    if (cur -> next){
                        head = cur -> next;
                        head -> prev = NULL;
                    }
                    else{
                        head = tail = NULL;
                    }
                    break;
                }
            }
            cur = cur -> next;
            if(cur == NULL){
                cout << "ERROR" << endl;
                ok = 0;
                return;
            }
        }
    }
    bool isEmpty(){
        if (head == NULL){
            return true;
        }
        else return false;
    }
    void print(){
        if(head == NULL){
            cout << "EMPTY" << endl;
            return;
        }
        Node * cur = head;
        while(cur != NULL){
            cout << cur->val << " ";
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
        string t = "";
        for(int i = 1; i < s.size(); i++){
            t += s[i];
        }
        stringstream ss;
        unsigned long a;
        ss << t;
        ss >> a;
        if(s[0] == '+'){
            list.push(a);
        }
        if(s[0] == '-'){
            if(list.isEmpty()){
                cout << "ERROR" << endl;
                return 0;
            }
            else{
                list.Remove(a);
                if(ok == 0){
                    return 0;
                }
            }
        }
    }
    list.sort();
    list.print();
}