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
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void push(string val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node * cur = head;
            while(cur != NULL){
                if(cur -> val == val){
                    cur -> cnt++;
                    break;
                }
                if(cur -> next == NULL){
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
            }
        }
    }
    void MergeSort(){
        Node* i = head;
        Node* j = head -> next;
        SortedMerge(i,j);
    }
    Node* SortedMerge(Node* i, Node* j){
        Node* result = NULL;
        if(i == NULL){
            
            return(j);
        }
        else if(j == NULL){
            return(i);
        }
        if(i -> cnt < j -> cnt){
            result = i;
            result -> next = SortedMerge(i -> next, j);
        }
        else{
            result = j;
            result -> next = SortedMerge(i, j -> next);
        }
        return(result);
        // while(i -> next != NULL){
        //     while(j != NULL){
        //         if(j -> cnt > i -> cnt){
        //             swap(j -> val, i -> val);
        //             swap(j -> cnt, i -> cnt);
        //         }
        //         if(j -> cnt == i -> cnt){
        //             if(j -> val < i -> val){
        //                 swap(j -> val, i -> val);
        //                 swap(j -> cnt, i -> cnt);
        //             }
        //         }
        //         j = j -> next;
        //     }
        //     i = i -> next;
        //     j = i;
        // }
    }
    void print(){
        Node * cur = head;
        while(cur != NULL){
            cout << cur -> val << " " << cur -> cnt << endl;
            cur = cur -> next;
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
    list.MergeSort();
    list.print();
}