#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int x){
        this->val = x;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LinkedList{
public:
    Node* head = NULL;
    Node* tail = NULL;
    void push(int x){
        Node* NewNode = new Node(x);
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
        while(i != NULL){
            while(j != NULL){
                if(i -> val < j -> val){
                    swap(i -> val, j -> val);
                }
                j = j -> next;
            }
            i = i -> next;
            j = i;
        }
    }
    void find(int min){
        Node* cur = head;
        while(cur -> val == min){
            cur = cur -> next;
        }
        cout << cur -> val;
    }
};

int main(){
    int n;
    cin >> n;
    int min = 0;
    LinkedList list;
    while(n--){
        int x;
        cin >> x;
        if(min < x){
            min = x;
        }
        list.push(x);
    }
    list.sort();
    list.find(min);
}