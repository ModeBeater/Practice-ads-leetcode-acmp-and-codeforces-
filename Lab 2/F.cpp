#include <iostream>
#include <sstream>

using namespace std;
bool ok = true;
int sum = 1;
struct Node{
    string val;
    Node* next;
    Node* prev;
    Node(string m){
        this->val = m;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LinkedList{
public:
    Node* head = NULL;
    Node* tail = NULL;
    void remove(int a){
        if(head == NULL){
            cout << "ERROR";
            ok = false;
            return;
        }
        else{
            int cnt = 1;
            Node* cur = head;
            while(cnt != a){
                cnt++;
                if(cur -> next == NULL){
                    cout << "ERROR";
                    ok = false;
                    return;
                }
                cur = cur -> next;
            }
            if(cnt == a){
                if(cur -> prev){
                    if(cur -> next){
                        cur -> prev -> next = cur -> next;
                        cur -> next -> prev = cur -> prev;
                    }
                    else{
                        cur -> prev -> next = NULL;
                    }
                }
                else{
                    if(cur -> next){
                        head = cur -> next;
                        cur -> next -> prev = NULL;
                    }
                    else{
                        head = NULL;
                    }
                }
            }
        }
    }
    void star(int a, string m){
        Node* NewNode = new Node(m);
        if(head == NULL){
            cout << "ERROR";
            ok = false;
            return;
        }
        else{
            int cnt = 1;
            Node* cur = head;
            while(cnt != a){
                cnt++;
                if(cur -> next == NULL){
                    cout << "ERROR";
                    ok = false;
                    return;
                }
                cur = cur -> next;
            }
            if(cnt == a){
                if(cur -> prev){
                    if(cur -> next){
                        cur -> prev -> next = NewNode;
                        NewNode -> prev = cur -> prev;
                        NewNode -> next = cur -> next;
                        cur -> next -> prev = NewNode;
                    }
                    else{
                        cur -> prev -> next = NewNode;
                        NewNode -> prev = cur -> prev;
                    }
                }
                else{
                    if(cur -> next){
                        head = NewNode;
                        NewNode -> next = cur -> next;
                        cur -> next -> prev = NewNode;
                    }
                    else{
                        head = NewNode;
                    }
                }
            }
        }
    }
    void push(int a,string m){
        Node* NewNode = new Node(m);
        if(head == NULL){
            head = tail = NewNode;
        }
        else{
            int cnt = 1;
            Node* cur = head;
            if(a > sum){
                cout << "ERROR" << endl;
                ok = false;
                return;
            }
            if(a == sum){
                while(cur -> next != NULL){
                    cur = cur -> next;
                }
                cur -> next = NewNode;
                NewNode -> prev = cur;
                return;
            }
            while(cnt != a){
                cnt++;
                if(cur -> next != NULL){
                    cur = cur -> next;
                }
            }
            if(cnt == a){
                if(cur -> prev){
                    if(cur -> next){
                        cur -> prev -> next = NewNode;
                        NewNode -> prev = cur -> prev;
                        NewNode -> next = cur;
                        cur -> prev = NewNode;
                    }
                    else{
                        cur -> prev -> next = NewNode;
                        NewNode -> prev = cur -> prev;
                        NewNode -> next = cur;
                        cur -> prev = NewNode;
                    }
                }
                else{
                    if(cur -> next){
                        head = NewNode;
                        NewNode -> next = cur;
                        cur -> prev = NewNode;
                    }
                    else{
                        head -> next = NewNode;
                        NewNode -> prev = head;
                    }
                }
            }
        }
    }
    void print(){
        Node* cur = head;
        if(head == NULL){
            cout << "EMPTY" << endl;
            return;
        }
        while(cur != NULL){
            cout << cur -> val << endl;
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
        string t;
        for(int i = 1; i < s.size(); i++){
            t += s[i];
        }
        stringstream ss;
        int a;
        ss << t;
        ss >> a;
        string b;
        getline(cin, b);
        string m;
        for(int i = 1; i < b.size(); i++){
            m += b[i];
        }
        if(s[0] == '+'){
            list.push(a,m);
            sum++;
            if(ok == false){
                return 0;
            }
        }
        if(s[0] == '-'){
            list.remove(a);
            sum--;
            if(ok == false){
                return 0;
            }
        }
        if(s[0] == '*'){
            list.star(a,m);
            if(ok == false){
                return 0;
            }
        }
    }
    list.print();
}