#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> st;
    string s;
    while(s != "exit"){
        cin >> s;
        int n;
        if(s == "push"){
            cin >> n;
            st.push(n);
            cout << "ok" << endl;
        }
        if(s == "pop"){
            if(!st.empty()){
                cout << st.top() << endl;
                st.pop();
            }
        }
        if(s == "back"){
            cout << st.top() << endl;
        }
        if(s == "size"){
            cout << st.size() << endl;
        }
        if(s == "clear"){
            while(!st.empty()){
                st.pop();
            }
            cout << "ok" << endl;
        }
    }
    cout << "bye";
}