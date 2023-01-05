#include <iostream>
#include <vector>
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
    vector<pair<int,int> > vec;
    LinkedList list[505];
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m;j++){
            int x;
            cin >> x;
            list[i].push_back(x);
        }
    }
    if(n > 2){
        while(!list[1].empty()){
            list[2].push_back(list[1].top());
            list[1].pop_back();
            vec.push_back(make_pair(1,2));
        }
        for(int i = 2; i <= n; i++){
            while(!list[i].empty()){
                if(list[i].top() == 1){
                    list[1].push_back(list[i].top());
                    vec.push_back(make_pair(i,1));
                }
                else{
                    if(i == 2){
                        list[3].push_back(list[i].top());
                        vec.push_back(make_pair(2,3));
                    }
                    else{
                        list[2].push_back(list[i].top());
                        vec.push_back(make_pair(i,2));
                    }
                }
                list[i].pop_back();
            }
        }
        while(!list[2].empty()){
            list[1].push_back(list[2].top());
            list[2].pop_back();
            vec.push_back(make_pair(2,1));
        }
        while(!list[1].empty() && list[1].top() != 1){
            int index = list[1].top();
            list[index].push_back(list[1].top());
            vec.push_back(make_pair(1,list[1].top()));
            list[1].pop_back();
        }
    }
    if(n == 2){
        while(!list[1].empty() && list[1].top() == 2){
            list[2].push_back(2);
            list[1].pop_back();
            vec.push_back(make_pair(1,2));
        }
        while(!list[2].empty() && list[2].top() == 1){
            list[1].push_back(1);
            list[2].pop_back();
            vec.push_back(make_pair(2,1));
        }
        while(!list[1].empty() && list[1].top() == 1){
            list[1].pop_back();
        }
        while(!list[2].empty() && list[2].top() == 2){
            list[2].pop_back();
        }
        if(!list[1].empty() || !list[2].empty()){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i].first << " " << vec[i].second << " " << endl;
    }
}