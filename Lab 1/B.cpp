#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    string s;
    while(s != "exit"){
        cin >> s;
        if (s == "push"){
            int n;
            cin >> n;
            q.push(n);
            cout << "ok" << endl;
        }
        if (s == "pop"){
            if(!q.empty()){
                cout << q.front() << endl;
                q.pop();
            }
            else{
                cout << "error" << endl;
            }
        }
        if (s == "front"){
            if(!q.empty()){
                cout << q.front() << endl;
            }
            else{
                cout << "error" << endl;
            }
        }
        if (s == "size"){
            cout << q.size() << endl;
        }
        if (s == "clear"){
            while(!q.empty()){
                q.pop();
            }
            cout << "ok" << endl;
        }
    }
    cout << "bye" << endl;
}