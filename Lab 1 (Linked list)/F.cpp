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
bool check(string s){
    LinkedList list;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            list.push_back(s[i]);
        }
        else{
            if (list.empty()){
                return false;
            }
            if(list.top() == '(' && s[i] == ')'){
                list.pop_back();
            }
            else if(list.top() == '{' && s[i] == '}'){
                list.pop_back();
            }
            else if(list.top() == '[' && s[i] == ']'){
                list.pop_back();
            }
            else{
                return false;
            }
        }
    }
    if(list.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cin >> s;
    if(check(s)){
        cout << "yes";
    }
    else{
        cout << "no";
    }
}