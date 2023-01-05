#include <iostream>
#include <stack>
using namespace std;

bool check(string s){
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if (st.empty()){
                return false;
            }
            if(st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else if(st.top() == '{' && s[i] == '}'){
                st.pop();
            }
            else if(st.top() == '[' && s[i] == ']'){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
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