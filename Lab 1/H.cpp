#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> dq1;
    deque<int> dq2;
    deque<int> dq;
    while(n--){
        if(dq1.size() < dq2.size()){
            int a = dq2.front();
            dq1.push_back(a);
            dq2.pop_front();
        }
        char s;
        cin >> s;
        if(s == '+'){
            int m;
            cin >> m;
            if(dq1.size() > dq2.size()){
                dq2.push_back(m);
            }
            else if(dq1.size() < dq2.size()){
                int a = dq2.front();
                dq1.push_back(a);
                dq2.pop_front();
                dq2.push_back(m);
            }
            else if(dq1.size() == dq2.size()){
                dq2.push_back(m);
                int a = dq2.front();
                dq1.push_back(a);
                dq2.pop_front();
            }
        }
        if(s == '*'){
            int m;
            cin >> m;
            dq2.push_front(m);
        }
        if(s == '-'){
            int a = dq1.front();
            dq.push_back(a);
            dq1.pop_front();
            if(dq1.size() < dq2.size()){
                int b = dq2.front();
                dq1.push_back(b);
                dq2.pop_front();
            }
        }
    }
    while(!dq.empty()){
        cout << dq.front() << endl;
        dq.pop_front();
    }
}