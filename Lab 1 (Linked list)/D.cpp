#include <iostream>

using namespace std;

struct Node{
    int n;
    string s;
    Node* next;
    Node* prev;
    Node(int val, string name){
        s = name;
        n = val;
        next = prev = NULL;
    }
};

class LinkedList{
public:
    Node* head = NULL;
    Node* tail = NULL;
    void push(int n, string s){
        Node* NewNode = new Node(n, s);
        if(head == NULL){
            head = tail = NewNode;
        }
        else{
            tail -> next = NewNode;
            NewNode -> prev = tail;
            tail = NewNode;
        }
    }
    void sort(){
        Node* i = head;
        Node* j = head -> next;
        while(i -> next != NULL){
            while(j != NULL){
                if(i -> n > j -> n){
                    swap(i -> n, j -> n);
                    swap(i -> s, j -> s);
                }
                j = j -> next;
            }
            i = i -> next;
            j = i;
        }
    }
    void print(){
        Node* cur = head;
        while(cur != NULL){
            cout << cur -> n << " " << cur -> s << endl;
            cur = cur -> next;
        }
    }
};
int main(){
    LinkedList list1;
    LinkedList list2;
    LinkedList list3;
    int n;
    while(cin >> n){
        string s;
        cin >> s;
        if(n == 9){
            list1.push(n,s);
        }
        if(n == 10){
            list2.push(n,s);
        }
        if(n == 11){
            list3.push(n,s);
        }
    }
    list1.print();
    list2.print();
    list3.print();
}
