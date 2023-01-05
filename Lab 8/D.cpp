#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100500];
bool ok[100500];
vector<int> g[100500];
int cnt = 0;
int b = 0;
void check(int x){
    if(ok[x]){
        return;
    }
    ok[x] = true;
    b = 1;
    g[cnt].push_back(x);
    for(int i = 0; i < v[x].size(); i++){
        if(!ok[v[x][i]]){
            check(v[x][i]);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        check(i);
        if(b == 1){
            cnt++;
            b = 0;
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++){
        cout << g[i].size() << endl;
        for(int j = 0; j < g[i].size(); j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}