#include <iostream>
#include <stack>
using namespace std;



int main(){
    int n;
    cin >> n;
    stack<int> st;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.push(x);
    }
    int cnt1 = 0;
    int cnt2 = 0;
    int max = 0;
    while(!st.empty()){
        cout << "ASDASD" << endl;
        if(st.top() == 1){
            cnt1++;
            st.pop();
            while(st.top() == 1){
                cnt1++;
                st.pop();
            }
            while(st.top() == 2){
                cnt2++;
                st.pop();
            }
            if(cnt1 > cnt2){
                if(cnt2 > max){
                    max = cnt2;
                }
            }
            if(cnt2 > cnt1){
                if(cnt1 > max){
                    max = cnt1;
                }
            }
            cnt1 = 0;
            cnt2 = 0;
            cout << max << endl;
        }
        if(st.top() == 2){
            cnt2++;
            st.pop();
            while(st.top() == 2){
                cnt2++;
                st.pop();
            }
            while(st.top() == 1){
                cnt1++;
                st.pop();
            }
            if(cnt1 > cnt2){
                if(cnt2 > max){
                    max = cnt2;
                }
            }
            if(cnt2 > cnt1){
                if(cnt1 > max){
                    max = cnt1;
                }
            }
            cnt1 = 0;
            cnt2 = 0;
            cout << max << endl;
        }
    }
    cout << max;
}