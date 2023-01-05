#include <iostream>
#include <stack>
using namespace std;


int main(){
    char a;
    stack<int> st;
    while(cin >> a){
        if(a == '-' || a == '+' || a == '*'){
            int b = st.top();
            st.pop();
            int c = st.top();
            st.pop();
            if(a == '-'){
                int d = c - b;
                st.push(d);
            }
            if(a == '+'){
                int d = b + c;
                st.push(d);
            }
            if(a == '*'){
                int d = b * c;
                st.push(d);
            }
        }
        else{
            int b = a - '0';
            st.push(b);
        }
    }
    cout << st.top();
}