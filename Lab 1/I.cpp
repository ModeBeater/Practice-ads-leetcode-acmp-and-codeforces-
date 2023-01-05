#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    vector<pair<int,int> > vec;
    stack<int> st[505];
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m;j++){
            int x;
            cin >> x;
            st[i].push(x);
        }
    }
    if(n > 2){
        while(!st[1].empty()){
            st[2].push(st[1].top());
            st[1].pop();
            vec.push_back(make_pair(1,2));
        }
        for(int i = 2; i <= n; i++){
            while(!st[i].empty()){
                if(st[i].top() == 1){
                    st[1].push(st[i].top());
                    vec.push_back(make_pair(i,1));
                }
                else{
                    if(i == 2){
                        st[3].push(st[i].top());
                        vec.push_back(make_pair(2,3));
                    }
                    else{
                        st[2].push(st[i].top());
                        vec.push_back(make_pair(i,2));
                    }
                }
                st[i].pop();
            }
        }
        while(!st[2].empty()){
            st[1].push(st[2].top());
            st[2].pop();
            vec.push_back(make_pair(2,1));
        }
        while(!st[1].empty() && st[1].top() != 1){
            int index = st[1].top();
            st[index].push(st[1].top());
            vec.push_back(make_pair(1,st[1].top()));
            st[1].pop();
        }
    }
    if(n == 2){
        while(!st[1].empty() && st[1].top() == 2){
            st[2].push(2);
            st[1].pop();
            vec.push_back(make_pair(1,2));
        }
        while(!st[2].empty() && st[2].top() == 1){
            st[1].push(1);
            st[2].pop();
            vec.push_back(make_pair(2,1));
        }
        while(!st[1].empty() && st[1].top() == 1){
            st[1].pop();
        }
        while(!st[2].empty() && st[2].top() == 2){
            st[2].pop();
        }
        if(!st[1].empty() || !st[2].empty()){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i].first << " " << vec[i].second << " " << endl;
    }
}