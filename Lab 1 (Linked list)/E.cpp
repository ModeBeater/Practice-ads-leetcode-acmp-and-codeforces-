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
    int back(){
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
    LinkedList list1;
    LinkedList list2;
    int size = 0;
    for(int i = 0; i < 5; i++){
        int x;
        cin >> x;
        list1.push_back(x);
    }
    for(int i = 0; i < 5; i++){
        int x;
        cin >> x;
        list2.push_back(x);
    }
    while(size < 1000000){
        size++;
        int a = list1.front();
        int b = list2.front();
        list1.pop_front();
        list2.pop_front();
        if(a == 0 && b == 9){
            list1.push_back(a);
            list1.push_back(b);
        }
        else if(a == 9 && b == 0){
            list2.push_back(a);
            list2.push_back(b);
        }
        else if(a > b){
            list1.push_back(a);
            list1.push_back(b);
        }
        else{
            list2.push_back(a);
            list2.push_back(b);
        }
        if(list1.empty()){
            cout << "second " << size;
            return 0;
        }
        else if(list2.empty()){
            cout << "first " << size;
            return 0;
        }
    }
    cout << "botva";
}