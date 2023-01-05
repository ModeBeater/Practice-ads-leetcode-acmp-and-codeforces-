#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> v[105];
vector<int> st;
vector<int> st1;
int k;
int min1 = 1000000;
int ans[3];
int sum = 0;
bool ok[105];
int n;
void check(int x){
    if(ok[x]){
        return;
    }
    ok[x] = true;
    for(int j = 0; j < v[x].size(); j++){
        if(v[x][j] != 0 && !ok[j + 1]){
            // cout << j + 1 << " ";
            st1.push_back(x);
            st.push_back(v[x][j]);
            if(st.size() == 2){
                // cout << st[0] << ' ' << st[1] << ' ' << v[j + 1][k - 1] << endl;
                int sum = st[0] + st[1] + v[j + 1][k - 1];
                if(sum < min1){
                    min1 = sum;
                    ans[0] = st1[0];
                    ans[1] = st1[1];
                    ans[2] = x + 1;
                }
                st.pop_back();
                // continue;
            }
            else if(st.size() < 2){
                check(j + 1);
            }
        }
    }
    st1.pop_back();
    st.pop_back();
}
​
​
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for(int i = 1; i <= n; i++){
        // ok[i] = true;
        k = i;
        check(i);
        // cout << endl;
        // return 0;
        for(int j = 1; j <= n; j++){
            ok[j] = false;
        }
        st.erase(st.begin(), st.end());
        st1.erase(st1.begin(), st1.end());
    }
    cout << min1 << endl;
    // for(int i = 0; i < 3; i++){
    //     cout << ans[i] << ' ';
    // }
}
