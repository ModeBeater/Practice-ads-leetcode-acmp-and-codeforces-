#include <iostream>
using namespace std;
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
    int cnt;
    LinkedList(){
        head = NULL;
        cnt = 0;
    }
    void push_front(int n){
        Node* NewNode = new Node(n);
        if(head == NULL){
            head = tail = NewNode;
        }
        else{
            head -> prev = NewNode;
            NewNode -> next = head;
            head = NewNode;
        }
        cnt++;
    }
    void push_back(int n){
        Node* NewNode = new Node(n);
        if(head == NULL){
            head = tail = NewNode;
        }
        else{
            tail -> next = NewNode;
            NewNode -> prev = tail;
            tail = NewNode;
        }
        cnt++;
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
    int size(){
        return cnt;
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
    int n;
    cin >> n;
    LinkedList list1;
    LinkedList list2;
    LinkedList list;
    while(n--){
        if(list1.size() < list2.size()){
            int a = list2.front();
            list1.push_back(a);
            list2.pop_front();
        }
        char s;
        cin >> s;
        if(s == '+'){
            int m;
            cin >> m;
            if(list1.size() > list2.size()){
                list2.push_back(m);
            }
            else if(list1.size() < list2.size()){
                int a = list2.front();
                list1.push_back(a);
                list2.pop_front();
                list2.push_back(m);
            }
            else if(list1.size() == list2.size()){
                list2.push_back(m);
                int a = list2.front();
                list1.push_back(a);
                list2.pop_front();
            }
        }
        if(s == '*'){
            int m;
            cin >> m;
            list2.push_front(m);
        }
        if(s == '-'){
            int a = list1.front();
            list.push_back(a);
            list1.pop_front();
            if(list1.size() < list2.size()){
                int b = list2.front();
                list1.push_back(b);
                list2.pop_front();
            }
        }
    }
    while(!list.empty()){
        cout << list.front() << endl;
        list.pop_front();
    }
}