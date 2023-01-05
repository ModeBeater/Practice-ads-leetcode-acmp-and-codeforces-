#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> v[100500];
int cnt = 0;
bool used[100500];
vector<int> st;

void dfs(int a){
    if(used[a]){
        return;
    }
    used[a] = true;
    st.push_back(a);
    for(int i = 0; i < v[a].size(); i++){
        int to = v[a][i];
        if(!used[to]){
            dfs(to);
        }
    }
}


int main(){
    int n,m;
    cin >> n >> m;
    int ans = 0;
    vector<int> s[100500];
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int k = 1;
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            dfs(i);
            if(st.size() != 0){
                // sort(st.begin(), st.end());
                for(int j = 0; j < st.size(); j++){
                    s[k].push_back(st[j]);
                }
                st.erase(st.begin(),st.end());
                k++;
            }
        }
    }
    cout << k - 1 << endl;
    for(int i = 1; i < k; i++){
        cout << s[i].size() << endl;
        for(int j = 0; j < s[i].size(); j++){
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}