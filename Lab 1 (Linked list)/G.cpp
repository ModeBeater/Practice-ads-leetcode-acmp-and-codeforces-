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
    void push_front(int n){
        Node* NewNode = new Node(n);
        if(head == NULL){
            head = tail = NewNode;
            cnt++;
        }
        else{
            head -> prev = NewNode;
            NewNode -> next = head;
            head = NewNode;
            cnt++;
        }
    }
    void push_back(int n){
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
    }
    void pop_back(){
        if(tail -> prev == NULL){
            tail = head = NULL;
        }
        else{
            tail -> prev -> next = NULL;
            tail = tail -> prev;
        }
        cnt--;
    }
    void pop_front(){
        if(head -> next == NULL){
            tail = head = NULL;
        }
        else{
            head -> next -> prev = NULL;
            head = head -> next;
        }
        cnt--;
    }
    bool empty(){
        if(head == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    int front(){
        return head -> val;
    }
    int top(){
        return tail -> val;
    }
    void clear(){
        Node* cur;
        while(head != NULL){
            cur = head;
            head = head -> next;
        }
        cnt = 0;
    }
};
int main(){
    char a;
    LinkedList list;
    while(cin >> a){
        if(a == '-' || a == '+' || a == '*'){
            int b = list.top();
            list.pop_back();
            int c = list.top();
            list.pop_back();
            if(a == '-'){
                int d = c - b;
                list.push_back(d);
            }
            if(a == '+'){
                int d = b + c;
                list.push_back(d);
            }
            if(a == '*'){
                int d = b * c;
                list.push_back(d);
            }
        }
        else{
            int b = a - '0';
            list.push_back(b);
        }
    }
    cout << list.top();
}