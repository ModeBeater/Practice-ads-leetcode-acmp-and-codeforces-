#include <iostream>

using namespace std;
int cnt = 0;
struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int n){
        val = n;
        next = NULL;
        prev = NULL;
    }
};
class LinkedList{
public:
    Node* head;
    Node* tail;
    LinkedList(){
        head = NULL;
    }
    void push(int n){
        Node* NewNode = new Node(n);
        if(head == NULL){
            head = tail = NewNode;
            cnt++;
        }
        else{
            tail -> next = NewNode;
            NewNode -> prev = tail;
            tail = NewNode;
            cnt++;
        }
        cout << "ok" << endl;
    }
    void pop(){
        cout << head -> val << endl;
        if(head -> next == NULL){
            tail = head = NULL;
        }
        else{
            head -> next -> prev = NULL;
            head = head -> next;
        }
        cnt--;
    }
    void size(){
        cout << cnt << endl;
    }
    void front(){
        cout << head -> val << endl;
    }
    void clear(){
        Node* cur;
        while(head != NULL){
            cur = head;
            head = head -> next;
        }
        cnt = 0;
        cout << "ok" << endl;
    }
};

int main(){
    LinkedList list;
    string s;
    while(s != "exit"){
        cin >> s;
        int n;
        if(s == "push"){
            cin >> n;
            list.push(n);
        }
        if(s == "pop"){
            if(cnt == 0){
                cout << "error" << endl;
            }
            else{
                list.pop();
            }
        }
        if(s == "front"){
            if(cnt == 0){
                cout << "error" << endl;
            }
            else{
                list.front();
            }
        }
        if(s == "size"){
            list.size();
        }
        if(s == "clear"){
            list.clear();
        }
    }
    cout << "bye";
}